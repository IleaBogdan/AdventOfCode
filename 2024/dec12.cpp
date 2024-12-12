#include <bits/stdc++.h>

using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");

vector<string> v;
vector<vector<bool>> b;
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
    while (getline(fin, s)){
        v.push_back(s);
        b.push_back({});
        b.back().resize(s.size(), false);
    }
    unsigned long long tot=0;
    int n=v.size(), m=v[0].size();
    for (int i=0; i<n; ++i){
        for (int j=0; j<m; ++j){
            if (!b[i][j]){
                tot+=feel(i, j, v[i][j]);
            }
        }
    }
    fout<<tot;
}
int feelingsForNig(int i, int j, char c)
{
    int area=1;
    queue<pair<int, int>>q;
    b[i][j]=1;
    q.push({i, j});
    cout<<c<<endl;
    set<pair<int, int>> is, js;
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
                    cout<<pi<<" "<<pj<<" - "<<k<<endl;
                    if (!is.count({pi, k}) && !js.count({pj, k})){
                        is.insert({pi, k});
                        js.insert({pj, k});
                        cout<<"added\n";
                    }
                }
            }
            else {
                cout<<pi<<" "<<pj<<" - "<<k<<endl;
                if (!is.count({pi, k}) && !js.count({pj, k})){
                    is.insert({pi, k});
                    js.insert({pj, k});
                    cout<<"added\n";
                }
            }
        }
    }
    cout<<(is.size()+js.size())/2<<endl;
    return area*(is.size()+js.size())/2;
}
void p2()
{
    string s;
    while (getline(fin, s)){
        v.push_back(s);
        b.push_back({});
        b.back().resize(s.size(), false);
    }
    unsigned long long tot=0;
    int n=v.size(), m=v[0].size();
    for (int i=0; i<n; ++i){
        for (int j=0; j<m; ++j){
            if (!b[i][j]){
                tot+=feelingsForNig(i, j, v[i][j]);
                exit(0);
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
