#include <bits/stdc++.h>

using namespace std;

const string file="date";
ifstream fin(file+".in");
ofstream fout(file+".out");
#define endl '\n';

void p1()
{
    int n=1000;
    int a1[1000], a2[1000];
    for (int i=0; i<n; ++i){
        fin>>a1[i]>>a2[i];
    }
    sort(a1, a1+n), sort(a2, a2+n);
    long long sum=0;
    for (int i=0; i<n; ++i){
        sum+=abs(a1[i]-a2[i]);
    }
    fout<<sum;
}
void p2()
{
    int n=1000;
    int a1[1000], a2[1000];
    for (int i=0; i<n; ++i){
        fin>>a1[i]>>a2[i];
    }
    map<int, int>frec;
    for (int i=0; i<n; ++i){
        ++frec[a2[i]];
    }
    int s=0;
    for (int i=0; i<n; ++i){
        s+=(frec[a1[i]]*a1[i]);
    }
    fout<<s;
}
int main()
{
    //p1();
    p2();
    return 0;
}
