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
};