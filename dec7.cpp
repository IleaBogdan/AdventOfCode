#include <iostream>
#include <fstream>
#include <vector>
#include <string>

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
vector<int> v;
bool valid(int rez, int i, int num=0)
{
    if (rez==num)return true;
    if (i<v.size())return valid(rez, i+1, num*v[i]) || valid(rez, i+1, num+v[i]);
    else return false;
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
        while (i<s.size()){
            v.push_back(getInt(s, i));
            while (s[i]<'0' || s[i]>'9' && i<s.size()){
                ++i;
            }
        }
        if (valid(rez, 0))tot+=rez;
    }
    fout<<tot;
}
int main()
{
    //cout<<"H";
    p1();
}