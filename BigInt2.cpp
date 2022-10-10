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

    BigDecimalInt operator-(BigDecimalInt num2) {
        vector<int>sum;
        num2.number[0]='-'+num2.number[0];
        cout<<num2.number[0];
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
   //diffirance(num1.sign,num1.len,num1.number,num2);
   BigDecimalInt num3;
   num3=num1-num2;

}
