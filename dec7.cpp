#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");

#define int long long
int getInt(string s, int &i)
{
    int n=0;
    while (s[i]>='0' && s[i]<='9' && i<s.size()){
        n*=10;
        n+=s[i]-'0';
        ++i;
    }
    return n;
}
vector<int> v;
bool valid(int rez, int i)
{
    if (i==0)
        return rez==v[0];
    
    if (rez%v[i]==0 && valid(rez/v[i], i-1))
        return true;
     return valid(rez-v[i], i-1);
}
void p1()
{
    string s;
    long long tot=0;
    while (getline(fin, s)){
        int i=0, rez=0;
        for(;s[i]!=':' && i<s.size();++i){
            //cout<<i<<endl;
            rez*=10;
            rez+=s[i]-'0';
        }
        while (s[i]<'0' || s[i]>'9' && i<s.size()){
            ++i;
        }
        cout<<rez<<endl;
        while (i<s.size()){
            v.push_back(getInt(s, i));
            cout<<v.back()<<" ";
            while (s[i]<'0' || s[i]>'9' && i<s.size()){
                ++i;
            }
        }
        cout<<endl;
        if (valid(rez, v.size()-1))tot+=rez;
        v.clear();
    }
    fout<<tot;
}
signed main()
{
    //cout<<"H";
    p1();
}