#include <iostream> 
#include <cstdlib>
#include <vector>
#include <string>
#include <cmath>
#include <numeric>
using namespace std;
class BigDecimalInt {
private:
    vector<int>number;
    int len;
public:
    BigDecimalInt() {

    }
    BigDecimalInt(string n) {
        len = n.length();
        number.resize(len);
        for (int i = 0; i < len; i++) {
            number[i] = n[i] - '0';
        }
    }
    BigDecimalInt operator+(BigDecimalInt num2) {
        vector<int>sum;
        if (len > num2.len) {
            sum.resize(len);
            num2.number.resize(len);
            int diffirance = len - num2.len;
            for (int i = diffirance; i > 0; i--) {
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
            if (len < num2.len) {
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
        vector<signed int>subtract;
        if (len > num2.len) {
            while (len != num2.len) {
                num2.number.insert(num2.number.begin(), 0);
                num2.len += 1;
            }
            subtract.resize(len);
            for (int i = len-1; i >= 0; i--) {
                int x = i;
                while (number[i] < num2.number[i] && i!=0) {
                    if (number[x - 1] == 0) {
                        x--;
                    }
                    else {
                        number[x - 1] -= 1;
                        number[i] += 10;
                    }
                }
                subtract[i] = number[i] - num2.number[i];
            }
            int z = 0;
            while (subtract[z] == 0) {
                subtract.erase(subtract.begin());
                z++;
            }
        }
        else if(len < num2.len) {
            while (len != num2.len) {
                number.insert(number.begin(), 0);
                len += 1;
            }
            subtract.resize(len);
            for (int i = len - 1; i >= 0; i--) {
                int x = i;
                while (num2.number[i] < number[i] && i != 0) {
                    if (num2.number[x - 1] == 0) {
                        x--;
                    }
                    else {
                        num2.number[x - 1] -= 1;
                        num2.number[i] += 10;
                    }
                }
                subtract[i] = num2.number[i] - number[i];
            }
            int z = 0;
            while (subtract[z] == 0) {
                subtract.erase(subtract.begin());
                z++;
            }
        }
        else {
            for (int i = 0; i < len; i++) {
                if (number[i] > num2.number[i]) {
                    while (len != num2.len) {
                        num2.number.insert(num2.number.begin(), 0);
                        num2.len += 1;
                    }
                    subtract.resize(len);
                    for (int i = len - 1; i >= 0; i--) {
                        int x = i;
                        while (number[i] < num2.number[i] && i != 0) {
                            if (number[x - 1] == 0) {
                                x--;
                            }
                            else {
                                number[x - 1] -= 1;
                                number[i] += 10;
                            }
                        }
                        subtract[i] = number[i] - num2.number[i];
                    }
                    int z = 0;
                    while (subtract[z] == 0) {
                        subtract.erase(subtract.begin());
                        z++;
                    }
                    number = subtract;
                    len = subtract.size() + 1;
                    return *this;
                }
                else if(number[i] > num2.number[i]) {
                    while (len != num2.len) {
                        number.insert(number.begin(), 0);
                        len += 1;
                    }
                    subtract.resize(len);
                    for (int i = len - 1; i >= 0; i--) {
                        int x = i;
                        while (num2.number[i] < number[i] && i != 0) {
                            if (num2.number[x - 1] == 0) {
                                x--;
                            }
                            else {
                                num2.number[x - 1] -= 1;
                                num2.number[i] += 10;
                            }
                        }
                        subtract[i] = num2.number[i] - number[i];
                    }
                    int z = 0;
                    while (subtract[z] == 0) {
                        subtract.erase(subtract.begin());
                        z++;
                    }
                    number = subtract;
                    len = subtract.size() + 1;
                    return *this;
                }
                else {
                    continue;
                }
            }
        }
        if (len == num2.len) {
            subtract.resize(1);
            subtract[0] = 0;
        }
        number = subtract;
        len = subtract.size()+1;
        return *this;
    }


    friend ostream& operator<< (ostream& output, BigDecimalInt& d) {

        for (int i = 0; i < d.len - 1; i++) {
            output << d.number[i];
        }
        return output;
    }

};



int main()
{
    BigDecimalInt num1("5561"), num2("5561");
    BigDecimalInt num3;
    num3 = num1 - num2;
    cout << num3;


}

