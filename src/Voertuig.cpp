/**
 * @file Voertuig.cpp
 * @authors Yassir Chebaa, Chloë Mansibang
 * @date 24/03/2022
 */

#include "Voertuig.h"
#include "cmath"
#include <vector>
#include "Verkeerslicht.h"
#include "Baan.h"

Voertuig::Voertuig() {
    positie = 0;
    lengte = 0;
    snelheid = 0;
    maxSnelheid = 0;
    AbsMaxSnelheid = 0;
    versnelling = 0;
    maxVersnelling = 0;
    maxRemfactor = 0;
    minVolgAfstand = 0;
    vertraagAfstand = 50;
    stopAfstand = 15;
    vertraagFactor = 0.4;
    id = 0;
    init = this;
    ENSURE(properlyInitialized(), "Voertuig is niet correct geïnitialiseerd.");
}

Voertuig::Voertuig(int l, double maxSnel, double maxVers, double maxRem, double minvolg) {
    positie = 0;
    lengte = l;
    snelheid = 0;
    AbsMaxSnelheid = maxSnel;
    versnelling = 0;
    maxSnelheid = maxSnel;
    maxVersnelling = maxVers;
    maxRemfactor = maxRem;
    minVolgAfstand = minvolg;
    vertraagAfstand = 50;
    stopAfstand = 15;
    vertraagFactor = 0.4;
    id = 0;
    init = this;
    ENSURE(properlyInitialized(), "Voertuig is niet correct geïnitialiseerd.");
}

void Voertuig::setLengte(int l) {
    REQUIRE(properlyInitialized(), "Voertuig is niet correct geïnitialiseerd.");
    lengte = l;
    ENSURE(getLengte() == l, "Lengte is niet correct aangepast.");
}

void Voertuig::setAbsMaxSnelheid(double m) {
    REQUIRE(properlyInitialized(), "Voertuig is niet correct geïnitialiseerd.");
    AbsMaxSnelheid = m;
    maxSnelheid = AbsMaxSnelheid;
    ENSURE(getMaxSnelheid() == m, "Maximale snelheid is niet correct aangepast.");
    ENSURE(getMaxSnelheid() == m, "Maximale snelheid is niet correct aangepast.");
}

void Voertuig::setMaxRemfactor(double r) {
    REQUIRE(properlyInitialized(), "Voertuig is niet correct geïnitialiseerd.");
    maxRemfactor = r;
}

void Voertuig::setMinVolgafstand(int v) {
    REQUIRE(properlyInitialized(), "Voertuig is niet correct geïnitialiseerd.");
    minVolgAfstand = v;
}

Baan *Voertuig::getBaan() const {
    REQUIRE(properlyInitialized(), "Voertuig is niet correct geïnitialiseerd.");
    return baan;
}

void Voertuig::setBaan(Baan *b) {
    REQUIRE(properlyInitialized(), "Voertuig is niet correct geïnitialiseerd.");
    Voertuig::baan = b;
    ENSURE(getBaan() == b, "Baan is niet correct aangepast.");
}

int Voertuig::getPositie() const {
    REQUIRE(properlyInitialized(), "Voertuig is niet correct geïnitialiseerd.");
    return positie;
}

void Voertuig::setPositie(int p) {
    REQUIRE(properlyInitialized(), "Voertuig is niet correct geïnitialiseerd.");
    REQUIRE(p >= 0, "Positie mag niet negatief zijn.");
    Voertuig::positie = p;
    ENSURE(getPositie() == p, "Positie is niet correct aangepast.");
}

int Voertuig::getLengte() const {
    REQUIRE(properlyInitialized(), "Voertuig is niet correct geïnitialiseerd.");
    return lengte;
}

double Voertuig::getSnelheid() const {
    REQUIRE(properlyInitialized(), "Voertuig is niet correct geïnitialiseerd.");
    return snelheid;
}

double Voertuig::getMaxSnelheid() const {
    REQUIRE(properlyInitialized(), "Voertuig is niet correct geïnitialiseerd.");
    return maxSnelheid;
}

double Voertuig::getVersnelling() const {
    REQUIRE(properlyInitialized(), "Voertuig is niet correct geïnitialiseerd.");
    return versnelling;
}

double Voertuig::getMaxVersnelling() const {
    REQUIRE(properlyInitialized(), "Voertuig is niet correct geïnitialiseerd.");
    return maxVersnelling;
}

