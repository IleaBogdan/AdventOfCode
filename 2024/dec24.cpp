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

bool verify_itermediate_xor(string w, int num);
bool verify_carry_bit(string w, int num);
bool verify_direct_carry(string w, int num);
bool verify_recarry(string w, int num);
void printer(string s, string w, int num)
{
    return;
    printf("%s %s %d\n", s.c_str(), w.c_str(), num);
}
string mkwire(char c, int num)
{
    string s; s.push_back(c);
    if (num<10)s.push_back('0');
    return s+to_string(num);
}
bool verify_itermediate_xor(string w, int num)
{
    printer("vx", w, num);
    string op=c[w].oper, x=c[w].x, y=c[w].y;
    if (op!="XOR")return false;
    return (x==mkwire('x', num) && y==mkwire('y', num)) || (x==mkwire('y', num) && y==mkwire('x', num));
}
bool verify_carry_bit(string w, int num)
{
    printer("vc", w, num);
    string op=c[w].oper, x=c[w].x, y=c[w].y;
    if (num==1){
        if (op=="AND")return false;
        return (x=="x00" && y=="y00") || (x=="y00" && y=="x00");
    }
    if (op!="OR")return false;
    return (verify_direct_carry(x, num-1) && verify_recarry(y, num-1)) || 
            (verify_direct_carry(y, num-1) && verify_recarry(x, num-1));
}
bool verify_direct_carry(string w, int num)
{
    printer("vd", w, num);
    string op=c[w].oper, x=c[w].x, y=c[w].y;
    if (op!="AND")return false;
    return (x==mkwire('x', num) && y==mkwire('y', num)) || (x==mkwire('y', num) && y==mkwire('x', num));
}
bool verify_recarry(string w, int num)
{
    printer("vr", w, num);
    string op=c[w].oper, x=c[w].x, y=c[w].y;
    if (op!="AND")return false;
    return (verify_itermediate_xor(x, num) && verify_carry_bit(y, num)) || 
            (verify_itermediate_xor(y, num) && verify_carry_bit(x, num)); 
}
bool verify_z(string w, int num)
{
    printer("vz", w, num);
    string op=c[w].oper, x=c[w].x, y=c[w].y;
    if (op!="XOR")return false;
    if (num==0)return (x=="x00" && y=="y00") || (x=="y00" && y=="x00");
    return (verify_itermediate_xor(x, num) && verify_carry_bit(y, num)) || 
            (verify_itermediate_xor(y, num) && verify_carry_bit(x, num));
}
bool verify(int num)
{
    return verify_z(mkwire('z', num), num);
}
int progress()
{
    int i=0; 
    while (true){
        if (!verify(i++))break;
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
    for (int _=0; _<4; ++_){
        int b=progress();
        bool ok=false;
        auto mp=c;
        cout<<b<<endl<<endl;
        for (auto ix:mp){
            if (ok)break;
            for (auto jy:mp){
                swap(c[ix.first], c[jy.first]);
                cout<<progress()<<endl;
                if (b<progress()){
                    ok=true;
                    fout<<ix.first<<" "<<jy.first<<" ";
                    break;
                }
                swap(c[ix.first], c[jy.first]);
            }
        }
    }
}
int main()
{
    //p1();
    p2();
}