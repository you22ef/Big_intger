#include <iostream>
#include <string>
#include <iostream>
using namespace std;
void pattern(int n, int i){

    if (n == 0){
        return;
    }

    else{
        
        pattern( n/2, i);
        for (int k = 0; k < i ; k++){
            cout << " ";
        }
        for (int k = 0; k < n; k++){
            cout << "* ";
        }
        cout<<endl;
        pattern( n / 2, i+n);
        

    }
}
int main(){
    pattern(8,0);
}
