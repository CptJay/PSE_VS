//
// Created by User on 23/03/2022.
//

#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <gtest/gtest.h>

using namespace std;

#include "../Verkeerssimulatie.h"
#include "projectDomainTests.cpp"
#include "projectInputTests.cpp"
#include "projectOutputTests.cpp"

int main(int arg, char **argv){
    ::testing::InitGoogleTest(&arg, argv);
    return RUN_ALL_TESTS();
}