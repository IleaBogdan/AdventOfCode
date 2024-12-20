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
                            // contidie exemplu:
                            // ++num;
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
int value;
int upoint(int i, int j, int k)
{
    int count=0;
    int add_i=k, add_j=0;
    while (add_i){
        for (int pk=0; pk<4; ++pk){
            int pi=i+add_i*di[pk], pj=j+add_j*dj[pk];
            if (inMat(pi, pj)){
                if (v[pi][pj]!='#' && mat[pi][pj]>mat[i][j]){
                    //++count;
                    count+=bool(mat[pi][pj]>mat[i][j]+50);
                }
            }
        }
        --add_i;
        ++add_j;
    }
    return count;
}
int cheat(int i, int j)
{
    int count=0;
    for (int k=2; k<=20; ++k){
        count+=upoint(i, j, k);
    }
    return count;
}
void p2()
{
    int si, sj, ei, ej;
    find(si, sj, ei, ej);
    lee(si, sj);
    int num=0;
    value=mat[ei][ej];
    for (int i=1; i<n-1; ++i){
        for (int j=1; j<m-1; ++j){
            if (v[i][j]!='#'){
                num+=cheat(i, j);
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