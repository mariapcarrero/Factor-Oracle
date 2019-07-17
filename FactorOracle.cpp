#include "FactorOracle.h"

int phi, k;

string FactorOracle::FOGenerate(FactorOracle& States, int i, string v, float q)
{
    //! A normal member taking four arguments and returning a string value.
    /*!
      \param States a reference to a FactorOracle class.
      \param i an integer argument.
      \param v a string argument.
      \param q a float argument.
      \return The factor oracle improvisation
    */
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<> dis(0.0, 1.0);
    float u = dis(gen);
    // float u = (float)rand() / RAND_MAX;
    if (u < q)
    {
        i = i + 1;
        char w = States.states[i].transition[0].symbol;
        string s(1,w);
        v = v + s;
    }
    else
    {
        int lenSuffix = States.states[States.states[i].suffixTransition].transition.size() - 1;
        std::uniform_int_distribution<> dis_int(0, lenSuffix);
        int rand_alpha = dis_int(gen);
        char alpha = States.states[States.states[i].suffixTransition].transition[rand_alpha].symbol;
        i = States.states[States.states[i].suffixTransition].transition[rand_alpha].last_state;
        v = v + alpha;
    }
    return v;
}


int FactorOracle::FindBetter(FactorOracle& States, vector <vector<int>> &T, int i, char alpha, string word)
{
    //! A normal member taking five arguments and returning an integer value.
    /*!
      \param States a reference to a FactorOracle class.
      \param T a reference to a vector of vector of integers.
      \param i an integer argument.
      \param alpha a char argument.
      \param word a string argument.
      \return A better state
    */
    int lenT = T[States.states[i].suffixTransition].size();
    int statei = States.states[i].suffixTransition;
    if (lenT == 0) return 0;
    sort(T[statei].begin(), T[statei].end());
    for (int j = 0; j < lenT; j++)
    {
        if (States.states[T[States.states[i].suffixTransition][j]].lrs == States.states[i].lrs && word[T[States.states[i].suffixTransition][j] - States.states[i].lrs - 1] == alpha)
        {
            int out = T[States.states[i].suffixTransition][j];
            return out;
        }

    }
    return 0;
}
int FactorOracle::LengthCommonSuffix(FactorOracle& States, int phi_one, int phi_two)
{
    if (phi_two == States.states[phi_one].suffixTransition)
        return States.states[phi_one].lrs;
    else
    {
        while (States.states[phi_one].suffixTransition!= States.states[phi_two].suffixTransition)
            phi_two = States.states[phi_two].suffixTransition;
    }
    if (States.states[phi_one].lrs <= States.states[phi_two].lrs)
        return States.states[phi_one].lrs;
    else return States.states[phi_two].lrs;
}
void FactorOracle::AddLetter(FactorOracle &States, vector<vector<int>> &T, int i, string word)
{
    //! A normal member taking four arguments and returning no value.
    /*!
      \param States a reference to a FactorOracle class.
      \param T a reference to a vector of vector of integers.
      \param i an integer argument.
      \param word a string argument.
    */
    char alpha = word[i-1];
    States.states[i-1].state = i-1;
    SingleTransition tran;
    tran.first_state = i-1;
    tran.last_state = i;
    tran.symbol = alpha;
    int statemplusone = i;
    States.states[i-1].transition.push_back(tran); /*!< delta(i-1, p[i]) <- i */
    k = States.states[i-1].suffixTransition; /*!< k = S[i-1] */
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

        while (iter < States.states[k].transition.size())
        {
            if (States.states[k].transition[iter].symbol == alpha)
            {
                flag = 1;
            }
            iter++;
        }

        if (flag == 0)
        {
            SingleTransition transition_k;
            transition_k.first_state = k;
            transition_k.last_state = statemplusone;
            transition_k.symbol = alpha;
            States.states[k].transition.push_back(transition_k);
            phi = k;
            k = States.states[k].suffixTransition;
            iter = 0;
        }

    }
    if (k == -1)
    {
        States.states[statemplusone].suffixTransition = 0;
        States.states[statemplusone].lrs = 0;
    }
    else
    {
        flag = 0, iter = 0;
        if (States.states[k].transition[iter].symbol == alpha)
        {
            flag = 1;
            States.states[statemplusone].suffixTransition = States.states[k].transition[iter].last_state;
            States.states[statemplusone].lrs = States.LengthCommonSuffix(States, phi, States.states[statemplusone].suffixTransition -1) + 1;
        }
        while (iter < States.states[k].transition.size() && flag == 0)
        {
            if (States.states[k].transition[iter].symbol == alpha)
            {

                States.states[statemplusone].suffixTransition = States.states[k].transition[iter].last_state;
                States.states[statemplusone].lrs = States.LengthCommonSuffix(States, phi, States.states[statemplusone].suffixTransition -1) + 1;
                flag = 1;
            }

            iter++;
        }


    }
    k = States.FindBetter(States,T, statemplusone, word[statemplusone - States.states[statemplusone].lrs - 1], word);
    if (k != 0)
    {
        States.states[statemplusone].lrs = States.states[statemplusone].lrs + 1;
        States.states[statemplusone].suffixTransition = k;
    }
    T[States.states[statemplusone].suffixTransition].push_back(statemplusone);
}


void FactorOracle::FactorOracleStart(FactorOracle& OracleRelations,string word)
{
    //! A normal member taking one argument and returning no value.
    /*!
      \param word a string argument.
    */
    int len = word.size();
    OracleRelations.states.resize(len+1);
    SingleTransition statezero; /*!< Create state 0 */
    OracleRelations.states[0].state = 0;
    OracleRelations.states[0].lrs = 0;
    OracleRelations.states[0].suffixTransition = -1; /*!< S[0] = -1 */
    vector <vector<int>> T;
    T.resize(len+1);
    for (int i = 1; i <= len; i++)
    {
        /*!< for i <- 1 to m
        * do AddLetter(i)
        */
        OracleRelations.AddLetter(OracleRelations, T , i, word);
    }

    for (int i = 0; i < len+1; i++){

        cout << "STATE[" << i << "]:\n" << "LRS: "<< OracleRelations.states[i].lrs << "\n";
        cout << "Suffix: " << OracleRelations.states[i].suffixTransition << "\n";
        cout << "Transitions: " << "\n";
        for (int w = 0; w < OracleRelations.states[i].transition.size(); w++)
        {
            cout << OracleRelations.states[i].transition[w].first_state << " " << OracleRelations.states[i].transition[w].last_state << " "  << OracleRelations.states[i].transition[w].symbol << "\n";
        }
        cout << "\n";

    }
    cout << "Factor Oracle Sequence: " << OracleRelations.FOGenerate(OracleRelations,0,"",0.5);
}

