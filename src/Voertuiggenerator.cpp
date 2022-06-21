//
// Created by chloeacm on 20.06.22.
//

#include "Voertuiggenerator.h"
#include "Voertuig.h"

Voertuiggenerator::Voertuiggenerator() {
    frequentie = 0;
    tijd = 0;
    init = this;
}

void Voertuiggenerator::setBaan(Baan *b) {
    baan = b;
}

Baan* Voertuiggenerator::getBaan() {
    return baan;
}

void Voertuiggenerator::setFrequentie(int f) {
    frequentie = f;
}

int Voertuiggenerator::getFrequentie() {
    return frequentie;
}

void Voertuiggenerator::updateTijd(double simulatietijd) {
    tijd += simulatietijd;
}



Voertuig* Voertuiggenerator::generateVoertuig(double simulatietijd) {
    updateTijd(simulatietijd);
    Voertuig* nieuwVoertuig = NULL;
    if (tijd > frequentie) {
        tijd = 0;
        bool generate = generatePossible();
        if (generate) {
            if (typeV == "auto") nieuwVoertuig = new Auto;
            else if (typeV == "bus") nieuwVoertuig = new Bus;
            else if (typeV == "brandweerwagen") nieuwVoertuig = new Brandweerwagen;
            else if (typeV == "ziekenwagen") nieuwVoertuig = new Ziekenwagen;
            else if (typeV == "politiecombi") nieuwVoertuig = new Politiecombi;
            nieuwVoertuig->setBaan(baan);
        }
    }
    return nieuwVoertuig;
}

void Voertuiggenerator::setType(std::string &t) {
    typeV = t;
}

std::string Voertuiggenerator::getType() {
    return typeV;
}

void Voertuiggenerator::setL(int l) {
    lengte = l;
}

int Voertuiggenerator::getL() {
    return lengte;
}

bool Voertuiggenerator::generatePossible() {
    std::vector<Voertuig*> vt = baan->getVoertuigen();
    for (unsigned int i = 0; i < vt.size(); i++) {
        if (vt[i]->getPositie() <= 2*lengte && vt[i]->getPositie() >= 0) {
            return false;
        }
    }
    return true;
}

