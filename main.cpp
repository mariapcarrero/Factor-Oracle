//
// Created by MARIA PAULA CARRERO on 7/17/19.
//

#include "FactorOracle.h"
/*! \file main.cpp
    \brief A file that contains the main functions, which starts all the algorithm.

    One functions: main.
*/


int main() {
    FactorOracle<int> oracle_relations;
    oracle_relations.FactorOracleStart({1});
   // oracle_relations.FactorOracleStart({1,2,2,3,1,2,3,4,1,2,3});
    oracle_relations.CallGenerate(10,0.6);
    return 0;
}
