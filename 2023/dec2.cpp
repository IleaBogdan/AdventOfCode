#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <map>

using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");

void p1()
{
    map<string, int>mp;
    string s;
    int tot=0, gameId=0;
    while (getline(fin, s)){
        mp.clear();
        ++gameId;
        stringstream sin(s);
        int num;
        bool ok=true;
        string elg;
        sin>>elg;
        while (sin>>num){
            sin>>elg;
            if (elg.back()==',' || elg.back()==';')elg.pop_back();
            mp[elg]=num;
            if (elg=="red" && mp[elg]>12){
                ok=0;
                break;
            }
            if (elg=="green" && mp[elg]>13){
                ok=0;
                break;
            }
            if (elg=="blue" && mp[elg]>14){
                ok=0;
                break;
            }
        }
        tot+=ok*gameId;
        //cout<<gameId*ok<<" "<<mp["red,"]<<" "<<mp["green,"]<<" "<<mp["blue,"]<<endl;
    }
    fout<<tot;
}
void p2()
{
    map<string, int>mp;
    string s;
    int tot=0, gameId=0;
    while (getline(fin, s)){
        mp.clear();
        ++gameId;
        stringstream sin(s);
        int num;
        bool ok=true;
        string elg;
        sin>>elg;
        while (sin>>num){
            sin>>elg;
            if (elg.back()==',' || elg.back()==';')elg.pop_back();
            mp[elg]=max(num, mp[elg]);
        }
        tot+=mp["red"]*mp["blue"]*mp["green"];
    }
    fout<<tot;
}
int main()
{
    //p1();
    p2();
}