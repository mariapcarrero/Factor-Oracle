//
// Created by MARIA PAULA CARRERO on 7/17/19.
//

#include "FactorOracle.h"
#include "catch.hpp"
/*! \file main.cpp
    \brief A file that contains the main functions, which starts all the algorithm.

    One functions: main.
*/


int main() {
    string word;
    cout << "The string is: ";
    cin >> word;
    FactorOracle oracle_relations;
    oracle_relations.FactorOracleStart(word);
    return 0;
}
