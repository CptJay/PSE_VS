//
// Created by chloeacm on 02.05.22.
//

#include "Kruispunt.h"
#include <map>

Kruispunt::Kruispunt() {
    init = this;
    ENSURE(properlyInitialized(), "Kruispunt is niet correct geïnitialiseerd.");
}

void Kruispunt::setBanen(std::map<Baan*, int> b) {
    REQUIRE(properlyInitialized(), "Kruispunt is niet correct geïnitialiseerd.");
    banen = b;
}

std::map<Baan*,int> Kruispunt::getBanen() {
    REQUIRE(properlyInitialized(), "Kruispunt is niet correct geïnitialiseerd.");
    return banen;
}

bool Kruispunt::properlyInitialized() const{
    return init == this;
}