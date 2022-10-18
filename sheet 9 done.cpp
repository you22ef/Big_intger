#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
void word_compare();
void char_compare();
using namespace std;

fstream file;
fstream myfile;
char name1[20];
char name2[20];

int main(){
    cout<<"Hi user!\nPlease enter the name of the two files you want to compare to each other\n";
    cin>>name1;
    cin>>name2;

    strcat(name1,".txt");
    strcat(name2,".txt");
    cout<<"Please choose..How you want to compare the two files ?\n1)char by char\n2)word by word\n";
    int choose;
    
    while(true){
        cin>>choose;
        if(choose ==1){
            char_compare();
        }
        else if(choose ==2){
            word_compare();
        }
        else{
            cout<<"Please choose 1 or 2..try again";
            continue;
        }
        break;
    }
    
}
void char_compare(){
    file.open(name1);
    myfile.open(name2);
    string c1,c2;
    int line=0;
    bool valid =false;
    //done
    while(!file.eof() ){
        line++;
        getline(file,c1);
        getline(myfile,c2);
        if(c1!=c2){
            cout<<"Different characters in second file at Line : "<<line<<"  "<<c2;
            valid=false;
            break;
        }
    }
    if (valid ){
        cout<<"The two files are identical\n";
    }
}


void word_compare(){
    file.open(name1);
    myfile.open(name2);
    string word1,word2,one,two;
    int line=0; 
    string w;
    bool valid=true;
    
    while(file.good() && myfile.good()){
        file>>word1;
        myfile>>word2;
        if(word1!= word2){
            valid=false;
            break;
        }
    }
    while(getline(file,one)){
        getline(myfile,two);
        line ++;
        if(one!= two){
            break;
        }
    }
    
    if (valid ){
        cout<<"The two files are identical\n";
    }
    else{
        cout<<"Different word in second file in line "<<line<<"  "<<word2;
    }
}