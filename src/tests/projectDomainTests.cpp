//
// Created by Jay on 15/05/2022.
//


#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <gtest/gtest.h>
#include "../Verkeerssimulatie.h"
#include "../Baan.h"
using namespace std;


class projectDomainTests : public ::testing::Test{
protected:
    friend class Verkeerssimulatie;
    // You should make the members protected s.t. they can be
    // accessed from sub-classes.

    // virtual void SetUp() will be called before each test is run.  You
    // should define it if you need to initialize the variables.
    // Otherwise, this can be skipped.
    virtual void SetUp(){

    }

    // virtual void TearDown() will be called after each test is run.
    // You should define it if there is cleanup work to do.  Otherwise,
    // you don't have to provide it.
    virtual void TearDown(){

    }

    // Declares the variables your tests want to use.
    Verkeerssimulatie verkeerssimulatie;
};

TEST_F(projectDomainTests, DefaultConstructorVerkeersimulatie){
EXPECT_TRUE(verkeerssimulatie.properlyInitialized());
std::vector<Baan*> legeBaan;
EXPECT_EQ(legeBaan, verkeerssimulatie.getBanen());
EXPECT_EQ(0.0166, verkeerssimulatie.getSimulatietijd());
EXPECT_EQ(0, verkeerssimulatie.getId());
EXPECT_TRUE(verkeerssimulatie.properlyInitialized());
}

TEST_F(projectDomainTests, DefaultConstructorBaan){
Baan* baan = new Baan;
EXPECT_EQ("",baan->getNaam());
EXPECT_EQ(0, baan->getLengte());
EXPECT_EQ((long unsigned int)0, baan->getBushaltes().size());
EXPECT_EQ((long unsigned int)0, baan->getVerkeerslichten().size());
EXPECT_EQ((long unsigned int)0, baan->getVoertuigen().size());
EXPECT_TRUE(baan->properlyInitialized());
delete baan;
}

TEST_F(projectDomainTests, DefaultConstructorVerkeerslicht) {
Verkeerslicht* vl = new Verkeerslicht;
EXPECT_EQ(0, vl->getPositie());
EXPECT_EQ(NULL, vl->getBaan());
EXPECT_EQ(0, vl->getCycles());
EXPECT_EQ(0, vl->getTijd());
EXPECT_TRUE(vl->isGreen());
EXPECT_TRUE(vl->properlyInitialized());
delete vl;
}

TEST_F(projectDomainTests, DefaultConstructorVoertuig) {
Voertuig* vt = new Voertuig;
EXPECT_EQ(0, vt->getPositie());
EXPECT_EQ(0, vt->getLengte());
EXPECT_EQ(0, vt->getSnelheid());
EXPECT_EQ(0, vt->getMaxSnelheid());
EXPECT_EQ(0, vt->getAbsMaxSnelheid());
EXPECT_EQ(0, vt->getVersnelling());
EXPECT_EQ(0, vt->getMaxVersnelling());
EXPECT_EQ(0, vt->getMaxRemfactor());
EXPECT_EQ(0, vt->getMinVolgAfstand());
EXPECT_EQ(50, vt->getVertraagAfstand());
EXPECT_EQ(15, vt->getStopAfstand());
EXPECT_EQ(0.4, vt->getVertraagFactor());
EXPECT_TRUE(vt->properlyInitialized());
delete vt;
}

TEST_F(projectDomainTests, ConstructorAuto) {
Auto* vtAuto = new Auto;
EXPECT_EQ(0, vtAuto->getPositie());
EXPECT_EQ(4, vtAuto->getLengte());
EXPECT_EQ(0, vtAuto->getSnelheid());
EXPECT_EQ(16.6, vtAuto->getMaxSnelheid());
EXPECT_EQ(16.6, vtAuto->getAbsMaxSnelheid());
EXPECT_EQ(0, vtAuto->getVersnelling());
EXPECT_EQ(1.44, vtAuto->getMaxVersnelling());
EXPECT_EQ(4.61, vtAuto->getMaxRemfactor());
EXPECT_EQ(4, vtAuto->getMinVolgAfstand());
EXPECT_EQ(50, vtAuto->getVertraagAfstand());
EXPECT_EQ(15, vtAuto->getStopAfstand());
EXPECT_EQ(0.4, vtAuto->getVertraagFactor());
EXPECT_TRUE(vtAuto->properlyInitialized());
delete vtAuto;
}

