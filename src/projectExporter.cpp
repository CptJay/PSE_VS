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
    onStream << "### Baan: " << baan->getNaam() << " ###" << endl;
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
//        onStream << " -> baan: " << vt->getBaan()->getNaam()<< endl;
        onStream << " -> positie: " << vt->getPositie() << endl;
        onStream << " -> snelheid: " << vt->getSnelheid() << endl;
        onStream << " -> type: " << vt->getType() << endl;
    }
    for (long unsigned int j = 0; j < baan->getGenerators().size(); j++){
        Voertuiggenerator* vg = baan->getGenerators()[j];
        onStream << "Generator: " << endl;
        onStream << " -> frequentie: " << vg->getFrequentie() << endl;
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
        game.exportSimulatie();
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
    onstream << "Baan: " << baan->getNaam() << endl;
    for (int i = 0; i < baan->getLengte(); i++){
         for (long unsigned int j = 0; j < baan->getVerkeerslichten().size(); j++){
             if (baan->getVerkeerslichten()[j]->getPositie() == i){
                 if (baan->getVerkeerslichten()[j]->isGreen()){
                     verkeerslichtOutput += "G";
                 }
                else {
                    verkeerslichtOutput += "R";
                }
             } else {
                 verkeerslichtOutput += " ";
             }
         }
         for (long unsigned int j = 0; j < baan->getVoertuigen().size(); j++){
             if (baan->getVoertuigen()[j]->getPositie() == i){
                 for (int u = 0; u < baan->getVoertuigen()[j]->getLengte(); u++){
                     autoOutput += typeVoertuig(baan->getVoertuigen()[j]->getType());
                 }
             } else if (baan->hasKruispunt()){
                if (baan->getKruispunten()[0]->getPositie(baan) == i){
                    autoOutput += "X";
                } else {
                    autoOutput += "-";
                }
             } else{
                 autoOutput += "-";
             }
         }
         if (baan->getVoertuigen().empty()){
             autoOutput += "-";
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

std::string GrafischeExporter::typeVoertuig(basic_string<char> typeV) {
    if (typeV == "auto") return "A";
    else if (typeV == "bus") return "B";
    else if (typeV == "politiecombi") return "P";
    else if (typeV == "ziekenwagen") return "Z";
    else if (typeV == "brandweerwagen") return "R";
    return " ";
}

