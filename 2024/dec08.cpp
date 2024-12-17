#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");

vector<string> v;
map<char, vector<pair<int, int>>> antenas;
set<pair<int, int>> points;
bool inMat(int i, int j)
{
    return i>=0 && i<v.size() &&
            j>=0 && j<v[0].size();
}
pair<int,int> point_dist(pair<int, int> x, pair<int, int> y)
{
    return {y.first-x.first, y.second-x.second};
}
void p1()
{
    string s;
    while (fin>>s){
        v.push_back(s);
    }
    for (int i=0; i<v.size(); ++i){
        for (int j=0; j<v[0].size(); ++j){
            if (v[i][j]!='.'){
                antenas[v[i][j]].push_back({i, j});
            }
        }
    }
    for (auto it:antenas){
        char c=it.first;
        for (int i=0; i<antenas[c].size(); ++i){
            for (int j=i+1; j<antenas[c].size(); ++j){
                pair<int, int> p1=antenas[c][i], p2=antenas[c][j];
                pair<int, int> dist=point_dist(p1, p2);

                pair<int,int> np1=make_pair(p1.first-dist.first, p1.second-dist.second), 
                    np2=make_pair(p2.first+dist.first, p2.second+dist.second);
                if (inMat(np1.first, np1.second))points.insert(np1);
                if (inMat(np2.first, np2.second))points.insert(np2);
            }
        }
    }
    fout<<points.size();
}
bool inMat(pair<int, int>x)
{
    return inMat(x.first, x.second);
}
void p2()
{
    string s;
    while (fin>>s){
        v.push_back(s);
    }
    for (int i=0; i<v.size(); ++i){
        for (int j=0; j<v[0].size(); ++j){
            if (v[i][j]!='.'){
                antenas[v[i][j]].push_back({i, j});
            }
        }
    }
    for (auto it:antenas){
        char c=it.first;
        for (int i=0; i<antenas[c].size(); ++i){
            for (int j=i+1; j<antenas[c].size(); ++j){
                pair<int, int> p1=antenas[c][i], p2=antenas[c][j];
                pair<int, int> dist=point_dist(p1, p2);

                pair<int,int> np1=make_pair(p1.first, p1.second), 
                    np2=make_pair(p2.first, p2.second);
                while (inMat(np1)){
                    points.insert(np1);
                    np1.first-=dist.first, np1.second-=dist.second;
                }
                while (inMat(np2)){
                    points.insert(np2);
                    np2.first+=dist.first, np2.second+=dist.second;
                }
            }
        }
    }
    fout<<points.size();
}
int main()
{
    //p1();
    p2();
    return 0;
}