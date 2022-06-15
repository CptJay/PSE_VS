/**
 * @file Verkeerslicht.h
 * @authors Yassir Chebaa, Chloë Mansibang
 * @date 24/03/2022
 */

#ifndef UNTITLED_VERKEERSLICHT_H
#define UNTITLED_VERKEERSLICHT_H

#include "DesignByContract.h"
#include "Voertuig.h"

class Baan;
/** @class Verkeerslicht
 *  @brief Voorstelling van een verkeerslicht.
 *
 */
class Verkeerslicht {
private:
    Baan* baan;
    int positie;
    int cycles;
    bool green;
    double tijd;
    Verkeerslicht *init;
public:
    /** Default Constructor.
     *  Verkeerslicht wordt aangemaakt.
     *
     */
    Verkeerslicht();
    /** Controleert de integriteit van de instantie.
    * Controleert of de selfpointer nog steeds naar zichzelf wijst.
    *
    * @return Succeswaarde
    */
    bool properlyInitialized() const;
    /** Getter Baan
     *
     * @return Baan.
     *
     * REQUIRE(properlyInitialized(), "Verkeerslicht is niet correct geïnitialiseerd.");
     */
    Baan *getBaan() const;
    /** Setter Baan.
     *
     * @param b Baan.
     *
     * REQUIRE(properlyInitialized(), "Verkeerslicht is niet correct geïnitialiseerd.");
     * ENSURE(getBaan() == b, "Baan is niet correct aangepast.");
     */
    void setBaan(Baan *b);
    /** Getter Positie.
     *
     * @return Positie van het verkeerslicht.
     *
     * REQUIRE(properlyInitialized(), "Verkeerslicht is niet correct geïnitialiseerd.");
     */
    int getPositie() const;
    /** Setter Positie.
     *
     * @param p Positie van het verkeerslicht.
     *
     * REQUIRE(properlyInitialized(), "Verkeerslicht is niet correct geïnitialiseerd.");
     * REQUIRE(p >= 0, "Positie mag niet negatief zijn.");
     * ENSURE(getPositie() == p, "Positie is niet correct aangepast.");
     */
    void setPositie(int p);
    /** Getter Cyclus.
     *
     * @return Cyclus van het verkeerslicht.
     *
     * REQUIRE(properlyInitialized(), "Verkeerslicht is niet correct geïnitialiseerd.");
     */
    int getCycles() const;
    /** Setter Cyclus.
     *
     * @param c Cyclus van het verkeerlicht.
     *
     * REQUIRE(properlyInitialized(), "Verkeerslicht is niet correct geïnitialiseerd.");
     * REQUIRE(c >= 0, "Cyclus mag niet negatief zijn.");
     * ENSURE(getCycles() == c, "Cyclus is niet correct aangepast.");
     */
    void setCycles(int c);
    /** Telt de simulatietijd op met de tijd (soort van teller).
     *
     * @param simulatietijd Simulatietijd.
     *
     * REQUIRE(properlyInitialized(), "Verkeerslicht is niet correct geïnitialiseerd.");
     * REQUIRE(simulatietijd >= 0, "Simulatietijd kan niet negatief zijn.");
     */
    void updateTijd(double simulatietijd);
    /** Staat van het verkeerslicht.
     *
     * @return True als verkeerslicht groen is; False indien dit niet het geval is.
     *
     * REQUIRE(properlyInitialized(), "Verkeerslicht is niet correct geïnitialiseerd.");
     */
    bool isGreen() const;
    /** Verandert de kleur van rood naar groen of vice versa.
     *
     * REQUIRE(properlyInitialized(), "Verkeerslicht is niet correct geïnitialiseerd.");
     * REQUIRE(tijd > cycles, "Tijd is niet groter dan cyclus.");
     * ENSURE(getTijd() == 0, "Tijd werd niet gereset.");
     */
    void changeColor();
    /** Getter Tijd.
     *
     * @return Tijd van het verkeerslicht.
     *
     * REQUIRE(properlyInitialized(), "Verkeerslicht is niet correct geïnitialiseerd.");
     */
    double getTijd() const;
    /** Volledige verkeerslichtsimulatie.
     *
     * @param simulatietijd Simulatietijd.
     *
     *
     */
    void verkeerslichtSimulatie(double simulatietijd);
    /** Eerste voertuig dat zich voor het verkeerslicht bevindt.
     *
     * @return Voertuig object.
     */


};


#endif //UNTITLED_VERKEERSLICHT_H
