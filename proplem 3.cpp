#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Scores {
private:
    vector<string>names = {"ahmed","mohmed","hassan","salma","mostafa","saaied","bob","youssef","seif","sara"};
    vector<string>snames = { "ahmed","mohmed","hassan","salma","mostafa","saaied","bob","youssef","seif","sara" };
    vector<int>scores = {10,6,100,50,30,90,44,33,77,86};
    vector<int>scores2 = { 10,6,100,50,30,90,44,33,77,86 };
    bool check = false;

public:
    void sort_data() {

        int len = names.size();
        bool exist = true;
        if (check) {
            for (int i = 1; i < len; i++) {
                if (scores[0] == scores[i]) {
                    scores.insert(scores.begin() + i, scores[0]);
                    snames.insert(snames.begin() + i, snames[0]);
                    scores.erase(scores.begin());
                    snames.erase(snames.begin());
                    exist = false;
                }
                
            }
           
        }
        if (exist) {
            sort(scores.begin(), scores.end());
            for (int i = 0; i < len; i++) {
                for (int j = 0; j < len; j++) {
                    if (scores[i] == scores2[j]) {
                        snames[i] = names[j];
                    }
                }
            }
            check = true;
        }
        else {
            return;
        }
    }
    void add_player(string n , int s) {
        if (s > scores[0]) {
            scores[0] = s;
            snames[0] = n;
        }
        for (int i = 0; i < 10; i++) {
            scores2[i] = scores[i];
            names[i] = snames[i];
        }
        cout << endl;
        sort_data();
     }
    friend ostream& operator<<(ostream& output, Scores& d) {
        for (int i = 9; i > 0; i--) {
            cout << d.snames[i] << "  " << d.scores[i] << endl;
        }
        return output;
    }
    void print_player(string a) {
        for (int i = 0; i < 10; i++) {
            if (a == snames[i]) {
                cout << snames[i] << "    " << scores[i] << endl;
            }
        }
    }

};
int main()
{
    string name;
    int score;
    Scores a;
    a.sort_data();
    while (true) {
        string name;
        int score;
        int choice;
        cout << "Welcom what do you want to do today \n 1- Add player \n 2- print the top 10 names and scores \n 3- choose a player to see its score" << endl;
        cin >> choice;
        if (choice == 1) {
            cout << endl << "please enter the name of the player : ";
            cin >> name;
            cout << endl << "please enter the score of the player : ";
            cin >> score;
            a.add_player(name, score);
        }
        else if (choice == 2) {
            cout << a;
        }
        else {
            cout << endl << "please enter the name of the player : ";
            cin >> name;
            a.print_player(name);
        }
        
        
    }
        
}
