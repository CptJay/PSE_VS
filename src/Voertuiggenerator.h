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
    Voertuiggenerator* init;
public:
    Voertuiggenerator();
    void setBaan(Baan* b);
    Baan* getBaan();
    void setFrequentie(int f);
    int getFrequentie();
};


#endif //UNTITLED_VOERTUIGGENERATOR_H
