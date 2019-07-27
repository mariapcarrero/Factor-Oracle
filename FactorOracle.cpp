#include "FactorOracle.h"

/*! \file FactorOracle.cpp
    \brief A file that contains the functions needed for the creation of a Factor Oracle.

    Five main functions: FactorOracleStart, AddLetter, LengthCommonSuffix, FindBetter and FOGenerate.
*/


int phi, k, fo_iter;

string FactorOracle::FOGenerate(FactorOracle& all_states_, int& i, string v, float q)
{
    //! A normal member taking four arguments and returning a string value.
    /*!
      \param all_states_ a reference to a FactorOracle class.
      \param i an integer argument.
      \param v a string argument.
      \param q a float argument.
      \return The factor oracle improvisation
    */
    std::random_device rd;  ///Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); ///Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<> dis(0.0, 1.0);
    float u = dis(gen);
    /// float u = (float)rand() / RAND_MAX;
    if (u < q)
    {
        i = i + 1;
        char w = all_states_.states_[i].transition_[0].symbol_;
        string s(1,w);
        v = v + s;
    }
    else
    {
        int lenSuffix = all_states_.states_[all_states_.states_[i].suffix_transition_].transition_.size() - 1;
        std::random_device rd;  ///Will be used to obtain a seed for the random number engine
        std::mt19937 gen(rd()); ///Standard mersenne_twister_engine seeded with rd()
        std::uniform_int_distribution<> dis_int(0, lenSuffix);
        int rand_alpha = dis_int(gen);
        char alpha = all_states_.states_[all_states_.states_[i].suffix_transition_].transition_[rand_alpha].symbol_;
        i = all_states_.states_[all_states_.states_[i].suffix_transition_].transition_[rand_alpha].last_state_;
        v = v + alpha;
    }
    return v;
}


int FactorOracle::FindBetter(FactorOracle& all_states_, vector <vector<int> > &T, int i, char alpha, string word)
{
    //! A normal member taking five arguments and returning an integer value.
    /*!
      \param all_states_ a reference to a FactorOracle class.
      \param T a reference to a vector of vector of integers.
      \param i an integer argument.
      \param alpha a char argument.
      \param word a string argument.
      \return A better state
    */

    int len_t = T[all_states_.states_[i].suffix_transition_].size();
    int statei = all_states_.states_[i].suffix_transition_;
    if (len_t == 0) return 0;
    sort(T[statei].begin(), T[statei].end());
    for (int j = 0; j < len_t; j++)
    {
        if (all_states_.states_[T[all_states_.states_[i].suffix_transition_][j]].lrs_ == all_states_.states_[i].lrs_ && word[T[all_states_.states_[i].suffix_transition_][j] - all_states_.states_[i].lrs_ - 1] == alpha)
        {
            int out = T[all_states_.states_[i].suffix_transition_][j];
            return out;
        }

    }
    return 0;
}
int FactorOracle::LengthCommonSuffix(FactorOracle& all_states_, int phi_one, int phi_two)
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
void FactorOracle::AddLetter(FactorOracle &all_states_, vector<vector<int> > &T, int i, string word)
{
    //! A normal member taking four arguments and returning no value.
    /*!
      \param all_states_ a reference to a FactorOracle class.
      \param T a reference to a vector of vector of integers.
      \param i an integer argument.
      \param word a string argument.
    */
    char alpha = word[i-1];
    all_states_.states_[i-1].state_ = i-1;
    SingleTransition transition_i;
    transition_i.first_state_ = i-1;
    transition_i.last_state_ = i;
    transition_i.symbol_ = alpha;
    int statemplusone = i;
    all_states_.states_[i-1].transition_.push_back(transition_i); /*!< delta(i-1, p[i]) <- i */
    k = all_states_.states_[i-1].suffix_transition_; /*!< k = S[i-1] */
    phi = i-1; /*!< phi_one = i-1 */
    int flag = 0, iter = 0;
    /**
     * while k > -1 and delta(k,p[i]) is undefined
     *      do delta(k, p[i]) <- i
     *      phi_one = k
     *      k = S[k]
     * */
    while (k > -1 && flag == 0)
    {
        while (iter < all_states_.states_[k].transition_.size())
        {
            if (all_states_.states_[k].transition_[iter].symbol_ == alpha)
            {
                flag = 1;
            }
            iter++;
        }
        if (flag == 0)
        {
            SingleTransition transition_k;
            transition_k.first_state_ = k;
            transition_k.last_state_ = statemplusone;
            transition_k.symbol_ = alpha;
            all_states_.states_[k].transition_.push_back(transition_k);
            phi = k;
            k = all_states_.states_[k].suffix_transition_;
            iter = 0;
        }
    }
    if (k == -1)
    {
        all_states_.states_[statemplusone].suffix_transition_ = 0;
        all_states_.states_[statemplusone].lrs_ = 0;
    }
    else
    {
        flag = 0, iter = 0;
        if (all_states_.states_[k].transition_[iter].symbol_ == alpha)
        {
            flag = 1;
            all_states_.states_[statemplusone].suffix_transition_ = all_states_.states_[k].transition_[iter].last_state_;
            all_states_.states_[statemplusone].lrs_ = all_states_.LengthCommonSuffix(all_states_, phi, all_states_.states_[statemplusone].suffix_transition_ -1) + 1;
        }
        while (iter < all_states_.states_[k].transition_.size() && flag == 0)
        {
            if (all_states_.states_[k].transition_[iter].symbol_ == alpha)
            {

                all_states_.states_[statemplusone].suffix_transition_ = all_states_.states_[k].transition_[iter].last_state_;
                all_states_.states_[statemplusone].lrs_ = all_states_.LengthCommonSuffix(all_states_, phi, all_states_.states_[statemplusone].suffix_transition_ -1) + 1;
                flag = 1;
            }

            iter++;
        }


    }
    k = all_states_.FindBetter(all_states_,T, statemplusone, word[statemplusone - all_states_.states_[statemplusone].lrs_ - 1], word);
    if (k != 0)
    {
        all_states_.states_[statemplusone].lrs_ = all_states_.states_[statemplusone].lrs_ + 1;
        all_states_.states_[statemplusone].suffix_transition_ = k;
    }
    T[all_states_.states_[statemplusone].suffix_transition_].push_back(statemplusone);
    /*for (int f = 0; f < T.size(); f++)
    {
        for (int p = 0; p < T[f].size(); p++)
            cout << T[f][p] << " ";
        cout << "\n";
    }*/
}


