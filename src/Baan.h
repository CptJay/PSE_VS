/**
 * @file Baan.h
 * @authors Yassir Chebaa, Chloë Mansibang
 * @date 24/03/2022
 */

#ifndef UNTITLED_BAAN_H
#define UNTITLED_BAAN_H


#include <string>
#include <vector>
#include "set"
#include "DesignByContract.h"


class Verkeerslicht;
class Bushalte;
class Voertuiggenerator;
class Kruispunt;
class Voertuig;


/** @class Baan
 * @brief Voorstelling van een baan.
 *
 */
class Baan {
private:
    std::string naam;
    int lengte;
    Baan *init;
    std::vector<Voertuig*> voertuigen;
    std::vector<Verkeerslicht*> verkeerslichten;
    std::vector<Bushalte*> bushaltes;
    std::vector<Kruispunt*> kruispunten;
    std::vector<Voertuiggenerator*> generators;
public:
    /** Default constructor.
     * Baan wordt aangemaakt.
     */
    Baan();
    /** Controleert de integriteit van de instantie.
    * Controleert of de selfpointer nog steeds naar zichzelf wijst.
    *
    * @return Succeswaarde
     */
    bool properlyInitialized() const;
    /** Updates de naam van de baan.
     *
     * @param s Naam van de baan.
     *
     * REQUIRE(properlyInitialized(), "Baan is niet correct geïnitialiseerd.");
     * ENSURE(getNaam() == s, "Naam is niet correct aangepast.");
     */
    void setNaam(const std::string &s);
    /** Updates de lengte van de baan.
     *
     * @param l Lengte van de baan.
     *
     * REQUIRE(properlyInitialized(), "Baan is niet correct geïnitialiseerd.");
     * REQUIRE(l >= 0, "Lengte mag niet negatief zijn.");
     * ENSURE(getLengte() == l, "Lengte is niet correct aangepast.");
     */
    void setLengte(int l);
    /** Getter voor naam.
     *
     * @return Naam van de baan.
     *
     * REQUIRE(properlyInitialized(), "Baan is niet correct geïnitialiseerd.");
     */
    std::string getNaam() const;
    /** Getter voor lengte.
     *
     * @return Lengte van de baan.
     *
     * REQUIRE(properlyInitialized(), "Baan is niet correct geïnitialiseerd.");
     */
    int getLengte() const;
    /** Getter voertuigen.
     *
     * @return
     */
    std::vector<Voertuig*> getVoertuigen();
    /** Sorteert de voertuigen op de baan.
     *
     */
    void sorteerVoertuigen();
    /** Voegt voertuigen toe aan de baan.
     *
     * @param b Pointer naar een voertuig.
     *
     * REQUIRE(properlyInitialized(), "Baan is niet correct geïnitialiseerd.");
     * REQUIRE(b->properlyInitialized(), "Voertuig is niet correct geïnitialiseerd.");
     * ENSURE(voertuigen.size() != 0, "Voertuig is niet toegevoegd.);
     */
    void addVoertuig(Voertuig* b);
    /** Voegt verkeerslichten toe aan de baan.
     *
     * @param b Pointer naar een verkeerslicht.
     *
     * REQUIRE(properlyInitialized(), "Baan is niet correct geïnitialiseerd.");
     * REQUIRE(vl->properlyInitialized(), "Verkeerslicht is niet correct geïnitialiseerd.");
     * ENSURE(verkeerslichten.size() != 0, "Verkeerslicht is niet toegevoegd.);
     */
    void addVerkeerslicht(Verkeerslicht* vl);
    /** Verwijdert alle voertuigen die niet meer op de baan staan.
     *
     *
     * REQUIRE(properlyInitialized(), "Baan is niet correct geïnitialiseerd.");
     */
    void verwijderVoertuigen();
    /** Getter verkeerslichten.
     *
     * @return Vector bestaande uit pointers naar verkeerslichten.
     *
     * REQUIRE(properlyInitialized(), "Baan is niet correct geïnitialiseerd.");
     */
    std::vector<Verkeerslicht *> getVerkeerslichten() ;
    /** Voegt bushaltes toe aan de baan.
     *
     * @param b Pointer naar een bushalte.
     *
     * REQUIRE(properlyInitialized(), "Baan is niet correct geïnitialiseerd.");
     * REQUIRE(b->properlyInitialized(), "Bushalte is niet correct geïnitialiseerd.");
     */
    void addBushalte(Bushalte* b);
    /** Getter bushaltes.
     *
     * @return Vector bestaande uit pointers naar bushaltes.
     *
     * REQUIRE(properlyInitialized(), "Baan is niet correct geïnitialiseerd.");
     */
    std::vector<Bushalte*> getBushaltes();
    /** Geeft het eerste voertuig die in de richting van de bushalte rijdt.
     *
     * @param p Int die de positie van de bushalte voorstelt.
     * @return Pointer naar een voertuig of een nullpointer.
     *
     * REQUIRE(properlyInitialized(), "Baan is niet correct geïnitialiseerd.");
     */
    Voertuig* getEersteVoertuig(int p);
    /** Voegt een kruispunt toe aan de baan.
     *
     * @param kp Pointer naar een kruispunt.
     *
     * REQUIRE(properlyInitialized(), "Baan is niet correct geïnitialiseerd.");
     * REQUIRE(kp->properlyInitialized(), "Kruispunt is niet correct geïnitialiseerd.");
     */
    void addKruispunt(Kruispunt* kp);
    /** Getter kruispunten.
     *
     * @return Vector bestaande uit kruispunten.
     *
     * REQUIRE(properlyInitialized(), "Baan is niet correct geïnitialiseerd.");
     */
    std::vector<Kruispunt*> getKruispunten();
    /** Voegt voertuiggenerator toe aan de baan.
     *
     * @param g Pointer naar een voertuiggenerator.
     *
     * REQUIRE(properlyInitialized(), "Baan is niet correct geïnitialiseerd.");
     */
    void addGenerator(Voertuiggenerator* g);
    /** Getter generators.
     *
     * @return Vector bestaande uit pointers naar voertuiggenerators.
     *
     * REQUIRE(properlyInitialized(), "Baan is niet correct geïnitialiseerd.");
     */
    std::vector<Voertuiggenerator*> getGenerators();
    bool hasKruispunt();

};


#endif //UNTITLED_BAAN_H
