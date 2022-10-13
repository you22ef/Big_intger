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

    void remove_zeros(vector<int> &v) {
        int len = v.size();
        for (int i = 0; i < len; i++) {
            if (*v.begin() == 0) {
                v.erase(v.begin());
            }
            else {
                break;
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
        vector<int> copy_firstnum = number;
        if (sign == '+' && num2.sign == '+') {
            vector<int> sum;
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
                number = copy_firstnum;
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
                    number = copy_firstnum;
                    

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
                    number = copy_firstnum;
                }
            }
            BigDecimalInt ans;
            ans.number = sum;
            ans.len = ans.number.size();
            ans.sign = '+';
            return ans;
        }
        else if (sign == '+' && num2.sign == '-') {
            num2.sign = '+';
            BigDecimalInt ans = (*this - num2);
            sign = '+';
            ans.len = ans.number.size();
            return ans;
        }
        else if (sign == '-' && num2.sign == '+') {
            sign = '+';
            BigDecimalInt ans = (num2 - *this);
            sign = '-';
            ans.len = ans.number.size();
            return ans;
        }
        else {
            num2.sign = '+';
            BigDecimalInt ans = (*this - num2);
            ans.len = ans.number.size();
            return ans;
        }
    }

    BigDecimalInt operator-(BigDecimalInt num2) {
        vector<int> diff;
        vector<int> copy_firstnum = number;
        BigDecimalInt ans;
        if ((sign == '+' && num2.sign == '+') || (sign == '-' && num2.sign == '-')) {
            if (((num2 < *this) && (sign != '-')) || ((*this < num2) && (sign == '-'))) {
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
                number = copy_firstnum;
                remove_zeros(diff);
                ans.number = diff;
                ans.len = diff.size();
                ans.sign = this->sign;
                return ans;
            }
            else if (((*this < num2) && (sign != '-')) || ((num2 < *this) && (sign == '-'))) {
                if (sign == '-') {
                    sign = '+';
                    num2.sign = '+';
                }
                else {
                    num2.sign = '-';
                }
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
                number = copy_firstnum;
                remove_zeros(diff);
                ans.number = diff;
                ans.len = diff.size();
                ans.sign = num2.sign;
                return ans;
            }
            else {
                ans.number = {0};
                ans.sign = '+';
                ans.len = 1;
                return ans;
            }
        }
        if ((sign == '+' && num2.sign == '-') || (sign == '-' && num2.sign == '+')) {
            if (num2 < *this) {
                num2.sign = '+';
                BigDecimalInt sum = *this + num2;
                sum.sign = '+';
                sum.len = sum.number.size();
                return sum;
            }
            else if (*this < num2) {
                sign = '+';
                BigDecimalInt sum = *this + num2;
                sign = '-';
                sum.sign = '-';
                sum.len = sum.number.size();
                return sum;
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
    BigDecimalInt num1("-1"), num2("1000");
    cout << "num1 = " << num1 << '\n' << "num2 = " << num2 << '\n';
    BigDecimalInt num3;
    BigDecimalInt num4;
    num3 = num1 - num2;
    cout << "num3 = num1 - num2 = " << num3 << '\n';
    cout << "num1 = " << num1 << '\n' << "num2 = " << num2 << '\n';
    num4 = num2 - num1;
    cout << "num4 = num2 - num1 = " << num4 << '\n';
    cout << "num1 = " << num1 << '\n' << "num2 = " << num2 << '\n';
}
