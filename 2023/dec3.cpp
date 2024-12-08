#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>

using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");


                set<pair<int, int>> seen;
vector<string> v;
int di[]={-1, -1, -1, 0, 1, 1, 1, 0},
    dj[]={-1, 0, 1, 1, 1, 0, -1, -1};
bool inMat(int i, int j){
    return i>=0 && j>=0 && i<v.size() && j<v[0].size();
}
bool adjs(int i, int j)
{
    //cout<<v[i][j]<<endl;
    for (int k=0; k<8; ++k){
        int pi=i+di[k], pj=j+dj[k];
        //cout<<k<<endl;
        if (inMat(pi, pj)){
            if (v[pi][pj]!='.' && !isdigit(v[pi][pj])){
                return true;
            }
        }
    }
    return false;
}
int get_num(string s, int i)
{
    int num=0;
    while (i<s.size() && isdigit(s[i])){
        num*=10;
        num+=s[i]-'0';
        ++i;
    }
    return num;
}
void p1()
{
    string s;
    while (fin>>s){
        v.push_back(s);
    }
    int tot=0;
    for (int i=0; i<v.size(); ++i){
        for (int j=0; j<v[0].size(); ++j){
            if (isdigit(v[i][j])){
                int num=get_num(v[i], j), jj=0;
                bool ok=false;
                for (jj=j; jj<v[i].size() && isdigit(v[i][jj]); ++jj){
                    ok|=adjs(i, jj);
                }
                tot+=ok*num;
                //cout<<num<<endl;
                j=jj;
                //exit(0);
            }
        }
    }
    fout<<tot;
}
void p2()
{
    string s;
    while (fin>>s){
        v.push_back(s);
    }
    long long tot=0;
    for (int i=0; i<v.size(); ++i){
        for (int j=0; j<v[i].size(); ++j){
            if (v[i][j]=='*'){
                int num1=0, num2=0;
                int ti=i-1, tj=j-1;
                for (int k=0; k<8; ++k){
                    int pi=i+di[k], pj=j+dj[k];
                    if (inMat(pi, pj) && !seen.count({pi, pj})){
                        if (isdigit(v[pi][pj])){
                            while (isdigit(v[pi][pj])){
                                seen.insert({pi, pj});
                                --pj;
                            }
                            ++pj;
                            int num=0;
                            while (isdigit(v[pi][pj]) && pj<v[pi].size()){
                                num*=10;
                                num+=v[pi][pj]-'0';
                                seen.insert({pi, pj});
                                ++pj;
                            }
                            if (!num1)
                                num1=num;
                            else num2=num;
                        }
                    }
                }
                cout<<num1<<" "<<num2<<endl;
                tot+=num1*num2;
            }
        }
    }
    fout<<tot;
}
int main(){
    //p1();
    p2();
}