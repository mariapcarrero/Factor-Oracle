//
// Created by MARIA PAULA CARRERO on 7/16/19.
//
#include <iostream>
#include <new>
#include <string>
#include <vector>
#include <variant>
#include <random>
#include <algorithm>


#ifndef FACTORORACLESTRING_FACTORORACLE_H
#define FACTORORACLESTRING_FACTORORACLE_H

#define R 10
#define RAND_MAX 0x7fffffff

/*! \file FactorOracle.h
    \brief A file that contains the definitions of the classes needed for the functions.

    Three main classes: FactorOracle, State and SingleTransition.
*/


using namespace std;
/** The class SingleTransition denotes the elements that belong to each transition
  */
class SingleTransition
{
public:
    int first_state; /**< denotes the first state of the transition */
    int last_state; /**< denotes the last state of the transition */
    char symbol; /**< denotes the symbol (letter) of the transition */
};

/** The class State denotes the elements that belong to each state
 * state denotes de number of the state
 * vector <SingleTransition> transition is the vector where all forward links of the state are defined
 * suffixTransition denotes which is the suffix link of this state
 * lrs is the longest repeated subsequence of this state
 * */
class State
{
public:
    int state; /*!< denotes the number of the state */
    vector <SingleTransition> transition; /*!< denotes the number of the state */
    int suffixTransition;
    int lrs = 0;
    void singleTransitionResize(){
        transition.resize(R);
    }
};


class FactorOracle
{
public:
    vector <State> states; /**< vector of all the states */
    void AddLetter(FactorOracle& States, vector <vector<int>> &T, int i, string word);
    int LengthCommonSuffix(FactorOracle& States, int phi_one, int phi_two);
    int FindBetter(FactorOracle& States, vector <vector<int>> &T, int i, char alpha, string word);
    string FOGenerate(FactorOracle& States, int i, string v, float q);
    void FactorOracleStart(FactorOracle& OracleRelations,string word);

};



#endif //FACTORORACLESTRING_FACTORORACLE_H
