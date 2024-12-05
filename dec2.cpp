#include <fstream>
#include <string>
#include <vector>

using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");

int nums(string s, int &i)
{
    int x=0;
    while (s[i]>='0' && s[i]<='9' && i<s.size()){
        x*=10;
        x+=s[i]-'0';
        ++i;
    }
    return x;
}
bool valid(vector<int> v){
    int ok=(abs(v[0]-v[1])<=3 ? (v[0]<v[1] ? 1 : -1) : 0);
    for (int i=1; i<v.size() && ok; ++i){
        if (ok==-1 && v[i]>v[i-1]){
            ok=0;
        } else if (ok==1 && v[i]<v[i-1]){
            ok=0;
        }
        if (abs(v[i]-v[i-1])>3 || v[i]==v[i-1]){
            ok=0;
        }
    }
    return bool(ok);
}
void p1()
{
    string s="";
    int t=0;
    int l=1;
    while(getline(fin, s)){
        vector<int> v;
        for (int i=0; i<s.size(); ++i){
            v.push_back(nums(s, i));
        }

        t+=valid(v);
    }
    fout<<t;
}
void p2()
{
    string s="";
    int t=0;
    int l=1;
    while(getline(fin, s)){
        vector<int> v;
        for (int i=0; i<s.size(); ++i){
            v.push_back(nums(s, i));
        }
        vector<int> tmp;
        int size=v.size();
        bool ok=false;
        for (int i=0; i<size && !ok; ++i){
            for (int j=0; j<size; ++j){
                if (i!=j) tmp.push_back(v[j]);
            }
            ok=valid(tmp);
            tmp.clear();
        }
        t+=ok;
    }
    fout<<t;
}
int main()
{
    //p1();
    p2();
    return 0;
}
