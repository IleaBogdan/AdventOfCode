#include"lib.h"

int minim=0;
void g(int time,bitset<250>b,const vector<bitset<250>>&buttons,int ind=0){
    if(b.none()){
        minim=min(minim,time);
        return;
    }
    for(int i=ind;i<buttons.size();++i){
        g(time+1,b^buttons[i],buttons,ind=i+1);
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
        g(0,fp,buttons);
        sum+=minim;
    }
    cout<<sum;
}
int main(...){
    open_file();
    part1();
    return 0;
}