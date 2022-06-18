
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
    // game reinitialise
    REQUIRE(game.properlyInitialized(), "game wasn't initialized when passed to VerkeerssimulatieImporter");

    if (!doc.LoadFile(inputfilename)) {
        errStream << "XML IMPORT ABORTED: " << doc.ErrorDesc() << endl;
        return ImportAborted;
    };

    TiXmlElement *root = doc.FirstChildElement();

    if (strcmp(root->Value(), "Verkeerssimulatie") != 0) {
        errStream << "XML PARTIAL IMPORT: Expected <Verkeerssimulatie> ... </Verkeerssimulatie> and got <"
                  << root->Value() << "> ... </" << root->Value() << ">." << endl;
        endResult = PartialImport;
    } else {

        vector<Baan *> banen;
        map<string, vector<Verkeerslicht*> > verkeerslichten;
        bool Cleanup = false;

        for (TiXmlNode *node = root->FirstChild(); node != NULL; node = node->NextSibling()) {
            if (strcmp(node->Value(), "BAAN") == 0) {
                TiXmlNode *naamNode = node->FirstChild("naam");
                TiXmlNode *lengteNode = node->FirstChild("lengte");

                if (naamNode == NULL || lengteNode == NULL) {
                    errStream << "[Ongeldige informatie] Onvolledige baan ingelezen. Baan wordt genegeerd." << endl;
                    continue;
                }

                string naamString = naamNode->FirstChild()->ToText()->Value();
                string lengteString = lengteNode->FirstChild()->ToText()->Value();

                int lengte;

                sscanf(lengteString.c_str(), "%d", &lengte);

                if (lengte < 0) {
                    errStream << "[Ongeldige informatie] Lengte van baan kan niet negatief zijn. Baan wordt genegeerd."
                              << endl;
                    continue;
                }

                Baan *baan = new Baan;
                baan->setLengte(lengte);
                baan->setNaam(naamString);
                banen.push_back(baan);
            } else if (strcmp(node->Value(), "VERKEERSLICHT") == 0) {
                TiXmlNode* baanNode = node->FirstChild("baan");
                TiXmlNode* positieNode = node->FirstChild("positie");
                TiXmlNode* cyclusNode = node->FirstChild("cyclus");

                if (baanNode == NULL || positieNode == NULL || cyclusNode == NULL){
                    errStream << "[Ongeldige informatie] Onvolledige verkeerslicht ingelezen. Verkeerslicht wordt genegeerd." << endl;
                    continue;
                }

                string baanString = baanNode->FirstChild()->ToText()->Value();
                string positieString = positieNode->FirstChild()->ToText()->Value();
                string cyclusString = cyclusNode->FirstChild()->ToText()->Value();

                int positie;
                int cyclus;

                sscanf(positieString.c_str(), "%d", positie);
                sscanf(cyclusString.c_str(), "%d", cyclus);

                if (positie < 0){
                    errStream << "[Ongeldige informatie] Positie van verkeerslicht kan niet negatief zijn. Verkeerslicht wordt genegeerd."
                              << endl;
                    continue;
                }
                if (cyclus < 0){
                    errStream << "[Ongeldige informatie] Cyclus van verkeerslicht kan niet negatief zijn. Verkeerslicht wordt genegeerd."
                              << endl;
                    continue;
                }
                Verkeerslicht* vl = new Verkeerslicht;
                vl->setPositie(positie);
                vl->setCycles(cyclus);
                verkeerslichten[baanString].push_back(vl);
            } else if (strcmp(node->Value(), "VOERTUIG") == 0){
                TiXmlNode* baanNode = node->FirstChild("baan");
                TiXmlNode* positieNode = node->FirstChild("positie");
                TiXmlNode* typeNode = node->FirstChild("node");

                if (baanNode == NULL || positieNode == NULL || typeNode == NULL){
                    errStream << "[Ongeldige informatie] Onvolledige voertuig ingelezen. Voertuig wordt genegeerd." << endl;
                    continue;
                }

                string baanString = baanNode->FirstChild()->ToText()->Value();
                string positieString = positieNode->FirstChild()->ToText()->Value();
                string typeString = typeNode->FirstChild()->ToText()->Value();

                int positie;

                sscanf(positieString.c_str(), "%d", positie);

                if (positie < 0){
                    errStream << "[Ongeldige informatie] Positie van voertuig kan niet negatief zijn. Voertuig wordt genegeerd."
                              << endl;
                    continue;
                }
                if (typeString != "auto" || typeString != "bus" || typeString != "brandweerwagen" || typeString != "ziekenwagen" || typeString != "politiecombi"){
                    errStream << "[Ongeldige informatie] Type van voertuig wordt niet ondersteund. Voertuig wordt genegeerd."
                              << endl;
                    continue;
                }
                if (typeString == "auto"){
                    Auto* anAuto = new Auto;
                } else if (typeString == "bus"){
                    Bus* bus = new Bus;
                } else if (typeString == "brandweerwagen"){
                    Brandweerwagen* brandweerwagen = new Brandweerwagen;
                } else if (typeString == "ziekenwagen"){
                    Ziekenwagen* ziekenwagen = new Ziekenwagen;
                } else if (typeString == "politiecombi"){
                    Politiecombi* politiecombi = new Politiecombi;
                } //moet nog inorde gebracht worden
            } else if (strcmp(node->Value(), "BUSHALTE") == 0){

            } else if (strcmp(node->Value(), "KRUISPUNT") == 0){

            } else {

            }
        }
    }


    doc.Clear();
    return endResult;
}

int projectImporter::toIntConverter(TiXmlNode* TiNode) {
    string y = TiNode->FirstChild()->ToText()->Value();
    int x;
    sscanf(y.c_str(), "%d", x);
    return x;
}
