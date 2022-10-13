#include <bits/stdc++.h>
#include "big decimal integer functions.cpp"
using namespace std;

int main(){
    //Testing the 2 constructors
    BigDecimalInt num1("123456789012345678901234567890");
    BigDecimalInt num2("+113456789011345678901134567890");
    BigDecimalInt num3("-200000000000000000000000000000");
    BigDecimalInt num6(1234554);

    //Testing operator <<
    cout<<"Welcome user to Big Integer Class :)\n";
    cout << "num1 = " << num1 << endl;
    cout << "num2 = " << num2 << endl;

    //Testing Sign() function
    cout<<"num3 sign char is : "<<num3.Sign()<<endl;

    //Testing size() function
    cout<<"num3 size is : "<<num3.size()<<endl;

    //Testing operator >
    if(num1>num3){
        cout<<"num1 greater than num3\n";
    }
    //Testing operator <
    if(num3<num1){
        cout<<"num3 smaller than num1\n";
    }

    //Testing operator==
    if(num6==num3){
        cout<<"num6 equals num3\n";
    }

    //Testing operators + and -
    BigDecimalInt num4 = num2 + num3;
    BigDecimalInt num5 = num3 - num1;

    //Next statement will print 236913578023691357802369135780
    cout << "num2 + num1 = " << num4 << endl;

    //Next statement will print -313456789011345678901134567890
    cout << "num - num1 = " << num5 << endl;

    //Testing operator =
    num1=num3=num2;
    cout<<"Making num1 and num3 = num2\nnum1 :" <<num1<<"\nnum3 :"<<num3<<"\nnum2 :"<<num2;

}
