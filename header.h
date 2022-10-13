#include <bits/stdc++.h>
using namespace std;

class BigDecimalInt {
private:
    vector<int> number;
    int len;
    char sign;
public:
    BigDecimalInt();
    BigDecimalInt(int decimal);
    BigDecimalInt(string n);

    BigDecimalInt operator-(BigDecimalInt num2);
    BigDecimalInt operator+(BigDecimalInt num2);
    void remove_zeros(vector<int> &v);

    bool operator< (BigDecimalInt num2); 
    BigDecimalInt operator=(BigDecimalInt num2);
 
    friend ostream& operator<< (ostream& output, BigDecimalInt& d); 

    int size();
    int Sign();
    bool operator> ( BigDecimalInt num2); 
    bool operator ==(BigDecimalInt num2); 
};
