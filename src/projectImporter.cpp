
#include "DesignByContract.h"
#include "projectImporter.h"
#include "../TinyXML/tinyxml.h"
#include "Voertuig.h"
#include "Baan.h"
#include "Verkeerslicht.h"
#include "Kruispunt.h"

using namespace std;

//Auxiliary function for internal use only

const std::string fetch_text(TiXmlNode *pElement, std::ostream &errStream) {
    if (pElement == NULL) return "";

    TiXmlNode *elemNode = pElement->FirstChild();
    if (elemNode == NULL) return "";
    TiXmlText *text = elemNode->ToText();
    if (text == NULL) return "";
    return text->Value();
}

//Below is a static member function but one cannot repeat the static keyword in the implementation
#


SuccessEnum projectImporter::importVerkeerssimulatie(const char *inputfilename, std::ostream &errStream,
                                                     Verkeerssimulatie &game) {

    TiXmlDocument doc;
    SuccessEnum endResult = Succes;
    game.herstart();
    REQUIRE(game.properlyInitialized(), "game wasn't initialized when passed to VerkeerssimulatieImporter");

    if (!doc.LoadFile(inputfilename)) {
        errStream << "XML IMPORT ABORTED: " << doc.ErrorDesc() << endl;
        return ImportAborted;
    };

    TiXmlElement *root = doc.FirstChildElement();

    if (strcmp(root->Value(), "VERKEERSSIMULATIE") != 0) {
        errStream << "XML PARTIAL IMPORT: Expected <VERKEERSSIMULATIE> ... </VERKEERSSIMULATIE> and got <"
                  << root->Value() << "> ... </" << root->Value() << ">." << endl;
        endResult = PartialImport;
    } else {

        int ID = 0;
        vector<Baan *> banen;
        map<string, Verkeerslicht*> verkeerslichten;
        map<string, vector<Bushalte *> > bushalten;
        map<string, vector<Voertuig *> > voertuigen;
//        bool Cleanup = false;

        for (TiXmlNode *node = root->FirstChild(); node != NULL; node = node->NextSibling()) {
            if (strcmp(node->Value(), "BAAN") == 0) {
                TiXmlNode *naamNode = node->FirstChild("naam");
                TiXmlNode *lengteNode = node->FirstChild("lengte");

                if (naamNode == NULL || lengteNode == NULL) {
                    errStream << "[Ongeldige informatie] Onvolledige baan ingelezen. Baan wordt genegeerd." << endl;
                    endResult = PartialImport;
                    continue;
                }

                string naamString = naamNode->FirstChild()->ToText()->Value();
                string lengteString = lengteNode->FirstChild()->ToText()->Value();

                int lengte;

                sscanf(lengteString.c_str(), "%d", &lengte);

                if (lengte < 0) {
                    errStream << "[Ongeldige informatie] Lengte van baan kan niet negatief zijn. Baan wordt genegeerd."
                              << endl;
                    endResult = PartialImport;
                    continue;
                }

                Baan *baan = new Baan;
                baan->setLengte(lengte);
                baan->setNaam(naamString);
                banen.push_back(baan);
            } else if (strcmp(node->Value(), "VERKEERSLICHT") == 0) {
                TiXmlNode *baanNode = node->FirstChild("baan");
                TiXmlNode *positieNode = node->FirstChild("positie");
                TiXmlNode *cyclusNode = node->FirstChild("cyclus");

                if (baanNode == NULL || positieNode == NULL || cyclusNode == NULL) {
                    errStream
                            << "[Ongeldige informatie] Onvolledige verkeerslicht ingelezen. Verkeerslicht wordt genegeerd."
                            << endl;
                    endResult = PartialImport;
                    continue;
                }

                string baanString = baanNode->FirstChild()->ToText()->Value();
                string positieString = positieNode->FirstChild()->ToText()->Value();
                string cyclusString = cyclusNode->FirstChild()->ToText()->Value();

                int positie;
                int cyclus;

                sscanf(positieString.c_str(), "%d", &positie);
                sscanf(cyclusString.c_str(), "%d", &cyclus);

                if (positie < 0) {
                    errStream
                            << "[Ongeldige informatie] Positie van verkeerslicht kan niet negatief zijn. Verkeerslicht wordt genegeerd."
                            << endl;
                    endResult = PartialImport;
                    continue;
                }
                if (cyclus < 0) {
                    errStream
                            << "[Ongeldige informatie] Cyclus van verkeerslicht kan niet negatief zijn. Verkeerslicht wordt genegeerd."
                            << endl;
                    endResult = PartialImport;
                    continue;
                }
                Verkeerslicht *vl = new Verkeerslicht;
                vl->setPositie(positie);
                vl->setCycles(cyclus);
                verkeerslichten[baanString] = vl;
            } else if (strcmp(node->Value(), "VOERTUIG") == 0) {
                TiXmlNode *baanNode = node->FirstChild("baan");
                TiXmlNode *positieNode = node->FirstChild("positie");
                TiXmlNode *typeNode = node->FirstChild("type");

                if (baanNode == NULL || positieNode == NULL || typeNode == NULL) {
                    errStream << "[Ongeldige informatie] Onvolledige voertuig ingelezen. Voertuig wordt genegeerd."
                              << endl;
                    endResult = PartialImport;
                    continue;
                }

                string baanString = baanNode->FirstChild()->ToText()->Value();
                string positieString = positieNode->FirstChild()->ToText()->Value();
                string typeString = typeNode->FirstChild()->ToText()->Value();

                int positie;

                sscanf(positieString.c_str(), "%d", &positie);

                if (positie < 0) {
                    errStream
                            << "[Ongeldige informatie] Positie van voertuig kan niet negatief zijn. Voertuig wordt genegeerd."
                            << endl;
                    endResult = PartialImport;
                    continue;
                }
                if (!(typeString == "auto" || typeString == "bus" || typeString == "brandweerwagen" ||
                    typeString == "ziekenwagen" || typeString == "politiecombi")) {
                    errStream
                            << "[Ongeldige informatie] Type \""<< typeString <<"\" wordt niet ondersteund. Voertuig wordt genegeerd."
                            << endl;
                    endResult = PartialImport;
                    continue;
                }
                if (typeString == "auto") {
                    Auto *anAuto = new Auto;
                    anAuto->setPositie(positie);
                    anAuto->setType(typeString);
                    anAuto->setId(ID += 1);
                    voertuigen[baanString].push_back(anAuto);
                } else if (typeString == "bus") {
                    Bus *bus = new Bus;
                    bus->setPositie(positie);
                    bus->setType(typeString);
                    bus->setId(ID += 1);
                    voertuigen[baanString].push_back(bus);
                } else if (typeString == "brandweerwagen") {
                    Brandweerwagen *brandweerwagen = new Brandweerwagen;
                    brandweerwagen->setPositie(positie);
                    brandweerwagen->setType(typeString);
                    brandweerwagen->setId(ID += 1);
                    voertuigen[baanString].push_back(brandweerwagen);
                } else if (typeString == "ziekenwagen") {
                    Ziekenwagen *ziekenwagen = new Ziekenwagen;
                    ziekenwagen->setPositie(positie);
                    ziekenwagen->setType(typeString);
                    ziekenwagen->setId(ID += 1);
                    voertuigen[baanString].push_back(ziekenwagen);
                } else if (typeString == "politiecombi") {
                    Politiecombi *politiecombi = new Politiecombi;
                    politiecombi->setPositie(positie);
                    politiecombi->setType(typeString);
                    politiecombi->setId(ID += 1);
                    voertuigen[baanString].push_back(politiecombi);
                }
            } else if (strcmp(node->Value(), "BUSHALTE") == 0) {
                TiXmlNode *baanNode = node->FirstChild("baan");
                TiXmlNode *positieNode = node->FirstChild("positie");
                TiXmlNode *wachttijdNode = node->FirstChild("wachttijd");

                if (baanNode == NULL || positieNode == NULL || wachttijdNode == NULL) {
                    errStream << "[Ongeldige informatie] Onvolledige bushalte ingelezen. Bushalte wordt genegeerd."
                              << endl;
                    endResult = PartialImport;
                    continue;
                }

                string baanString = baanNode->FirstChild()->ToText()->Value();
                string positieString = positieNode->FirstChild()->ToText()->Value();
                string wachttijdString = wachttijdNode->FirstChild()->ToText()->Value();

                int positie;
                int wachttijd;

                sscanf(positieString.c_str(), "%d", &positie);
                sscanf(wachttijdString.c_str(), "%d", &wachttijd);

                if (positie < 0) {
                    errStream
                            << "[Ongeldige informatie] Positie van bushalte kan niet negatief zijn. Bushalte wordt genegeerd."
                            << endl;
                    endResult = PartialImport;
                    continue;
                }
                if (wachttijd < 0) {
                    errStream
                            << "[Ongeldige informatie] Wachttijd van bushalte kan niet negatief zijn. Bushalte wordt genegeerd."
                            << endl;
                    endResult = PartialImport;
                    continue;
                }
                Bushalte *bushalte = new Bushalte;
                bushalte->setPositie(positie);
                bushalte->setWachttijd(wachttijd);
                bushalten[baanString].push_back(bushalte);

            } else if (strcmp(node->Value(), "KRUISPUNT") == 0) {
                continue;
            } else {
                errStream << "[Onherkenbaar element] Element \"" << node->Value() <<"\" wordt niet herkend. Element wordt genegeerd." << endl;
                continue;
            }
        }
        if (banen.empty()){
            errStream << "XML PARTIAL IMPORT [Inconsistente verkeerssimulatie] Er zijn geen banen ingelezen." << endl;
            endResult = PartialImport;
        }
        if (voertuigen.empty()){
            errStream << "XML PARTIAL IMPORT [Inconsistente verkeerssimulatie] Er zijn geen voertuigen ingelezen." << endl;
            endResult = PartialImport;
        }
        if (verkeerslichten.empty()){
            errStream << "XML PARTIAL IMPORT [Inconsistente verkeerssimulatie] Er zijn geen verkeerslichten ingelezen." << endl;
            endResult = PartialImport;
        }
        if (bushalten.empty()){
            errStream << "XML PARTIAL IMPORT [Inconsistente verkeerssimulatie] Er zijn geen bushalten ingelezen." << endl;
            endResult = PartialImport;
        }

        //banen moeten gelinkt worden met voertuigen - verkeerslichten - bushalten
        for (long unsigned int i = 0; i < banen.size(); i++){
            // verkeerslichten
            string baanNaam = banen[i]->getNaam();
            for (long unsigned int j = 0; j < verkeerslichten.size(); j++){
                if (verkeerslichten.find(baanNaam) != verkeerslichten.end()){
                    verkeerslichten[baanNaam]->setBaan(banen[i]);
                    banen[i]->addVerkeerslicht(verkeerslichten[baanNaam]);
                } else {
                    // verkeerslicht niet gevonden
                }
            }

            // bushalten
            for (long unsigned int j = 0; j < bushalten.size(); j++){
                if (bushalten.find(baanNaam) != bushalten.end()){
                    for (long unsigned int u = 0; u < bushalten[baanNaam].size(); u++){
                        bushalten[baanNaam][u]->setBaan(banen[i]);
                        banen[i]->addBushalte(bushalten[baanNaam][u]);
                    }
                } else {
                    //bushalte niet gevonden
                }
            }

            // voertuigen
            for (long unsigned int j = 0; j < voertuigen.size(); j++){
                if (voertuigen.find(baanNaam) != voertuigen.end()){
                    for (long unsigned int u = 0; u < voertuigen[baanNaam].size(); u++){
                        voertuigen[baanNaam][u]->setBaan(banen[i]);
                        banen[i]->addVoertuig(voertuigen[baanNaam][u]);
                    }
                } else{
                    //voertuig niet gevonden
                }
            }
        }

        game.setBanen(banen);
    }

    doc.Clear();
    return endResult;
}
