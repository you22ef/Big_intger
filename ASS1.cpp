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
            number.resize(len);
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
            number.resize(num2.len);
            sum.resize(num2.len);
            num2.number.resize(num2.len);
            for (int i = num2.len - 1; i >= 0; i--) {
                sum[i] = number[i] + num2.number[i];
                if (sum[i] >= 10 && i != 0) {
                    sum[i] = sum[i] % 10;
                    number[i - 1] += 1;
                }
            }
            len = floor(log10(sum[0]) + 1) + num2.len;
        }
        
        number = sum;
        return *this;
    }
    friend ostream& operator<< (ostream& output, BigDecimalInt& d) {

        for (int i = 0; i < d.len-2; i++) {
            output << d.number[i];
        }
        return output;
   }
    
};



int main()
{
    BigDecimalInt num1("513131231553112131312311316151351"), num2("221313153153153135131561531564531351");
    BigDecimalInt num3;
    num3 = num1 + num2;
    cout << num3;
    

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
