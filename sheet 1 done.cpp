#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;
int main(){
    
    //vector getting word by word from getline
    cout<<"Welcome user :)\nThe program job is to replace all occurrences of masculine pronouns with both-gender pronouns.\nPlease enter the sentence\n";
    vector<string> v;
    string s;
    int size=1;
    getline(cin,s);
    for (int i = 0; i < s.length(); i++){
        if(s[i]==' '){
            size++;
        }
    }
    string word="",dot=".";
    bool d=false;
        for (int i = 0; i < s.length(); i++){
            if(s[i]!=' ' &&s[i]!='.'){
                word+=s[i];
            }
            
            else if(s[i]=='.'){
                d=true;
            }

            else{
                
                v.push_back(word);
                word="";
                if(d){
                    v.push_back(dot);
                    size++;
                    d=false;
                }
                continue;
            }
        }
        v.push_back(word);
        if(d){
            v.push_back(dot);
            size++;
            d=false;
        }
    

    //main idea
    bool accept=false;
    for(int i=0;i<size;i++){
        if(v[i]=="he" || v[i]=="He"){
            accept = true;
            v.insert(v.begin()+i+1,"or she");
            size++;
        } 

        if(v[i]=="him" ){
            accept = true;
            v.insert(v.begin()+i+1,"or her");
            size++;
        }

        if(v[i]=="his" || v[i]=="His"){
            accept = true;

            if(i==size-1 ){
                v.insert(v.begin()+i+1,"or hers");
                
            }            
            else if(i==size-2 && v[size-1]==dot){
                
                v.insert(v.begin()+i+1,"or hers");
                
            }    
            else{
                v.insert(v.begin()+i+1,"or her");
            }
            size++;
        }
    }

    if(accept){
        for (int i = 0; i < size; i++){
            if(v[i+1]==dot){
                cout<<v[i];
                continue;
            }
            cout<<v[i]<<" ";
        }
    }
    else{
        cout<<"Nothing to change..";
    }
    cout<<"\n\nThanks for using the program ;) ";
}