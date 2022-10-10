#include <bits/stdc++.h>
using namespace std;

class BigDecimalInt {
private:
    vector<int> number;
    int len;
    char sign;

public:
    BigDecimalInt() {
    }

    BigDecimalInt(string n) {
        if (n[0] == '-') {
            sign = '-';
            len = n.length()-1;
            number.resize(len);
            for (int i = 0; i < len; i++) {
                number[i] = n[i+1] - '0';
            }
        }
        else if (n[0] == '+') {
            sign = '+';
            len = n.length()-1;
            number.resize(len);
            for (int i = 0; i < len; i++) {
                number[i] = n[i+1] - '0';
            }
        }
        else {
            sign = '+';
            len = n.length();
            number.resize(len);
            for (int i = 0; i < len; i++) {
                number[i] = n[i] - '0';
            }
        }
    }

    bool operator< (BigDecimalInt num2) {
        if (sign == '+' && num2.sign == '-') {
            return false;
        }
        else if (sign == '-' && num2.sign == '+') {
            return true;
        }
        else if (sign == '+' && num2.sign == '+') {
            if (len > num2.len) {
                return false;
            }
            else if (len < num2.len) {
                return true;
            }
            else {
                for (int i = 0; i < len; i++) {
                    if (number[i] > num2.number[i]) {
                        return false;
                    }
                    else if (number[i] < num2.number[i]) {
                        return true;
                    }
                    else {
                        continue;
                    }
                }
                return false;
            }
        }
        else if (sign == '-' && num2.sign == '-') {
            if (len > num2.len) {
                return true;
            }
            else if (len < num2.len) {
                return false;
            }
            else {
                for (int i = 0; i < len; i++) {
                    if (number[i] > num2.number[i]) {
                        return true;
                    }
                    else if (number[i] < num2.number[i]) {
                        return false;
                    }
                    else {
                        continue;
                    }
                }
                return false;
            }
        }
    }

    BigDecimalInt operator+(BigDecimalInt num2) {
        vector<int>sum;
        if (len > num2.len) {
            sum.resize(len);
            num2.number.resize(len);
            int diffirance = len - num2.len;
            for (int i = diffirance; i > 0; i--){
                num2.number.insert(num2.number.begin(), 0);
            }
            for (int i = len - 1; i >= 0; i--) {
                sum[i] = number[i] + num2.number[i];
                if (sum[i] >= 10 && i != 0) {
                    sum[i] = sum[i] % 10;
                    number[i - 1] += 1;
                }
            }
            len = floor(log10(sum[0]) + 1) + len;
        }
        else {
            if (len <  num2.len) {
                sum.resize(num2.len);
                number.resize(num2.len);
                int diffirance = num2.len - len;
                for (int i = diffirance; i > 0; i--) {
                    number.insert(number.begin(), 0);
                }
                for (int i = num2.len - 1; i >= 0; i--) {
                    sum[i] = number[i] + num2.number[i];
                    if (sum[i] >= 10 && i != 0) {
                        sum[i] = sum[i] % 10;
                        number[i - 1] += 1;
                    }
                }
                len = floor(log10(sum[0]) + 1) + num2.len;

            }
            else {
                sum.resize(len);
                for (int i = len - 1; i >= 0; i--) {
                    sum[i] = number[i] + num2.number[i];
                    if (sum[i] >= 10 && i != 0) {
                        sum[i] = sum[i] % 10;
                        number[i - 1] += 1;
                    }
                }
            }
        }
        
        
        number = sum;
        return *this;
    }

    BigDecimalInt operator-(BigDecimalInt num2) {
        vector<int> diff;
        if (sign == '+' && num2.sign == '+') {
            if (diffirance(sign,len,number,num2)==false) {
                cout<<diffirance(sign,len,number,num2)<<endl;
                diff.resize(len);
                num2.number.resize(len);
                int zeros = len - num2.len;
                for (int i = zeros; i > 0; i--){
                    num2.number.insert(num2.number.begin(), 0);
                }
                for (int i = len-1; i >= 0; i--) {
                    if (number[i] >= num2.number[i]) {
                        diff[i] = number[i] - num2.number[i];
                    }
                    else if (number[i] < num2.number[i]) {
                        diff[i] = number[i] - num2.number[i] + 10;
                        number[i-1] -= 1;
                    }
                }
                number = diff;
                return *this;
            }
            else if (diffirance(sign,len,number,num2)==true) {
                num2.sign = '-';
                diff.resize(num2.len);
                number.resize(num2.len);
                int zeros = num2.len - len;
                for (int i = zeros; i > 0; i--){
                    number.insert(number.begin(), 0);
                }
                for (int i = num2.len-1; i >= 0; i--) {
                    if (num2.number[i] >= number[i]) {
                        diff[i] = num2.number[i] - number[i];
                    }
                    else if (num2.number[i] < number[i]) {
                        diff[i] = num2.number[i] - number[i] + 10;
                        num2.number[i-1] -= 1;
                    }
                }
                num2.number = diff;
                return num2;
            }
        }
        
        
    }
    bool diffirance(char sign,int len,vector<int> number ,BigDecimalInt num2){
            if (sign == '+' && num2.sign == '-') {
                cout<<"false";
                return false;
        }
        else if (sign == '-' && num2.sign == '+') {
            cout<<"TRUE";
            return true;
        }
        else if (sign == '+' && num2.sign == '+') {
            if (len > num2.len) {
                cout<<"false";
                return false;
            }
            else if (len < num2.len) {
                cout<<"TRUE";
                return true;
            }
            else {
                for (int i = 0; i < len; i++) {
                    if (number[i] > num2.number[i]) {
                        cout<<"false";
                        return false;
                    }
                    else if (number[i] < num2.number[i]) {
                        cout<<"TRUE";
                        return true;
                    }
                    else {
                        continue;
                    }
                }
                return false;
            }
        }
        
    }
    friend ostream& operator<< (ostream& output, BigDecimalInt& d) {
        if (d.sign == '-') {
            output << d.sign;
        }
        for (int i = 0; i < d.len; i++) {
            output << d.number[i];
        }
        return output;
   }

    
};



int main()
{
   /* BigDecimalInt num1("1056"), num2("56");
    cout << num1 << ' ' << num2 << '\n';
    if (num1 < num2) {
        cout << '1';
    }
    else if (num2 < num1) {
        cout << "0\n";
    }
    BigDecimalInt num3;
    num3 = num1 - num2;
    cout << num3;
    */
   BigDecimalInt num1("153132");
   BigDecimalInt num2("5533331");
   diffirance(num1.sign,num1.len,num1.number,num2);

}
