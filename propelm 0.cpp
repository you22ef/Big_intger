#include <iostream>
#include <vector>
#include <cctype>
#include <cmath>
using namespace std;

class Correct_sentence {
private:
    vector<char>sen;
    int len;
public:
    Correct_sentence(string a) {
        len = a.length();
        sen.resize(len);
        for (int i = 0; i < len; i++) {
            sen[i] = a[i];
        }
        sen[0] = toupper(sen[0]);
        int counter = 0;
        for (int i = 0; i < len; i++) {
            if (isupper(sen[i]) && i != 0) {
                sen[i] = tolower(sen[i]);
            }
            if (isspace(sen[i])) {
                counter++;
            }
            else {
                if (counter > 1) {
                    sen.erase(sen.begin() + abs(i - counter), sen.begin() + (i - 1));
                    sen.resize(sen.size());
                    len = sen.size();
                    i -= counter;
                    counter = 0;
                }
                else {
                    counter = 0;
                }
            }
        }

    }
    friend ostream& operator <<(ostream& output, Correct_sentence& b) {
        for (int i = 0; i < b.len; i++) {
            output << b.sen[i];
        }
        return output;
    }

};

int main()
{
    Correct_sentence a("the      Answer       to      life,      the      Universe     and    everything   IS 42.");
    cout << a;
}
