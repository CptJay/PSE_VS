//
// Created by Jay on 15/05/2022.
//

#include "projectExporter.h"
#include "Baan.h"


using namespace std;

projectExporter::projectExporter() {
    _initCheck = this;
//    _documentStarted = false;
    ENSURE(properlyInitialized(), "Constructor must end in properlyInitialized state");
}

bool projectExporter::properlyInitialized() {
    return _initCheck == this;
}

void projectExporter::documentStart(ostream &onStream) {
    REQUIRE(properlyInitialized(), "Exporter was niet correct geïnitialiseerd.");
}

void projectExporter::baanSectionStart(ostream &onStream) {
    REQUIRE(properlyInitialized(), "Exporter was niet correct geïnitialiseerd.");
}

void projectExporter::baanOverview(ostream &onStream, Baan *baan) {
    REQUIRE(properlyInitialized(), "Exporter was niet correct geïnitialiseerd bij aanroep van exportOn.");
    REQUIRE(baan->properlyInitialized(), "Gepasseerde baan was niet correct geïnitialiseerd bij aanroep van exportOn.");
    // verkeerslichten
    for (long unsigned int i = 0; i < baan->getVerkeerslichten().size(); i++){
        Verkeerslicht* vl = baan->getVerkeerslichten()[i];
        onStream << "Verkeerslicht: " << endl;
        onStream << "-> positie: " << vl->getPositie() << endl;
        onStream << "-> tijd/cyclus: " << vl->getTijd() << "/" << vl->getCycles() << endl;
    }
    onStream << endl;
    // bushalten
    for (long unsigned int l = 0; l < baan->getBushaltes().size(); l++) {
        Bushalte* bh = baan->getBushaltes()[l];
        onStream << "Bushalte: " << endl;
        onStream << " -> positie: " << bh->getPositie() << endl;
        onStream << " -> tijd/wachttijd: " << bh->getTijd() << "/" << bh->getWachttijd() << endl;
    }
    onStream << endl;
    // voertuigen
    for (long unsigned int j = 0; j < baan->getVoertuigen().size(); j++) {
        Voertuig* vt = baan->getVoertuigen()[j];
        onStream << "Voertuig: " << vt->getId() << endl;
        onStream << " -> baan: " << vt->getBaan()->getNaam()<< endl;
        onStream << " -> positie: " << vt->getPositie() << endl;
        onStream << " -> snelheid: " << vt->getSnelheid() << endl;
        onStream << " -> type: " << vt->getType() << endl;
    }
    onStream << endl;
}

void projectExporter::baanSectionEnd(ostream &onStream) {
    REQUIRE(properlyInitialized(), "Exporter was niet correct geïnitialiseerd.");
}

void projectExporter::documentEnd(std::ostream& onStream) {
    REQUIRE(properlyInitialized(), "Exporter was niet correct geïnitialiseerd.");
}

void projectExporter::exportOn(ostream &onStream, Verkeerssimulatie &game) {
    REQUIRE(properlyInitialized(), "Exporter was niet correct geïnitialiseerd.");
    REQUIRE(game.properlyInitialized(), "Verkeerssimulatie was niet correct geïnitialiseerd.");

    documentStart(onStream);

    baanSectionStart(onStream);
    for (long unsigned int i = 0; i < game.getBanen().size(); i++){
        baanOverview(onStream, game.getBanen()[i]);
    }
    baanSectionEnd(onStream);

    documentEnd(onStream);
}





