/**
 * @file Verkeerssimulatie.h
 * @authors Yassir Chebaa, Chloë Mansibang
 * @date 24/03/2022
 */

#ifndef UNTITLED_VERKEERSSIMULATIE_H
#define UNTITLED_VERKEERSSIMULATIE_H

#include <vector>
#include <string>
#include "DesignByContract.h"
#include "Baan.h"
#include "Verkeerslicht.h"
#include "Voertuig.h"
#include "Bushalte.h"

class Baan;

class Verkeerslicht;

class Voertuig;

class Bushalte;

class Verkeerssimulatie {
private:
    std::vector<Baan *> banen;
    double simulatietijd;
    Verkeerssimulatie *init;
    int ID;
public:
    /** Setter vector banen.
     *
     * @param b banen
     *
     * REQUIRE(properlyInitialized(), "Verkeerssimulatie is niet correct geïnitialiseerd");
     * ENSURE(getBanen() == b, "Banen is niet correct aangepast");
     */
    void setBanen(const std::vector<Baan *> &b);
    /** Setter simulatietijd.
     *
     * @param st simulatietijd.
     *
     * REQUIRE(properlyInitialized(), "Verkeerssimulatie is niet correct geïnitialiseerd");
     * ENSURE(getSimulatietijd() == st, "Simulatietijd is niet correct aangepast");
     */
    void setSimulatietijd(double st);
    /** Setter ID.
     *
     * @param id ID
     *
     * REQUIRE(properlyInitialized(), "Verkeerssimulatie is niet correct geïnitialiseerd");
     * ENSURE(getId() == id, "ID is niet correct aangepast");
     */
    void setId(int id);
    /** Getter banen.
     *
     * @return vector met pointers naar Baan.
     *
     * REQUIRE(properlyInitialized(), "Verkeerssimulatie is niet correct geïnitialiseerd");
     */
    const std::vector<Baan *> &getBanen() const;
    /** Getter ID
     *
     * @return ID
     *
     * REQUIRE(properlyInitialized(), "Verkeerssimulatie is niet correct geïnitialiseerd");
     */
    int getId() const;

    /** Default Constructor.
     *
     * ENSURE(properlyInitialized(), "(Constructor) Verkeerssimulatie niet correct geïnitialiseerd.");
     */
    Verkeerssimulatie();
    /** Constructor met een bestandsnaam.
     *
     * @param filename Bestandsnaam waaruit gelezen moet worden.
     *
     * ENSURE(properlyInitialized(), "(Constructor) Verkeerssimulatie niet correct geïnitialiseerd.");
     */
    Verkeerssimulatie(const char *filename);
    /** Controleert de integriteit van de instantie.
    * Controleert of de selfpointer nog steeds naar zichzelf wijst.
    *
    * @return Succeswaarde
    */
    bool properlyInitialized() const;
    /** Getter Simulatietijd.
     *
     * @return Simulatietijd.
     *
     * REQUIRE(properlyInitialized(), "Verkeerssimulatie is niet correct geïnitialiseerd");
     */
    double getSimulatietijd() const;

    /** prints de verkeerslichtspositie en de tijd van het verkeerslicht alsook het voertuig
     * met de bijhorende baan, positie en snelheid.
     *
     * @param vl Verkeerslicht
     *
     * REQUIRE(properlyInitialized(), "Verkeersimulatie was niet correct geïnitialiseerd");
     */
    void print();
    /** Volledige simulatie.
     *
     * REQUIRE(properlyInitialized(), "Verkeerssimulatie is niet correct geïnitialiseerd");
     */
    void automatischeSimulatie();
    /** Voegt een baan toe aan de verkeerssimulatie.
     *
     * @param b Baan
     *
     * REQUIRE(properlyInitialized(), "Verkeerssimulatie is niet correct geïnitialiseerd");
     */

    void herstart();
    void exportSimulatie();
};


#endif //UNTITLED_VERKEERSSIMULATIE_H
