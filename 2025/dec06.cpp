#include"lib.h"

vector<vector<size_t>>nums;
void p1(void){
    string s;
    size_t res=0;
    while(getline(cin,s)){
        if(s.find('+')==string::npos&&s.find('*')==string::npos){
            nums.push_back({});
            stringstream sin(s);
            size_t x;
            while(sin>>x){
                nums.back().push_back(x);
            }
        }else{
            char c;
            size_t i=0;
            stringstream sin(s);
            while(sin>>c){
                cerr<<"-- "<<c<<" --"<<endl;
                if(c=='+'){
                    size_t tres=0;
                    for(int j=0;j<nums.size();++j){
                        // cerr<<nums[j][i]<<" ";
                        tres+=nums[j][i];
                    }
                    res+=tres;
                    // cerr<<tres<<endl;
                }else{
                    size_t tres=1;
                    for(int j=0;j<nums.size();++j){
                        tres*=nums[j][i];
                    }                    
                    res+=tres;
                    // cerr<<tres<<endl;
                }
                ++i;
            }
        }
    }
    cout<<res; // sol: 6635273135233
}
void p2(void){
    string s;
    size_t res=0;
    while(getline(cin,s)){
        if(s.find('+')==string::npos&&s.find('*')==string::npos){
            nums.push_back({});
            stringstream sin(s);
            size_t x;
            while(sin>>x){
                nums.back().push_back(x);
            }
        }else{
            char c;
            size_t i=nums[0].size()-1;
            stringstream sin(s);
            while(sin>>c){
                // cerr<<"-- "<<c<<" --"<<endl;
                if(c=='+'){
                    
                }else{
                    
                }
                ++i;
            }
        }
    }
    cout<<res;
}
signed main(...){
    freopen("date.in","r",stdin);
    freopen("date.out","w",stdout);
    // p1();
    p2();
    return 0;
}