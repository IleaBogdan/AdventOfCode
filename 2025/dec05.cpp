#include"lib.h"

#define int size_t

set<pair<int,int>>fresh;
void p1(void){
    string s;
    int num,cnt=0;
    while(getline(cin,s)){
        if(s==" "){
            break;
        }
        stringstream sin(s);
        if(s.find('-')==string::npos){
            while(cin>>num){
                for(auto it:fresh){
                    if(it.first>num)break;
                    if(it.first<=num&&num<=it.second){
                        ++cnt;
                        break;
                    }
                }
            }
            continue;
        }
        int x,y;
        char c;
        sin>>x>>c>>y;
        fresh.insert({x,y});
    }
    cout<<cnt<<endl; // sol: 694
}
signed main(...){
    freopen("date.in","r",stdin);
    freopen("date.out","w",stdout);
    p1();
    return 0;
}