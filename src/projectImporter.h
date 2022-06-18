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
private:
    static int toIntConverter(TiXmlNode* TiNode);
public:
    static SuccessEnum importVerkeerssimulatie(const char* inputfilename, std::ostream& errStream, Verkeerssimulatie& game);
};


#endif //UNTITLED_PROJECTIMPORTER_H
