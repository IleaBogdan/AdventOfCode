#include"lib.h"

#define int size_t

set<pair<int,int>>fresh;
vector<pair<int,int>>vfresh;
bool is_fresh(int x){
    for(auto it:fresh){
        if(x<it.first)break;
        if(it.first<=x&&x<=it.second){
            return true;
        }
    }
    return false;
}
pair<int,int> where_fresh(int x){
    for(auto it:fresh){
        if(x<it.first)return make_pair(LLONG_MAX,LLONG_MAX);
        if(it.first<=x&&x<=it.second){
            return it;
        }
    }
    return make_pair(0,0);
}
void p1(void){
    string s;
    int num,cnt=0;
    while(getline(cin,s)){
        if(s==" "){
            break;
        }
        stringstream sin(s);
        if(s.find('-')==string::npos){
            sin>>num;
            cnt+=is_fresh(num);
            continue;
        }
        int x,y;
        char c;
        sin>>x>>c>>y;
        fresh.insert({x,y});
    }
    cout<<cnt<<endl; // sol: 694
}
void print(const vector<pair<int,int>>&v){
    for(auto it:v){
        cerr<<it.first<<" "<<it.second<<endl;
    }
    cerr<<endl;
}
bool can(pair<int,int>p1,pair<int,int>p2){
    return p2.first<=p1.second;
}
void p2(void){
    string s;
    int num,cnt=0;
    while(getline(cin,s)){
        if(s==" "){
            break;
        }
        stringstream sin(s);
        if(s.find('-')==string::npos){
            break;
        }
        int x,y;
        char c;
        sin>>x>>c>>y;
        vfresh.push_back({x,y});
    }
    sort(vfresh.begin(),vfresh.end(),[](pair<int,int>p1,pair<int,int>p2){
        if(p1.first!=p2.first)return p1.first>p2.first;
        return p1.second>p2.second;
    });
    while(vfresh.size()>1){
        auto e1=vfresh.back();
        vfresh.pop_back();
        if(can(e1,vfresh.back())){
            auto e2=vfresh.back();
            vfresh.pop_back();
            vfresh.push_back(make_pair(e1.first,max(e1.second,e2.second))); // yep, I forgot the max
        }else{
            //cerr<<e1.first<<" "<<e1.first<<endl;
            cnt+=e1.second-e1.first+1;
        }
    }
    cnt+=vfresh.back().second-vfresh.back().first+1;
    cout<<cnt<<endl; // sol: 352716206375547
    // nope1: 339644251944860 -- to big
    // nope2: 339644251944840 -- to low
    // nope3: 334627858315252 
}
signed main(...){
    freopen("date.in","r",stdin);
    freopen("date.out","w",stdout);
    // freopen("cerr.out","w",stderr);
    // p1();
    p2();
    return 0;
}