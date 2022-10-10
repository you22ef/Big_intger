#include <bits/stdc++.h>
#include "big decimal integer functions.cpp"
using namespace std;

int main(){
    BigDecimalInt n1("50000"), n2("10000"); 
    
    if(n1==n2){
        cout<<"yes";
    }
    cout<<"n1 sign char "<<n1.Sign()<<endl;
    cout<<"n1 : "<<n1<<"\nn2 : "<<n2<<endl;

    //problems example
    cout<<"\nprob\n";
    BigDecimalInt n4 =n1+n2;
    cout<<"n4= "<<n4<<"\nn1 changed to sum :"<<n1; 

    BigDecimalInt n5 =n1-n2;
    cout<<"\nn5= "<<n5<<"\nn1 changed  :"<<n1;

}
