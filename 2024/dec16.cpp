#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include <climits>
#include <queue>
#include <map>


using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");

vector<string> v;
int dij1[150][150], dij2[150][150], n, m, di[]={1, 0, -1, 0}, dj[]={0, 1, 0, -1};
int sc[]={-1, 0, 1}, sum[]={1001,1,1001};
bool inmat(int i, int j){
    return i>=0 && j>=0 && i<n && j<m;
}

//set<pair<int, int>> st;
void dijkstra(int i, int j, int dir, int dij[][150]=dij1)
{
    set<pair<pair<int, int>, pair<int,int>>> st;
    st.insert({{0, dir}, {i, j}});
    dij[i][j]=0;
    while (!st.empty()){
        //cout<<i<<" - "<<j<<endl;
        i=st.begin()->second.first;
        j=st.begin()->second.second;
        dir=st.begin()->first.second;
        int tmp=st.begin()->first.first;
        st.erase(st.begin());
        if (tmp>dij[i][j])continue;
        for (int k=0; k<3; ++k){
            int kk=(dir+4+sc[k])%4;
            int pi=i+di[kk], pj=j+dj[kk];
            if (inmat(pi, pj)){
                if (v[pi][pj]!='#'){
                    if (dij[pi][pj]>dij[i][j]+sum[k]){
                        dij[pi][pj]=dij[i][j]+sum[k];
                        st.insert({{dij[pi][pj], kk}, {pi, pj}});
                    }
                }
            }
        }
    }
}
void reset(int dij[][150]){
    for (int i=0; i<n; ++i){
        for (int j=0; j<m; ++j){
            dij[i][j]=INT_MAX;
        }
    }
}
int smallestPath(int si, int sj, int ei, int ej)
{
    int mi=INT_MAX;
    reset(dij1);
    dijkstra(si, sj, 1);
    return dij1[ei][ej];
}
void read()
{
    string s;
    while (fin>>s){
        v.push_back(s);
    }
    n=v.size(), m=v[0].size();
}
void find(int &si, int &sj, int &ei, int &ej)
{
    for (int i=0; i<n; ++i){
        for (int j=0; j<m; ++j){
            if (v[i][j]=='S'){
                si=i, sj=j;
            }
            if (v[i][j]=='E'){
                ei=i, ej=j;
            }
            //dij[i][j]=INT_MAX;
        }
    }
}
void p1(){
    read();
    int si, sj, ei, ej;
    find(si, sj, ei, ej);
    fout<<smallestPath(si, sj, ei, ej);
}
int ei, ej;
int dijkstra2(int i, int j, int dir, int dij[][150]=dij1)
{
    map<pair<int, int>,  set<pair<int, int>>> paths;
    paths[{i, j}].insert({i, j});
    set<pair<pair<int, int>, pair<int,int>>> st;
    st.insert({{0, dir}, {i, j}});
    dij[i][j]=0;
    while (!st.empty()){
        //cout<<i<<" - "<<j<<endl;
        i=st.begin()->second.first;
        j=st.begin()->second.second;
        paths[{i, j}].insert({i, j});
        dir=st.begin()->first.second;
        int tmp=st.begin()->first.first;
        st.erase(st.begin());
        if (tmp>dij[i][j])continue;
        for (int k=0; k<3; ++k){
            int kk=(dir+4+sc[k])%4;
            int pi=i+di[kk], pj=j+dj[kk];
            if (inmat(pi, pj)){
                if (v[pi][pj]!='#'){
                    if (dij[pi][pj]>dij[i][j]+sum[k]){
                        dij[pi][pj]=dij[i][j]+sum[k];
                        st.insert({{dij[pi][pj], kk}, {pi, pj}});
                        paths[{pi, pj}].clear();
                    } 
                    if (dij[pi][pj]==dij[i][j]+sum[k]){
                        for (auto it:paths[{i, j}]){
                            paths[{pi, pj}].insert(it);
                        }
                    }
                }
            }
        }
    }
    return paths[{ei, ej}].size();
}
void p2(){
    read();
    cout<<"fuck\n";
    int si, sj, sm;
    find(si, sj, ei, ej);
    reset(dij1);
    fout<<dijkstra2(si, sj, 1);    
}
int main()
{
    //p1();
    p2();
}