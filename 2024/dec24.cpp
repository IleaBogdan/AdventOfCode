#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");
#define endl "\n"

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

bool verif_carry_bit(string w, int num);
bool verif_inter_xor(string w, int num);
bool verif_direct_carry(string w, int num);
bool verif_recarry(string w, int num);
string makeWire(char c, int num)
{
    string xorC{c};
    xorC+="0";
    if (num>9){
        xorC.pop_back();
    }
    xorC+=to_string(num);
    return xorC;
}
bool verif_inter_xor(string w, int num)
{
    if (!c.count(w))return false;
    form f4=c[w];
    if (f4.oper!="XOR")return false;
    return f4.x==makeWire('x', num) && f4.y==makeWire('y', num);
}
bool verif_direct_carry(string w, int num)
{
    if (!c.count(w))return false;
    form f5=c[w];
    if (f5.oper!="AND")return false;
    return f5.x==makeWire('x', num) && f5.y==makeWire('y', num);
}
bool verif_recarry(string w, int num)
{
    if (!c.count(w))return false;
    form f5=c[w];
    if (f5.oper!="AND")return false;
    return verif_inter_xor(f5.x, num) && verif_carry_bit(f5.y, num) ||
            verif_inter_xor(f5.y, num) && verif_carry_bit(f5.x, num);
}
bool verif_carry_bit(string w, int num)
{
    if (!c.count(w))return false;
    form f4=c[w];
    if (num==1)return f4.oper=="AND" && f4.x=="x00" && f4.y=="y00";
    if (f4.oper!="OR")return false;
    return verif_direct_carry(f4.x, num-1) && verif_recarry(f4.y, num-1) ||
            verif_direct_carry(f4.y, num-1) && verif_recarry(f4.x, num-1);
}
bool verif_z(string w, int num)
{
    if (!c.count(w))return false;
    form f3=c[w];
    if (f3.oper!="XOR")return false;
    if (num==0)return f3.x=="x00" && f3.y=="y00";
    return verif_inter_xor(f3.x, num) && verif_carry_bit(f3.y, num) ||
            verif_inter_xor(f3.y, num) && verif_carry_bit(f3.x, num);
}
bool verif(int num)
{
    return verif_z(makeWire('z', num), num);
}
int progress()
{
    int i=0;
    while (true){
        if (!verif(i++))break;
    }
    return i;
}
void p2()
{
    //read();
    //new read:
    string s;
    while (getline(fin, s)){
        if (s=="")break;
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
    for (int rp=0; rp<4; ++rp){
        int b=progress();
        //auto keepC=c;
        bool ok=true;
        for (auto x:c){
            if (!ok)break;
            for (auto y:c){
                // swap
                swap(c[x.first], c[y.first]);
                if (progress()>b){
                    ok=false;
                    fout<<x.first<<" - "<<y.first<<endl;
                    break;
                }
                // reswap
                swap(c[x.first], c[y.first]);
            }
        }
        cout<<"failed on: "<<b<<endl;

    }
}
int main()
{
    //p1();
    p2();
}