#include <iostream>
#include <new>
#include <string>
#include <vector>
#include <variant>
using namespace std;
#define R 10
#define C 3
#define D 2
#define RAND_MAX 0x7fffffff

class SingleTransition
{
public:
    int first_state;
    int last_state;
    char symbol;
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
    vector <SingleTransition> transition;
    int suffixTransition;
    int lrs = 0;
    void singleResize(){
        transition.resize(R);
    }
};

class States
{
public:
    vector <State> states;
};


int phi, k;

string FOGenerate(States& States, int i, string v, float q)
{
    float u = (float)rand() / RAND_MAX;
    if (u < q)
    {
        i = i + 1;
        char w = States.states[i].transition[0].symbol;
        v = v + w;
    }
    else
    {
        int lenSuffix = States.states[States.states[i].suffixTransition].transition.size() - 1;
        int rand_alpha = rand() % lenSuffix;
        char alpha = States.states[States.states[i].suffixTransition].transition[rand_alpha].symbol;
        i = States.states[States.states[i].suffixTransition].transition[lenSuffix].last_state;
        v = v + alpha;
    }
}


int FindBetter(States& States, vector <vector<int>> &T, int i, char alpha, string word)
{
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
    States.states[i-1].state = i-1;
    SingleTransition tran;
    tran.first_state = i-1;
    tran.last_state = i;
    tran.symbol = alpha;
    int statemplusone = i;
    // delta(i-1, p[i]) <- i
    States.states[i-1].transition.push_back(tran);
    // k = S[i-1]
    k = States.states[i-1].suffixTransition;
    // phi_one = i-1
    phi = i-1;
    int flag = 0, iter = 0;
    /*
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
            States.states[statemplusone].lrs = LengthCommonSuffix(States, phi, States.states[statemplusone].suffixTransition -1) + 1;
        }
        while (iter < States.states[k].transition.size() && flag == 0)
        {
            if (States.states[k].transition[iter].symbol == alpha)
            {

                States.states[statemplusone].suffixTransition = States.states[k].transition[iter].last_state;
                States.states[statemplusone].lrs = LengthCommonSuffix(States, phi, States.states[statemplusone].suffixTransition -1) + 1;
                flag = 1;
            }

            iter++;
        }


    }
    k = FindBetter(States,T, statemplusone, word[statemplusone - States.states[statemplusone].lrs - 1], word);
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
    States OracleRelations;
    OracleRelations.states.resize(len+1);
    // Create state 0
    SingleTransition statezero;
    OracleRelations.states[0].state = 0;
    OracleRelations.states[0].lrs = 0;
    // S[0] = -1
    OracleRelations.states[0].suffixTransition = -1;
    vector <vector<int>> T;
    T.resize(len+1);
    /* for i <- 1 to m
     * do AddLetter(i)
    */
    for (int i = 1; i <= len; i++)
    {
        AddLetter(OracleRelations, T , i, word);
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

       //cout << "Sequence: " << FOGenerate(OracleRelations,1,"",0.5);
   }

    return 0;
}

