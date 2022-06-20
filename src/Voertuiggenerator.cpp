//
// Created by chloeacm on 20.06.22.
//

#include "Voertuiggenerator.h"

Voertuiggenerator::Voertuiggenerator() {
    frequentie = 0;
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