#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <climits>

using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");

int di[]={0, 1, 0, -1}, dj[]={1, 0, -1, 0};
char dm[]=">v<^";
vector<pair<char, char>> zip(string s1, string s2)
{
    vector<pair<char, char>> vc;
    for (int i=0; i<min(s1.size(), s2.size()); ++i){
        vc.push_back({s1[i], s2[i]});
    }
    return vc;
}
void carp(const vector<vector<string>>& v, 
        vector<string>& r, 
        string curr, int i)
{
    if (i==v.size()){
        r.push_back(curr);
        return;
    }
    for (auto it:v[i]){
        carp(v, r, curr+it, i+1);
    }
}
vector<string> solve(string type, vector<string> keypad)
{
    map<char, pair<int, int>> keys;
    for (int i=0; i<keypad.size(); ++i){
        for (int j=0; j<keypad[i].size(); ++j){
            if (keypad[i][j]!=' ') keys[keypad[i][j]]={i, j};
        }
    }
    map<pair<char, char>, vector<string>> seq;
    for (auto ki:keys){
       for (auto kj:keys){
            int i=ki.first, j=kj.first;
            if (i==j){
                seq[{i, j}]={"A"};
                continue;
            }
            vector<string> pos;
            queue<pair<pair<int, int>, string>> q;
            q.push({keys[i], ""});
            int optlen=100000;
            while (!q.empty()){
                pair<int, int> rc=q.front().first;
                string moves=q.front().second;
                q.pop();
                for (int k=0; k<4; ++k){
                    int pi=rc.first+di[k], pj=rc.second+dj[k];
                    if (pi>=0 && pj>=0 && pi<keypad.size() && pj<keypad[0].size()){
                        if (keypad[pi][pj]!=' '){
                            if (keypad[pi][pj]==j){
                                if (optlen<moves.size()+1){
                                    while (!q.empty())q.pop();
                                    break;
                                }
                                optlen=moves.size()+1;
                                pos.push_back(moves+dm[k]+'A');
                            } else {
                                q.push({{pi, pj} , moves+dm[k]});
                            }
                        }
                    }
                }
            }
            seq[{i, j}]=pos;
        }
    }
    auto vc=zip("A"+type, type);
    vector<vector<string>> ops;
    for (auto it:vc){
        ops.push_back(seq[it]);
    }
    vector<string> vs;
    carp(ops, vs, "", 0);
    return vs;
}
vector<string> door={"789","456","123"," 0A"};
vector<string> robot={" ^A", "<v>"};
void addback(vector<string> &v1, vector<string> v2)
{
    for (auto it:v2){
        v1.push_back(it);
    }
}
void p1()
{
    string s;
    long long total=0;
    while (fin>>s){
        vector<string> r1=solve(s, door);
        vector<string> pos_r2;
        for (auto it:r1){
            //cout<<it<<endl;
            addback(pos_r2, (it, robot));
        }
        int minLen=INT_MAX;
        vector<string> r2;
        for (auto it:pos_r2){
            if (minLen>it.size()){
                minLen=it.size();
                r2.clear();
            }
            if (minLen==it.size()){
                r2.push_back(it);
            }
        }
        for (auto it:r2){
            cout<<it<<endl;
            //addback(pos_r2, (it, robot));
        }
    }
}
int main()
{
    p1();
}