TEST_F(projectDomainTests, ConstructorBus) {
Bus* bus = new Bus;
EXPECT_EQ(0, bus->getPositie());
EXPECT_EQ(12, bus->getLengte());
EXPECT_EQ(0, bus->getSnelheid());
EXPECT_EQ(11.4, bus->getMaxSnelheid());
EXPECT_EQ(11.4, bus->getAbsMaxSnelheid());
EXPECT_EQ(0, bus->getVersnelling());
EXPECT_EQ(1.22, bus->getMaxVersnelling());
EXPECT_EQ(4.29, bus->getMaxRemfactor());
EXPECT_EQ(12, bus->getMinVolgAfstand());
EXPECT_EQ(50, bus->getVertraagAfstand());
EXPECT_EQ(15, bus->getStopAfstand());
EXPECT_EQ(0.4, bus->getVertraagFactor());
EXPECT_FALSE(bus->isAanBushalte());
EXPECT_TRUE(bus->properlyInitialized());
delete bus;
}

TEST_F(projectDomainTests, ConstructorBrandweerwagen) {
Brandweerwagen* brandweerwagen = new Brandweerwagen;
EXPECT_EQ(0, brandweerwagen->getPositie());
EXPECT_EQ(10, brandweerwagen->getLengte());
EXPECT_EQ(0, brandweerwagen->getSnelheid());
EXPECT_EQ(14.6, brandweerwagen->getMaxSnelheid());
EXPECT_EQ(14.6, brandweerwagen->getAbsMaxSnelheid());
EXPECT_EQ(0, brandweerwagen->getVersnelling());
EXPECT_EQ(1.33, brandweerwagen->getMaxVersnelling());
EXPECT_EQ(4.56, brandweerwagen->getMaxRemfactor());
EXPECT_EQ(10, brandweerwagen->getMinVolgAfstand());
EXPECT_EQ(50, brandweerwagen->getVertraagAfstand());
EXPECT_EQ(15, brandweerwagen->getStopAfstand());
EXPECT_EQ(0.4, brandweerwagen->getVertraagFactor());
EXPECT_TRUE(brandweerwagen->properlyInitialized());
delete brandweerwagen;
}

TEST_F(projectDomainTests, ConstructorZiekenwagen) {
Ziekenwagen* ziekenwagen = new Ziekenwagen;
EXPECT_EQ(0, ziekenwagen->getPositie());
EXPECT_EQ(8, ziekenwagen->getLengte());
EXPECT_EQ(0, ziekenwagen->getSnelheid());
EXPECT_EQ(15.5, ziekenwagen->getMaxSnelheid());
EXPECT_EQ(15.5, ziekenwagen->getAbsMaxSnelheid());
EXPECT_EQ(0, ziekenwagen->getVersnelling());
EXPECT_EQ(1.44, ziekenwagen->getMaxVersnelling());
EXPECT_EQ(4.47, ziekenwagen->getMaxRemfactor());
EXPECT_EQ(8, ziekenwagen->getMinVolgAfstand());
EXPECT_EQ(50, ziekenwagen->getVertraagAfstand());
EXPECT_EQ(15, ziekenwagen->getStopAfstand());
EXPECT_EQ(0.4, ziekenwagen->getVertraagFactor());
EXPECT_TRUE(ziekenwagen->properlyInitialized());
delete ziekenwagen;
}

TEST_F(projectDomainTests, ConstructorPolitiecombi) {
Politiecombi* politiecombi = new Politiecombi;
EXPECT_EQ(0, politiecombi->getPositie());
EXPECT_EQ(6, politiecombi->getLengte());
EXPECT_EQ(0, politiecombi->getSnelheid());
EXPECT_EQ(17.2, politiecombi->getMaxSnelheid());
EXPECT_EQ(17.2, politiecombi->getAbsMaxSnelheid());
EXPECT_EQ(0, politiecombi->getVersnelling());
EXPECT_EQ(1.55, politiecombi->getMaxVersnelling());
EXPECT_EQ(4.92, politiecombi->getMaxRemfactor());
EXPECT_EQ(6, politiecombi->getMinVolgAfstand());
EXPECT_EQ(50, politiecombi->getVertraagAfstand());
EXPECT_EQ(15, politiecombi->getStopAfstand());
EXPECT_EQ(0.4, politiecombi->getVertraagFactor());
EXPECT_TRUE(politiecombi->properlyInitialized());
delete politiecombi;
}

TEST_F(projectDomainTests, DefaultConstructorBushalte) {
Bushalte* bh = new Bushalte;
EXPECT_EQ(NULL, bh->getBaan());
EXPECT_EQ(0, bh->getPositie());
EXPECT_EQ(0, bh->getTijd());
EXPECT_EQ(0, bh->getWachttijd());
EXPECT_TRUE(bh->properlyInitialized());
delete bh;
}

TEST_F(projectDomainTests, DefaultConstructorKruispunt) {
Kruispunt* kp = new Kruispunt;
EXPECT_TRUE(kp->properlyInitialized());
delete kp;
}

