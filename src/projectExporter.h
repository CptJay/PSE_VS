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
/** Constructor
\n ENSURE(properlyInitialized(), "constructor must end in properlyInitialized state.");
*/
    projectExporter();
    bool properlyInitialized();

    /** export verkeerssimulatie in basicOutput
\n REQUIRE(this->properlyInitialized(), "Verkeerssimulatie wasn't initialized when calling exportOn.");
\n REQUIRE(game.properlyInitialized(), "game wasn't initialized when passing to Exporter::exportOn.");
*/
    void exportOn (std::ostream& onStream, Verkeerssimulatie &game);

protected:
    /** documentStart
    * Schrijft de informatie in het documentStart weg naar writeOn.
    *
    * @param onStream
    *
    * REQUIRE(properlyInitialised(), "Exporter was niet correct geïnitialiseerd.");
    */
    virtual void documentStart(std::ostream& onStream);
    /** baanSectionStart
    * Schrijft de informatie in het baanSectionStart weg naar onStream.
    *
    * @param onStream
    *
    * REQUIRE(properlyInitialised(), "Exporter was niet correct geïnitialiseerd.");
    */
    virtual void baanSectionStart(std::ostream& onStream);
    /** baanOverview
     * Schrijft de informatie in het baanOverview weg naar onStream.
    *
    * @param onStream
    * @param baan Pointer naar de baan van welke de informatie wordt opgehaald.
    *
    * REQUIRE(properlyInitialised(), "Exporter was niet correct geïnitialiseerd.");
    * REQUIRE(baan->properlyInitialised(), "Gepasseerde baan was niet correct geïnitialiseerd.");
    */
    virtual void baanOverview(std::ostream& onStream, Baan* baan);
    /** Sectie 4: baanSectionEnd
    * Schrijft de informatie in het baanSectionEnd weg naar onStream.
    *
    * @param onStream
    *
    * REQUIRE(properlyInitialised(), "Exporter was niet correct geïnitialiseerd.");
    */
    virtual void baanSectionEnd(std::ostream& onStream);
    /** Sectie 8: documentEnd
    * Schrijft de informatie in het documentEnd weg naar onStream.
    *
    * @param onStream
    *
    * REQUIRE(properlyInitialised(), "Exporter was niet correct geïnitialiseerd.");
    */
    virtual void documentEnd(std::ostream& onStream);



private:
    projectExporter * _initCheck; //!use pointer to myself to verify whether I am properly initialized
//    bool _documentStarted;
};

class GrafischeExporter: public projectExporter {
public:
    /** export verkeerssimulatie in grafischOutput
\n REQUIRE(this->properlyInitialized(), "Verkeerssimulatie wasn't initialized when calling exportOn.");
\n REQUIRE(game.properlyInitialized(), "game wasn't initialized when passing to Exporter::exportOn.");
*/
    void exportOnG(std::ostream& onStream, Verkeerssimulatie &game);

protected:
    /** baanOverview
     * Schrijft de informatie in het baanOverview weg naar onStream.
    *
    * @param onStream
    * @param baan Pointer naar de baan van welke de informatie wordt opgehaald.
    *
    * REQUIRE(properlyInitialised(), "Exporter was niet correct geïnitialiseerd.");
    * REQUIRE(baan->properlyInitialised(), "Gepasseerde baan was niet correct geïnitialiseerd.");
    */
    virtual void overview(std::ostream& onstream, Baan* baan);
    virtual std::string typeVoertuig(std::basic_string<char> typeV);

};



#endif //UNTITLED_PROJECTEXPORTER_H
