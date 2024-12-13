#include <bits/stdc++.h>

using namespace std;

//#define 1ULL 1LL
ifstream fin("date.in");
ofstream fout("date.out");
void get_prize(long long &x, long long &y, const string &s)
{
    int i=s.find('X');
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
long long minim=LLONG_MAX;
long long px, py;
long long xa, ya, xb, yb;
void rizzlerAproved(int lima=100, int limb=100)
{
    for (int i=0; i<=lima; ++i){
        for (int j=0; j<=limb; ++j){
            if (i*xa+j*xb==px && i*ya+j*yb==py){
                minim=min(minim, (i*3+j)*1LL);
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
        //mA=min(100, min(px/xa, py/ya)+1);
        //B=min(100, min(px/xb, py/yb)+1);
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
    long long tot=0, offset=10000000000000;
    while (getline(fin, s)){
        string aa, bb;
        aa=s;
        getline(fin, bb);
        getline(fin, s);
        fin.get();
        //unsigned long long xa, xb, ya, yb;
        get_prize(xa, ya, aa);
        get_prize(xb, yb, bb);
        get_prize(px, py, s);
        px += 10000000000000;
        py += 10000000000000;
        long long b = (py*xa - px*ya)/((-ya)*xb + yb*xa);
        long long a = (px-xb*b)/xa;
        if(a*xa + b*xb == px && a*ya + b*yb == py)
            tot += a*3 + b;
    }
    fout<<tot;
}
int main()
{
    //p1();
    p2();
    return 0;
}