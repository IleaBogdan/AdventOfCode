#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");

vector<vector<int>> v;
int n, m, di[]={0, 1, 0, -1}, dj[]={1, 0, -1, 0};
bool inMat(int i, int j)
{
    return i>=0 && j>=0 && i<n && j<m;
}
int lee(int i, int j)
{
    queue<pair<int, int>> q;
    q.push({i, j});
    map<int, map<int, int>>mp;
    mp[i][j]=1;
    int c10=0;
    while (!q.empty()){
        i=q.front().first, j=q.front().second;
        //cout<<i<<" - "<<j<<" --- ";
        q.pop();
        for (int k=0; k<4; ++k){
            int pi=i+di[k], pj=j+dj[k];
            if (inMat(pi, pj)){
                //cout<<pi<<" "<<pj<<" - "<<bool(v[pi][pj]==v[i][j]+1)<<endl;
                if (mp[pi][pj]==0 && v[pi][pj]==v[i][j]+1){
                    cout<<pi<<" - "<<pj<<endl;
                    mp[pi][pj]=mp[i][j]+1;
                    q.push({pi, pj});
                    if (mp[pi][pj]==10)++c10;
                }
            }
        }
        //break;
        //cout<<endl;
    }
    return c10;
}
void p1()
{
    string s;
    while (fin>>s){
        v.push_back({});
        for (auto it:s){
            v.back().push_back(it-'0');
        }
    }
    set<pair<int, int>> points;
    n=v.size();
    m=v[0].size();
    for (int i=0; i<n; ++i){
        for (int j=0; j<m; ++j){
            if (!v[i][j])points.insert({i, j});
        }
    }
    int tot=0;
    for (auto it:points){
        tot+=lee(it.first, it.second);
        //break;
    }
    fout<<tot;
}
int bt(int i, int j)
{
    if (v[i][j]==9)return 1;
    int cnt=0;
    for (int k=0; k<4; ++k){
        int pi=i+di[k], pj=j+dj[k];
        if (inMat(pi, pj)){
            if (v[pi][pj]==v[i][j]+1){
                cnt+=bt(pi, pj);
            }
        }
    }
    return cnt;
}
void p2()
{
    string s;
    while (fin>>s){
        v.push_back({});
        for (auto it:s){
            v.back().push_back(it-'0');
        }
    }
    set<pair<int, int>> points;
    n=v.size();
    m=v[0].size();
    for (int i=0; i<n; ++i){
        for (int j=0; j<m; ++j){
            if (!v[i][j])points.insert({i, j});
        }
    }
    int tot=0;
    for (auto it:points){
        tot+=bt(it.first, it.second);
        //break;
    }
    fout<<tot;
}
int main()
{
    //p1();
    p2();
}