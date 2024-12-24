#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <vector>


using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");

map<string, set<string>> g;
void p1()
{
    string s;
    while (fin>>s){
        string s1=s.substr(0, 2), s2=s.substr(3, 2);
        g[s1].insert(s2);
        g[s2].insert(s1);
        //cout<<s1<<" - "<<s2<<endl;
    }
    s="t";
    set<string> v;
    for (char c='a'; c<='z'; ++c){
        s.push_back(c);
        //cout<<s<<endl;
        if (g.count(s)){
            for (auto it:g[s]){
                for (auto jt:g[it]){
                    if (g[s].count(jt)){
                        if (!v.count(s+","+it+","+jt) && 
                            !v.count(s+","+jt+","+it) &&
                            !v.count(it+","+s+","+jt) &&
                            !v.count(it+","+jt+","+s) &&
                            !v.count(jt+","+s+","+it) &&
                            !v.count(jt+","+it+","+s)
                        ) v.insert(s+","+it+","+jt);
                    }
                }
            }
        }
        s.pop_back();
    }
    /*for (auto it:v){
        cout<<it<<endl;
    }*/
    fout<<v.size();
}
int main()
{
    p1();
}