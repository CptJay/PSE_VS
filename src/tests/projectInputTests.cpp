//
// Created by Jay on 15/05/2022.
//

#include <iostream>
#include <fstream>
#include <gtest/gtest.h>

using namespace std;

#include "../Verkeerssimulatie.h"
#include "../projectUtils.h"
#include "../projectImporter.h"
#include "../projectExporter.h"


class projectInputTests : public ::testing::Test{
protected:
    friend class Verkeerssimulatie;
    virtual void SetUp(){
    }

    virtual void TearDown(){
    }

    Verkeerssimulatie verkeerssimulatie;
};

TEST_F(projectInputTests, HappyDaySimulatie){
    ASSERT_TRUE(DirectoryExists("src"));
    ASSERT_TRUE(DirectoryExists("src/testInput"));

    ofstream myfile;
    SuccessEnum importResult;

    myfile.open("src/testInput/zzzInput.xml");
    myfile << "<?xml version =\"1.0\" ?>" << endl
        << "<VERKEERSSIMULATIE>" << endl
        << "\t<BAAN>" << endl
        << "\t\t<naam>Middelheimlaan</naam>" << endl
        << "\t\t<lengte>500</lengte>" << endl
        << "\t</BAAN>" << endl
        << "\t<BAAN>" << endl
        << "\t\t<naam>Floralienlaan</naam>" << endl
        << "\t\t<lengte>750</lengte>" << endl
        << "\t</BAAN>" << endl
        << "\t<BUSHALTE>" << endl
        << "\t\t<baan>Middelheimlaan</baan>" << endl
        << "\t\t<positie>250</positie>" << endl
        << "\t\t<wachttijd>20</wachttijd>" << endl
        << "\t</BUSHALTE>" << endl
        << "\t<VERKEERSLICHT>" << endl
        << "\t\t<baan>Middelheimlaan</baan>" << endl
        << "\t\t<positie>400</positie>" << endl
        << "\t\t<cyclus>20</cyclus>" << endl
        << "\t</VERKEERSLICHT>" << endl
        << "\t<VOERTUIG>" << endl
        << "\t\t<baan>Middelheimlaan</baan>" << endl
        << "\t\t<positie>20</positie>" << endl
        << "\t\t<type>bus</type>" << endl
        << "\t</VOERTUIG>" << endl
        << "</VERKEERSSIMULATIE>" << endl;


    myfile.close();
    myfile.open("src/testInput/zzzError.txt");

    importResult = projectImporter::importVerkeerssimulatie("src/testInput/zzzInput.xml", myfile, verkeerssimulatie);
    myfile.close();
    EXPECT_TRUE(importResult == Succes);
    EXPECT_TRUE(FileIsEmpty("src/testInput/zzzError.txt"));

    EXPECT_EQ(verkeerssimulatie.getBanen(),verkeerssimulatie.getBanen());
    EXPECT_EQ(2, (int)verkeerssimulatie.getBanen().size());
    EXPECT_EQ(1, (int)verkeerssimulatie.getBanen()[0]->getVoertuigen().size());
    EXPECT_EQ(1, (int)verkeerssimulatie.getBanen()[0]->getBushaltes().size());
    EXPECT_EQ(1, (int)verkeerssimulatie.getBanen()[0]->getVerkeerslichten().size());
}

TEST_F(projectInputTests, InputIllegalSim){
    ASSERT_TRUE(DirectoryExists("src"));
    ASSERT_TRUE(DirectoryExists("src/testInput"));
    ASSERT_TRUE(DirectoryExists("src/testOutput"));

    ofstream myfile;
    SuccessEnum importResult;
    int fileCounter = 1;
    string fileName = "src/testInput/IllegalInfo" + ToString(fileCounter) + ".xml";
    string writeOut = "src/testOutput/IllegalInfo" + ToString(fileCounter) + ".txt";
    string errorFileName;


    while (FileExists(fileName)){
        myfile.open(writeOut.c_str());
        importResult = projectImporter::importVerkeerssimulatie(fileName.c_str(), myfile, verkeerssimulatie);
        myfile.close();
        EXPECT_EQ(PartialImport, importResult);
        errorFileName = "src/testInput/IllegalInfo" + ToString(fileCounter) + ".txt";
        EXPECT_TRUE(FileCompare(writeOut, errorFileName));

        fileCounter += 1;
        fileName = "src/testInput/IllegalInfo" + ToString(fileCounter) + ".xml";
        writeOut = "src/testOutput/IllegalInfo" + ToString(fileCounter) + ".txt";
    }
    EXPECT_TRUE(fileCounter == 9);
}

TEST_F(projectInputTests, LegalInfoSim){
    ASSERT_TRUE(DirectoryExists("src"));
    ASSERT_TRUE(DirectoryExists("src/testInput"));
    ASSERT_TRUE(DirectoryExists("src/testOutput"));

    ofstream myfile;
    SuccessEnum importResult;
    int fileCounter = 1;
    string fileName = "src/testInput/LegalInfo" + ToString(fileCounter) + ".xml";
    string writeOut = "src/testOutput/LegalInfo" + ToString(fileCounter) + ".txt";

    while(FileExists(fileName)){
        myfile.open(writeOut.c_str());
        importResult = projectImporter::importVerkeerssimulatie(fileName.c_str(), myfile, verkeerssimulatie);
        myfile.close();
        EXPECT_TRUE(importResult == Succes);
        EXPECT_TRUE(FileIsEmpty(writeOut));

        fileCounter += 1;
        fileName = "src/testInput/LegalInfo" + ToString(fileCounter) + ".xml";
        writeOut = "src/testOutput/LegalInfo" + ToString(fileCounter) + ".txt";
    }


}

TEST_F(projectInputTests, XMLSyntaxError){
    ASSERT_TRUE(DirectoryExists("src"));
    ASSERT_TRUE(DirectoryExists("src/testInput"));
    ASSERT_TRUE(DirectoryExists("src/testOutput"));

    ofstream myfile;
    SuccessEnum importResult;
    int fileCounter = 1;
    string fileName = "src/testInput/XMLSyntaxError" + ToString(fileCounter) + ".xml";
    string writeOut = "src/testOutput/XMLSyntaxError" + ToString(fileCounter) + ".txt";
    string errorFileName;

    while (FileExists(fileName)){
        myfile.open(writeOut.c_str());
        importResult = projectImporter::importVerkeerssimulatie(fileName.c_str(), myfile, verkeerssimulatie);
        myfile.close();
        EXPECT_EQ(ImportAborted, importResult);
        errorFileName = "src/testInput/XMLSyntaxError" + ToString(fileCounter) + ".txt";
        EXPECT_TRUE(FileCompare(writeOut, errorFileName));

        fileCounter += 1;
        fileName = "src/testInput/XMLSyntaxError" + ToString(fileCounter) + ".xml";
        writeOut = "src/testOutput/XMLSyntaxError" + ToString(fileCounter) + ".txt";
    }
}

TEST_F(projectInputTests, Kruispunt){
    ASSERT_TRUE(DirectoryExists("src"));
    ASSERT_TRUE(DirectoryExists("src/testInput"));
    ASSERT_TRUE(DirectoryExists("src/testOutput"));

    ofstream myfile;
    SuccessEnum importResult;
    string fileName = "src/testInput/LegalInfo5.xml";
    string writeOut = "src/testOutput/LegalInfo5.txt";

    myfile.open("src/testInput/LegalInfo5.txt");
    importResult = projectImporter::importVerkeerssimulatie(fileName.c_str(), myfile, verkeerssimulatie);
    myfile.close();

    ASSERT_EQ(Succes, importResult);

}
