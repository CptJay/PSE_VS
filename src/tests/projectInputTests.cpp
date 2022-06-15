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
    ASSERT_TRUE(DirectoryExists("../testInput"));

    ofstream myfile;

    myfile.open("../testInput/zzzInput.xml");
    myfile << "<?xml version =\"1.0\" ?>" << endl
        << "<Verkeersimulatie>" << endl;


}
