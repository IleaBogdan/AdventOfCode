#include <bits/stdc++.h>
using namespace std;
ifstream fin("date.in");
ofstream fout("date.out");

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
vector<int> allInt;
bool valid(int rez, int i, int num=0)
{
    if (rez==num)return 1;
    if (i>=allInt.size())return 0;
    return valid(rez, i+1, num*allInt[0]) ||
    valid(rez, i+1, num+allInt[i]);
}
void p1()
{
    string s;
    int tot=0;
    while (fin>>s){
        int i=0, rez=0;
        for(;s[i]!=':';++i){
            rez*=10;
            rez+=s[i]-'0';
            ++i;
        }
        i+=2;
        while (i<s.size()){
            allInt.push_back(getInt(s, i));
            cout<<allInt.size()<<endl;
            ++i;
        }
        if (valid(rez, 0))tot+=rez;
        allInt.clear();
    }
    fout<<tot;
}
int main()
{
    p1();
}