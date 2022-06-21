//
// Created by chloeacm on 20.06.22.
//

#ifndef UNTITLED_VOERTUIGGENERATOR_H
#define UNTITLED_VOERTUIGGENERATOR_H

#include <string>
#include "Baan.h"


class Voertuiggenerator {
private:
    Baan* baan;
    int frequentie;
    double tijd;
    std::string typeV;
    int lengte;
    Voertuiggenerator* init;
    bool generatePossible();
public:
    /** Default constructor.
     *
     */
    Voertuiggenerator();
    /** Setter baan.
     *
     * @param b Pointer naar een baan.
     *
     * REQUIRE(properlyInitialized(), "Voertuiggenerator is niet correct geïnitialiseerd.");
     */
    void setBaan(Baan* b);
    /** Getter baan.
     *
     * @return Pointer naar een baan.
     *
     * REQUIRE(properlyInitialized(), "Voertuiggenerator is niet correct geïnitialiseerd.");
     */
    Baan* getBaan();
    /** Setter frequentie.
     *
     * @param f Int die de frequentie voorstelt
     *
     * REQUIRE(properlyInitialized(), "Voertuiggenerator is niet correct geïnitialiseerd.");
     */
    void setFrequentie(int f);
    /** Getter frequentie.
     *
     * @return Int die de frequentie voorstelt.
     *
     * REQUIRE(properlyInitialized(), "Voertuiggenerator is niet correct geïnitialiseerd.");
     */
    int getFrequentie();
    /** Houdt de tijd van de generator up-to-date met de simulatie.
     *
     * @param simulatietijd Double die de simulatietijd voorstelt.
     *
     * REQUIRE(properlyInitialized(), "Voertuiggenerator is niet correct geïnitialiseerd.");
     */
    void updateTijd(double simulatietijd);
    /** Maakt een nieuw voertuig aan op het begin van de baan, als dit mogelijk is.
     *
     * @param simulatietijd Double die de simulatietijd voorstelt.
     * @return Pointer naar een nieuw voertuig of een nullpointer.
     *
     * REQUIRE(properlyInitialized(), "Voertuiggenerator is niet correct geïnitialiseerd.");
     */
    Voertuig* generateVoertuig(double simulatietijd);
    /** Setter typeV.
     *
     * @param t String die het type beschrijft.
     *
     * REQUIRE(properlyInitialized(), "Voertuiggenerator is niet correct geïnitialiseerd.");
     */
    void setType(std::string &t);
    /** Setter lengte.
     *
     * @param l Int die de lengte voorstelt.
     *
     * REQUIRE(properlyInitialized(), "Voertuiggenerator is niet correct geïnitialiseerd.");
     */
    void setL(int l);
    /** Getter lengte.
     *
     * @return Int die de lengte voorstelt.
     *
     * REQUIRE(properlyInitialized(), "Voertuiggenerator is niet correct geïnitialiseerd.");
     */
    int getL();
    /** Getter tijd.
     *
     * @return Double die de tijd voorstelt.
     *
     * REQUIRE(properlyInitialized(), "Voertuiggenerator is niet correct geïnitialiseerd.");
     */
    double getTijd();
    /** Controleert de integriteit van de instantie.
    * Controleert of de selfpointer nog steeds naar zichzelf wijst.
    *
    * @return Succeswaarde
    */
    bool properlyInitialized() const;
};


#endif //UNTITLED_VOERTUIGGENERATOR_H