void FactorOracle::FactorOracleStart(FactorOracle& oracle_relations,string word)
{
    //! A normal member taking one argument and returning no value.
    /*!
      \param oracle_relations a reference to a FactorOracle class.
      \param word a string argument.
    */
    int len = word.size();
    oracle_relations.states_.resize(len+1);
    //SingleTransition statezero; /*!< Create state 0 */
    oracle_relations.states_[0].state_ = 0;
    oracle_relations.states_[0].lrs_ = 0;
    oracle_relations.states_[0].suffix_transition_ = -1; /*!< S[0] = -1 */
    oracle_relations.T.resize(len+1);
    for (int i = 1; i <= len; i++)
    {
        /*!< for i <- 1 to m
        * do AddLetter(i)
        */
        oracle_relations.AddLetter(oracle_relations, oracle_relations.T , i, word);
    }
    /*
    for (int i = 0; i < len+1; i++){

        cout << "STATE[" << i << "]:\n" << "LRS: "<< oracle_relations.states_[i].lrs_ << "\n";
        cout << "Suffix: " << oracle_relations.states_[i].suffix_transition_ << "\n";
        cout << "Transitions: " << "\n";
        for (int w = 0; w < oracle_relations.states_[i].transition_.size(); w++)
        {
            cout << oracle_relations.states_[i].transition_[w].first_state_ << " " << oracle_relations.states_[i].transition_[w].last_state_ << " "  << oracle_relations.states_[i].transition_[w].symbol_ << "\n";
        }
        cout << "\n";

    }
    string oracle = "";
    fo_iter = 1;
    for (int x = 0; x < len; x++)
    {
        oracle = oracle_relations.FOGenerate(oracle_relations,fo_iter,oracle,0.5);
        if (fo_iter == len)
            fo_iter = len-1;
        cout << "Factor Oracle Sequence: " << oracle << "\n";

    }*/

}

void FactorOracle::FactorOracleWord(FactorOracle& oracle_relations,string word)
{
    oracle_relations.FactorOracleStart(oracle_relations,word);
}

