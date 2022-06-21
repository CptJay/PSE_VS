//
// Created by Jay on 15/05/2022.
//

#ifndef UNTITLED_PROJECTUTILS_H
#define UNTITLED_PROJECTUTILS_H


#include <iostream>

/** Controleer of een bestandsmap bestaat.
 *
 * @param dirname Pad om te controleren. Indien relatief, vanaf de plaats waar de applicatie uitgevoerd wordt.
 * @return
 */
bool DirectoryExists(const std::string& dirname);
/** Controleer of een bestand bestaat.
 *
 * @param filename Pad om te controleren. Indien relatief, vanaf de plaats waar de applicatie uitgevoerd wordt.
 * @return
 */
bool FileExists(const std::string& dirname);
/** Controleer of een bestand al dan niet leeg is.
 *
 * @param filename Pad naar het bestand dat moet gecontroleerd worden. Indien relatief, vanaf de plaats waar de applicatie uitgevoerd wordt.
 * @return
 */
bool FileIsEmpty(const std::string& filename);
/** Vergelijk twee bestanden.
 * Een side-by-side vergelijking van de bestanden. Indien ze niet overeen komen wordt false terug gegeven.
 *
 * @param leftFileName Eerste bestand om te vergelijken.
 * @param rightFileName Tweede bestand om te vergelijken.
 * @return
 */
bool FileCompare(const std::string& leftFileName, const std::string& rightFileName);
/** Zet een integer x om naar een string.
 *
 * @param x Integer om om te zetten.
 * @return Stringvoorstelling van x .
 */
std::string ToString( int x );

#endif //UNTITLED_PROJECTUTILS_H
