#include <bits/stdc++.h>

using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");

int di[]={-1, -1, -1, 0, 1, 1, 1, 0}, dj[]={-1, 0, 1, 1, 1, 0, -1, -1}, globalCount=0;
map<int, map<int, bool>> b;
void init(int i, int j, map<int, map<int, char>> vs)
{
    string s="XMAS";
    for (int k=0; k<8; ++k){
        bool ok=true;
        for (int num=1; num<=3; ++num){
            int pi=i+num*di[k], pj=j+num*dj[k];
            //cout<<pi<<" - "<<pj<<" ";
            if (pi>=0 && pi<vs.size()){
                //cout<<"in1 ";
                if (pj>=0 && pj<vs[pi].size()){
                    //cout<<"in2 ";
                    if (vs[pi][pj]!=s[num]){
                        ok=false;
                        //cout<<vs[pi][pj]<<" - ";
                    }
                    //cout<<s[num];
                } else ok=false;
            } else ok=false;
            //1cout<<endl;
        }
        if (ok){
            ++globalCount;
            for (int num=0; num<=3; ++num){
                int pi=i+num*di[k], pj=j+num*dj[k];
                if (pi>=0 && pi<vs.size()){
                    if (pj>=0 && pj<vs[pi].size()){
                        b[pi][pj]=1;
                        //cout<<pi<<" - "<<pj<<endl;
                    }
                }
            }
        }
    }
}
void p1()
{
    map<int, map<int, char>> vs;
    string s;
    int index=0;
    while (fin>>s){
        for (int i=0; i<s.size(); ++i){
            vs[index][i]=s[i];
        }
        ++index;
    }
    //map<int, map<int, bool>> b;
    for (int i=0; i<vs.size(); ++i){
        for (int j=0; j<vs[i].size(); ++j){
            if (vs[i][j]=='X'){
                //cout<<"X";
                init(i, j, vs);
            }
        }
    }
    for (int i=0; i<vs.size(); ++i){
        for (int j=0; j<vs[i].size(); ++j){
            if (!b[i][j]){
                vs[i][j]='.';
                //cout<<i<<" - "<<j<<endl;
            }
            //cout<<vs[i][j];
        }
        //cout<<endl;
    }
    fout<<globalCount;
}
void p2()
{
    string s, v[200];
    int n=0, m=0;
    while (fin>>s){
        m=s.size();
        v[n++]=s;
    }
    globalCount=0;
    for (int i=1; i<n-1; ++i){
        for (int j=1; j<=m-1; ++j){
            if (v[i][j]=='A'){
                if (v[i-1][j-1]=='M' && v[i-1][j+1]=='M' &&
                    v[i+1][j-1]=='S' && v[i+1][j+1]=='S')++globalCount;
                else if (v[i-1][j+1]=='M' && v[i+1][j+1]=='M' &&
                    v[i-1][j-1]=='S' && v[i+1][j-1]=='S')++globalCount;
                else if (v[i+1][j+1]=='M' && v[i+1][j-1]=='M' &&
                    v[i-1][j-1]=='S' && v[i-1][j+1]=='S')++globalCount;
                else if (v[i+1][j-1]=='M' && v[i-1][j-1]=='M' &&
                    v[i+1][j+1]=='S' && v[i-1][j+1]=='S')++globalCount;
            }
        }
    }
    fout<<globalCount;
}
int main()
{
    //p1();
    p2();
    return 0;
}
