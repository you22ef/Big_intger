#include <bits/stdc++.h>
using namespace std;

class BigDecimalInt {
private:
    vector<int> number;
    int len;
    char sign;

public:
    BigDecimalInt(int decimal);
    BigDecimalInt(string n);
    
    bool operator< (BigDecimalInt num2); 


    BigDecimalInt operator+(BigDecimalInt num2); 
    BigDecimalInt operator-(BigDecimalInt num2); 
    friend ostream& operator<< (ostream& output, BigDecimalInt& d); 

    int size();
    int Sign();
    bool operator> ( BigDecimalInt num2); 
    bool operator ==(BigDecimalInt num2); 
};
