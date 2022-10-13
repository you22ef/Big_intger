#include <bits/stdc++.h>
#include "header.h"
using namespace std;

//constructors
BigDecimalInt ::BigDecimalInt(){} //default constructor

BigDecimalInt ::BigDecimalInt(int decimal){
    string str = to_string(decimal);
    len = str.length();
    int c=0;
    if(signbit(decimal)){ //if negative
        sign ='-';
        len--;
        number.resize(len);
        c=1;
    }
    else{
        sign='+';
        number.resize(len);
    }
    for(int i=0;i<len;i++){
        number[i]=str[i+c]-'0';
    }
}
BigDecimalInt:: BigDecimalInt(string n){
    bool valid =true;
    int cnt=0;
    len = n.length();
    number.resize(len);
    if(n[0]=='-' || n[0]=='+'){
        sign=n[0];
        cnt++; //begin from 1
        len--;
    }
    for (int i = cnt; i < n.length(); i++) {    //check if string n only contains integers

        if( n[i]>57 || n[i]<48 ){   
            valid =false;
        }
    }
    
    if(valid){ 
        if(cnt==0){ //has no sign
            sign ='+';
        }
        for (int i = 0; i < len; i++) {    
            number[i] = n[i+cnt] - '0'; //neglecting the sign in vector so +,- operarions work ;you can call sign function to know sign of the number
        }

    }
    else{
        cout<<"Invalid number..";
        abort();
    }
}
//----------------------------------------------------------------------------------------
int BigDecimalInt::size(){
    return len;
}

int BigDecimalInt:: Sign(){
    int s=sign; //43 for positive //45 for negative
    return s;
}

void BigDecimalInt :: remove_zeros(vector<int> &v) {
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

//few operators
bool BigDecimalInt:: operator> ( BigDecimalInt num2){
    if (sign == '+' && num2.sign == '-') {
            return true;
        }
    else if (sign == '-' && num2.sign == '+') {
        return false;
    }

    //negative numbers
    else if(sign == '-' && num2.sign == '-'){
        if(len<num2.len){
            return true;
        }
        else if(num2.len<len){
            return false;
        }
        else if(len==num2.len){
            for(int i=0;i<len;i++){
                if(number[i]<num2.number[i]){
                    return true;
                }
                else{
                    return false;
                }
            }
        }
    }

    //positive numbers
    else if(sign == '+' && num2.sign == '+'){
        if(len>num2.len){
            return true;
        }
        else if(num2.len>len){
            return false;
        }
        else if(len==num2.len){
            for(int i=0;i<len;i++){
                if(number[i]>num2.number[i]){
                    return true;
                }
                else{
                    return false;
                }
            }
        }
    }
}


//operator =
BigDecimalInt BigDecimalInt:: operator=(BigDecimalInt num2){
    
    sign=num2.sign;
    number =num2.number;
    len =num2.len;
    return *this;
}

//operator ==
bool BigDecimalInt ::operator ==(BigDecimalInt num2){
    if(len != num2.len || sign!=num2.sign){
            return false;
    }

    else if(sign ==num2.sign){
        for(int i=0;i<len;i++){
            if(number[i]!=num2.number[i]){
                return false;
            }
        }
        return true;
    }
}


// smaller than operator
bool BigDecimalInt ::operator< (BigDecimalInt num2){
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

//+ and - operators

//operator +
BigDecimalInt BigDecimalInt:: operator+(BigDecimalInt num2) {
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

//operator -
BigDecimalInt BigDecimalInt:: operator-(BigDecimalInt num2) {
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

//-----------------------------------
ostream& operator<< (ostream& output, BigDecimalInt& d){
    if (d.sign == '-') {
            output << d.sign;
    }
    for (int i = 0; i < d.len; i++) {
        output << d.number[i];
    }
    return output;
}