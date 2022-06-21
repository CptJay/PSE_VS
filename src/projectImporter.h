//
// Created by Jay on 15/05/2022.
//

#ifndef UNTITLED_PROJECTIMPORTER_H
#define UNTITLED_PROJECTIMPORTER_H

#include <iostream>
#include "Verkeerssimulatie.h"
#include "../TinyXML/tinyxml.h"

enum SuccessEnum {
    ImportAborted,
    PartialImport,
    Succes
};

class projectImporter {
public:
    /**
     *
     * @param inputfilename bestandsnaam waaruit ingelezen wordt.
     * @param errStream het naartoe te schrijven bestand.
     * @param game Verkeerssimulatie
     * @return succesrate van het importeren.
     *
     * REQUIRE(game.properlyInitialized(), "game wasn't initialized when passed to VerkeerssimulatieImporter");
     */
    static SuccessEnum importVerkeerssimulatie(const char* inputfilename, std::ostream& errStream, Verkeerssimulatie& game);
};


#endif //UNTITLED_PROJECTIMPORTER_H
