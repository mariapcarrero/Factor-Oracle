#include <iostream>
#include <new>
#include <string>
#include <vector>
#include <variant>
using namespace std;
#define R 10
#define C 3
#define D 2
class SingleTransition
{
public:
    int first_state;
    int last_state;
    char symbol;
};

class SuffixTransition
{
public:
    int last_state;
    int first_state;
};


class Transitions
{
public:
    vector <vector<SingleTransition>> transition;
};

/* Denotes the elements that belong to each state
 * state denotes de number of the state
 * number denotes the number
 * vector <SingleTransition> transition is the vector where all forward links of the state are defined
 * suffixTransition denotes which is the suffix link of this state
 * lrs is the longest repeated subsequence of this state
 * */
class State
{
public:
    int state;
   // int number;
    vector <SingleTransition> transition;
    int suffixTransition;
    int lrs = 0;
    void singleResize(){
        transition.resize(R);
    }

  /*  void suffixResize(){
        suffixTransition.resize(R, vector<SuffixTransition>(D));
    }*/
};

class States
{
public:
    vector <State> states;
};


int phi, k;
// HACER FUNCION SUFFIX
int Suffix(int m)
{

    return m;
}
int FindBetter(States& States, vector <vector<int>> &T, int i, char alpha, string word)
{
    int lenT = T[i].size();
    if (lenT == 0) return 0;
    //sort(T[i].begin(), T[i].end());
    for (int j = 0; j < lenT; j++)
    {
        if (States.states[j].lrs == States.states[i].lrs && word[j - States.states[i].lrs] == alpha)
            return j;
    }
    return 0;
}
int LengthCommonSuffix(States& States, int phi_one, int phi_two)
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
void AddLetter(States& States, vector <vector<int>> &T, int i, string word)
{
    char alpha = word[i-1];
    States.states[i].state = i+1;
 //   States.states[i].state = word[i-1];
    SingleTransition tran;
    tran.first_state = i;
    tran.last_state = i+1;
    tran.symbol = alpha;

    int statemplusone = i+1;

  /*  if (States.states[i].transition.empty())
    {
        States.states[i].singleResize();
       // States.states[i].suffixResize();
    }*/

   // States.states[i].transition.resize(R, vector<SingleTransition>(C));
   // int sizeTransition = States.states[i].transition.size();
    int m = i;
    States.states[m].transition.push_back(tran);
    phi = m;
    k = States.states[m].suffixTransition;
    int flag = 0, iter = 0;
    while (k > -1 && flag == 0)
    {

        while (States.states[k].transition[iter].symbol != alpha && iter < States.states[k].transition.size())
        {
            if (States.states[k].transition[iter].symbol == alpha)
                flag = 1;
            iter++;
        }
        if (flag == 0)
        {
            SingleTransition transition_k;
            tran.first_state = k;
            tran.last_state = statemplusone;
            tran.symbol = alpha;
            States.states[i].transition.push_back(transition_k);
            phi = k;
            k = States.states[k].suffixTransition;
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
        while (States.states[k].transition[iter].symbol != alpha && flag == 0)
        {
            if (States.states[k].transition[iter].symbol == alpha)
                flag = 1;
            iter++;
        }


    }
    k = FindBetter(States,T, statemplusone, word[statemplusone - States.states[statemplusone].lrs], word);
    if (k != 0)
    {
        States.states[statemplusone].lrs = States.states[statemplusone].lrs + 1;
        States.states[statemplusone].suffixTransition = k;
    }
    T[States.states[statemplusone].suffixTransition].push_back(statemplusone);

}


int main() {
    string word;
    int len;
    cout << "El string es: ";
    cin >> word;
    len = word.size();

    cout << word;

    States OracleRelations;
    OracleRelations.states.resize(len+1);
    SingleTransition statezero;
    statezero.first_state = 0;
    statezero.last_state = 1;
    statezero.symbol = word[0];
    OracleRelations.states[0].transition.push_back(statezero);
    OracleRelations.states[0].state = 0;
    OracleRelations.states[0].lrs = 0;
    OracleRelations.states[0].suffixTransition = -1;
    vector <vector<int>> T;
    T.resize(len+1);
    cout << OracleRelations.states.size();

 /*   OracleRelations.letters.reserve(len+2);
    OracleRelations.suffix.reserve(len+2);
    OracleRelations.lrs.reserve(len+2);
   // strcpy(OracleRelations.letters, word.c_str());
    OracleRelations.letters[0] = ' ';
 /*   for (int i = 1; i < len+1; i++)
        OracleRelations.letters[i] = word[i-1];
*/
/*
    OracleRelations.numbers[0] = 0;
    OracleRelations.suffix[0] = -1;*/

    for (int i = 1; i <= len; i++)
    {
        AddLetter(OracleRelations, T , i, word);
    }

   for (int i = 0; i < len+1; i++)
        cout << '* ' << OracleRelations.states[i].lrs << ' ';
    //cout << "Hello, World!" << std::endl;  << "\n"
    return 0;
}
