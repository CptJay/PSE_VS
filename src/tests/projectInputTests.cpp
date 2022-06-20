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


class projectInputTests : public ::testing::Test{
protected:
    friend class Verkeerssimulatie;
    virtual void SetUp(){
    }

    virtual void TearDown(){
    }

    Verkeerssimulatie verkeerssimulatie;
};

TEST_F(projectInputTests, InputHappyDay){
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
        << "\t\t<type>auto</type>" << endl
        << "\t</VOERTUIG>" << endl
        << "</VERKEERSSIMULATIE>" << endl;


    myfile.close();
    myfile.open("src/testInput/zzzError.txt");

    importResult = projectImporter::importVerkeerssimulatie("src/testInput/zzzInput.xml", myfile, verkeerssimulatie);
    myfile.close();
    EXPECT_TRUE(importResult == Succes);
    EXPECT_TRUE(FileIsEmpty("src/testInput/zzzError.txt"));
}
