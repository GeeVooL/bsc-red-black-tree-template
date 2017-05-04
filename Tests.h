/*
* Name: tests.h
* Purpose: Header file of a tests class for RBTRee class
* @Author: Michał Dziewulski
* @Version: 1.0 30.04.2017
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