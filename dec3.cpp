#include <bits/stdc++.h>

using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");

int finding(const string &s, int i)
{
    string tmp="";
    while (i<s.size() && tmp!="mul("){
        if (s[i]=='m' && tmp.empty()){
            tmp.push_back('m');
        } else if (s[i]=='u' && tmp.back()=='m'){
            tmp.push_back('u');
        } else if (s[i]=='l' && tmp.back()=='u'){
            tmp.push_back('l');
        } else if (s[i]=='(' && tmp.back()=='l'){
            tmp.push_back('(');
        } else if (s[i]=='m'){
            tmp="m";
        } else tmp.clear();
        ++i;
    }
    return i;
}
void p1()
{
    string s,x;
    while (fin>>x){
        s+=x;
    }
    int i=0;
    long long sum=0;
    while (i<s.size()) {
        i=finding(s, i);
        //cout<<s[i]<<" - "<<i<<endl;
        int num1=0, num2=0, j;
        for (j=i; j<=i+3 && s[j]>='0' && s[j]<='9'; ++j){
            num1*=10;
            num1+=s[j]-'0';
        }
        //cout<<s[j]<<" - "<<j<<endl;
        i=j+1;
        if (s[j]!=','){continue;}
        for (j=i; j<=i+3 && s[j]>='0' && s[j]<='9'; ++j){
            num2*=10;
            num2+=s[j]-'0';
        }
        if (s[j]!=')'){i=j; continue;}
        i=j;
        fout<<"mul("<<num1<<","<<num2<<") "<<endl;
        sum+=(long long)(num1)*(long long)(num2);
    }
    fout<<sum;
}
void p2()
{
    string s, x;
    while (fin>>x){
        s+=x;
    }
    long long sum=0;
    bool d=true;
    for (int i=0; i<s.size();++i){
        //cout<<i<<endl;
        if (s[i]=='m'){
            if (s[i+1]=='u' && s[i+2]=='l' && s[i+3]=='('){
                if (d){
                    i+=4;
                    int num1=0, num2=0, j;
                    for (j=i; j<=i+3 && s[j]>='0' && s[j]<='9'; ++j){
                        num1*=10;
                        num1+=s[j]-'0';
                    }
                    //cout<<s[j]<<" - "<<j<<endl;
                    i=j+1;
                    if (s[j]==','){
                        for (j=i; j<=i+3 && s[j]>='0' && s[j]<='9'; ++j){
                            num2*=10;
                            num2+=s[j]-'0';
                        }
                        i=j;
                        if (s[j]==')'){
                            //fout<<"mul("<<num1<<","<<num2<<") "<<endl;
                            sum+=(long long)(num1)*(long long)(num2);
                        }
                    }
                }
            }
        }
        else if (s[i]=='d' && s[i+1]=='o'){
            //cout<<i<<endl;;
            if (s[i+2]=='(' && s[i+3]==')'){
                d=true;
                i+=3;
            }
            else if (s[i+2]=='n' && s[i+3]==char(39) && s[i+4]=='t' && s[i+5]=='(' && s[i+6]==')'){
                d=false;
                i+=6;
            }
        }
    }
    fout<<sum;
}
int main()
{
    //p1();
    p2();
    return 0;
}

