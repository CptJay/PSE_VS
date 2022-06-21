//
// Created by chloeacm on 02.05.22.
//

#include "Kruispunt.h"
#include "Voertuig.h"
#include <map>
#include <cstdlib>
#include <ctime>

Kruispunt::Kruispunt() {
    init = this;
    ENSURE(properlyInitialized(), "Kruispunt is niet correct geïnitialiseerd.");
}

void Kruispunt::setBanen(std::pair<Baan*,Baan*> b) {
    REQUIRE(properlyInitialized(), "Kruispunt is niet correct geïnitialiseerd.");
    banen = b;
}

std::pair<Baan*,Baan*> Kruispunt::getBanen() {
    REQUIRE(properlyInitialized(), "Kruispunt is niet correct geïnitialiseerd.");
    return banen;
}

std::pair<int,int>  Kruispunt::getPosities() {
    REQUIRE(properlyInitialized(), "Kruispunt is niet correct geïnitaliseerd.");
    return posities;
}

void Kruispunt::setPosities(std::pair<int, int> pos) {
    REQUIRE(properlyInitialized(), "Kruispunt is niet correct geïnitaliseerd.");
    posities = pos;
}

bool Kruispunt::properlyInitialized() const{
    return init == this;
}

int Kruispunt::getPositie(Baan *b) {
    REQUIRE(properlyInitialized(), "Kruispunt is niet correct geïnitaliseerd.");

    if (banen.first->getNaam() == b->getNaam()) {
        return posities.first;
    }
    else if (banen.second->getNaam() == b->getNaam()) {
        return posities.second;
    }
    ENSURE(true == false, "Geen positie");
}

void Kruispunt::kruispuntSimulatie(Baan* b) {
    REQUIRE(properlyInitialized(), "Kruispunt is niet correct geïnitaliseerd.");
    std::vector<Voertuig*> vt = b->getVoertuigen();
    for (unsigned int i = 0; i < vt.size(); i++) {
        int pos = getPositie(b);
        if (vt[i]->getPositie() >= pos-10 && vt[i]->getPositie() <= pos) {
            Baan* nieuweBaan = kiesBaan();
            std::vector<Voertuig*> vtgen = b->getVoertuigen();
            std::vector<Voertuig*> nieuweVt;
            b->verwijderVoertuigen();
            vt[i]->setBaan(nieuweBaan);
            int nieuwePos = getPositie(nieuweBaan);
            vt[i]->setPositie(nieuwePos);
            break;
        }
    }
}

Baan* Kruispunt::kiesBaan() {
    REQUIRE(properlyInitialized(), "Kruispunt is niet correct geïnitaliseerd.");
    if (banen.first->getLengte() == posities.first) {
        return banen.second;
    }
    else if (banen.second->getLengte() == posities.second) {
        return banen.first;
    }
    else {
        std::vector<Baan*> b; b.push_back(banen.first); b.push_back(banen.second);
        srand (time(NULL));
        int index = rand() %2;
        return b[index];
    }
}

