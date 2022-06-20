/**
 * @file Baan.cpp
 * @authors Yassir Chebaa, Chloë Mansibang
 * @date 24/03/2022
 */

#include "Baan.h"
#include "gtest/gtest.h"
#include "Voertuig.h"

Baan::Baan() {
    lengte = 0;
    init = this;
    vg = NULL;
    ENSURE(properlyInitialized(), "Baan is niet correct geïnitialiseerd.");
}

void Baan::setNaam(const std::string &s) {
    REQUIRE(properlyInitialized(), "Baan is niet correct geïnitialiseerd.");
    naam = s;
    ENSURE(getNaam() == s, "Naam is niet correct aangepast.");
}

void Baan::setLengte(int l) {
    REQUIRE(properlyInitialized(), "Baan is niet correct geïnitialiseerd.");
    REQUIRE(l >= 0, "Lengte mag niet negatief zijn.");
    lengte = l;
    ENSURE(getLengte() == l, "Lengte is niet correct aangepast.");
}

std::string Baan::getNaam() const {
    REQUIRE(properlyInitialized(), "Baan is niet correct geïnitialiseerd.");
    return naam;
}

int Baan::getLengte() const {
    REQUIRE(properlyInitialized(), "Baan is niet correct geïnitialiseerd.");
    return lengte;
}

bool Baan::properlyInitialized() const{
    return init == this;
}

std::vector<Voertuig*> Baan::getVoertuigen() {
    return voertuigen;
}

void Baan::sorteerVoertuigen() {
    std::vector<Voertuig*> vt;
    for (int i = lengte; i >= 0; i--) {
        for (long unsigned int j = 0; j < voertuigen.size(); j++) {
            if (voertuigen[j]->getPositie() == i) {
                vt.push_back(voertuigen[j]);
            }
        }
    }
    voertuigen = vt;
}

void Baan::addVoertuig(Voertuig* b) {
    voertuigen.push_back(b);
}

void Baan::addVerkeerslicht(Verkeerslicht *vl) {
    verkeerslichten.push_back(vl);
}

void Baan::verwijderVoertuigen() {
    std::vector<Voertuig*> vt;
    for (unsigned int i=0; i<voertuigen.size(); i++) {
        if (voertuigen[i]->getPositie() <= lengte) vt.push_back(voertuigen[i]);
    }
    voertuigen = vt;
}

std::vector<Verkeerslicht *> Baan::getVerkeerslichten()  {
    return verkeerslichten;
}

void Baan::addBushalte(Bushalte *b) {
    bushaltes.push_back(b);
}

std::vector<Bushalte*> Baan::getBushaltes() {
    return bushaltes;
}

Voertuig *Baan::getEersteVoertuig(int p) {
    for (long unsigned int i = 0; i < voertuigen.size(); i++){
        if (voertuigen[i]->getPositie() <= p){
            Voertuig* eerste = voertuigen[i];
            return eerste;
        }
    }
    return NULL;
}

void Baan::addKruispunt(Kruispunt *kp) {
    kruispunten.push_back(kp);
}

std::vector<Kruispunt*> Baan::getKruispunten() {
    return kruispunten;
}

void Baan::setVoertuiggenerator(Voertuiggenerator *g) {
    vg = g;
}

Voertuiggenerator* Baan::getVoertuiggenerator() {
    return vg;
}