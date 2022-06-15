/**
 * @file Verkeerslicht.cpp
 * @authors Yassir Chebaa, Chloë Mansibang
 * @date 24/03/2022
 */

#include "Verkeerslicht.h"
#include "Voertuig.h"
#include "Baan.h"

Baan *Verkeerslicht::getBaan() const {
    REQUIRE(properlyInitialized(), "Verkeerslicht is niet correct geïnitialiseerd.");
    return baan;
}

void Verkeerslicht::setBaan(Baan *b) {
    REQUIRE(properlyInitialized(), "Verkeerslicht is niet correct geïnitialiseerd.");
    Verkeerslicht::baan = b;
    ENSURE(getBaan() == b, "Baan is niet correct aangepast.");
}

int Verkeerslicht::getPositie() const {
    REQUIRE(properlyInitialized(), "Verkeerslicht is niet correct geïnitialiseerd.");
    return positie;
}

void Verkeerslicht::setPositie(int p) {
    REQUIRE(properlyInitialized(), "Verkeerslicht is niet correct geïnitialiseerd.");
    REQUIRE(p >= 0, "Positie mag niet negatief zijn.");
    Verkeerslicht::positie = p;
    ENSURE(getPositie() == p, "Positie is niet correct aangepast.");
}

int Verkeerslicht::getCycles() const {
    REQUIRE(properlyInitialized(), "Verkeerslicht is niet correct geïnitialiseerd.");
    return cycles;
}

void Verkeerslicht::setCycles(int c) {
    REQUIRE(properlyInitialized(), "Verkeerslicht is niet correct geïnitialiseerd.");
    REQUIRE(c >= 0, "Cyclus mag niet negatief zijn.");
    Verkeerslicht::cycles = c;
    ENSURE(getCycles() == c, "Cyclus is niet correct aangepast.");
}

Verkeerslicht::Verkeerslicht() {
    tijd = 0;
    positie = 0;
    cycles = 0;
    green = true;
    baan = NULL;
    init = this;
}

void Verkeerslicht::updateTijd(double simulatietijd) {
    REQUIRE(properlyInitialized(), "Verkeerslicht is niet correct geïnitialiseerd.");
    REQUIRE(simulatietijd >= 0, "Simulatietijd kan niet negatief zijn.");
    tijd += simulatietijd;
}

bool Verkeerslicht::isGreen() const {
    REQUIRE(properlyInitialized(), "Verkeerslicht is niet correct geïnitialiseerd.");
    return green;
}

void Verkeerslicht::changeColor() {
    REQUIRE(properlyInitialized(), "Verkeerslicht is niet correct geïnitialiseerd.");
    REQUIRE(tijd >= cycles, "Tijd is niet groter dan cyclus.");
    if (green) green = false;
    else green = true;
    tijd = 0;
    ENSURE(getTijd() == 0, "Tijd werd niet gereset.");
}

double Verkeerslicht::getTijd() const {
    REQUIRE(properlyInitialized(), "Verkeerslicht is niet correct geïnitialiseerd.");
    return tijd;
}

bool Verkeerslicht::properlyInitialized() const {
    return this == init;
}

void Verkeerslicht::verkeerslichtSimulatie(double simulatietijd) {
    Voertuig* eerste = baan->getEersteVoertuig(positie);
    if (tijd >= cycles) {
        changeColor();
    }
    if (eerste != NULL) {
        if (isGreen()) {
            eerste->versnellen();
        }
        else if (!isGreen() && eerste->getType() == "auto" && eerste->getType() != "bus") {
            if (eerste->_inVertraagafstand(this)) {
                eerste->vertragen();
            }
            else if (eerste->_inStopafstand(this)) {
                eerste->stoppen();
            }
        }
    }
    updateTijd(simulatietijd);
}

