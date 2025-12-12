#include "lib.h"

// check how many # we need to place
// if we need to place more # then n*m the input is wrong

void part1(void){
    string s;
    vector<int>base_counts; 
    base_counts.reserve(6);
    for(int i=0;i<6;++i){
        if(!getline(cin,s))return;
        int cnt=0;
        for(int r=0;r<3;++r){
            if(!getline(cin,s))return;
            for(char c:s){
                if(c=='#'){
                    ++cnt;
                }
            }
        }
        base_counts.push_back(cnt);
        getline(cin,s);
    }
    int n,m,sol=0;
    char gunoi;
    while(cin>>n>>gunoi>>m>>gunoi){
        vector<int>times(6);
        for(int i=0;i<6;++i){
            cin>>times[i];
        }
        size_t required=0;
        for(int i=0;i<6;++i)required+=1ull*base_counts[i]*times[i];
        size_t area=1ull*n*m;
        if(area>=required)++sol;
    }
    cout<<sol; // sol: 427
}
int main(...){
    open_file();
    part1();
    return 0;
}