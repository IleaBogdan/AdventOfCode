#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include <climits>
#include <queue>
#include <sstream>

using namespace std;

//ifstream fin("date.in");
ofstream fout("date.out");

bool grid[100][100];
int mat[100][100], n=70, m=70;
int di[]={0, 1, 0, -1}, dj[]={1, 0, -1, 0};
bool inMat(int i, int j){
    return i>=0 && j>=0 && i<=n && j<=m;
}
void lee(int i, int j)
{
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
                if (!mat[pi][pj] && !grid[pi][pj]){
                    mat[pi][pj]=mat[i][j]+1;
                    q.push({pi, pj});
                }
            }
        }
    }
}
void p1(){
    int x, y, cnt=0;
    string s;
    while (cin>>s){
        if (cnt==1024)break;
        ++cnt;
        s[s.find(',')]=' ';
        stringstream sin(s);
        sin>>x>>y;
        grid[x][y]=true;
    }
    lee(0, 0);
    fout<<mat[n][m]-1<<endl;
    for (int i=0; i<=n; ++i){
        for (int j=0; j<=n; ++j){
            fout<<grid[i][j]<<"  ";
        }
        fout<<endl;
    }
}
int main()
{
    freopen("date.in", "r", stdin);
    p1();
    //p2();
}
