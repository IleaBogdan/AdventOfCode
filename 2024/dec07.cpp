#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>
#include <cstdint>

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
        //cout<<rez<<endl;
        while (i<s.size()){
            v.push_back(getInt(s, i));
            //cout<<v.back()<<" ";
            while (s[i]<'0' || s[i]>'9' && i<s.size()){
                ++i;
            }
        }
        if (valid(rez, v.size()-1)){
            tot+=rez;
            cout<<rez<<endl;
        }
        v.clear();
    }
    fout<<tot;
}
int count_dig(int n) {
    if (n == 0) return 1;
    int r = 0;
    while (n) {
        n /= 10;
        r++;
    }
    return r;
}

int pow10(int p) {
    int res = 1;
    while (p) {
        res *= 10;
        p--;
    }
    return res;
}
int rez;
bool valid2(int k, int sum) {
    if (k==v.size() && sum==rez){
        return 1;
    }
    if (k==v.size() || sum>rez){
        return 0;
    }
    return valid2(k+1, sum+v[k]) || 
           valid2(k+1, sum*v[k]) || 
           (valid2(k+1, sum*pow10(count_dig(v[k]))+v[k]));
}
void p2()
{
    string s;
    long long tot=0;
    while (getline(fin, s)){
        int i=0; 
        rez=0;
        for(;s[i]!=':' && i<s.size();++i){
            //cout<<i<<endl;
            rez*=10;
            rez+=s[i]-'0';
        }
        while (s[i]<'0' || s[i]>'9' && i<s.size()){
            ++i;
        }
        //cout<<rez<<endl;
        while (i<s.size()){
            v.push_back(getInt(s, i));
            //cout<<v.back()<<" ";
            while (s[i]<'0' || s[i]>'9' && i<s.size()){
                ++i;
            }
        }
        //fout<<rez<<":\n";
        //cout<<endl;
        if (valid2(1, v[0])){
            cout<<rez<<endl;
            tot+=rez;
        }
        //fout<<endl;
        v.clear();
    }
    fout<<tot;
}
signed main()
{
    //cout<<"H";
    //p1();
    p2();
}