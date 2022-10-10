#include <bits/stdc++.h>
#include "header.h"
using namespace std;

//constructors
BigDecimalInt ::BigDecimalInt(int decimal){
    string str = to_string(decimal);
    len = str.length();
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
    int s=sign; //43 for plus //45 for minus
    return s;
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
            for (int i = 1; i < len; i++) {
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
}

//+ and - operators

//operator +

BigDecimalInt BigDecimalInt:: operator+(BigDecimalInt num2){
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

//operator -

BigDecimalInt BigDecimalInt ::operator-(BigDecimalInt num2){
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
        if (len == num2.len) {
            subtract.resize(1);
            subtract[0] = 0;
            number = subtract;
            len = subtract.size() + 1;
            return *this;
        }
    }
    
    number = subtract;
    len = subtract.size()+1;
    return *this;
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