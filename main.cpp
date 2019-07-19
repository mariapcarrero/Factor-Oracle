//
// Created by MARIA PAULA CARRERO on 7/17/19.
//
#include "FactorOracle.h"

/*! \file main.cpp
    \brief A file that contains the main functions, which starts all the algorithm.

    One functions: main.
*/

int main() {
    string word;
    cout << "El string es: ";
    cin >> word;
    FactorOracle OracleRelations;
    OracleRelations.FactorOracleStart(OracleRelations,word);
    return 0;
}

