#include <iostream>
#include <fstream>
#include <map>
#include <deque>
#include <math.h>
#include <cmath>
#include <set>

using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");

#define endl '\n'
#define MOD 16777216

const int miter=2000;
void p1()
{
    unsigned long long x, sum=0;
    while (fin>>x){
        for (int i=0; i<miter; ++i){
            x^=(x*64);
            x%=MOD;
            x^=(x/32);
            x%=MOD;
            x^=(x*2048);
            x%=MOD;
        }
        //cout<<x<<endl;
        sum+=x;
    }
    fout<<sum;
}
unsigned long long genNext(unsigned long long x)
{
    x^=(x*64);
    x%=MOD;
    x^=(x/32);
    x%=MOD;
    x^=(x*2048);
    x%=MOD;
    return x;
}
set<deque<int>> seen;
map<deque<int> , int> seq;
void p2()
{
    unsigned long long x;
    while (fin>>x){
        seen.clear();
        deque<int> secv;
        secv.push_back(x%10);
        for (int i=0; i<miter; ++i){
            x=genNext(x);
            secv.push_back(x%10);
        }
        for (int i=0; i<secv.size()-4; ++i){
            deque<int> s5, s4;
            for (int j=0; j<5; ++j){
                s5.push_back(secv[i+j]);
            }
            for (int k=1; k<s5.size(); ++k){
                s4.push_back(s5[k]-s5[k-1]);
            }
            if (!seen.count(s4)){
                seen.insert(s4);
                seq[s4]+=s5.back();
            }
        }
    }
    int maxim=0;
    for (auto it:seq){
        maxim=max(maxim, it.second);
    }
    fout<<maxim;
}
int main()
{
    //p1();
    p2();
}