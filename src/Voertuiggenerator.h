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
public:
    Voertuiggenerator();
    void setBaan(Baan* b);
    Baan* getBaan();
    void setFrequentie(int f);
    int getFrequentie();
    void updateTijd(double simulatietijd);
    Voertuig* generateVoertuig(double simulatietijd);
    void setType(std::string &t);
    std::string getType();
    bool generatePossible();
    void setL(int l);
    int getL();
    double getTijd();
    bool properlyInitialized() const;
};


#endif //UNTITLED_VOERTUIGGENERATOR_H
