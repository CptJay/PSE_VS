/**
 * @file Parser.h
 * @authors Yassir Chebaa, Chloë Mansibang
 * @date 24/03/2022
 */

#ifndef UNTITLED_PARSER_H
#define UNTITLED_PARSER_H

#include "DesignByContract.h"
#include "vector"
#include "string"
#include "map"
#include "Voertuiggenerator.h"

class Baan;
class Voertuig;
class Voertuiggenerator;
class Parser {
private:
    Parser *init;
    int ID;
    std::vector<Baan*> banen;

    std::string baanNaam;
    int positie;
    std::string typeVoertuig;
public:
    /** Default constructor.
     *
     */
    Parser();
    /** Constructor.
     *
     * @param filename Bestandsnaam
     *
     * ENSURE(properlyInitialized(), "Parser is niet correct geïnitialiseerd.");
     */
    explicit Parser(const char *filename);

    /** Converteert een string naar een integer.
     *
     * @param s String.
     * @return Integer.
     *
     * REQUIRE(properlyInitialized(), "Parser was niet correct geïnitialiseerd");
     */
    int stringToInt(const std::string &s);
    /** Getter banen
     *
     * @return vector van pointers naar banen
     *
     * REQUIRE(properlyInitialized(), "Parser was niet correct geïnitialiseerd");
     */
    const std::vector<Baan *> &getBanen() const;

private:
    void XML(const char *filename);
    /** Zoekt de juiste baan uit de vector op basis van de naam.
    *
    * @param s Naam van de baan.
    * @return Baan.
    *
    * REQUIRE(properlyInitialized(), "Parser was niet correct geïnitialiseerd");
    * REQUIRE(!banen.empty(), "Banen mag niet leeg zijn.");
    */
    Baan *findBaan(const std::string &s);
    /** Controleert de integriteit van de instantie.
    * Controleert of de selfpointer nog steeds naar zichzelf wijst.
    *
    * @return Succeswaarde
    */
    bool properlyInitialized() const;
    /** Hulpfunctie
     *
     * @param voertuig
     *
     * REQUIRE(properlyInitialized(), "Parser was niet correct geïnitialiseerd");
     */
    void assignInfo(Voertuig* voertuig);
};


#endif //UNTITLED_PARSER_H
