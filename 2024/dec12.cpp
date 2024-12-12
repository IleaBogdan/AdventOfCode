#include <bits/stdc++.h>

using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");


map<int, string> v;
map<int, map<int, bool>> b, mb;
map<int, map<int, int>> mg;
int di[]={0, 1, 0, -1}, dj[]={1, 0, -1, 0};
int inMat(int i, int j)
{
    return i>=0 && j>=0 && i<v.size() && j<v[0].size();
}
int feel(int i, int j, char c)
{
    int area=1, perim=0;
    queue<pair<int, int>>q;
    b[i][j]=1;
    q.push({i, j});
    while (!q.empty()){
        i=q.front().first, j=q.front().second;
        q.pop();
        for (int k=0; k<4; ++k){
            int pi=i+di[k], pj=j+dj[k];
            if (inMat(pi, pj)){
                if (c==v[pi][pj]){
                    if (!b[pi][pj]){
                        b[pi][pj]=1;
                        q.push({pi, pj});
                        ++area;
                    }
                } else {
                    ++perim;
                }
            }
            else {
                ++perim;
            }
        }
    }
    //cout<<c<<" - "<<area<<" "<<perim<<endl;
    return area*perim;
}
void p1()
{
    string s;
    int n=0, m=0;
    while (getline(fin, s)){
        v[n]=s;
        ++n;
        m=s.size();
    }
    unsigned long long tot=0;
    for (int i=0; i<n; ++i){
        for (int j=0; j<m; ++j){
            if (!b[i][j]){
                tot+=feel(i, j, v[i][j]);
            }
        }
    }
    fout<<tot;
}
void feeler(int i, int j)
{
    mb[i][j]=1;
    --mg[i][j];
    for (int k=0; k<4; ++k){
        int pi=i+di[k], pj=j+dj[k];
        if (mg[pi][pj] && !mb[pi][pj]) feeler(pi, pj);
    }
}
int n=0, m;
set<pair<int, int>> vec;
void dfs(int i, int j)
{
    vec.insert({i, j});
    b[i][j]=true;
    for (int k=0; k<4; ++k){
        int pi=i+di[k], pj=j+dj[k];
        if (inMat(pi, pj)){
            if (!b[pi][pj]){
                dfs(pi, pj);
            }
        }
    }
}
set<pair<pair<int, int>, char>> st;
void gps()
{
    for (auto k:vec){
        if (k.first==0 || v[k.first-1][k.second]!=v[k.first][k.second]){
            st.insert({k, 'U'});
        }
        if (k.first==n-1 || v[k.first+1][k.second]!=v[k.first][k.second]) {
            st.insert({k, 'D'});
        }
        if (k.second==0 || v[k.first][k.second-1]!=v[k.first][k.second]) {
            st.insert({k, 'L'});
        }
        if (k.second==m-1 || v[k.first][k.second+1]!=v[k.first][k.second]) {
            st.insert({k, 'R'});
        }
    }
}
int getSides()
{
    map<pair<double, double>, pair<double, double>> colturi;
    for (auto it:st){
        pair<int, int> nr;
        if (it.second=='U') {
            nr=make_pair(it.first.first-1, it.first.second);
        } else if (it.second=='D') {
            nr=make_pair(it.first.first+1, it.first.second);
        } else if (it.second=='L') {
            nr=make_pair(it.first.first, it.first.second-1);
        } else {
            nr=make_pair(it.first.first, it.first.second+1);
        }
        pair<double,double> e=make_pair((it.first.first+nr.first)/2.0, 
                                        (it.first.second+nr.second)/2.0);
        colturi[e] = {e.first-it.first.first, e.second-it.first.second};
    } 
    set<pair<double, double>> viz;
    int sc=0;
    for (auto it:colturi){
        if (viz.count(it.first))continue;
        viz.insert(it.first);
        ++sc;
        auto r=it.first.first, c=it.first.second;
        if (!fmod(r, 1.0)){
            for (int dr:{-1,1}){
                double cr=r+dr;
                pair<double, double> ne={cr, c};
                while (colturi.count(ne) && colturi[ne]==it.second){
                    viz.insert(ne);
                    cr+=dr;
                    ne={cr, c};
                }
            }
        } else {
            for (int dc:{-1,1}){
                double cc=c+dc;
                pair<double, double> ne={r, cc};
                while (colturi.count(ne) && colturi[ne]==it.second){
                    viz.insert(ne);
                    cc+=dc;
                    ne={r, cc};
                }
            }
        }
    }

    return sc;
}
void p2()
{
    string s;
    while (getline(fin, s)){
        v[n]=s;
        ++n;
        m=s.size();
    }
    unsigned long long tot=0;
    for (int i=0; i<n; ++i){
        for (int j=0; j<m; ++j){
            if (!b[i][j]){
                vec.clear();
                st.clear();
                dfs(i, j);
                int area=vec.size(), sides=0;
                gps();
                tot+=(area*getSides());
            }
        }
    }
    fout<<tot;
}
int main()
{
    //p1();
    p2();
    return 0;
}
