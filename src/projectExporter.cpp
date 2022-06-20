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
        game.exportSimulatie();
    }


    baanSectionEnd(onStream);

    documentEnd(onStream);
}


void GrafischeExporter::exportOnG(ostream &onStream, Verkeerssimulatie &game) {
    REQUIRE(properlyInitialized(), "Exporter was niet correct geïnitialiseerd.");
    REQUIRE(game.properlyInitialized(), "Verkeerssimulatie was niet correct geïnitialiseerd.");

    documentStart(onStream);

    baanSectionStart(onStream);

    for (long unsigned int i = 0; i < game.getBanen().size(); i++){
        overview(onStream, game.getBanen()[i]);
    }

    baanSectionEnd(onStream);

    documentEnd(onStream);
}

void GrafischeExporter::overview(ostream &onstream, Baan* baan) {
    REQUIRE(properlyInitialized(), "Exporter was niet correct geïnitialiseerd bij aanroep van exportOn.");
    REQUIRE(baan->properlyInitialized(), "Gepasseerde baan was niet correct geïnitialiseerd bij aanroep van exportOn.");

    string autoOutput = "VT: ";
    string verkeerslichtOutput = "VL: ";
    string bushalteOutput = "BH: ";
    for (int i = 0; baan->getLengte(); i++){
         for (long unsigned int j = 0; baan->getVerkeerslichten().size(); j++){
             if (baan->getVerkeerslichten()[j]->getPositie() == i){
                 verkeerslichtOutput += "|";
             } else {
                 verkeerslichtOutput += " ";
             }
         }
         for (long unsigned int j = 0; j < baan->getVoertuigen().size(); j++){
             if (baan->getVoertuigen()[j]->getPositie() == i){
                 for (int u = 0; u < baan->getVoertuigen()[j]->getLengte(); u++){
                     autoOutput += "A";
                 }
             } else{
                 autoOutput += "-";
             }
         }
         for (long unsigned int j = 0; j < baan->getBushaltes().size(); j++){
             if (baan->getBushaltes()[j]->getPositie() == i){
                 bushalteOutput += "H";
             } else{
                 bushalteOutput += " ";
             }
         }
    }
    onstream << verkeerslichtOutput << endl << autoOutput << endl << bushalteOutput << endl << endl;
}

