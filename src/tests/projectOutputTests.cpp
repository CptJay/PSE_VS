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
    EXPECT_TRUE(FileCompare("src/testOutput/wf1", "src/testOutput/wf2"));
    EXPECT_TRUE(FileCompare("src/testOutput/wf2", "src/testOutput/wf1"));

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
