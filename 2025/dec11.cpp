// very important note: it has no cycles
#include"lib.h"

void part1(void){
    string s;
    map<string,vector<string>>g;
    while(getline(cin,s)){
        stringstream sin(s);
        string x,reader;
        sin>>x;
        x.pop_back();
        while(sin>>reader){
            g[x].push_back(reader);
        }
    }
    // for(auto it:g){
    //     cerr<<it.first<<": ";
    //     for(auto s:it.second){
    //         cerr<<s<<" ";
    //     }
    //     cerr<<endl;
    // }
    queue<string>q;
    q.push("you");
    map<string,int>d;
    d["you"]++;
    while(!q.empty()){
        auto i=q.front();
        //cerr<<i<<" "<<d[i]<<endl;
        q.pop();
        for(auto it:g[i]){
            d[it]++;
            q.push(it);
        }
    }
    cout<<d["out"]; // sol: 668
}
int main(...){
    open_file();
    part1();
    return 0;
}