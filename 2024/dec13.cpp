#include <bits/stdc++.h>

using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");

void get_prize(unsigned long long &x, unsigned long long &y, const string &s)
{
    unsigned int i=s.find('X');
    i+=2;
    //cout<<s[i]<<endl;
    x=0, y=0;
    while (isdigit(s[i])){
        x*=10;
        x+=s[i]-'0';
        ++i;
    }
    i+=4;
    //cout<<s[i]<<endl;
    while (isdigit(s[i]) && i<s.size()){
        y*=10;
        y+=s[i]-'0';
        ++i;
    }
}
long long bpA=0, bpB=0, mA, mB;
unsigned long long minim=LLONG_MAX;
unsigned long long px, py;
unsigned long long xa, ya, xb, yb;
void rizzlerAproved(int lima=100, int limb=100)
{
    for (int i=0; i<=lima; ++i){
        for (int j=0; j<=limb; ++j){
            if (i*xa+j*xb==px && i*ya+j*yb==py){
                minim=min(minim, (i*3+j)*1ULL);
            }
        }
    }
}
void p1()
{
    string s;
    unsigned long long tot=0;
    while (getline(fin, s)){
        string a, b;
        a=s;
        getline(fin, b);
        getline(fin, s);
        fin.get();
        //unsigned long long xa, xb, ya, yb;
        get_prize(xa, ya, a);
        get_prize(xb, yb, b);
        get_prize(px, py, s);
        mA=min(100*1ULL, min(px/xa, py/ya)+1);
        mB=min(100*1ULL, min(px/xb, py/yb)+1);
        //cout<<mA<<" - "<<mB<<endl;
        //generate_minim();
        minim=LLONG_MAX;
        rizzlerAproved();
        tot+=(minim!=LLONG_MAX ? minim : 0);
        cout<<minim<<endl;
    }
    fout<<tot;
}
void p2()
{
    string s;
    unsigned long long tot=0;
    while (getline(fin, s)){
        string a, b;
        a=s;
        getline(fin, b);
        getline(fin, s);
        fin.get();
        //unsigned long long xa, xb, ya, yb;
        get_prize(xa, ya, a);
        get_prize(xb, yb, b);
        get_prize(px, py, s);
        minim=LLONG_MAX;

        /// cod:
        int kpi=0, kpj=0;
        mA=min(px/xa, py/ya)+1;
        mB=min(px/xb, py/yb)+1;
        for (int i=0; i<=mA; ++i){
            if ((px-xa*i)%xb==0 && (py-ya*i)%yb==0 && (py-ya*i)%yb==(px-xa*i)%xb){
                if (minim>1ULL*(i*3+(py-ya*i)/yb)){
                    minim=1ULL*(i*3+(py-ya*i)/yb);
                    //cout<<kpi<<" - "<<kpj<<endl;
                    kpi=i, kpj=(py-ya*i)/yb;
                }
            }
        }
        tot+=(minim!=LLONG_MAX ? minim : 0);
        cout<<minim<<endl;
    }
    fout<<tot;
}
int main()
{
    //p1();
    p2();
    return 0;
}