TEST_F(projectDomainTests, SetterVerkeerssimulatie) {
Baan* baan1 = new Baan;
baan1->setNaam("Botermelkbaan");
baan1->setLengte(900);
std::vector<Baan*> banen;
banen.push_back(baan1);
verkeerssimulatie.setBanen(banen);
verkeerssimulatie.setSimulatietijd(1);
verkeerssimulatie.setId(0);
EXPECT_EQ(banen, verkeerssimulatie.getBanen());
EXPECT_EQ("Botermelkbaan", banen[0]->getNaam());
EXPECT_EQ(900, banen[0]->getLengte());
EXPECT_EQ(1, verkeerssimulatie.getSimulatietijd());
EXPECT_EQ(0, verkeerssimulatie.getId());
delete baan1;
}

TEST_F(projectDomainTests, SettersVoertuig) {
Baan* baan1 = new Baan;
baan1->setLengte(900);
baan1->setNaam("Botermelbaan");
Voertuig* voertuig = new Voertuig;
voertuig->setPositie(20);
voertuig->setId(1);
voertuig->setBaan(baan1);
voertuig->setType("bus");
EXPECT_EQ(20,voertuig->getPositie());
EXPECT_EQ(1, voertuig->getId());
EXPECT_EQ(baan1, voertuig->getBaan());
EXPECT_EQ("bus", voertuig->getType());
delete baan1;
delete voertuig;
}

TEST_F(projectDomainTests, SettersBushalte) {
Baan* baan1 = new Baan;
baan1->setNaam("Botermelkbaan");
baan1->setLengte(900);
Bushalte* bh = new Bushalte;
bh->setBaan(baan1);
bh->setPositie(250);
bh->setWachttijd(10);
EXPECT_EQ(baan1, bh->getBaan());
EXPECT_EQ(250,bh->getPositie());
EXPECT_EQ(10, bh->getWachttijd());
EXPECT_EQ(0, bh->getTijd());
delete baan1;
delete bh;
}


TEST_F(projectDomainTests, SettersKruispunt) {
    Kruispunt* kp = new Kruispunt;
    Baan* baan1 = new Baan;
    baan1->setNaam("Botermelkbaan");
    baan1->setLengte(900);
    Baan* baan2 = new Baan;
    baan2->setNaam("Carnotstraat");
    baan2->setLengte(900);
    std::pair<Baan*,Baan*> banen; banen.first = baan1; banen.second = baan2;
    kp->setBanen(banen);
    std::pair<int,int> posities; posities.first = 400; posities.second = 500;
    kp->setPosities(posities);
    EXPECT_EQ(banen,kp->getBanen());
    EXPECT_EQ(posities,kp->getPosities());
    delete kp;
    delete baan1;
    delete baan2;
}

TEST_F(projectDomainTests, SettersVerkeerslicht) {
Verkeerslicht* vl = new Verkeerslicht;
Baan* baan1 = new Baan;
baan1->setNaam("Botermelkbaan");
baan1->setLengte(900);
vl->setBaan(baan1);
vl->setPositie(250);
vl->setCycles(5);
EXPECT_EQ(baan1, vl->getBaan());
EXPECT_EQ(250, vl->getPositie());
EXPECT_EQ(5, vl->getCycles());
delete vl;
}

TEST_F(projectDomainTests, ChangeStatusBus) {
Bus* bus = new Bus;
bus->changeStatus();
EXPECT_TRUE(bus->isAanBushalte());
delete bus;
}

TEST_F(projectDomainTests, RijdenVoertuig) {
Baan* baan1 = new Baan;
baan1->setNaam("Botermelkbaan");
baan1->setLengte(900);
Auto* vtAuto1 = new Auto;
vtAuto1->setBaan(baan1);
vtAuto1->setPositie(20);
Auto* vtAuto2 = new Auto;
vtAuto2->setPositie(0);
vtAuto2->setBaan(baan1);
baan1->addVoertuig(vtAuto1);
baan1->addVoertuig(vtAuto2);
vtAuto1->berekenPosEnSnelheid(2);
vtAuto2->berekenPosEnSnelheid(2);
vtAuto2->berekenVersnelling(vtAuto1);
vtAuto1->versnellen();
vtAuto1->berekenPosEnSnelheid(2);
vtAuto2->berekenVersnelling(vtAuto1);
vtAuto2->berekenPosEnSnelheid(2);
EXPECT_EQ(28, vtAuto1->getPositie());
EXPECT_EQ(2.88, vtAuto1->getSnelheid());
EXPECT_EQ(8, vtAuto2->getPositie());
EXPECT_EQ(2.8, vtAuto2->getSnelheid());
double voorVertragen = vtAuto1->getVersnelling();
vtAuto1->vertragen();
vtAuto2->berekenVersnelling(vtAuto1);
vtAuto1->berekenPosEnSnelheid(4);
EXPECT_TRUE(voorVertragen > vtAuto1->getVersnelling());
vtAuto1->stoppen();
vtAuto1->berekenPosEnSnelheid(4);
EXPECT_TRUE(vtAuto1->getVersnelling() < 0);
delete baan1;
delete vtAuto1;
delete vtAuto2;
}

