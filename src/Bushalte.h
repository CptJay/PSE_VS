/**
 * @file Bushalte.h
 * @authors Yassir Chebaa, Chloë Mansibang
 * @date 24/03/2022
 */

#ifndef UNTITLED_BUSHALTE_H
#define UNTITLED_BUSHALTE_H

#include "DesignByContract.h"

class Baan;
class Bushalte {
private:
    Baan* baan;
    int positie;
    int tijd;
    int wachttijd;
    Bushalte* init;
public:
    /** Default Constructor.
     *
     *  ENSURE(properlyInitialized(), "Baan is niet correct geïnitialiseerd.");
     */
    Bushalte();
    /** Setter baan van een bushalte.
     *
     * @param b Baan
     *
     * REQUIRE(properlyInitialized(), "Baan is niet correct geïnitialiseerd.");
     * ENSURE(getBaan() == b, "Baan is niet correct aangepast.");
     */
    void setBaan(Baan* b);
    /** Setter positie van een bushalte.
     *
     * @param p Positie
     *
     * REQUIRE(properlyInitialized(), "Baan is niet correct geïnitialiseerd.");
     * ENSURE(getPositie() == p, "Positie is niet correct aangepast.");
     */
    void setPositie(int p);
    /** Setter wachttijd van een bushalte. De tijd dat een bus stilstaat aan een bushalte.
     *
     * @param w Wachttijd
     *
     * REQUIRE(properlyInitialized(), "Baan is niet correct geïnitialiseerd.");
     * ENSURE(getWachttijd() == w, "Wachttijd is niet correct aangepast.");
     */
    void setWachttijd(int w);
    /** Getter baan.
     *
     * @return baan
     */
    Baan* getBaan();
    /** Getter positie.
     *
     * @return Positie
     *
     * REQUIRE(properlyInitialized(), "Baan is niet correct geïnitialiseerd.");
     */
    int getPositie();
    /** Getter wachttijd.
     *
     * @return Wachttijd
     *
     * REQUIRE(properlyInitialized(), "Baan is niet correct geïnitialiseerd.");
     */
    int getWachttijd();
    /** Controleert de integriteit van de instantie.
    * Controleert of de selfpointer nog steeds naar zichzelf wijst.
    *
    * @return Succeswaarde
    */
    bool properlyInitialized() const;
    /** Volledige simulatie van een bushalte.
     *
     * @param simulatietijd De tijd die nodig is om een cyclus te voltooien in één bushaltesimulatie.
     *
     * REQUIRE(properlyInitialized(), "Baan is niet correct geïnitialiseerd.");
     * REQUIRE(simulatietijd >= 0, "Simulatietijd moet positief zijn.");
     *
     */
    void bushalteSimulatie(double simulatietijd);
    /** Getter tijd van een bushalte.
     *
     * @return Tijd
     *
     * REQUIRE(properlyInitialized(), "Baan is niet correct geïnitialiseerd.");
     */
    int getTijd();



};


#endif //UNTITLED_BUSHALTE_H
