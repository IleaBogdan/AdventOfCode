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
vector<string>numss;
void p2(void){
    string s;
    while(getline(cin,s)){
        if(s.find('+')==string::npos&&s.find('*')==string::npos){
            numss.push_back(s);
        }
    }
    s.push_back(' ');
    for(int i=0;i<numss.size();++i){
        for(int j=0;j<numss[i].size();++j){
            if(numss[i][j]==' ')numss[i][j]='0';
        }
    }
    for(int i=1;i<s.size();++i){
        if(s[i]!=' '){
            for(int k=0;k<numss.size();++k){
                numss[k][i-1]=' ';
            }
        }
    }
    // for(auto it:numss){
    //     cerr<<it<<endl;
    // }
    nums.push_back({});
    for(int j=0;j<numss[0].size();++j){
        if(numss[0][j]==' '){
            nums.push_back({});
            continue;
        }
        size_t n=0;
        for(int i=0;i<numss.size();++i){
            n*=10;
            n+=(numss[i][j]-'0');
        }
        while(n%10==0)n/=10;
        nums.back().push_back(n);
    }
    char c;
    stringstream sin(s);
    int i=0;
    size_t res=0;
    while(sin>>c){
        size_t tres=bool(c=='*');
        for(auto it:nums[i]){
            // cerr<<it<<" ";
            if(c=='+'){
                tres+=it;
            }else{
                tres*=it;
            }
        }
        // cerr<<tres<<endl;
        res+=tres;
        ++i;
    }
    cout<<res; // sol: 12542543681221
}
signed main(...){
    freopen("date.in","r",stdin);
    freopen("date.out","w",stdout);
    // p1();
    p2();
    return 0;
}