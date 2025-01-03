#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");

vector<string> v;
int n, m;
void read()
{
    string s;
    while (getline(fin, s)){
        v.push_back(s);
    }
    n=v.size();
    m=v[0].size();
}
void find(int &si, int &sj, int &ei, int &ej)
{
    for (int i=0; i<n; ++i){
        for (int j=0; j<m; ++j){
            if (v[i][j]=='S'){
                si=i;
                sj=j;
            } else if (v[i][j]=='E'){
                ei=i;
                ej=j;
            }
        }
    }
}
map<int, map<int, int>> mat;
int di[]={0, 1, 0, -1}, dj[]={1, 0, -1, 0};
bool inMat(int i, int j)
{
    return i>=0 && j>=0 && i<n && j<m;
}
void lee(int i, int j)
{
    mat.clear();
    queue<pair<int, int>> q;
    q.push({i, j});
    mat[i][j]=1;
    while (!q.empty()){
        i=q.front().first;
        j=q.front().second;
        q.pop();
        for (int k=0; k<4; ++k){
            int pi=i+di[k], pj=j+dj[k];
            if (inMat(pi, pj)){
                if (v[pi][pj]!='#' && !mat[pi][pj]){
                    mat[pi][pj]=mat[i][j]+1;
                    q.push({pi, pj});
                }
            }
        }
    }
}
void p1()
{
    int si, sj, ei, ej;
    find(si, sj, ei, ej);
    lee(si, sj);
    int value=mat[ei][ej], num=0;
    for (int i=1; i<n-1; ++i){
        for (int j=1; j<m-1; ++j){
            if (v[i][j]!='#'){
                for (int k=0; k<4; ++k){
                    int pi1=i+di[k], pj1=j+dj[k], 
                        pi2=i+2*di[k], pj2=j+2*dj[k];
                    if (inMat(pi2, pj2) && v[pi1][pj1]=='#'){
                        if (v[pi2][pj2]!='#' && mat[pi2][pj2]>mat[i][j]){
                            // contidie eiemplu:
                            // ejnum;
                            // contindia de 100:
                            num+=bool(mat[pi2][pj2]>mat[i][j]+100);
                        }
                    }
                }
            }
        }
    }
    fout<<num;
}
int mhdist(pair<int, int> x, pair<int, int> y)
{
    return abs(x.first-y.first)+abs(x.second-y.second);
}
void p2()
{
    int si, sj, ei, ej;
    find(si, sj, ei, ej);
    lee(si, sj);
    int num=0;
    int x=si, y=sj;
    while (x!=ei || y!=ej) {
        for (int i=x-20; i<=x+20; ++i) {
            for (int j=y-(20-abs(x-i)); j<=y+(20-abs(x-i)); ++j) {
                if (inMat(i, j) && v[i][j]!='#' && mat[x][y]+abs(x-i)+abs(y-j)+100<=mat[i][j]) {
                    ++num;
                }
            }
        }
        for (int p=0; p<4; ++p) {
            if (mat[x+di[p]][y+dj[p]]==mat[x][y]+1) {
                x+=di[p]; 
                y+=dj[p];
                break; 
            }
        }
    }
    fout<<num;
}
int main()
{
    read();
    //p1();
    p2();
}