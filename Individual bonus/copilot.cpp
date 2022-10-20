#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
//function to add feminine pronouns to masculine pronouns in a sentence and cout the result with or between the pronouns
void addFemininePronouns(string &sentence, string masculinePronoun, string femininePronoun)
{
    //find the masculine pronoun in the sentence
    size_t pos = sentence.find(masculinePronoun);
    //if the masculine pronoun is found
    if (pos != string::npos)
    {
        //add the feminine pronoun to the sentence
        sentence.insert(pos, femininePronoun + " or ");
    }
}
int main(){
    //declare variables
    string sentence;
    //get the sentence from the user
    cout << "Enter a sentence: ";
    getline(cin, sentence);
    //add feminine pronouns to the sentence
    addFemininePronouns(sentence, "he", "she");
    addFemininePronouns(sentence, "He", "She");
    addFemininePronouns(sentence, "him", "her");
    addFemininePronouns(sentence, "His", "Her");
    addFemininePronouns(sentence, "Him", "Her");
    //cout the sentence
    cout << sentence << endl;
    return 0;
}