//
// Created by chloeacm on 02.05.22.
//

#include "Kruispunt.h"
#include <map>

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
    return posities;
}

void Kruispunt::setPosities(std::pair<int, int> pos) {
    posities = pos;
}

bool Kruispunt::properlyInitialized() const{
    return init == this;
}

