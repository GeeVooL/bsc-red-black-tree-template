/*
* Name: Tests.cpp
* Purpose: Implementation of test methods
* Note: None of methods use assert function and all data has to be compared directly
*       by programmer during program execution (I had no time to implement proper tests)
* @Author: Michał Dziewulski
* @Version: 1.0 03.05.2017
*/

#include "Tests.h"
#include <iomanip>

void Tests::runAllInt()
{
    insertTestInt();
    removeTestInt();
    valuesTestInt();
    minimumTestInt();
    maximumTestInt();
    successorTestInt();
    predecessorTestInt();
    mergeTestInt();
    substituteTestInt();
    copyTestInt();
    operatorsTest1Int();
    operatorsTest2Int();
    compareTestInt();
}

void Tests::insertTestInt()
{
    std::cout << "insertTestInt" << std::endl;
    RBTree<int> treeInt;
    treeInt.insert(6);
    treeInt.insert(4);
    treeInt.insert(1);
    treeInt.insert(5);
    treeInt.insert(3);
    treeInt.insert(8);
    treeInt.insert(9);
    treeInt.insert(7);
    treeInt.printTree(treeInt.getRoot());
    std::cout << std::endl;
}

void Tests::removeTestInt()
{
    std::cout << "removeTestInt" << std::endl;
    RBTree<int> treeInt;
    treeInt.insert(6);
    treeInt.insert(4);
    treeInt.insert(1);
    treeInt.insert(5);
    treeInt.insert(3);
    treeInt.insert(8);
    treeInt.insert(9);
    treeInt.insert(7);
    treeInt.printTree(treeInt.getRoot());
    std::cout << std::endl;
    treeInt.remove(8);
    treeInt.printTree(treeInt.getRoot());
    std::cout << std::endl;
    treeInt.remove(5);
    treeInt.printTree(treeInt.getRoot());
    std::cout << std::endl;
}

void Tests::valuesTestInt()
{
    std::cout << "valuesTestInt" << std::endl;
    RBTree<int> treeInt;
    treeInt.insert(6);
    treeInt.insert(4);
    treeInt.insert(1);
    treeInt.insert(5);
    treeInt.insert(3);
    treeInt.insert(8);
    treeInt.insert(9);
    treeInt.insert(7);
    std::vector<int> val;
    treeInt.getValues(val);
    for(int i = 0; i < treeInt.size(); i++)
    {
        std::cout << val[i] << " ";
    }
    std::cout << std::endl;
}

void Tests::minimumTestInt()
{
    std::cout << "minimumTestInt" << std::endl;
    RBTree<int> treeInt;
    treeInt.insert(6);
    treeInt.insert(4);
    treeInt.insert(1);
    treeInt.insert(5);
    treeInt.insert(3);
    treeInt.insert(8);
    treeInt.insert(9);
    treeInt.insert(7);
    treeInt.printTree(treeInt.getRoot());
    std::cout << std::endl << treeInt.getKey(treeInt.minimum()) << std::endl;
}

void Tests::maximumTestInt()
{
    std::cout << "maximumTestInt" << std::endl;
    RBTree<int> treeInt;
    treeInt.insert(6);
    treeInt.insert(4);
    treeInt.insert(1);
    treeInt.insert(5);
    treeInt.insert(3);
    treeInt.insert(8);
    treeInt.insert(9);
    treeInt.insert(7);
    treeInt.printTree(treeInt.getRoot());
    std::cout << std::endl << treeInt.getKey(treeInt.maximum()) << std::endl;
}

void Tests::successorTestInt()
{
    std::cout << "successorTestInt" << std::endl;
    RBTree<int> treeInt;
    treeInt.insert(6);
    treeInt.insert(4);
    treeInt.insert(1);
    treeInt.insert(5);
    treeInt.insert(3);
    treeInt.insert(8);
    treeInt.insert(9);
    treeInt.insert(7);
    treeInt.printTree(treeInt.getRoot());
    std::cout << std::endl << treeInt.getKey(treeInt.successor(&treeInt.search(treeInt.getRoot(), 6))) << std::endl;
}

