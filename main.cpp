#include <iostream>
#include <fstream>
#include <cstring>
#include <set>
#include <utility>
#define MAX 40
using namespace std;
typedef pair<int, int> pereche;
struct tranzitie
{
    int x,y;
    char alph;
}E[MAX];

int n,m,q0,k,l;
char C[MAX];
int D[MAX];
int len=0,len_finish;
bool ok;
string input;
set <pereche> set_stari_curente;

bool caracter_e_in_alfabet(char c) // e ce ne trebuie pentru acceptare
{
    bool ok_1 = false;
    if (c=='\0')
        return ok_1 = true;
    for(int i=0;i<m;i++)
        if(c==C[i])
            ok_1=true;
    return ok_1;
}


bool confirma_stare_finala(const pereche &st, char c)
{

if(!caracter_e_in_alfabet(c))
    return false;
for(int i=0;i<k;i++)
    if(st.first==D[i] && st.second == len_finish)
        return true;
return false;
}

bool parcurge( int st, char c)
{
    bool success = false;
    if(c=='\0') // am acceptat toate caracterele aparent - caz len_finish
        return success = true;
    for(int i=0;i<l;i++){
        if(E[i].x == st && E[i].alph == c)
        {
                set_stari_curente.insert(make_pair(E[i].y,len+1));
                success = true;
        }
        if(E[i].x == st && E[i].alph == '$'){
                set_stari_curente.insert(make_pair(E[i].y,len));
                success = true;
        }
        if(E[i].x == E[i].y)
            continue;
    }
    return success;
}


/*
void debug_afis()
{
    for(auto it : set_stari_curente)
    {
        cout << it.first << " " << input[it.second]  << " " << it.second << endl;
    }
    cout << "*" << endl;
}
*/


int main()
{
    ifstream f("input.txt");
    f>>n>>m;
    for(int i=0;i<m;i++)
        f>>C[i]; // alfabetul curent
    f>>q0>>k;
    for(int i=0;i<k;i++)
        f>>D[i]; // starile finale
    f>>l;
    for(int i=0;i<l;i++)
        f>>E[i].x>>E[i].alph>>E[i].y; // translatii

    cout<<"inputul este: ";
    cin >> input;

    len_finish=input.length();
    set_stari_curente.insert(make_pair(q0,len));
    ok=false;
    while(!set_stari_curente.empty())
    {

        auto it = *set_stari_curente.begin();
        len=it.second;
        bool success = parcurge(it.first, input[it.second]);

        //debug_afis();

        set_stari_curente.erase(it);
        if(!set_stari_curente.empty()) // resetare in cazul in care am trecut de o stare finala
            ok=false;

        //cout << "<x a y sters>" << endl;
        //debug_afis();
        //if(set_stari_curente.empty())
        //    cout<<"GOL!"<<endl;

        if(confirma_stare_finala(it,input[it.second]) && success)
        {
               //cout << "DA!!" << endl;

               ok=true;
        }
    }
    if(ok)
        cout << "cuvantul a fost acceptat";
    else
        cout << "cuvantul nu a fost acceptat";

}
