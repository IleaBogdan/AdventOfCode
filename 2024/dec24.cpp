#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");
#define endl '\n'

map<string, bool> k;
struct form{
    string oper, x, y;
};
map<string, form> c;
void read()
{
    string s;
    while (getline(fin, s)){
        if (s=="")break;
        string input=s.substr(0, s.find(':'));
        k[input]=(s[s.find(':')+2]=='1');
        //cout<<k[input]<<endl;
    }
    while (getline(fin, s)){
        for (size_t i=0; i<s.size(); ++i){
            form f1;
            string r;
            int alcat=0;
            for (int i=0; i<s.size(); ++i){
                if (s[i]==' '){
                    if (s[i+1]=='-')i+=3;
                    ++alcat;
                    continue;
                }
                if (alcat==0){
                    f1.x.push_back(s[i]);
                } else if (alcat==1){
                    f1.oper.push_back(s[i]);
                } else if (alcat==2){
                    f1.y.push_back(s[i]);
                } else {
                    r.push_back(s[i]);
                }
            }
            c[r]=f1;
        }
    }
}
bool calc(string w)
{
    if (k.count(w))return k[w];
    form f2=c[w];
    if (f2.oper=="OR"){
        k[w]=calc(f2.x)|calc(f2.y);
    } else if (f2.oper=="AND"){
        k[w]=calc(f2.x)&calc(f2.y);
    } else {
        k[w]=calc(f2.x)^calc(f2.y);
    }
    return k[w];
}
void p1()
{
    read();
    vector<bool> z;
    int znum=0;
    while (true){
        string tmp="z0";
        if (znum>9)tmp.pop_back();
        tmp+=to_string(znum);
        if (!c.count(tmp))break;
        z.push_back(calc(tmp));
        ++znum;
    }
    unsigned long long rez=0, p2=1;
    for (auto it:z){
        cout<<it;
        rez+=(p2*it);
        p2*=2;
    }
    fout<<rez;
}
int main()
{
    p1();
}