void Tests::predecessorTestInt()
{
    std::cout << "predecessorTestInt" << std::endl;
    RBTree<int> treeInt;
    treeInt.insert(6);
    treeInt.insert(4);
    treeInt.insert(1);
    treeInt.insert(5);
    treeInt.insert(3);
    treeInt.insert(8);
    treeInt.insert(9);
    treeInt.insert(7);
    treeInt.printTree(treeInt.getRoot());
    std::cout << std::endl << treeInt.getKey(treeInt.predecessor(&treeInt.search(treeInt.getRoot(), 6))) << std::endl;
}

void Tests::mergeTestInt()
{
    std::cout << "mergeTestInt" << std::endl;
    RBTree<int> treeInt;
    treeInt.insert(6);
    treeInt.insert(4);
    treeInt.insert(1);
    treeInt.insert(5);
    treeInt.insert(3);
    treeInt.insert(8);
    treeInt.insert(9);
    treeInt.insert(7);
    treeInt.printTree(treeInt.getRoot());
    std::cout << std::endl;

    RBTree<int> treeInt2;
    treeInt2.insert(123);
    treeInt2.insert(456);
    treeInt2.printTree(treeInt2.getRoot());
    std::cout << std::endl;

    treeInt.merge(treeInt2);
    treeInt.printTree(treeInt.getRoot());
    std::cout << std::endl;
}

void Tests::substituteTestInt()
{
    std::cout << "substituteTestInt" << std::endl;
    RBTree<int> treeInt;
    treeInt.insert(6);
    treeInt.insert(4);
    treeInt.insert(1);
    treeInt.insert(5);
    treeInt.insert(3);
    treeInt.insert(8);
    treeInt.insert(9);
    treeInt.insert(7);
    treeInt.printTree(treeInt.getRoot());
    std::cout << std::endl;

    RBTree<int> treeInt2;
    treeInt2.insert(3);
    treeInt2.insert(5);
    treeInt2.printTree(treeInt2.getRoot());
    std::cout << std::endl;

    treeInt.subtract(treeInt2);
    treeInt.printTree(treeInt.getRoot());
    std::cout << std::endl;
}

void Tests::copyTestInt()
{
    std::cout << "copyTestInt" << std::endl;
    RBTree<int> treeInt;
    treeInt.insert(6);
    treeInt.insert(4);
    treeInt.insert(1);
    treeInt.insert(5);
    treeInt.insert(3);
    treeInt.insert(8);
    treeInt.insert(9);
    treeInt.insert(7);
    treeInt.printTree(treeInt.getRoot());
    std::cout << std::endl;

    RBTree<int> copyInt(treeInt);
    copyInt.printTree(copyInt.getRoot());
    std::cout << std::endl;
}

void Tests::operatorsTest1Int()
{
    std::cout << "operatorsTest1Int" << std::endl;
    RBTree<int> treeInt;
    treeInt.insert(6);
    treeInt.insert(4);
    treeInt.insert(1);
    treeInt.insert(5);
    treeInt.insert(3);
    treeInt.insert(8);
    treeInt.insert(9);
    treeInt.insert(7);
    treeInt.printTree(treeInt.getRoot());
    std::cout << std::endl;

    RBTree<int> treeInt2;
    treeInt2.insert(123);
    treeInt2.insert(456);
    treeInt2.printTree(treeInt2.getRoot());
    std::cout << std::endl;

    treeInt += treeInt2;
    treeInt.printTree(treeInt.getRoot());
    std::cout << std::endl;

    RBTree<int> treeInt3;
    treeInt3.insert(3);
    treeInt3.insert(8);
    treeInt3.printTree(treeInt3.getRoot());
    std::cout << std::endl;

    treeInt -= treeInt3;
    treeInt.printTree(treeInt.getRoot());
    std::cout << std::endl;
}

