#include <vector>
#include <string>
#include <iostream>
using namespace std;

vector<string> split(string target, string delimiter) {
	vector<string> split_words;
	string word = "";
	for (int i = 0; i < target.length(); i++) {
		if (target[i] != delimiter[0]) {
			word += target[i];
		}
		else {
			split_words.push_back(word);
			word = "";
		}
	}
	split_words.push_back(word);
	return split_words;
}

int main() {
	vector<string> v1 = split("10,20,30", ",");
	for (int i = 0; i < v1.size(); i++) {
		cout << "v1 = " << v1[i] << '\n';
	}
    cout << '\n';
	vector<string> v2 = split("do re mi fa so la ti do", " ");
	for (int i = 0; i < v2.size(); i++) {
		cout << "v2 = " << v2[i] << '\n';
	}
}