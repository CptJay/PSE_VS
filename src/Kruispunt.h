//
// Created by chloeacm on 02.05.22.
//

#ifndef UNTITLED_KRUISPUNT_H
#define UNTITLED_KRUISPUNT_H

#include "Baan.h"
#include <map>
#include <string>


class Kruispunt {
private:
    std::pair<Baan*,Baan*> banen;
    std::pair<int,int> posities;
    Kruispunt* init;
public:
    Kruispunt();
    /** Controleert de integriteit van de instantie.
    * Controleert of de selfpointer nog steeds naar zichzelf wijst.
    *
    * @return Succeswaarde
    */
    bool properlyInitialized() const;
    /** Setter banen in een zelfgekozen STLcontainer, nl. een map.
     *
     * @param b Map bestaande uit een baan en zijn positie.
     *
     * REQUIRE(properlyInitialized(), "Kruispunt is niet correct geïnitialiseerd.");
     */
    void setBanen(std::pair<Baan*,Baan*> b);
    /** Getter Banen
     *
     * @return
     *
     * REQUIRE(properlyInitialized(), "Kruispunt is niet correct geïnitialiseerd.");
     */
    std::pair<Baan*,Baan*> getBanen();
    std::pair<int,int> getPosities();
    void setPosities(std::pair<int,int> pos);
    void kruispuntSimulatie(Baan* b);
    Baan* kiesBaan();
    int getPositie(Baan* b);


};


#endif //UNTITLED_KRUISPUNT_H
