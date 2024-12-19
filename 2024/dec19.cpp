#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <set>
#include <map>


using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");

set<string> patr;
map<string, bool> dp;
bool compose(string s)
{
    if (s=="")return true;
    if (dp[s])return dp[s];
    dp[s]=false;
    for (auto w:patr){
        int len=w.size();
        string start=s.substr(0, len), rest="";
        for (int i=len; i<s.size(); ++i){
            rest.push_back(s[i]);
        }
        if (start==w && compose(rest)){
            dp[s]=true;
            break;
        }
    }
    return dp[s];
}
void p1()
{
    string s;
    getline(fin, s);
    stringstream sin(s);
    string p;
    while (sin>>p){
        p.pop_back();
        patr.insert(p);
    }
    fin.get();
    int cnt=0, line=0;
    while (getline(fin, s)){
        cout<<++line<<endl;
        //dp.clear();
        cnt+=compose(s);
        //if (can(s))cout<<s<<endl;
    }
    fout<<cnt;
}
int main()
{
    p1();
    return 0;
}
