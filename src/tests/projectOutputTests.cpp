//
// Created by Jay on 15/05/2022.
//

#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <gtest/gtest.h>

using namespace std;

#include "../Verkeerssimulatie.h"
#include "../projectUtils.h"
#include "../projectExporter.h"

class projectOutputTests : public ::testing::Test{
protected:
    friend class Verkeerssimulatie;
    virtual void SetUp(){
    }

    virtual void TearDown(){
    }

    Verkeerssimulatie verkeerssimulatie;
    projectExporter exporter;
    GrafischeExporter grafischeExporter;
};

TEST_F(projectOutputTests, UtilIntegrityTest){
    ASSERT_TRUE(DirectoryExists("src"));
    ASSERT_TRUE(DirectoryExists("src/testOutput"));

    ofstream myfile;
    myfile.open("src/testOutput/wf");
    myfile.close();

    // FileExist && FileIsEmpty
    EXPECT_TRUE(FileExists("src/testOutput/wf"));
    EXPECT_FALSE(FileExists("src/testOutput/bestaatniet"));
    EXPECT_TRUE(FileExists("src/testOutput/wf"));

    myfile.open("src/testOutput/wf");
    myfile << "abc" << endl;
    myfile.close();
    EXPECT_FALSE(FileIsEmpty("src/testOutput/wf"));

    // FileCompare

    // 2 lege bestanden
    myfile.open("src/testOutput/wf1");
    myfile.close();
    myfile.open("src/testOutput/wf2");
    myfile.close();

    EXPECT_TRUE(FileExists("src/testOutput/wf1"));
    EXPECT_TRUE(FileExists("src/testOutput/wf2"));
    EXPECT_TRUE(FileIsEmpty("src/testOutput/wf1"));
    EXPECT_TRUE(FileIsEmpty("src/testOutput/wf2"));
//    EXPECT_TRUE(FileCompare("src/testOutput/wf1", "src/testOutput/wf2"));
//    EXPECT_TRUE(FileCompare("src/testOutput/wf2", "src/testOutput/wf1"));

    // Leeg en niet-leeg bestand
    myfile.open("src/testOutput/wf1");
    myfile << "Dit is niet leeg" << endl;
    myfile.close();

    EXPECT_TRUE(FileExists("src/testOutput/wf1"));
    EXPECT_TRUE(FileExists("src/testOutput/wf2"));
    EXPECT_FALSE(FileIsEmpty("src/testOutput/wf1"));
    EXPECT_TRUE(FileIsEmpty("src/testOutput/wf2"));
    EXPECT_FALSE(FileCompare("src/testOutput/wf1", "src/testOutput/wf2"));
    EXPECT_FALSE(FileCompare("src/testOutput/wf2", "src/testOutput/wf1"));

    // 2 niet-lege bestanden - verschillend
    myfile.open("src/testOutput/wf2");
    myfile << "PSE is cool" << endl;
    myfile.close();

    EXPECT_TRUE(FileExists("src/testOutput/wf1"));
    EXPECT_TRUE(FileExists("src/testOutput/wf2"));
    EXPECT_FALSE(FileIsEmpty("src/testOutput/wf1"));
    EXPECT_FALSE(FileIsEmpty("src/testOutput/wf2"));
    EXPECT_FALSE(FileCompare("src/testOutput/wf1", "src/testOutput/wf2"));
    EXPECT_FALSE(FileCompare("src/testOutput/wf2", "src/testOutput/wf1"));

    // 2 niet-lege bestanden - identiek
    myfile.open("src/testOutput/wf1");
    myfile << "azerty" << endl;
    myfile.close();
    myfile.open("src/testOutput/wf2");
    myfile << "azerty" << endl;
    myfile.close();

    EXPECT_TRUE(FileExists("src/testOutput/wf1"));
    EXPECT_TRUE(FileExists("src/testOutput/wf2"));
    EXPECT_FALSE(FileIsEmpty("src/testOutput/wf1"));
    EXPECT_FALSE(FileIsEmpty("src/testOutput/wf2"));
    EXPECT_TRUE(FileCompare("src/testOutput/wf1", "src/testOutput/wf2"));
    EXPECT_TRUE(FileCompare("src/testOutput/wf2", "src/testOutput/wf1"));
}