void Tests::operatorsTest2Int()
{
    std::cout << "operatorsTest2Int" << std::endl;
    RBTree<int> treeInt;
    treeInt.insert(6);
    treeInt.insert(4);
    treeInt.insert(1);
    treeInt.insert(5);
    treeInt.insert(3);
    treeInt.insert(8);
    treeInt.insert(9);
    treeInt.insert(7);
    treeInt.printTree(treeInt.getRoot());
    std::cout << std::endl;

    RBTree<int> treeInt2;
    treeInt2 = treeInt;
    treeInt2.printTree(treeInt2.getRoot());
    std::cout << std::endl;

    RBTree<int> treeInt3;
    treeInt3.insert(1);
    treeInt3.insert(11);
    treeInt3.printTree(treeInt3.getRoot());
    std::cout << std::endl;

    RBTree<int> treeInt4;
    treeInt4 = treeInt + treeInt3;
    treeInt4.printTree(treeInt4.getRoot());
    std::cout << std::endl;

    RBTree<int> treeInt5;
    treeInt5.insert(3);
    treeInt5.insert(8);
    treeInt5.printTree(treeInt5.getRoot());
    std::cout << std::endl;

    RBTree<int> treeInt6;// = treeInt - treeInt5;;
    treeInt6 = treeInt - treeInt5;
    treeInt6.printTree(treeInt6.getRoot());
    std::cout << std::endl;

    treeInt.printTree(treeInt.getRoot());
    std::cout << std::endl;
}

void Tests::compareTestInt()
{
    std::cout << "compareTestInt" << std::endl;
    RBTree<int> treeInt;
    treeInt.insert(6);
    treeInt.insert(4);
    treeInt.insert(1);
    treeInt.insert(5);
    treeInt.insert(3);
    treeInt.insert(8);
    treeInt.insert(9);
    treeInt.insert(7);
    treeInt.printTree(treeInt.getRoot());
    std::cout << std::endl;

    RBTree<int> treeInt2;
    treeInt2 = treeInt;
    treeInt2.printTree(treeInt2.getRoot());
    std::cout << std::endl;

    std::cout << (treeInt == treeInt2);
    std::cout << std::endl;

    RBTree<int> treeInt3;
    treeInt3.insert(1);
    treeInt3.insert(11);
    treeInt3.printTree(treeInt3.getRoot());
    std::cout << std::endl;

    std::cout << (treeInt3 != treeInt2);
    std::cout << std::endl;
}

void Tests::runAllFloat()
{
    insertTestFloat();
    removeTestFloat();
    valuesTestFloat();
    minimumTestFloat();
    maximumTestFloat();
    successorTestFloat();
    predecessorTestFloat();
    mergeTestFloat();
    substituteTestFloat();
    copyTestFloat();
    operatorsTest1Float();
    operatorsTest2Float();
    compareTestFloat();
}

void Tests::insertTestFloat()
{
    std::cout << "insertTestFloat" << std::endl;
    RBTree<float> treeFloat;
    treeFloat.insert(6);
    treeFloat.insert(4);
    treeFloat.insert(1);
    treeFloat.insert(5);
    treeFloat.insert(3);
    treeFloat.insert(8);
    treeFloat.insert(9);
    treeFloat.insert(7);
    treeFloat.printTree(treeFloat.getRoot());
    std::cout << std::endl;
}

void Tests::removeTestFloat()
{
    std::cout << "removeTestFloat" << std::endl;
    RBTree<float> treeFloat;
    treeFloat.insert(6);
    treeFloat.insert(4);
    treeFloat.insert(1);
    treeFloat.insert(5);
    treeFloat.insert(3);
    treeFloat.insert(8);
    treeFloat.insert(9);
    treeFloat.insert(7);
    treeFloat.printTree(treeFloat.getRoot());
    std::cout << std::endl;
    treeFloat.remove(8);
    treeFloat.printTree(treeFloat.getRoot());
    std::cout << std::endl;
    treeFloat.remove(5);
    treeFloat.printTree(treeFloat.getRoot());
    std::cout << std::endl;
}

void Tests::valuesTestFloat()
{
    std::cout << "valuesTestFloat" << std::endl;
    RBTree<float> treeFloat;
    treeFloat.insert(6);
    treeFloat.insert(4);
    treeFloat.insert(1);
    treeFloat.insert(5);
    treeFloat.insert(3);
    treeFloat.insert(8);
    treeFloat.insert(9);
    treeFloat.insert(7);
    std::vector<float> val;
    treeFloat.getValues(val);
    for(int i = 0; i < treeFloat.size(); i++)
    {
        std::cout << val[i] << " ";
    }
    std::cout << std::endl;
}

