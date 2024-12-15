#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>


using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");

vector<string> v;
string dir;
int n, m;
map<char, int> di, dj;
pair<int, int> get_robot()
{
    for (int i=0; i<n; ++i){
        for (int j=0; j<m; ++j){
            if (v[i][j]=='@')return make_pair(i, j);
        }
    }
    return make_pair(n, m);
}
bool all(string s, char c)
{
    for (auto it:s){
        if (c!=it)return false;
    }
    return true;
}
void p1()
{
    string s;
    getline(fin, s);
    v.push_back(s);
    while (getline(fin, s)){
        v.push_back(s);
        if (all(s, '#'))break;
    }
    while (fin>>s){
        dir+=s;
    }
    n=v.size(), m=v[0].size();
    pair<int, int> r=get_robot();
    int ri=r.first, rj=r.second;
    for (auto c:dir){
        int pi=ri+di[c], pj=rj+dj[c];
        while (v[pi][pj]=='O'){
            pi+=di[c];
            pj+=dj[c];
        }
        if (v[pi][pj]=='#')continue;
        while (pi!=ri || pj!=rj){
            v[pi][pj]=v[pi-di[c]][pj-dj[c]];
            pi-=di[c];
            pj-=dj[c];
        }
        v[ri][rj]='.';
        ri+=di[c], rj+=dj[c];
    }
    long long tot=0;
    for (int i=1; i<n-1; ++i){
        for (int j=1; j<m-1; ++j){
            if (v[i][j]=='O'){
                tot+=(100*i+j);
            }
        }
    }
    fout<<tot;
}
string scale(const string & s){
    string st="";
    for (const auto it:s){
        if (it=='.')st+="..";
        else if (it=='O')st+="[]";
        else if (it=='#')st+="##";
        else st+="@.";
    }
    return st;
}
void moveIt(int &ri, int &rj,  const char& c)
{
    set<pair<int, int>> mul;
    int i=ri, j=rj;
    queue<pair<int, int>> q;
    stack<pair<int, int>> st;
    q.push({i, j});
    st.push({i, j});
    mul.insert({i, j});
    while (!q.empty()){
        //cout<<i<<" - "<<j<<endl;
        i=q.front().first+di[c];
        j=q.front().second+dj[c];
        q.pop();
        if (v[i][j]=='['){
            // i,j
            // i,j+1
            pair<int, int> pu1={i, j}, pu2={i, j+1};
            q.push(pu1);
            q.push(pu2);
            
            st.push(pu1);
            st.push(pu2);
            
            mul.insert(pu1);
            mul.insert(pu2);
        } else if (v[i][j]==']'){
            // i,j
            // i,j-1
            pair<int, int> pu1={i, j}, pu2={i, j-1};
            q.push(pu1);
            q.push({i, j-1});
            
            st.push(pu1);
            st.push(pu2);
            
            mul.insert(pu1);
            mul.insert(pu2);
        } else if (v[i][j]=='#'){
            while (!st.empty())st.pop();
            while (!q.empty())q.pop();
            mul.clear();
            return;
        }
        else {
            st.push({i, j});
        }
    }
    for (auto it:mul){
        if (v[it.first][it.second]=='#')return;
    }
    //cout<<mul.size()<<endl;
    while (!st.empty()){
        i=st.top().first;
        j=st.top().second;
        st.pop();
        //cout<<st.size()<<endl;
        int pi=i-di[c], pj=j-dj[c];
        if (mul.count({pi, pj})){
            v[i][j]=v[pi][pj];
        } else {
            v[i][j]='.';
        }
    }
    ri=i+di[c], rj=j+dj[c];
}
void afis(const vector<string>& mat)
{
    for (auto i:mat){
        fout<<i<<endl;
    }
}
void p2()
{
    string s;
    getline(fin, s);
    s=scale(s);
    v.push_back(s);
    while (getline(fin, s)){
        s=scale(s);
        v.push_back(s);
        if (all(s, '#'))break;
    }
    while (fin>>s){
        dir+=s;
    }
    //cout<<dir.size()<<endl;
    n=v.size(), m=v[0].size();
    pair<int, int> r=get_robot();
    int ri=r.first, rj=r.second;
    for (int i=0; i<dir.size(); ++i){
        auto c=dir[i];
        if (i==53){
            fout<<i<<endl;
            afis(v);
        }
        //cout<<i<<" - "<<v[ri][rj]<<endl;
        int pi=ri+di[c], pj=rj+dj[c];
        if (v[pi][pj]=='.'){
            v[ri][rj]='.';
            ri=pi, rj=pj;
            v[ri][rj]='@';
            continue;
        }
        if (v[pi][pj]=='#')continue;
        if (c=='>' || c=='<'){
            while (v[pi][pj]!='.' && v[pi][pj]!='#'){
                pi+=di[c];
                pj+=dj[c];
            }
            if (v[pi][pj]=='#')continue;
            while (pi!=ri || pj!=rj){
                v[pi][pj]=v[pi-di[c]][pj-dj[c]];
                pi-=di[c];
                pj-=dj[c];
            }
            v[ri][rj]='.';
            ri+=di[c], rj+=dj[c];
        } else {
            moveIt(ri, rj, c);
        }
    }
    cout<<"out bitch";
    long long tot=0;
    for (int i=1; i<n-1; ++i){
        for (int j=1; j<m-1; ++j){
            if (v[i][j]=='['){
                tot+=(100*i+j);
            }
        }
    }
    fout<<tot;
}
int main()
{
    di['<']=0;
    dj['<']=-1;
    di['>']=0;
    dj['>']=1;
    di['^']=-1;
    dj['^']=0;
    di['v']=1;
    dj['v']=0;
    //p1();
    p2();
    return 0;
}