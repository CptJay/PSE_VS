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
    /** Default Constructor.
     *
     */
    Kruispunt();
    /** Controleert de integriteit van de instantie.
    * Controleert of de selfpointer nog steeds naar zichzelf wijst.
    *
    * @return Succeswaarde
    */
    bool properlyInitialized() const;
    /** Setter banen in een zelfgekozen STLcontainer, nl. een map.
     *
     * @param b Pair bestaande uit pointers naar een baan.
     *
     * REQUIRE(properlyInitialized(), "Kruispunt is niet correct geïnitialiseerd.");
     */
    void setBanen(std::pair<Baan*,Baan*> b);
    /** Getter Banen.
     *
     * @return Pair bestaande uit pointers naar banen.
     *
     * REQUIRE(properlyInitialized(), "Kruispunt is niet correct geïnitialiseerd.");
     */
    std::pair<Baan*,Baan*> getBanen();
    /** Getter Posities
     *
     * @return Pair bestaande uit integers
     *
     * REQUIRE(properlyInitialized(), "Kruispunt is niet correct geïnitaliseerd.");
     */
    std::pair<int,int> getPosities();
    /** Setter Posities
     *
     * @param pos Pair bestaande uit integers.
     *
     * REQUIRE(properlyInitialized(), "Kruispunt is niet correct geïnitaliseerd.");
     */
    void setPosities(std::pair<int,int> pos);
    /** Voertuigen die aan het kruispunt staan, laten veranderen van baan.
     *
     * @param b  Pointer naar een baan.
     *
     * REQUIRE(properlyInitialized(), "Kruispunt is niet correct geïnitaliseerd.");
     */
    void kruispuntSimulatie(Baan* b);
    /** Een baan kiezen voor het voertuig op het kruispunt.
     *
     * REQUIRE(properlyInitialized(), "Kruispunt is niet correct geïnitaliseerd.");
     */
    Baan* kiesBaan();
    /** Geeft aan op welke positie van een baan het kruispunt staat.
     *
     * @param b Pointer naar een baan.
     * @return Int die de positie voorstelt.
     *
     * REQUIRE(properlyInitialized(), "Kruispunt is niet correct geïnitaliseerd.");
     */
    int getPositie(Baan* b);


};


#endif //UNTITLED_KRUISPUNT_H
