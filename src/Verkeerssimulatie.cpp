/**
 * @file Verkeerssimulatie.cpp
 * @authors Yassir Chebaa, Chloë Mansibang
 * @date 24/03/2022
 */

#include "Verkeerssimulatie.h"
#include "DesignByContract.h"
#include "../TinyXML/tinyxml.h"
#include <sstream>
#include <iostream>
#include "cmath"
#include "Baan.h"
#include "Voertuig.h"
#include "Verkeerslicht.h"
#include "Bushalte.h"
#include "Kruispunt.h"
#include "Parser.h"

using namespace std;

Verkeerssimulatie::Verkeerssimulatie() {
    simulatietijd = 0.0166;
    ID = 0;
    init = this;
    ENSURE(properlyInitialized(), "(Constructor) Verkeerssimulatie niet correct geïnitialiseerd.");
}

Verkeerssimulatie::Verkeerssimulatie(const char *filename) {
    init = this;
    ID = 0;
    simulatietijd = 1;//
    Parser parser(filename);
    banen = parser.getBanen();
    ENSURE(properlyInitialized(), "(Constructor) Verkeerssimulatie niet correct geïnitialiseerd.");
}

double Verkeerssimulatie::getSimulatietijd() const {
    REQUIRE(properlyInitialized(), "Verkeerssimulatie is niet correct geïnitialiseerd");
    return simulatietijd;
}

void Verkeerssimulatie::print() {
    REQUIRE(properlyInitialized(), "Verkeerssimulatie was niet correct geïnitialiseerd");
    //cout << "Verkeerslichtpositie: " << intToString(vl->getPositie()) << endl;
    //cout << "Tijd van verkeerslicht: " << intToString(vl->getTijd()) << endl;
    for (long unsigned int i = 0; i < banen.size(); i++) {
        for (long unsigned int k = 0; k < banen[i]->getVerkeerslichten().size(); k++) {
            Verkeerslicht* vl = banen[i]->getVerkeerslichten()[k];
            cout << "Verkeerslicht: " << endl;
            cout << " -> position: " << vl->getPositie() << endl;
            cout << " -> tijd/cycle: " << vl->getTijd() << "/" << vl->getCycles() << endl;
        }
        for (long unsigned int l = 0; l < banen[i]->getBushaltes().size(); l++) {
            Bushalte* bh = banen[i]->getBushaltes()[l];
            cout << "Bushalte: " << endl;
            cout << " -> position: " << bh->getPositie() << endl;
            cout << " -> tijd/wachttijd: " << bh->getTijd() << "/" << bh->getWachttijd() << endl;
        }
        for (long unsigned int j = 0; j < banen[i]->getVoertuigen().size(); j++) {
            Voertuig* vt = banen[i]->getVoertuigen()[j];
            cout << "Voertuig: " << vt->getId() << endl;
            cout << " -> baan: " << vt->getBaan()->getNaam()<< endl;
            cout << " -> positie: " << vt->getPositie() << endl;
            cout << " -> snelheid: " << vt->getSnelheid() << endl;
            cout << " -> type: " << vt->getType() << endl;
        }
        cout << "-----------------------------------------------" << endl;
    }
}

void Verkeerssimulatie::automatischeSimulatie() {
    REQUIRE(properlyInitialized(), "Verkeerssimulatie is niet correct geïnitialiseerd");
    bool geenVoertuigenMeer = false;
    while (!geenVoertuigenMeer) {
        for (unsigned int i=0; i<banen.size(); i++) {
            vector<Voertuig*> vt = banen[i]->getVoertuigen();
            if (vt.size() == 1) {
                vt[0]->berekenPosEnSnelheid(simulatietijd);
                if (vt[0]->getPositie() <= banen[i]->getLengte()) {
                    Voertuig* n = NULL;
                    vt[0]->berekenVersnelling(n);
                }
            }
            else {
                for (unsigned int j=1; j<vt.size(); j += 2) {
                    vt[j-1]->berekenPosEnSnelheid(simulatietijd);
                    vt[j]->berekenPosEnSnelheid(simulatietijd);
                    vt[j]->berekenVersnelling(vt[j-1]);
                }
            }
            banen[i]->verwijderVoertuigen();
            std::vector<Verkeerslicht*> vl = banen[i]->getVerkeerslichten();
            for (unsigned int k=0; k<vl.size(); k++) {
                vl[k]->verkeerslichtSimulatie(simulatietijd);
                print();
            }
            std::vector<Bushalte*> bh = banen[i]->getBushaltes();
            for (unsigned int l=0; l<bh.size(); l++) {
                bh[l]->bushalteSimulatie(simulatietijd);
            }
        }
        geenVoertuigenMeer = true;
        for (unsigned int i=0; i<banen.size(); i++) {
            if (banen[i]->getVoertuigen().size() != 0) {
                geenVoertuigenMeer = false;
            }
        }
    }
}

bool Verkeerssimulatie::properlyInitialized() const{
    return init == this;
}

const vector<Baan *> &Verkeerssimulatie::getBanen() const {
    REQUIRE(properlyInitialized(), "Verkeerssimulatie is niet correct geïnitialiseerd");
    return banen;
}

int Verkeerssimulatie::getId() const {
    REQUIRE(properlyInitialized(), "Verkeerssimulatie is niet correct geïnitialiseerd");
    return ID;
}

void Verkeerssimulatie::setBanen(const vector<Baan *> &b) {
    REQUIRE(properlyInitialized(), "Verkeerssimulatie is niet correct geïnitialiseerd");
    Verkeerssimulatie::banen = b;
    ENSURE(getBanen() == b, "Banen is niet correct aangepast");
}

void Verkeerssimulatie::setSimulatietijd(double st) {
    REQUIRE(properlyInitialized(), "Verkeerssimulatie is niet correct geïnitialiseerd");
    Verkeerssimulatie::simulatietijd = st;
    ENSURE(getSimulatietijd() == st, "Simulatietijd is niet correct aangepast");
}

void Verkeerssimulatie::setId(int id) {
    REQUIRE(properlyInitialized(), "Verkeerssimulatie is niet correct geïnitialiseerd");
    ID = id;
    ENSURE(getId() == id, "ID is niet correct aangepast");
}

void Verkeerssimulatie::addBaan(Baan* b) {
    REQUIRE(properlyInitialized(), "Verkeerssimulatie is niet correct geïnitialiseerd");
    banen.push_back(b);
}

void Verkeerssimulatie::herstart() {
    REQUIRE(properlyInitialized(), "Verkeerssimulatie was niet correct geïnitialiseerd.");
    for (vector<Baan*>::iterator it = banen.begin(); it != banen.end(); it++) delete *it;
    banen.clear();
    ENSURE(banen.empty(), "Vector banen in verkeersimulatie is niet leeg");
}
