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
map<string,int>in;
vector<string>topsort(map<string,vector<string>>&g){
    vector<string>sol;
    queue<string>q;
    q.push("svr");
    while(!q.empty()){
        auto i=q.front();
        q.pop();
        sol.push_back(i);
        for(auto it:g[i]){
            --in[it];
            if(in[it]==0){
                q.push(it);
            }
        }
    }
    return sol;
}
void part2(void){
    string s;
    map<string,vector<string>>g;
    while(getline(cin,s)){
        stringstream sin(s);
        string x,reader;
        sin>>x;
        x.pop_back();
        while(sin>>reader){
            in[reader]++;
            g[x].push_back(reader);
        }
    }
    struct valid{
        string s;
        int mask;
    };
    queue<valid>q;
    q.push({"svr",0});
    size_t sol=0ull;
    map<string,map<int,size_t>>dp;
    dp["svr"][0]=1;
    auto sorted=topsort(g);
    for(auto node:sorted){
        for(int mask=0;mask<4;++mask){
            if(!dp[node][mask])continue;
            for(auto it:g[node]){
                auto nmask=mask;
                if(it=="dac")nmask|=1;
                if(it=="fft")nmask|=2;
                dp[it][nmask]+=dp[node][mask];
            }
        }
    }
    cout<<dp["out"][3];
}
int main(...){
    open_file();
    // part1();
    part2();
    return 0;
}