TEST_F(projectOutputTests, BasicOutput){
    ASSERT_TRUE(DirectoryExists("src"));
    ASSERT_TRUE(DirectoryExists("src/testOutput"));

    // Basic
    vector<Baan*> banen;
    Baan* baan = new Baan;
    baan->setNaam("Middelheim");
    baan->setLengte(500);
    banen.push_back(baan);

    Baan* baan2 = new Baan;
    baan2->setNaam("Flora");
    baan2->setLengte(200);
    banen.push_back(baan2);

    Auto* anAuto = new Auto;
    anAuto->setPositie(20);
    anAuto->setBaan(baan);
    anAuto->setLengte(7);
    anAuto->setSnelheid(1);
    baan->addVoertuig(anAuto);

    Politiecombi* politiecombi = new Politiecombi;
    politiecombi->setPositie(20);
    politiecombi->setBaan(baan2);
    politiecombi->setLengte(10);
    politiecombi->setSnelheid(10);
    baan2->addVoertuig(politiecombi);

    Verkeerslicht* verkeerslicht = new Verkeerslicht;
    verkeerslicht->changeColor();
    verkeerslicht->setPositie(30);
    verkeerslicht->setCycles(20);
    verkeerslicht->setBaan(baan);
    baan->addVerkeerslicht(verkeerslicht);

    Bushalte* bushalte = new Bushalte;
    bushalte->setBaan(baan);
    bushalte->setPositie(30);
    bushalte->setWachttijd(20);
    baan->addBushalte(bushalte);

    pair<Baan*, Baan* > tempBanen;
    tempBanen.first = baan;
    tempBanen.second = baan2;
    pair<int, int> tempPos;
    tempPos.first = 50;
    tempPos.second = 45;
    Kruispunt* kruispunt = new Kruispunt;
    kruispunt->setBanen(tempBanen);
    kruispunt->setPosities(tempPos);
    baan->addKruispunt(kruispunt);
    baan2->addKruispunt(kruispunt);


    verkeerssimulatie.setBanen(banen);
    verkeerssimulatie.setSimulatietijd(1);

    ofstream myfile;
    myfile.open("src/testOutput/BasicExportExpected.txt");
    for (int i = 0; i < 10; i++){
        exporter.exportOn(myfile, verkeerssimulatie);
    }
    myfile.close();

    //delete pointers
    EXPECT_TRUE(FileCompare("src/testOutput/BasicExport.txt","src/testOutput/BasicExportExpected.txt"));
}

TEST_F(projectOutputTests, GrafischeOutput){
    ASSERT_TRUE(DirectoryExists("src"));
    ASSERT_TRUE(DirectoryExists("src/testOutput"));

    // Grafisch
    vector<Baan*> banen;
    Baan* baan = new Baan;
    baan->setNaam("Middelheim");
    baan->setLengte(500);
    banen.push_back(baan);

    Baan* baan2 = new Baan;
    baan2->setNaam("Flora");
    baan2->setLengte(200);
    banen.push_back(baan2);

    Auto* anAuto = new Auto;
    anAuto->setPositie(20);
    anAuto->setBaan(baan);
    anAuto->setLengte(7);
    anAuto->setSnelheid(10);
    baan->addVoertuig(anAuto);

    Politiecombi* politiecombi = new Politiecombi;
    politiecombi->setPositie(20);
    politiecombi->setBaan(baan2);
    politiecombi->setLengte(10);
    politiecombi->setSnelheid(10);
    baan2->addVoertuig(politiecombi);

    Verkeerslicht* verkeerslicht = new Verkeerslicht;
    verkeerslicht->changeColor();
    verkeerslicht->setPositie(30);
    verkeerslicht->setCycles(8);
    verkeerslicht->setBaan(baan);
    baan->addVerkeerslicht(verkeerslicht);

    Bushalte* bushalte = new Bushalte;
    bushalte->setBaan(baan);
    bushalte->setPositie(30);
    bushalte->setWachttijd(20);
    baan->addBushalte(bushalte);

    pair<Baan*, Baan* > tempBanen;
    tempBanen.first = baan;
    tempBanen.second = baan2;
    pair<int, int> tempPos;
    tempPos.first = 50;
    tempPos.second = 45;
    Kruispunt* kruispunt = new Kruispunt;
    kruispunt->setBanen(tempBanen);
    kruispunt->setPosities(tempPos);
    baan->addKruispunt(kruispunt);
    baan2->addKruispunt(kruispunt);


    verkeerssimulatie.setBanen(banen);
    verkeerssimulatie.setSimulatietijd(1);

    ofstream myfile;
    myfile.open("src/testOutput/GrafischExportExpected.txt");
    for (int i = 0; i < 10; i++){
        grafischeExporter.exportOnG(myfile, verkeerssimulatie);
    }
    myfile.close();

    EXPECT_TRUE(FileCompare("src/testOutput/GrafischExport.txt", "src/testOutput/GrafischExportExpected.txt"));
}