TEST_F(projectDomainTests, VerkeerslichtSimulatie) {
Verkeerslicht* vl = new Verkeerslicht;
vl->setCycles(4);
int tijd = vl->getTijd();
vl->updateTijd(2);
EXPECT_EQ(tijd+2, vl->getTijd());
vl->updateTijd(2);
vl->changeColor();
vl->updateTijd(2);
EXPECT_EQ(2, vl->getTijd());
EXPECT_FALSE(vl->isGreen());
delete vl;
}

TEST_F(projectDomainTests, Bushalte) {
Baan *baan1 = new Baan;
baan1->setNaam("Botermelkbaan");
baan1->setLengte(900);
Bus *bus = new Bus;
Bushalte *bushalte = new Bushalte;
bushalte->setWachttijd(2);
baan1->addVoertuig(bus);
bushalte->setBaan(baan1);
bushalte->setPositie(200);
bus->setBaan(baan1);
bus->setPositie(199);
bus->setSnelheid(10);
bus->setVersnelling(2);
bus->setType("bus");
bushalte->bushalteSimulatie(1);
EXPECT_TRUE(bus->isAanBushalte());
EXPECT_TRUE(bus->getVersnelling() < 0);
bushalte->bushalteSimulatie(1);
bushalte->bushalteSimulatie(1);
EXPECT_FALSE(bus->isAanBushalte());
delete baan1;
delete bus;
delete bushalte;
}

TEST_F(projectDomainTests, KruispuntSimulatie) {
    Kruispunt* kp = new Kruispunt;
    Baan* baan1 = new Baan;
    baan1->setNaam("Botermelkbaan");
    baan1->setLengte(900);
    Baan* baan2 = new Baan;
    baan2->setNaam("Carnotstraat");
    baan2->setLengte(900);
    std::pair<Baan*,Baan*> banen; banen.first = baan1; banen.second = baan2;
    kp->setBanen(banen);
    std::pair<int,int> posities; posities.first = 400; posities.second = 500;
    kp->setPosities(posities);
    Auto* a = new Auto;
    a->setPositie(395); baan1->addVoertuig(a); a->setBaan(baan1);
    Bus* b = new Bus;
    b->setPositie(495); baan2->addVoertuig(b); b->setBaan(baan2);
    kp->kruispuntSimulatie(baan1);
    kp->kruispuntSimulatie(baan2);
    EXPECT_FALSE(a->getPositie() == 395);
    EXPECT_FALSE(b->getPositie() == 495);
    posities.first = 900; kp->setPosities(posities);
    kp->setPosities(posities);
    a->setPositie(895); baan1->addVoertuig(a); a->setBaan(baan1);
    kp->kruispuntSimulatie(baan1);
    EXPECT_TRUE(a->getBaan()->getNaam() == "Carnotstraat");
    posities.second = 900; posities.first = 400;
    b->setPositie(895); baan2->addVoertuig(b); b->setBaan(baan2);
    kp->setPosities(posities);
    kp->kruispuntSimulatie(baan2);
    EXPECT_TRUE(b->getBaan()->getNaam() == "Botermelkbaan");
}

TEST_F(projectDomainTests,DefaultConstructorVoertuiggenerator) {
    Voertuiggenerator* g = new Voertuiggenerator;
    EXPECT_EQ(0,g->getFrequentie());
    EXPECT_EQ(0,g->getL());
    EXPECT_EQ(0,g->getTijd());
    EXPECT_TRUE(g->properlyInitialized());
}

TEST_F(projectDomainTests,VoertuiggeneratorSimulatie) {
    Voertuiggenerator* g = new Voertuiggenerator;
    Baan* baan1 = new Baan;
    baan1->setNaam("Botermelkbaan");
    baan1->setLengte(900);
    Auto* a = new Auto;
    a->setPositie(5); baan1->addVoertuig(a); a->setBaan(baan1);
    g->setBaan(baan1);
    g->setFrequentie(2);
    string au = "auto";
    g->setType(au);
    g->setL(a->getLengte());
    EXPECT_FALSE(g->generatePossible());
    g->updateTijd(1);
    g->updateTijd(1);
    a->setPositie(100);
    EXPECT_TRUE(g->generatePossible());
    Voertuig* nieuwVoertuig = g->generateVoertuig(1);
    EXPECT_EQ(0,g->getTijd());
    EXPECT_TRUE(nieuwVoertuig != NULL);
}

