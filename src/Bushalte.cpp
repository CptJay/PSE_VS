/**
 * @file Baan.cpp
 * @authors Yassir Chebaa, Chloë Mansibang
 * @date 24/03/2022
 */

#include "Bushalte.h"
#include "Voertuig.h"
#include "Baan.h"
#include <vector>

Bushalte::Bushalte() {
    positie = 0;
    tijd = 0;
    wachttijd = 0;
    init = this;
    baan = NULL;
    ENSURE(properlyInitialized(), "Baan is niet correct geïnitialiseerd.");
}

void Bushalte::setBaan(Baan *b) {
    REQUIRE(properlyInitialized(), "Baan is niet correct geïnitialiseerd.");
    baan = b;
    ENSURE(getBaan() == b, "Baan is niet correct aangepast.");
}

void Bushalte::setPositie(int p) {
    REQUIRE(properlyInitialized(), "Baan is niet correct geïnitialiseerd.");
    positie = p;
    ENSURE(getPositie() == p, "Positie is niet correct aangepast.");
}

void Bushalte::setWachttijd(int w) {
    REQUIRE(properlyInitialized(), "Baan is niet correct geïnitialiseerd.");
    wachttijd = w;
    ENSURE(getWachttijd() == w, "Wachttijd is niet correct aangepast.");
}

Baan* Bushalte::getBaan() {
    REQUIRE(properlyInitialized(), "Baan is niet correct geïnitialiseerd.");
    return baan;
}

int Bushalte::getPositie() {
    REQUIRE(properlyInitialized(), "Baan is niet correct geïnitialiseerd.");
    return positie;
}

int Bushalte::getWachttijd() {
    REQUIRE(properlyInitialized(), "Baan is niet correct geïnitialiseerd.");
    return wachttijd;
}

bool Bushalte::properlyInitialized() const {
    return init == this;
}

void Bushalte::bushalteSimulatie(double simulatietijd) {
    REQUIRE(properlyInitialized(), "Baan is niet correct geïnitialiseerd.");
    REQUIRE(simulatietijd >= 0, "Simulatietijd moet positief zijn.");
    Voertuig* eersteVoertuig = baan->getEersteVoertuig(positie);
    if (eersteVoertuig != NULL) {
        if (eersteVoertuig->getType() == "bus") {
            Bus *bus = baan->getEersteBus(positie);
            int vtPositie = eersteVoertuig->getPositie();
            if (positie - eersteVoertuig->getVertraagAfstand() <= vtPositie &&
                vtPositie <= positie - (eersteVoertuig->getStopAfstand() / 2)) {
                eersteVoertuig->vertragen();
            } else if (positie - (eersteVoertuig->getStopAfstand() / 2) <= vtPositie) {
                if (tijd == 0 && !bus->isAanBushalte()) {
                    bus->changeStatus();
                    bus->stoppen();
                    tijd += simulatietijd;
                } else if (0 < tijd && tijd < wachttijd && bus->isAanBushalte()) {
                    tijd += simulatietijd;
                    bus->stoppen();
                } else if (tijd >= wachttijd) {
                    bus->versnellen();
                    bus->changeStatus();
                    tijd = 0;
                }
            }
        }
    }
}

int Bushalte::getTijd() {
    REQUIRE(properlyInitialized(), "Baan is niet correct geïnitialiseerd.");
    return tijd;
}
