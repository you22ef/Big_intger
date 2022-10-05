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
        
        for (int i = 0; i < d.len-1; i++) {
            output << d.number[i];
        }
        return output;
   }
    
};



int main()
{
    BigDecimalInt num1("56"), num2("168");
    BigDecimalInt num3;
    num3 = num1 + num2;
    cout << num3;
    

}

