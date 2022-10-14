#include <vector>
#include <string>
#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;

fstream file;
string str_of_recovery;
char filename[100];
vector<string> phrases = {"urgent","penalty","label","invoice","post",
"vulnerability","postal","click","copy","fedex","statement","financial",
"violations","usps","tax","notification","irs","law","no" ,"delivery","copyright",
"verification required","use the following link","your password is about to expire",
"action required","to perform the verification","click the link",
"fill this form","account has been locked","click here to unlock your account"};
vector<int> values = {5,5,5,5,5,5,4,4,4,4,4,3,3,3,3,3,2,2,2,2,2,5,5,5,5,5,5,5,5,5};

void load_file(){
    cout << "welcome to the phishing scanner!\n";
    cout << "please enter the txt-file name you want to deal with: ";
    cin >> filename;
    strcat(filename, ".txt");
    file.open(filename);
    if(file.fail()){
        cout << "this file doesn't exist. try again.\n";
        load_file();
    }
    file.close();
}

string tolower(string str){
    for(int i = 0; i < str.length(); i++){
        if(isalpha(str[i])) {
            str[i] = tolower(str[i]);
        }
    }
    return str;
}

void phish_scan(){
    cout << "here's your phishing scan..\n";
    int total_points = 0;
    for (int i = 0; i < 21; i++) {
        file.open(filename, ios::in);
        string temp_word;
        long long word_counter = 0;
        long long point_counter = 0;
        while(!file.eof()){
            file >> temp_word;
            if(tolower(temp_word) == phrases[i]) {
                word_counter += 1;
                point_counter += values[i];
            }
        }
        if (word_counter > 0) {
            total_points += point_counter;
            cout << "the phrase (" << phrases[i] << ") occurrences (" << word_counter << ") points (" << point_counter << ")\n";
        }
        file.close();
    }
    for (int i = 21; i < 30; i++) {
        file.open(filename, ios::in);
        string line;
        long long word_counter = 0;
        long long point_counter = 0;
        while (!file.eof()) {
            getline(file, line);
            string lower = tolower(line);
            if (lower.find(phrases[i]) != string::npos) {
                word_counter += 1;
                point_counter += values[i];
            }
        }
        if (word_counter > 0) {
            total_points += point_counter;
            cout << "the phrase (" << phrases[i] << ") occurrences (" << word_counter << ") points (" << point_counter << ")\n";
        }
        file.close();
    }
    cout << "total points = " << total_points;
}


int main() {
    load_file();
    phish_scan();
}