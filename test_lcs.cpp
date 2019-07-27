//
// Created by MARIA PAULA CARRERO on 7/23/19.
//

#define CATCH_CONFIG_MAIN
#include "catch.h"
#include "FactorOracle.h"


int LengthCommonSuffix(FactorOracle& all_states_, int phi_one, int phi_two)
{
    if (phi_two == all_states_.states_[phi_one].suffix_transition_)
        return all_states_.states_[phi_one].lrs_;
    else
    {
        while (all_states_.states_[phi_one].suffix_transition_!= all_states_.states_[phi_two].suffix_transition_)
            phi_two = all_states_.states_[phi_two].suffix_transition_;
    }
    if (all_states_.states_[phi_one].lrs_ <= all_states_.states_[phi_two].lrs_)
        return all_states_.states_[phi_one].lrs_;
    else return all_states_.states_[phi_two].lrs_;
}

TEST_CASE( "LengthCommonSuffix 4 0 == 0 (pass)", "[classic]") {
    FactorOracle oracle_relations;
    string word = "abbcabcdabc";
    oracle_relations.FactorOracleStart(oracle_relations,"abbcabcdabc");
    REQUIRE(LengthCommonSuffix(oracle_relations, 4,0) == 0 );
}

TEST_CASE( "LengthCommonSuffix 4 0 == 2 (fail)", "[classic]") {
    FactorOracle oracle_relations;
    string word = "abbcabcdabc";
    oracle_relations.FactorOracleStart(oracle_relations,"abbcabcdabc");
    REQUIRE(LengthCommonSuffix(oracle_relations, 4,0) == 2 );
}

TEST_CASE( "LengthCommonSuffix 5 1 == 1 (pass)", "[classic]") {
    FactorOracle oracle_relations;
    string word = "abbcabcdabc";
    oracle_relations.FactorOracleStart(oracle_relations,"abbcabcdabc");
    REQUIRE(LengthCommonSuffix(oracle_relations, 5,1) == 1 );
}


TEST_CASE( "LengthCommonSuffix 6 3 == 1 (pass)", "[classic]") {
    FactorOracle oracle_relations;
    string word = "abbcabcdabc";
    oracle_relations.FactorOracleStart(oracle_relations,"abbcabcdabc");
    REQUIRE(LengthCommonSuffix(oracle_relations,6,3) == 1 );
}

TEST_CASE( "LengthCommonSuffix 9 1 == 1 (pass)", "[classic]") {
    FactorOracle oracle_relations;
    string word = "abbcabcdabc";
    oracle_relations.FactorOracleStart(oracle_relations,"abbcabcdabc");
    REQUIRE(LengthCommonSuffix(oracle_relations, 9,1) == 1 );
}

TEST_CASE( "LengthCommonSuffix 10 3 == 1 (pass)", "[classic]") {
    FactorOracle oracle_relations;
    string word = "abbcabcdabc";
    oracle_relations.FactorOracleStart(oracle_relations,"abbcabcdabc");
    REQUIRE(LengthCommonSuffix(oracle_relations, 10,3) == 1 );
}

TEST_CASE( "LengthCommonSuffix 8 0 == 0 (pass)", "[classic]") {
    FactorOracle oracle_relations;
    string word = "abbcabcdabc";
    oracle_relations.FactorOracleStart(oracle_relations,"abbcabcdabc");
    REQUIRE(LengthCommonSuffix(oracle_relations, 8,0) == 0 );
}


/*
unsigned int Factorial( unsigned int number ) {
    return number <= 1 ? number : Factorial(number-1)*number;
}
     REQUIRE(LengthCommonSuffix(oracle_relations, 9,1) == 1);
    REQUIRE(LengthCommonSuffix(oracle_relations, 10,3) == 0);
    REQUIRE(LengthCommonSuffix(oracle_relations, 6,3) == 1);

TEST_CASE( "Factorials are computed", "[factorial]" ) {
    REQUIRE( Factorial(0) == 1 );
    REQUIRE( Factorial(1) == 1 );
    REQUIRE( Factorial(2) == 2 );
    REQUIRE( Factorial(3) == 6 );
    REQUIRE( Factorial(10) == 3628800 );
}
*/