#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");

vector<unsigned long long> nv, v;
deque<int> split;
int get_size(unsigned long long n)
{
    int s=0;
    while (n>9){
        split.push_front(n%10);
        n/=10;
        ++s;
    }
    split.push_front(n);
    ++s;
    return s;
}
int iterate(int iterations)
{
    for (int i=1; i<=iterations; ++i){
        //cout<<i<<endl;
        nv.clear();
        for (auto it:v){
            if (!it) nv.push_back(1);
            else {
                split.clear();
                int sz=get_size(it);
                if (sz%2){
                    nv.push_back(it*2024);
                } else {
                    unsigned long long num1=0, num2=0;
                    for (int j=0; j<sz/2; ++j){
                        num1*=10;
                        num1+=split[j];
                    }
                    nv.push_back(num1);
                    for (int j=sz/2; j<sz; ++j){
                        num2*=10;
                        num2+=split[j];
                    }
                    nv.push_back(num2);
                }
            }
        }
        v=nv;
    }
    return v.size();
}
void p1()
{
    string s, cs;
    while (getline(fin, cs)){
        s+=cs;
    }
    stringstream sin(s);
    unsigned long long x;
    while (sin>>x){
        v.push_back(x);
    }

    fout<<iterate(25);
}
vector<unsigned long long>save, nsave;
void p2()
{
    string s, cs;
    while (getline(fin, cs)){
        s+=cs;
    }
    stringstream sin(s);
    unsigned long long x, tot=0, cnt=1;
    while (sin>>x){
        v.push_back(x);
    }


    /// ok deci solutia ii un dp pe numere individuale si faci ca in pyhon cu un cach pe a memora function callurile si dupa dute plangi ca abea 
    /// amu tio venit ideea
    iterate(40);
    cout<<"40 allready\n";
    cout<<"done";
    save=v;
    v.clear();
    for (int i=0; i<save.size(); ++i){
        v.clear();
        v.push_back(s[i]);
        tot+=iterate(35);
        cout<<i+1<<" done\n";
    }
    fout<<tot;
}
map<pair<unsigned long long, int>, int> cache;
unsigned long long calc(unsigned long long stone, int iter)
{
    if (!iter)return 1;
    if (!cache.count({stone, iter})){
        if (stone==0)cache[{stone, iter}]=calc(1, iter-1);
        else {
            string s=to_string(stone);
            if (s.size()%2)cache[{stone, iter}]=calc(stone*2024, iter-1);
            else {
                unsigned long long num1=0, num2=0;
                for (int j=0; j<s.size()/2; ++j){
                    num1*=10;
                    num1+=s[j]-'0';
                }
                for (int j=s.size()/2; j<s.size(); ++j){
                    num2*=10;
                    num2+=s[j]-'0';
                }
                cache[{stone, iter}]=(calc(num1, iter-1)+calc(num2, iter-1));
            }
        }
    }
    return cache[{stone, iter}];
}
void p2eficient()
{
    string s, cs;
    while (getline(fin, cs)){
        s+=cs;
    }
    stringstream sin(s);
    unsigned long long x, tot=0;
    while (sin>>x){
        tot+=calc(x, 75);
    }
    fout<<tot;
}
unordered_map<unsigned long long, unsigned long long> mp1, mp2;
void p2Cu2MapuriCaVectori()
{
    string s, cs;
    while (getline(fin, cs)){
        s+=cs;
    }
    stringstream sin(s);
    unsigned long long x, tot=0;
    while (sin>>x){
        ++mp1[x];
    }
    for (int i=0; i<75; ++i){
        mp2.clear();
        for (auto it:mp1){
            if (!it.first){
                mp2[1]+=it.second;
            } else if (to_string(it.first).size()%2){
                mp2[it.first*2024]+=it.second;
            } else {
                cs=to_string(it.first);
                unsigned long long num1=stoull(cs.substr(0, cs.size()/2)), 
                num2=stoul(cs.substr(cs.size()/2, cs.size()/2));
                mp2[num1]+=it.second;
                mp2[num2]+=it.second;
            }
        }
        mp1=mp2;
    }
    for (auto it:mp1){
        tot+=it.second;
    }
    fout<<tot;
}
int main()
{
    /*ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    */
    //p1();
    //p2eficient();
    p2Cu2MapuriCaVectori();
}