double Voertuig::getMaxRemfactor() const {
    REQUIRE(properlyInitialized(), "Voertuig is niet correct geïnitialiseerd.");
    return maxRemfactor;
}

double Voertuig::getMinVolgAfstand() const {
    REQUIRE(properlyInitialized(), "Voertuig is niet correct geïnitialiseerd.");
    return minVolgAfstand;
}

double Voertuig::getVertraagAfstand() const {
    REQUIRE(properlyInitialized(), "Voertuig is niet correct geïnitialiseerd.");
    return vertraagAfstand;
}

double Voertuig::getStopAfstand() const {
    REQUIRE(properlyInitialized(), "Voertuig is niet correct geïnitialiseerd.");
    return stopAfstand;
}

double Voertuig::getVertraagFactor() const {
    REQUIRE(properlyInitialized(), "Voertuig is niet correct geïnitialiseerd.");
    return vertraagFactor;
}

void Voertuig::setSnelheid(double s) {
    REQUIRE(properlyInitialized(), "Voertuig is niet correct geïnitialiseerd.");
    REQUIRE(s >= 0, "Snelheid kan niet negatief zijn.");
    Voertuig::snelheid = s;
    ENSURE(getSnelheid() == s, "Snelheid is niet correct aangepast.");
}

void Voertuig::setVersnelling(double v) {
    REQUIRE(properlyInitialized(), "Voertuig is niet correct geïnitialiseerd.");
    Voertuig::versnelling = v;
    ENSURE(getVersnelling() == v, "Versnelling is niet correct aangepast.");
}

void Voertuig::setMaxSnelheid(double ms) {
    REQUIRE(properlyInitialized(), "Voertuig is niet correct geïnitialiseerd.");
    REQUIRE(ms >= 0, "Maximale snelheid kan niet negatief zijn.");
    Voertuig::maxSnelheid = ms;
    ENSURE(getMaxSnelheid() == ms, "Maximale snelheid is niet correct aangepast.");
}

double Voertuig::getAbsMaxSnelheid() const {
    REQUIRE(properlyInitialized(), "Voertuig is niet correct geïnitialiseerd.");
    return AbsMaxSnelheid;
}

bool Voertuig::properlyInitialized() const {
    return this == init;
}

void Voertuig::berekenPosEnSnelheid(double simulatietijd) {
    REQUIRE(properlyInitialized(), "Voertuig is niet correct geïnitialiseerd.");
    REQUIRE(snelheid >= 0, "Snelheid can niet negatief zijn");
    REQUIRE(AbsMaxSnelheid >= 0, "Absolute maximale snelheid kan niet negatief zijn");
    if (snelheid + versnelling * simulatietijd > 0) {
        double snelh = snelheid + versnelling * simulatietijd;
        int pos = positie + snelh*simulatietijd + versnelling*((simulatietijd*simulatietijd)/2);
        if (snelh > AbsMaxSnelheid) {
            snelheid = AbsMaxSnelheid;
            versnelling = 0;
        }
        snelheid = snelh;
        positie = pos;
        ENSURE(getPositie() == pos, "Positie is niet correct aangepast.");
        ENSURE(getSnelheid() == snelh, "Snelheid is niet correct aangepast.");
    }
    else if (snelheid + versnelling* simulatietijd < 0) {
        int pos = positie - (pow(snelheid,2)/(2*versnelling));
        positie = pos;
        snelheid = 0;
        ENSURE(getPositie() == pos, "Positie is niet correct aangepast.");
        ENSURE(getSnelheid() == 0, "Snelheid is niet correct aangepast.");
    }
}

double Voertuig::_berekenVolgafstand(double x0) {
    REQUIRE(properlyInitialized(), "Voertuig is niet correct geïnitialiseerd.");
    double volgafstand = x0 - positie - lengte;
    return volgafstand;
}

double Voertuig::_berekenSnelheidsverschil(double v0) {
    REQUIRE(properlyInitialized(), "Voertuig is niet correct geïnitialiseerd.");
    return snelheid - v0;
}

double Voertuig::_berekenInteractie(Voertuig* voertuig0) {
    REQUIRE(properlyInitialized(), "Voertuig is niet correct geïnitialiseerd.");
    double maxW = 0;
    double deltaV = _berekenSnelheidsverschil(voertuig0->snelheid);
    double temp = snelheid + (snelheid*deltaV / (2* sqrt(maxVersnelling*maxRemfactor)));
    if (maxW < temp) maxW = temp;
    double a = minVolgAfstand + maxW;
    double b = _berekenVolgafstand(voertuig0->positie);
    double interactieterm = a/b;
    return interactieterm;
}

