//
// Created by Jay on 15/05/2022.
//

#ifndef UNTITLED_PROJECTUTILS_H
#define UNTITLED_PROJECTUTILS_H


#include <iostream>

bool DirectoryExists(const std::string& dirname);

bool FileExists(const std::string& dirname);

bool FileIsEmpty(const std::string& filename);

bool FileCompare(const std::string& leftFileName, const std::string& rightFileName);

std::string ToString( int x );

#endif //UNTITLED_PROJECTUTILS_H
