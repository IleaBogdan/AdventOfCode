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
#define endl '\n'

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
ostream& afis(ostream& out, const vector<string>& v){
    for (const auto & it : v){
        out<<it<<endl;
    }
    out<<endl;
    return out;
}
int tonums(string s)
{
    int num=0, i=0;
    while (s[i]==0 && i<s.size()){
        ++i;
    }
    while (isdigit(s[i]) && i<s.size()){
        num*=10, num+=s[i]-'0';
        ++i;
    }
    return num;
}
void p1()
{
    string s;
    long long total=0;
    while (fin>>s){
        vector<string> robot1=solve(s, door);
        vector<string> possible_robot2;
        vector<string> robot2, tmpRobot;
        tmpRobot=robot1;
        for (int rp=0; rp<2; ++rp){
            possible_robot2.clear();
            robot2.clear();
            for (auto it:tmpRobot){
                addback(possible_robot2, solve(it, robot));
            }
            robot2.push_back(possible_robot2.back());
            possible_robot2.pop_back();
            for (auto it:possible_robot2){
                if (it.size()<robot2.back().size()){
                    robot2.clear();
                    robot2.push_back(it);
                } else if (it.size()==robot2.back().size())robot2.push_back(it);
            }
            tmpRobot=robot2;
        }
        //cout<<tonums(s)<<endl;
        total+=(tmpRobot[0].size())*(tonums(s));
    }
    fout<<total;
}
int main()
{
    p1();
}