/**
 * @file Parser.cpp
 * @authors Yassir Chebaa, Chloë Mansibang
 * @date 24/03/2022
 */

#include "Parser.h"
#include "Voertuig.h"
#include "Baan.h"
#include "Verkeerslicht.h"
#include "Kruispunt.h"
#include "sstream"
#include "../TinyXML/tinyxml.h"
#include "iostream"
#include "DesignByContract.h"
#include "Voertuiggenerator.h"

using namespace std;

Parser::Parser(const char *filename) {
    init = this;
    ID = 0;
    positie = 0;
    XML(filename);
    ENSURE(properlyInitialized(), "Parser is niet correct geïnitialiseerd.");
}

void Parser::XML(const char *filename) {
    TiXmlDocument doc;
    if (!doc.LoadFile(filename)) {
        cerr << doc.ErrorDesc() << endl;
    }
    if (doc.FirstChildElement() == NULL) {
        cerr << "Failed to load file: No root element." << endl;
        doc.Clear();
    }
    TiXmlElement* root = doc.FirstChildElement();
    for (TiXmlElement *elem = root->FirstChildElement(); elem != NULL; elem = elem->NextSiblingElement()) {
        string b = "BAAN";
        string v = "VERKEERSLICHT";
        string vt = "VOERTUIG";
        string bh = "BUSHALTE";
        string k = "KRUISPUNT";
        string vg = "VOERTUIGGENERATOR";
        if (elem->Value() == b) {
            Baan *baan = new Baan;
            for (TiXmlElement *elemBaan = elem->FirstChildElement();
                 elemBaan != NULL; elemBaan = elemBaan->NextSiblingElement()) {
                string elemName = elemBaan->Value();
                if (elemName == "naam") {
                    baan->setNaam(elemBaan->GetText());
                }
                else if (elemName == "lengte") {
                    baan->setLengte(stringToInt(elemBaan->GetText()));
                }
            }
            banen.push_back(baan);
        }
        else if (elem->Value() == v) {
            Verkeerslicht *licht = new Verkeerslicht;
            string name;
            pair<int, int> vlPair;
            for (TiXmlElement *elemLicht = elem->FirstChildElement();
                 elemLicht != NULL; elemLicht = elemLicht->NextSiblingElement()) {
                string elemName = elemLicht->Value();
                if (elemName == "positie") {
                    licht->setPositie(stringToInt(elemLicht->GetText()));
                    vlPair.first = stringToInt(elemLicht->GetText());
                } else if (elemName == "cyclus") {
                    licht->setCycles(stringToInt(elemLicht->GetText()));
                    vlPair.second = stringToInt(elemLicht->GetText());
                } else if (elemName == "baan") {
                    Baan* juisteBaan = findBaan(elemLicht->GetText());
                    juisteBaan->addVerkeerslicht(licht);
                    licht->setBaan(juisteBaan);
                    name = elemLicht->GetText();
                    // wat als verkeerslicht eerder komt dan baan in bestand?
                }
            }
        }
        else if (elem->Value() == vt) {
            for (TiXmlElement *elemVoertuig = elem->FirstChildElement();
                 elemVoertuig != NULL; elemVoertuig = elemVoertuig->NextSiblingElement()) {
                string elemName = elemVoertuig->Value();
                if (elemName == "positie") {
                    positie = stringToInt(elemVoertuig->GetText());
                }
                else if (elemName == "baan") {
                    baanNaam = elemVoertuig->GetText();
                }
                else if (elemName == "type") {
                    typeVoertuig = elemVoertuig->GetText();
                    if (typeVoertuig == "auto"){
                        Auto *anAuto = new Auto;
                        assignInfo(anAuto);
                    } else if (typeVoertuig == "bus"){
                        Bus *bus = new Bus;
                        assignInfo(bus);
                    } else if (typeVoertuig == "brandweerwagen"){
                        Brandweerwagen *brandweerwagen = new Brandweerwagen;
                        assignInfo(brandweerwagen);
                    } else if (typeVoertuig == "ziekenwagen"){
                        Ziekenwagen *ziekenwagen = new Ziekenwagen;
                        assignInfo(ziekenwagen);
                    } else if (typeVoertuig == "politiecombi"){
                        Politiecombi *politiecombi = new Politiecombi;
                        assignInfo(politiecombi);
                    }
                }
            }
        }
        else if (elem->Value() == bh) {
            Bushalte* bushalte = new Bushalte;
            for (TiXmlElement *elemBH = elem->FirstChildElement(); elemBH != NULL; elemBH = elemBH->NextSiblingElement()) {
                string elemName = elemBH->Value();
                if (elemName == "positie") {
                    bushalte->setPositie(stringToInt(elemBH->GetText()));
                }
                else if (elemName == "wachttijd") {
                    bushalte->setWachttijd(stringToInt(elemBH->GetText()));
                }
                else if (elemName == "baan") {
                    Baan* juisteBaan = findBaan(elemBH->GetText());
                    juisteBaan->addBushalte(bushalte);
                    bushalte->setBaan(juisteBaan);
                }
            }
        }
        else if (elem->Value() == k) {
            std::pair<Baan*,Baan*> tempBanen;
            std::pair<int,int> tempPosities;
            Kruispunt* kruispunt = new Kruispunt;
            TiXmlElement* elemK = elem->FirstChildElement();
            while (elemK != NULL) {
                string elemAtr = elemK->Attribute("positie");
                int pos = stringToInt(elemAtr);
                string elemName = elemK->Value();
                Baan* baan = findBaan(elemK->GetText());

                if (tempBanen.first == NULL) {
                    tempBanen.first = baan;
                    tempPosities.first = pos;
                }
                else {
                    tempBanen.second = baan;
                    tempPosities.second = pos;
                }
                elemK = root->NextSiblingElement();
            }
            kruispunt->setBanen(tempBanen);
            kruispunt->setPosities(tempPosities);
            tempBanen.first->addKruispunt(kruispunt);
            tempBanen.second->addKruispunt(kruispunt);
        }
        else if (elem->Value() == vg) {
            Voertuiggenerator* g = new Voertuiggenerator;
            for (TiXmlElement* elemVG = elem->FirstChildElement(); elemVG != NULL; elemVG = elemVG->NextSiblingElement()) {
                string elemName = elemVG->Value();
                if (elemName == "baan") {
                    Baan* juisteBaan = findBaan(elemVG->GetText());
                    g->setBaan(juisteBaan);
                    juisteBaan->addGenerator(g);
                }
                else if (elemName == "frequentie") {
                    g->setFrequentie(stringToInt(elemVG->GetText()));
                }
                else if (elemName == "type") {
                    string t = elemVG->GetText();
                    g->setType(t);
                    if (t == "auto") g->setL(4);
                    else if (t == "bus") g->setL(12);
                    else if (t == "brandweerwagen") g->setL(10);
                    else if (t == "ziekenwagen") g->setL(8);
                    else if (t == "politiecombi") g->setL(6);
                }
            }

        }
    }
    for (unsigned int i = 0; i < banen.size(); i++) { //moet dit wel hier? moeten we niet sorteren na elke simulatiestap?
        banen[i]->sorteerVoertuigen();
    }
}

