//
// Created by Jay on 15/05/2022.
//

#ifndef UNTITLED_PROJECTEXPORTER_H
#define UNTITLED_PROJECTEXPORTER_H

#include "projectUtils.h"
#include "Verkeerssimulatie.h"

class Verkeerssimulatie;
class projectExporter {
public:
/**
\n ENSURE(properlyInitialized(), "constructor must end in properlyInitialized state.");
\n REQUIRE(! this->documentStarted(), "After constructor a TicTacToeExporter is *not* in the documentStarted state.");
*/
    projectExporter();
    bool properlyInitialized();

    /**
\n REQUIRE(this->properlyInitialized(), "TicTacToeExporter wasn't initialized when calling exportOn.");
\n REQUIRE(this->documentStarted(), "TicTacToeExporter wasn't in documentStarted state when calling exportOn.");
\n REQUIRE(game.properlyInitialized(), "game wasn't initialized when passing to Exporter::exportOn.");
*/
    void exportOn (std::ostream& onStream, Verkeerssimulatie &game);

protected:

    virtual void documentStart(std::ostream& onStream);
    virtual void baanSectionStart(std::ostream& onStream);
    virtual void baanOverview(std::ostream& onStream, Baan* baan);
    virtual void baanSectionEnd(std::ostream& onStream);
    virtual void documentEnd(std::ostream& onStream);



private:
    projectExporter * _initCheck; //!use pointer to myself to verify whether I am properly initialized
//    bool _documentStarted;
};

class GrafischeExporter: public projectExporter {
public:

    void exportOnG(std::ostream& onStream, Verkeerssimulatie &game);

protected:

    virtual void overview(std::ostream& onstream, Baan* baan);

};



#endif //UNTITLED_PROJECTEXPORTER_H