void Voertuig::berekenVersnelling(Voertuig *voertuig0) {
    REQUIRE(properlyInitialized(), "Voertuig is niet correct geïnitialiseerd.");
    // to do: rangschikken voertuigen van baan
    std::vector<Voertuig*>voertuigen = baan->getVoertuigen();
    double a = 0;
    double b = 0;
    if (voertuigen.size() == 1) {
        versnelling = maxVersnelling * (1 - pow(snelheid/maxSnelheid,4));
    }
    else if (voertuigen.size() > 1) {
        double versn = voertuig0->getMaxVersnelling() * (1 - pow(voertuig0->getSnelheid()/voertuig0->getMaxSnelheid(),4));
        voertuig0->setVersnelling(versn);
        a = pow(snelheid/maxSnelheid,4);
        b = pow(_berekenInteractie(voertuig0),2);
        versnelling = maxVersnelling*(1 - a - b);
    }
}

void Voertuig::vertragen() {
    REQUIRE(properlyInitialized(), "Voertuig is niet correct geïnitialiseerd.");
    maxSnelheid = AbsMaxSnelheid * vertraagFactor;
    ENSURE(getMaxSnelheid() == AbsMaxSnelheid * vertraagFactor, "Maximale snelheid is niet correct aangepast.");
}

void Voertuig::versnellen() {
    REQUIRE(properlyInitialized(), "Voertuig is niet correct geïnitialiseerd.");
    maxSnelheid = AbsMaxSnelheid;
    ENSURE(getMaxSnelheid() == AbsMaxSnelheid, "Maximale snelheid is niet correct aangepast.");
}

bool Voertuig::_inStopafstand(Verkeerslicht *vl) {
    REQUIRE(properlyInitialized(), "Voertuig is niet correct geïnitialiseerd.");
    if (positie >= vl->getPositie() - (stopAfstand/2)) return true;
    return false;
}

bool Voertuig::_inVertraagafstand(Verkeerslicht* vl) {
    REQUIRE(properlyInitialized(), "Voertuig is niet correct geïnitialiseerd.");
    if (vl->getPositie() - vertraagAfstand <= positie && positie < vl->getPositie() - stopAfstand) return true;
    return false;
}

void Voertuig::stoppen() {
    REQUIRE(properlyInitialized(), "Voertuig is niet correct geïnitialiseerd.");
    versnelling = -(maxRemfactor*snelheid/maxSnelheid);
}

int Voertuig::getId() const {
    REQUIRE(properlyInitialized(), "Voertuig is niet correct geïnitialiseerd.");
    return id;
}

void Voertuig::setId(int i) {
    REQUIRE(properlyInitialized(), "Voertuig is niet correct geïnitialiseerd.");
    id = i;
    ENSURE(getId() == i, "ID is niet correct aangepast.");
}

void Voertuig::setType(std::string s) {
    REQUIRE(properlyInitialized(), "Voertuig is niet correct geïnitialiseerd.");
    type = s;
    ENSURE( getType() == s, "Type is niet correct aangepast.");
}

std::string Voertuig::getType() {
    REQUIRE(properlyInitialized(), "Voertuig is niet correct geïnitialiseerd.");
    return type;
}

double Voertuig::getStopAfstand() {
    REQUIRE(properlyInitialized(), "Voertuig is niet correct geïnitialiseerd.");
    return stopAfstand;
}

Auto::Auto(): Voertuig(4, 16.6, 1.44, 4.61, 4) {
    setType("auto");
}

Bus::Bus(): Voertuig(12, 11.4, 1.22, 4.29, 12) {
    setType("bus");
    aanBushalte = false;
}

bool Bus::isAanBushalte() {
    return aanBushalte;
}

void Bus::changeStatus() {
    if (aanBushalte) aanBushalte = false;
    else aanBushalte = true;
}

Brandweerwagen::Brandweerwagen(): Voertuig(10, 14.6, 1.33, 4.56, 10) {
    setType("brandweerwagen");
}

Ziekenwagen::Ziekenwagen(): Voertuig(8, 15.5, 1.44, 4.47, 8) {
    setType("ziekenwagen");
}

Politiecombi::Politiecombi(): Voertuig(6, 17.2, 1.55, 4.92, 6) {
    setType("politiecombi");
}


