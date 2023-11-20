#include<bits/stdc++.h>
using namespace std;
int main()
{
    fstream inp,mnt,mdt,ic,ala;
    inp.open("input.txt",ios::in);
    mdt.open("mdt.txt",ios::out);
    mnt.open("mnt.txt",ios::out);
    ala.open("ala.txt",ios::out);
    ic.open("ic.txt",ios::out);
    string line="";
    map<string,string>m;
    int count=0,flag=0;
    while(getline(inp,line)){
        if(line=="MACRO"){
            flag=1;
        }
        else if(line=="MEND"){
            flag=0;
        }
        else if(flag==1){count++;
            mdt<<line<<endl;
            string temp="";
            for(auto ch:line){
                if(ch!=' ') temp+=ch;
                else{
                    mnt<<temp<<" "<<count<<endl;
                    break;
                }
            }
            temp="";
            int check=0;
            int cnt=0;
            for(auto ch:line){
                if(ch=='=') break;
                else if(ch==' ') check=1;
                else if(ch==','){
                    m[temp]='#'+to_string(cnt);
                    cnt++;
                    temp="";
                }
                else if(check){
                    temp+=ch;
                }
            }
            m[temp]='#'+to_string(cnt);
            flag=2;
        }
        else if(flag==2){count++;
            string temp="";
            for(auto ch:line){
                if(ch!=' ') temp+=ch;
                else{
                    mdt<<temp<<" ";
                    break;
                }
            }
            temp="";
            bool check=0;
            for(auto ch:line)
            {
                if(ch=='=') break;
                else if(ch==' ') check=1;
                else if(ch==','){
                    mdt<<m[temp]<<",";
                    temp="";
                }
                else if(check==1){
                    temp+=ch;
                }
            }
            mdt<<m[temp]<<endl;
        }
    }
    inp.close();
    ala.close();
    mdt.close();
    mnt.close();
    ic.close();
}