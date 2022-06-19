//
// Created by Jay on 15/05/2022.
//

#include "projectExporter.h"
#include "DesignByContract.h"

using namespace std;

projectExporter::projectExporter() {
    _initCheck = this;
    _documentStarted = false;
    ENSURE(properlyInitialized(), "Constructor must end in properlyInitialized state");
}

bool projectExporter::properlyInitialized() {
    _initCheck == this;
}

bool projectExporter::documentStarted() {
    return _documentStarted;
}

