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
map<string, long long> dp;
bool compose(string s)
{
    if (s=="")return true;
    if (dp[s])return (dp[s]<0 ? false : true);
    dp[s]=-1;
    for (auto w:patr){
        int len=w.size();
        string start=s.substr(0, len), rest="";
        for (int i=len; i<s.size(); ++i){
            rest.push_back(s[i]);
        }
        if (start==w && compose(rest)){
            dp[s]=1;
            return true;
        }
    }
    return false;
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
        //cout<<++line<<endl;
        //dp.clear();
        cnt+=compose(s);
        //if (can(s))cout<<s<<endl;
    }
    fout<<cnt;
}
map<string, bool> bp;
vector<string> v;
long long counter(string s)
{
    if (s==""){
        for (auto it:v){
            fout<<it<<endl;
        }
        return 1;
    }
    if (bp[s])return dp[s];
    dp[s]=0;
    bp[s]=1;
    for (auto w:patr){
        int len=w.size();
        string start=s.substr(0, len), rest="";
        for (int i=len; i<s.size(); ++i){
            rest.push_back(s[i]);
        }
        if (start==w){
            v.push_back(start);
            v.push_back(rest);
            dp[s]+=counter(rest);
            v.pop_back();
            v.pop_back();
        }
    }
    return dp[s];
}
void p2()
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
    long long cnt=0, line=0;
    while (getline(fin, s)){
        //cout<<++line<<endl;
        fout<<s+": "<<endl;
        cnt+=counter(s);
        cout<<counter(s)<<endl;
    }
    fout<<cnt;
}
int main()
{
    //p1();
    p2();
    return 0;
}
