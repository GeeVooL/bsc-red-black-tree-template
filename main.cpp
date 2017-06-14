/*
* Name: main.cpp
* Purpose: Source code of main function, used to run tests
* @Author: Michał Dziewulski
* @Version: 1.0 03.05.2017
*/

#include "Tests.h"

int main()
{
    Tests::runAllInt();
    Tests::runAllFloat();
    return 0;
}