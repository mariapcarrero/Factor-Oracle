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
    cout << "entro \n";
    for (int j = 0; j < lenT; j++)
    {
        if (States.states[j].lrs == States.states[i].lrs && word[j - States.states[i].lrs] == alpha)
        {
            cout << "wordVAL: " << word[j - States.states[i].lrs] << "\n";
            cout <<  "word: " << word << "\n";
            cout <<  "alpha11: " << alpha << "\n";
            cout <<  "j: " << j << "\n";
            return j;
        }

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
    States.states[i-1].state = i;
    //   States.states[i].state = word[i-1];
    SingleTransition tran;
    tran.first_state = i-1;
    tran.last_state = i;
    tran.symbol = alpha;

    int statemplusone = i;

    /*  if (States.states[i].transition.empty())
      {
          States.states[i].singleResize();
         // States.states[i].suffixResize();
      }*/

    // States.states[i].transition.resize(R, vector<SingleTransition>(C));
    // int sizeTransition = States.states[i].transition.size();
    //  int m = i;
    States.states[i-1].transition.push_back(tran);
    phi = i-1;
    k = States.states[i-1].suffixTransition;
    int flag = 0, iter = 0;
    while (k > -1 && flag == 0)
    {

        while ( iter < States.states[k].transition.size())
        {
            cout << "k__k: " << k << "\n";
            cout << "symbol: " << States.states[k].transition[iter].symbol << "\n";
            cout << "alpha: " << alpha << "\n";
            cout << "lenK: " << States.states[k].transition.size() << "\n";
            for(int w = 0; w < States.states[k].transition.size(); w++)
                cout << "SSS: " << States.states[k].transition[w].symbol << "\n";
            if (States.states[k].transition[iter].symbol == alpha)
            {
               // cout << "entroflag1";
                flag = 1;
            }
            cout << iter << "\n";
            iter++;
        }
        if (flag == 0)
        {
            cout << alpha << "\n";
            SingleTransition transition_k;
            transition_k.first_state = k;
            transition_k.last_state = statemplusone;
            transition_k.symbol = alpha;
            States.states[k].transition.push_back(transition_k);
            phi = k;
            k = States.states[k].suffixTransition;
        }

    }
    cout << "K AFTER: " << k << "\n";
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
            States.states[statemplusone].lrs = LengthCommonSuffix(States, phi, States.states[statemplusone].suffixTransition -1) + 1;
            cout << "LENGTH: " << States.states[statemplusone].lrs << "\n";
        }
        while (States.states[k].transition[iter].symbol != alpha && flag == 0)
        {
            cout << "TRANS: " <<States.states[k].transition[iter].symbol << "\n";
            if (States.states[k].transition[iter].symbol == alpha)
            {
                flag = 1;
                States.states[statemplusone].suffixTransition = States.states[k].transition[iter].last_state;
                States.states[statemplusone].lrs = LengthCommonSuffix(States, phi, States.states[statemplusone].suffixTransition -1) + 1;
                cout << "LENGTH: " << States.states[statemplusone].lrs << "\n";
            }

            iter++;
        }


    }
    cout << "statemp: " << statemplusone << "\n";
    cout << "Statestates: " << States.states[statemplusone].lrs << "\n";
    k = FindBetter(States,T, statemplusone, word[statemplusone - States.states[statemplusone].lrs], word);
    cout << "k: " << k << "\n";
    if (k != 0)
    {
        States.states[statemplusone].lrs = States.states[statemplusone].lrs + 1;
        States.states[statemplusone].suffixTransition = k;
    }
    T[States.states[statemplusone].suffixTransition].push_back(statemplusone);
    cout << "SUFFIX: " << States.states[statemplusone].suffixTransition << "\n";
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
    OracleRelations.states[0].state = 0;
    OracleRelations.states[0].lrs = 0;
    OracleRelations.states[0].suffixTransition = -1;
    vector <vector<int>> T;
    T.resize(len+1);
    // cout << OracleRelations.states.size();

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
        cout << "estadoOut: " << i << "\n";
        AddLetter(OracleRelations, T , i, word);
    }

    for (int i = 0; i < len+1; i++)
        cout << '* ' << OracleRelations.states[i].lrs << ' ';
    //cout << "Hello, World!" << std::endl;  << "\n"
    return 0;
}

