#include <bits/stdc++.h>

using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");

int getInt(string s, int &i)
{
    int n=0;
    while (i<s.size() && s[i]>='0' && s[i]<='9'){
        n*=10;
        n+=s[i]-'0';
        ++i;
    }
    return n;
}
void p1()
{
    map<int, set<int>>mp;
    string s;
    int sum=0;
    while (fin>>s){
        if (s.find('|')!=-1){
            int i=0, x, y;
            x=getInt(s, i);
            ++i;
            y=getInt(s, i);
            mp[y].insert(x);
        } else {
            vector<int> v;
            for (int i=0; i<s.size(); ++i){
                v.push_back(getInt(s, i));
            }
            bool ok=true;
            for (int i=0; i<v.size() && ok; ++i){
                for (int j=i+1; j<v.size() && ok; ++j){
                    ok=!mp[v[i]].count(v[j]);
                }
            }
            if (ok){
                sum+=v[v.size()/2];
            }
        }
    }
    fout<<sum;
}
map<int, set<int>>mp;

bool sor(int a, int b){
    return !mp[a].count(b);
}
void p2()
{
    string s;
    int sum=0;
    while (fin>>s){
        if (s.find('|')!=-1){
            int i=0, x, y;
            x=getInt(s, i);
            ++i;
            y=getInt(s, i);
            mp[y].insert(x);
        } else {
            vector<int> v;
            for (int i=0; i<s.size(); ++i){
                v.push_back(getInt(s, i));
            }
            bool ok=true;
            for (int i=0; i<v.size() && ok; ++i){
                for (int j=i+1; j<v.size() && ok; ++j){
                    ok=!mp[v[i]].count(v[j]);
                }
            } 
            if (!ok){
                sort(v.begin(), v.end(), sor);
                sum+=v[v.size()/2];
            }
        }
    }
    fout<<sum;
}
int main()
{
    //p1();
    p2();
    return 0;
}