int Parser::stringToInt(const std::string &s) {
    REQUIRE(properlyInitialized(), "Parser was niet correct geïnitialiseerd");
    int i;
    std::istringstream(s) >> i;
    return i;
    // wat als s ook letter bevat?
}

Baan *Parser::findBaan(const std::string &s) {
    REQUIRE(properlyInitialized(), "Verkeerssimulatie was niet correct geïnitialiseerd");
    REQUIRE(!banen.empty(), "Banen mag niet leeg zijn.");
    for (long unsigned int b = 0; b < banen.size(); b++) {
        if (banen[b]->getNaam() == s) {
            return banen[b];
        }
    }
    return NULL;
}

bool Parser::properlyInitialized() const{
    return init == this;
}

const vector<Baan *> &Parser::getBanen() const {
    REQUIRE(properlyInitialized(), "Parser was niet correct geïnitialiseerd");
    return banen;
}

void Parser::assignInfo(Voertuig *voertuig) {
    REQUIRE(properlyInitialized(), "Parser was niet correct geïnitialiseerd");
    voertuig->setId(ID += 1);
    voertuig->setPositie(positie);
    voertuig->setType(typeVoertuig);
    Baan* juisteBaan = findBaan(baanNaam);
    juisteBaan->addVoertuig(voertuig);
    voertuig->setBaan(juisteBaan);
}


