/**
 * @file Voertuig.h
 * @authors Yassir Chebaa, Chloë Mansibang
 * @date 24/03/2022
 */

#ifndef UNTITLED_VOERTUIG_H
#define UNTITLED_VOERTUIG_H

#include "DesignByContract.h"
#include <string>

class Verkeerslicht;

class Baan;
/** @class Voertuig
 * @brief Voorstelling van een voertuig.
 *
 */
class Voertuig {
private:
    Baan* baan;
    int positie;
    int lengte;
    int id;
    std::string type;
    double snelheid;
    double maxSnelheid;
    double AbsMaxSnelheid;
    double versnelling;
    double maxVersnelling;
    double maxRemfactor;
    double minVolgAfstand;
    double vertraagAfstand;
    double stopAfstand;
    double vertraagFactor;
    Voertuig* init;
public:
    /** Setter lengte.
     *
     * @param l lengte
     *
     * REQUIRE(properlyInitialized(), "Voertuig is niet correct geïnitialiseerd.");
     * ENSURE(getLengte() == l, "Lengte is niet correct aangepast.");
     */
    void setLengte(int l);
    /** Setter Absolute maximale snelheid.
     *
     * @param m absolute maximale snelheid
     *
     * REQUIRE(properlyInitialized(), "Voertuig is niet correct geïnitialiseerd.");
     * ENSURE(getMaxSnelheid() == m, "Maximale snelheid is niet correct aangepast.");
     * ENSURE(getMaxSnelheid() == m, "Maximale snelheid is niet correct aangepast.");
     */
    void setAbsMaxSnelheid(double m);
    /** Setter maximale versnelling
     *
     * @param m maximale versnelling
     *
     *
     */
    void setMaxVersnelling(double m);
    /** Setter maximale remfactor.
     *
     * @param r maximale remfactor
     *
     * REQUIRE(properlyInitialized(), "Voertuig is niet correct geïnitialiseerd.");
     */
    void setMaxRemfactor(double r);
    /** Setter minimale volgafstand.
     *
     * @param v minimale volgafstand
     *
     * REQUIRE(properlyInitialized(), "Voertuig is niet correct geïnitialiseerd.");
     */
    void setMinVolgafstand(int v);
    /** Getter ID.
     *
     * @return ID
     *
     * REQUIRE(properlyInitialized(), "Voertuig is niet correct geïnitialiseerd.");
     */
    int getId() const;
    /** Setter ID
     *
     * @param id
     *
     * REQUIRE(properlyInitialized(), "Voertuig is niet correct geïnitialiseerd.");
     * ENSURE(getId() == i, "ID is niet correct aangepast.");
     */
    void setId(int id);
    /** Default constructor.
     *  @brief Voertuig wordt aangemaakt.
     *
     *  ENSURE(properlyInitialized(), "Voertuig is niet correct geïnitialiseerd.");
     */
    Voertuig();
    /** Constructor
     *
     * @param l lengte
     * @param maxSnel maximale snelheid
     * @param maxVers maximale versnelling
     * @param maxRem maximale remfactor
     * @param minvolg minimale volgafstand
     *
     * ENSURE(properlyInitialized(), "Voertuig is niet correct geïnitialiseerd.");
     */
    Voertuig(int l, double maxSnel, double maxVers, double maxRem, double minvolg);
    /** Controleert de integriteit van de instantie.
    * Controleert of de selfpointer nog steeds naar zichzelf wijst.
    *
    * @return Succeswaarde
    */
    bool properlyInitialized() const;
    /** Getter Baan.
     *
     * @return Baan.
     *
     * REQUIRE(properlyInitialized(), "Voertuig is niet correct geïnitialiseerd.");
     */
    Baan *getBaan() const;
    /** Setter Maximale snelheid.
     *
     * @param ms Maximale snelheid van het voertuig.
     *
     * REQUIRE(properlyInitialized(), "Voertuig is niet correct geïnitialiseerd.");
     * REQUIRE(ms >= 0, "Maximale snelheid kan niet negatief zijn.");
     * ENSURE(getMaxSnelheid() == ms, "Maximale snelheid is niet correct aangepast.");
     */
    void setMaxSnelheid(double ms);
    /** Setter Baan.
     *
     * @param b Baan.
     *
     * REQUIRE(properlyInitialized(), "Voertuig is niet correct geïnitialiseerd.");
     * ENSURE(getBaan() == b, "Baan is niet correct aangepast.");
     */
    void setBaan(Baan *b);
    /** Getter Positie.
     *
     * @return Positie van het voertuig op de baan.
     *
     * REQUIRE(properlyInitialized(), "Voertuig is niet correct geïnitialiseerd.");
     */
    int getPositie() const;
    /** Setter Positie.
     *
     * @param Positie van het voertuig op de baan.
     *
     * REQUIRE(properlyInitialized(), "Voertuig is niet correct geïnitialiseerd.");
     * REQUIRE(p >= 0, "Positie mag niet negatief zijn.");
     * ENSURE(getPositie() == p, "Positie is niet correct aangepast.");
     */
    void setPositie(int p);
    /** Getter Lengte.
     *
     * @return Lengte van het voertuig.
     *
     * REQUIRE(properlyInitialized(), "Voertuig is niet correct geïnitialiseerd.");
     */
    int getLengte() const;
    /** Getter Snelheid.
     *
     * @return Snelheid van het voertuig.
     *
     * REQUIRE(properlyInitialized(), "Voertuig is niet correct geïnitialiseerd.");
     */
    double getSnelheid() const;
    /** Getter Maximale Snelheid.
     *
     * @return Maximale snelheid van het voertuig.
     *
     * REQUIRE(properlyInitialized(), "Voertuig is niet correct geïnitialiseerd.");
     */
    double getMaxSnelheid() const;
    /** Getter Versnelling.
     *
     * @return Versnelling van het voertuig.
     *
     * REQUIRE(properlyInitialized(), "Voertuig is niet correct geïnitialiseerd.");
     */
    double getVersnelling() const;
    /** Getter Maximale versnelling
     *
     * @return Maximale versnelling van het voertuig.
     *
     * REQUIRE(properlyInitialized(), "Voertuig is niet correct geïnitialiseerd.");
     */
    double getMaxVersnelling() const;
    /** Getter Maximale remfactor.
     *
     * @return Maximale remfactor van het voertuig.
     *
     * REQUIRE(properlyInitialized(), "Voertuig is niet correct geïnitialiseerd.");
     */
    double getMaxRemfactor() const;
    /** Getter Minimale volgafstand.
     *
     * @return Minimale volgafstand van het voertuig.
     *
     * REQUIRE(properlyInitialized(), "Voertuig is niet correct geïnitialiseerd.");
     */
    double getMinVolgAfstand() const;
    /** Getter Vertraagafstand.
     *
     * @return Vertraagafstand van het voertuig.
     *
     * REQUIRE(properlyInitialized(), "Voertuig is niet correct geïnitialiseerd.");
     */
    double getVertraagAfstand() const;
    /** Getter stopafstand.
     *
     * @return Stopafstand van het voertuig.
     *
     * REQUIRE(properlyInitialized(), "Voertuig is niet correct geïnitialiseerd.");
     */
    double getStopAfstand() const;
    /** Getter vertraagafstand.
     *
     * @return Vertraagafstand van het voertuig.
     *
     * REQUIRE(properlyInitialized(), "Voertuig is niet correct geïnitialiseerd.");
     */
    double getVertraagFactor() const;
    /** Setter snelheid
     *
     * @param s Snelheid van het voertuig.
     *
     * REQUIRE(properlyInitialized(), "Voertuig is niet correct geïnitialiseerd.");
     * REQUIRE(s >= 0, "Snelheid kan niet negatief zijn.");
     * ENSURE(getSnelheid() == s, "Snelheid is niet correct aangepast.");
     */
    void setSnelheid(double s);
    /** Setter versnelling.
     *
     * @param v Versnelling van het voertuig.
     *
     * REQUIRE(properlyInitialized(), "Voertuig is niet correct geïnitialiseerd.");
     * ENSURE(getVersnelling() == v, "Versnelling is niet correct aangepast.");
     */
    void setVersnelling(double v);
    /** Getter Absolute maximale snelheid.
     *
     * @return Absolute maximale snelheid van het voertuig.
     *
     * REQUIRE(properlyInitialized(), "Voertuig is niet correct geïnitialiseerd.");
     */
    double getAbsMaxSnelheid() const;
    /** Het berekenen van de positie en snelheid van voertuig.
     *
     * @param simulatietijd
     *
     * REQUIRE(properlyInitialized(), "Voertuig is niet correct geïnitialiseerd.");
     * REQUIRE(snelheid >= 0, "Snelheid can niet negatief zijn");
     * REQUIRE(AbsMaxSnelheid >= 0, "Absolute maximale snelheid kan niet negatief zijn");
     * ENSURE(getPositie() == pos, "Positie is niet correct aangepast.");
     * ENSURE(getSnelheid() == snelh, "Snelheid is niet correct aangepast.");
     * ENSURE(getPositie() == pos, "Positie is niet correct aangepast.");
     * ENSURE(getSnelheid() == 0, "Snelheid is niet correct aangepast.");
     */
    void berekenPosEnSnelheid(double simulatietijd);
    /** Het berekenen van volgafstandsfactor
     *
     * @param x
     * @return volgafstand
     *
     * REQUIRE(properlyInitialized(), "Voertuig is niet correct geïnitialiseerd.");
     */
    double _berekenVolgafstand(double x);
    /** Het berekenen van het snelheidsverschil.
     *
     * @param v snelheid
     * @return Snelheidsverschil
     *
     * REQUIRE(properlyInitialized(), "Voertuig is niet correct geïnitialiseerd.");
     */
    double _berekenSnelheidsverschil(double v);
    /** Het berekenen van de interactieterm
     *
     * @param voertuig
     * @return interactieterm
     *
     * REQUIRE(properlyInitialized(), "Voertuig is niet correct geïnitialiseerd.");
     */
    double _berekenInteractie(Voertuig* voertuig);
    /** Het berekenen van de versnelling van het voertuig.
     *
     * @param voertuig
     *
     * REQUIRE(properlyInitialized(), "Voertuig is niet correct geïnitialiseerd.");
     */
    void berekenVersnelling(Voertuig* voertuig);
    /** Het afremmen van het voertuig. Snelheid daalt.
     *
     * REQUIRE(properlyInitialized(), "Voertuig is niet correct geïnitialiseerd.");
     * ENSURE(getMaxSnelheid() == AbsMaxSnelheid * vertraagFactor, "Maximale snelheid is niet correct aangepast.");
     */
    void vertragen();
    /** Het versnellen van het voertuig.
     *
     * REQUIRE(properlyInitialized(), "Voertuig is niet correct geïnitialiseerd.");
     * ENSURE(getMaxSnelheid() == AbsMaxSnelheid, "Maximale snelheid is niet correct aangepast.");
     */
    void versnellen();
    /** Zien of het verkeerslicht in stopafstand staat van het voertuig.
     *
     * @param vl verkeerslicht
     * @return Succeswaarde
     *
     * REQUIRE(properlyInitialized(), "Voertuig is niet correct geïnitialiseerd.");
     */
    bool _inStopafstand(Verkeerslicht* vl);
    /** Zien of het verkeerslicht in vertraagAfstand staat van het voertuig.
     *
     * @param vl verkeerslicht
     * @return Succeswaarde
     *
     * REQUIRE(properlyInitialized(), "Voertuig is niet correct geïnitialiseerd.");
     */
    bool _inVertraagafstand(Verkeerslicht* vl);
    /** Het stoppen van het voertuig. Versnelling wordt aangepast.
     *
     * REQUIRE(properlyInitialized(), "Voertuig is niet correct geïnitialiseerd.");
     */
    void stoppen();
    /** Setter Type voertuig.
     *
     * @param s Type van het voertuig in stringvorm.
     *
     * REQUIRE(properlyInitialized(), "Voertuig is niet correct geïnitialiseerd.");
     * ENSURE( getType() == s, "Type is niet correct aangepast.");
     */
    void setType(std::string s);
    /** Getter Type voertuig.
     *
     * @return Type
     *
     * REQUIRE(properlyInitialized(), "Voertuig is niet correct geïnitialiseerd.");
     */
    std::string getType();
    /** Getter stopafstand
     *
     * @return stopafstand
     *
     * REQUIRE(properlyInitialized(), "Voertuig is niet correct geïnitialiseerd.");
     */
    double getStopAfstand();
};

class Auto : public Voertuig{
public:
    /** Default constructor.
    *
    */
    Auto();
};

class Bus: public Voertuig{
private:
    bool aanBushalte;
public:
    /** Default constructor.
     *
     */
    Bus();
    /** Checkt of een bus aan een bushalte staat.
     *
     * @return Bool die aangeeft of een bus aan een bushalte staat.
     *
     * REQUIRE(properlyInitialized(), "Bus is niet correct geïnitialiseerd.");
     */
    bool isAanBushalte();
    /** Verandert het al dan niet aan een bushalte staan.
     *
     * REQUIRE(properlyInitialized(), "Bus is niet correct geïnitialiseerd.");
     */
    void changeStatus();
};

class Brandweerwagen: public Voertuig{
public:
    /** Default constructor.
    *
    */
    Brandweerwagen();
};

class Ziekenwagen: public Voertuig{
public:
    /** Default constructor.
     *
     */
    Ziekenwagen();
};

class Politiecombi: public Voertuig{
public:
    /** Default constructor.
    *
    */
    Politiecombi();
};
#endif //UNTITLED_VOERTUIG_H
