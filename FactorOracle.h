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
    \brief A file that contains the definitions of the classes needed for the creation of a Factor Oracle.

    Three main classes: FactorOracle, State and SingleTransition.
*/
/*! \fn void AddLetter(FactorOracle& States, vector <vector<int>> &T, int i, string word)
    \brief Adds new transitions from state i-1 to state i.
    \param States A reference to a FactorOracle class.
    \param T A vector where each position has all the suffix transitions directed to each state.
    \param i The integer of the current state.
    \param word The input string.

*/
/*! \fn int LengthCommonSuffix(FactorOracle& States, int phi_one, int phi_two)
    \brief Finds the length of a common suffix ending at the position phi_one and phi_two by traversing the suffix links.
    \param States A reference to a FactorOracle class.
    \param phi_one The position of the state.
    \param phi_two The position of the state.
*/
/*! \fn int FindBetter(FactorOracle& States, vector <vector<int>> &T, int i, char alpha, string word)
    \brief Writes \a count bytes from \a buf to the filedescriptor \a fd.
    \param States a reference to a FactorOracle class.
    \param T A vector where each position has all the suffix transitions directed to each state.
    \param i The integer of the current state.
    \param alpha The transition symbol.
    \param word The input string.
    \return A better state
*/
/*! \fn string FOGenerate(FactorOracle& States, int i, string v, float q)
    \brief Generates the Factor Oracle improvisation.
    \param States A reference to a FactorOracle class.
    \param i The integer of the current state.
    \param v The sequence v.
    \param q A float argument.
    \return The factor oracle improvisation
*/
/*! \fn void FactorOracleStart(FactorOracle& OracleRelations,string word)
    \brief Starts the process of the Factor Oracle generation .
    \param OracleRelations A reference to a FactorOracle class.
    \param word The input string.
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
