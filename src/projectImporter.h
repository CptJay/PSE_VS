//
// Created by Jay on 15/05/2022.
//

#ifndef UNTITLED_PROJECTIMPORTER_H
#define UNTITLED_PROJECTIMPORTER_H

#include <iostream>
#include "Verkeerssimulatie.h"

enum SuccesEnum {ImporterAborted, PartialImport, Succes};

class projectImporter {
public:

    static SuccesEnum importVerkeerssimulatie(const char* inputfilename, std::ostream& errStream, Verkeerssimulatie& game);
};


#endif //UNTITLED_PROJECTIMPORTER_H