void Tests::minimumTestFloat()
{
    std::cout << "minimumTestFloat" << std::endl;
    RBTree<float> treeFloat;
    treeFloat.insert(6);
    treeFloat.insert(4);
    treeFloat.insert(1);
    treeFloat.insert(5);
    treeFloat.insert(3);
    treeFloat.insert(8);
    treeFloat.insert(9);
    treeFloat.insert(7);
    treeFloat.printTree(treeFloat.getRoot());
    std::cout << std::endl << treeFloat.getKey(treeFloat.minimum()) << std::endl;
}

void Tests::maximumTestFloat()
{
    std::cout << "maximumTestFloat" << std::endl;
    RBTree<float> treeFloat;
    treeFloat.insert(6);
    treeFloat.insert(4);
    treeFloat.insert(1);
    treeFloat.insert(5);
    treeFloat.insert(3);
    treeFloat.insert(8);
    treeFloat.insert(9);
    treeFloat.insert(7);
    treeFloat.printTree(treeFloat.getRoot());
    std::cout << std::endl << treeFloat.getKey(treeFloat.maximum()) << std::endl;
}

void Tests::successorTestFloat()
{
    std::cout << "successorTestFloat" << std::endl;
    RBTree<float> treeFloat;
    treeFloat.insert(6);
    treeFloat.insert(4);
    treeFloat.insert(1);
    treeFloat.insert(5);
    treeFloat.insert(3);
    treeFloat.insert(8);
    treeFloat.insert(9);
    treeFloat.insert(7);
    treeFloat.printTree(treeFloat.getRoot());
    std::cout << std::endl << treeFloat.getKey(treeFloat.successor(&treeFloat.search(treeFloat.getRoot(), 6))) << std::endl;
}

void Tests::predecessorTestFloat()
{
    std::cout << "predecessorTestFloat" << std::endl;
    RBTree<float> treeFloat;
    treeFloat.insert(6);
    treeFloat.insert(4);
    treeFloat.insert(1);
    treeFloat.insert(5);
    treeFloat.insert(3);
    treeFloat.insert(8);
    treeFloat.insert(9);
    treeFloat.insert(7);
    treeFloat.printTree(treeFloat.getRoot());
    std::cout << std::endl << treeFloat.getKey(treeFloat.predecessor(&treeFloat.search(treeFloat.getRoot(), 6))) << std::endl;
}

void Tests::mergeTestFloat()
{
    std::cout << "mergeTestFloat" << std::endl;
    RBTree<float> treeFloat;
    treeFloat.insert(6);
    treeFloat.insert(4);
    treeFloat.insert(1);
    treeFloat.insert(5);
    treeFloat.insert(3);
    treeFloat.insert(8);
    treeFloat.insert(9);
    treeFloat.insert(7);
    treeFloat.printTree(treeFloat.getRoot());
    std::cout << std::endl;

    RBTree<float> treeFloat2;
    treeFloat2.insert(123);
    treeFloat2.insert(456);
    treeFloat2.printTree(treeFloat2.getRoot());
    std::cout << std::endl;

    treeFloat.merge(treeFloat2);
    treeFloat.printTree(treeFloat.getRoot());
    std::cout << std::endl;
}

void Tests::substituteTestFloat()
{
    std::cout << "substituteTestFloat" << std::endl;
    RBTree<float> treeFloat;
    treeFloat.insert(6);
    treeFloat.insert(4);
    treeFloat.insert(1);
    treeFloat.insert(5);
    treeFloat.insert(3);
    treeFloat.insert(8);
    treeFloat.insert(9);
    treeFloat.insert(7);
    treeFloat.printTree(treeFloat.getRoot());
    std::cout << std::endl;

    RBTree<float> treeFloat2;
    treeFloat2.insert(3);
    treeFloat2.insert(5);
    treeFloat2.printTree(treeFloat2.getRoot());
    std::cout << std::endl;

    treeFloat.subtract(treeFloat2);
    treeFloat.printTree(treeFloat.getRoot());
    std::cout << std::endl;
}

