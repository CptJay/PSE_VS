/**
 * @file Baan.h
 * @authors Yassir Chebaa, Chloë Mansibang
 * @date 24/03/2022
 */

#ifndef UNTITLED_BAAN_H
#define UNTITLED_BAAN_H


#include <string>
#include <vector>
#include "DesignByContract.h"
#include "Voertuig.h"
#include "Verkeerslicht.h"
#include "Bushalte.h"
#include "Kruispunt.h"

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
    void addVoertuig(Voertuig* b);
    void addVerkeerslicht(Verkeerslicht* vl);
    void verwijderVoertuigen();
    std::vector<Verkeerslicht *> getVerkeerslichten() ;
    void addBushalte(Bushalte* b);
    std::vector<Bushalte*> getBushaltes();
    Voertuig* getEersteVoertuig(int p);
    void addKruispunt(Kruispunt* kp);
    stdstd::vector<Kruispunt*> getKruispunten();
};


#endif //UNTITLED_BAAN_H
