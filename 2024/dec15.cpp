#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");

vector<string> v;
string dir;
int n, m;
map<char, int> di, dj;
pair<int, int> get_robot()
{
    for (int i=0; i<n; ++i){
        for (int j=0; j<m; ++j){
            if (v[i][j]=='@')return make_pair(i, j);
        }
    }
    return make_pair(n, m);
}
bool all(string s, char c)
{
    for (auto it:s){
        if (c!=it)return false;
    }
    return true;
}
void p1()
{
    string s;
    getline(fin, s);
    v.push_back(s);
    while (getline(fin, s)){
        v.push_back(s);
        if (all(s, '#'))break;
    }
    while (fin>>s){
        dir+=s;
    }
    n=v.size(), m=v[0].size();
    pair<int, int> r=get_robot();
    int ri=r.first, rj=r.second;
    for (auto c:dir){
        int pi=ri+di[c], pj=rj+dj[c];
        while (v[pi][pj]=='O'){
            pi+=di[c];
            pj+=dj[c];
        }
        if (v[pi][pj]=='#')continue;
        while (pi!=ri || pj!=rj){
            v[pi][pj]=v[pi-di[c]][pj-dj[c]];
            pi-=di[c];
            pj-=dj[c];
        }
        v[ri][rj]='.';
        ri+=di[c], rj+=dj[c];
    }
    long long tot=0;
    for (int i=1; i<n-1; ++i){
        for (int j=1; j<m-1; ++j){
            if (v[i][j]=='O'){
                tot+=(100*i+j);
            }
        }
    }
    fout<<tot;
}
string scale(const string & s){
    string st="";
    for (const auto it:s){
        if (it=='.')st+="..";
        else if (it=='O')st+="[]";
        else if (it=='#')st+="##";
        else st+="@.";
    }
    return st;
}
void p2()
{
    string s;
    getline(fin, s);
    v.push_back(s);
    while (getline(fin, s)){
        s=scale(s);
        v.push_back(s);
        if (all(s, '#'))break;
    }
    while (fin>>s){
        dir+=s;
    }
    n=v.size(), m=v[0].size();
    pair<int, int> r=get_robot();
    int ri=r.first, rj=r.second;
    for (auto c:dir){
        int pi, pj;
    }
}
int main()
{
    di['<']=0;
    dj['<']=-1;
    di['>']=0;
    dj['>']=1;
    di['^']=-1;
    dj['^']=0;
    di['v']=1;
    dj['v']=0;
    //p1();
    p2();
    return 0;
}