void Tests::copyTestFloat()
{
    std::cout << "copyTestFloat" << std::endl;
    RBTree<float> treeFloat;
    treeFloat.insert(6);
    treeFloat.insert(4);
    treeFloat.insert(1);
    treeFloat.insert(5);
    treeFloat.insert(3);
    treeFloat.insert(8);
    treeFloat.insert(9);
    treeFloat.insert(7);
    treeFloat.printTree(treeFloat.getRoot());
    std::cout << std::endl;

    RBTree<float> copyFloat(treeFloat);
    copyFloat.printTree(copyFloat.getRoot());
    std::cout << std::endl;
}

void Tests::operatorsTest1Float()
{
    std::cout << "operatorsTest1Float" << std::endl;
    RBTree<float> treeFloat;
    treeFloat.insert(6);
    treeFloat.insert(4);
    treeFloat.insert(1);
    treeFloat.insert(5);
    treeFloat.insert(3);
    treeFloat.insert(8);
    treeFloat.insert(9);
    treeFloat.insert(7);
    treeFloat.printTree(treeFloat.getRoot());
    std::cout << std::endl;

    RBTree<float> treeFloat2;
    treeFloat2.insert(123);
    treeFloat2.insert(456);
    treeFloat2.printTree(treeFloat2.getRoot());
    std::cout << std::endl;

    treeFloat += treeFloat2;
    treeFloat.printTree(treeFloat.getRoot());
    std::cout << std::endl;

    RBTree<float> treeFloat3;
    treeFloat3.insert(3);
    treeFloat3.insert(8);
    treeFloat3.printTree(treeFloat3.getRoot());
    std::cout << std::endl;

    treeFloat -= treeFloat3;
    treeFloat.printTree(treeFloat.getRoot());
    std::cout << std::endl;
}

void Tests::operatorsTest2Float()
{
    std::cout << "operatorsTest2Float" << std::endl;
    RBTree<float> treeFloat;
    treeFloat.insert(6);
    treeFloat.insert(4);
    treeFloat.insert(1);
    treeFloat.insert(5);
    treeFloat.insert(3);
    treeFloat.insert(8);
    treeFloat.insert(9);
    treeFloat.insert(7);
    treeFloat.printTree(treeFloat.getRoot());
    std::cout << std::endl;

    RBTree<float> treeFloat2;
    treeFloat2 = treeFloat;
    treeFloat2.printTree(treeFloat2.getRoot());
    std::cout << std::endl;

    RBTree<float> treeFloat3;
    treeFloat3.insert(1);
    treeFloat3.insert(11);
    treeFloat3.printTree(treeFloat3.getRoot());
    std::cout << std::endl;

    RBTree<float> treeFloat4;
    treeFloat4 = treeFloat + treeFloat3;
    treeFloat4.printTree(treeFloat4.getRoot());
    std::cout << std::endl;

    RBTree<float> treeFloat5;
    treeFloat5.insert(3);
    treeFloat5.insert(8);
    treeFloat5.printTree(treeFloat5.getRoot());
    std::cout << std::endl;

    RBTree<float> treeFloat6;// = treeFloat - treeFloat5;;
    treeFloat6 = treeFloat - treeFloat5;
    treeFloat6.printTree(treeFloat6.getRoot());
    std::cout << std::endl;

    treeFloat.printTree(treeFloat.getRoot());
    std::cout << std::endl;
}

void Tests::compareTestFloat()
{
    std::cout << "compareTestFloat" << std::endl;
    RBTree<float> treeFloat;
    treeFloat.insert(6);
    treeFloat.insert(4);
    treeFloat.insert(1);
    treeFloat.insert(5);
    treeFloat.insert(3);
    treeFloat.insert(8);
    treeFloat.insert(9);
    treeFloat.insert(7);
    treeFloat.printTree(treeFloat.getRoot());
    std::cout << std::endl;

    RBTree<float> treeFloat2;
    treeFloat2 = treeFloat;
    treeFloat2.printTree(treeFloat2.getRoot());
    std::cout << std::endl;

    std::cout << (treeFloat == treeFloat2);
    std::cout << std::endl;

    RBTree<float> treeFloat3;
    treeFloat3.insert(1);
    treeFloat3.insert(11);
    treeFloat3.printTree(treeFloat3.getRoot());
    std::cout << std::endl;

    std::cout << (treeFloat3 != treeFloat2);
    std::cout << std::endl;
}

