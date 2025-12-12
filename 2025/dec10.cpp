#include"lib.h"

int minim=0;
void backtrack1(int time,bitset<250>b,const vector<bitset<250>>&buttons,int ind=0){
    if(b.none()){
        minim=min(minim,time);
        return;
    }
    for(int i=ind;i<buttons.size();++i){
        backtrack1(time+1,b^buttons[i],buttons,ind=i+1);
    }
}
bool all_done(const vector<int>&s){
    for(const auto&it:s){
        if(it)return false;
    }
    return true;
}
bool lower_then_0(const vector<int>&s){
    for(const auto&it:s){
        if(it<0)return true;
    }
    return false;
}
void print_vector(const vector<int>&v){
    for(const auto&it:v){
        cerr<<it<<" ";
    }
    cerr<<endl;
}
void backtrack2(int time,bitset<250>b,const vector<bitset<250>>&buttons,vector<int>costs,int ind=0){
    if(b.none()&&all_done(costs)){
        minim=min(minim,time);
        return;
    }
    print_vector(costs);
    if(lower_then_0(costs))return;
    for(int i=ind;i<buttons.size();++i){
        for(int bit=0;bit<250;++bit){
            if(b[bit]){
                --costs[bit];
            }
        }
        backtrack2(time+1,b^buttons[i],buttons,costs,ind=i+1);
        for(int bit=0;bit<250;++bit){
            if(b[bit]){
                ++costs[bit];
            }
        }
    }
}
void part1(void){
    string s;
    size_t sum=0;
    while(getline(cin,s)){
        while(s.back()!='{')s.pop_back();
        s.pop_back();
        bitset<250>fp;
        reverse(s.begin(),s.end());
        s.pop_back();
        int j=0;
        for(int i=s.size()-1;s[i]!=']';--i){
            fp[j++]=bool(s.back()=='#');
            s.pop_back();
        }
        s.pop_back();
        reverse(s.begin(),s.end());
        vector<string>ibuttons;
        ibuttons.push_back("");
        for(int i=0;i<s.size();++i){
            if(s[i]==')'){
                ibuttons.push_back("");
            }else if(s[i]=='('){
            }else{
                ibuttons.back().push_back(s[i]!=','?s[i]:' ');
            }
        }
        // for(auto i:ibuttons){
        //     cerr<<i<<endl;
        // }
        vector<bitset<250>>buttons;
        for(auto str:ibuttons){
            stringstream sin(str);
            int x;
            buttons.push_back(0);
            while(sin>>x){
                buttons.back()[x]=true;
            }
        }
        minim=(1<<30);
        backtrack1(0,fp,buttons);
        sum+=minim;
    }
    cout<<sum;
}
void part2(void){
    string s;
    size_t sum=0;
    while(getline(cin,s)){
        string brackets="";
        s.pop_back();
        while(s.back()!='{'){
            brackets+=s.back();
            s.pop_back();
        }
        s.pop_back();
        reverse(brackets.begin(),brackets.end());
        vector<int>costs;
        for(auto&it:brackets){
            if(it==',')it=' ';
        }
        // cerr<<brackets<<endl;
        stringstream bin(brackets);
        int x;
        while(bin>>x){
            costs.push_back(x);
        }
        bitset<250>fp;
        reverse(s.begin(),s.end());
        s.pop_back();
        int j=0;
        for(int i=s.size()-1;s[i]!=']';--i){
            fp[j++]=bool(s.back()=='#');
            s.pop_back();
        }
        s.pop_back();
        reverse(s.begin(),s.end());
        vector<string>ibuttons;
        ibuttons.push_back("");
        for(int i=0;i<s.size();++i){
            if(s[i]==')'){
                ibuttons.push_back("");
            }else if(s[i]=='('){
            }else{
                ibuttons.back().push_back(s[i]!=','?s[i]:' ');
            }
        }
        // for(auto i:ibuttons){
        //     cerr<<i<<endl;
        // }
        vector<bitset<250>>buttons;
        for(auto str:ibuttons){
            stringstream sin(str);
            int x;
            buttons.push_back(0);
            while(sin>>x){
                buttons.back()[x]=true;
            }
        }
        minim=(1<<30);
        backtrack2(0,fp,buttons,costs);
        sum+=minim;
    }
    cout<<sum;
}
int main(...){
    open_file();
    // part1();
    part2();
    return 0;
}