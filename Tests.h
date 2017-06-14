/*
* Name: Tests.cpp
* Purpose: Header of unit test class for RBTree.h
* Note: None of methods use assert function and all data has to be compared directly
*       by programmer during program execution (I had no time to implement proper tests)
* @Author: Michał Dziewulski
* @Version: 1.0 03.05.2017
*/

#ifndef TESTS_H
#define TESTS_H

#include <string>
#include "RBTree.h"


class Tests
{
private:
    Tests() { }
public:
    static void runAllInt();
    static void insertTestInt();
    static void removeTestInt();
    static void valuesTestInt();
    static void minimumTestInt();
    static void maximumTestInt();
    static void successorTestInt();
    static void predecessorTestInt();
    static void mergeTestInt();
    static void substituteTestInt();
    static void copyTestInt();
    static void operatorsTest1Int();
    static void operatorsTest2Int();
    static void compareTestInt();

    static void runAllFloat();
    static void insertTestFloat();
    static void removeTestFloat();
    static void valuesTestFloat();
    static void minimumTestFloat();
    static void maximumTestFloat();
    static void successorTestFloat();
    static void predecessorTestFloat();
    static void mergeTestFloat();
    static void substituteTestFloat();
    static void copyTestFloat();
    static void operatorsTest1Float();
    static void operatorsTest2Float();
    static void compareTestFloat();
};

#endif