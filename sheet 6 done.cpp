#include <iostream>
#include <string>
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
















//int pattern(int n,int i){ //* ** 
//     cout<<sp<<"* \n"<<sp<<"* *\n";
//     i+=2;
//     for(int k=0;k<i;k++){
//         cout<<" ";
//     }
//     cout<<"*\n";
//     for(int k=0;k<n/2;k++){
//         cout<<"* ";
//     }
//     cout<<"\n";
//     //****
//     cout<<n<<" ";
//     cout<<i;
//     if(n==4){
//         cout<<"kofta";
//     }

//     if(i==4){
//         return 0;
//     }
//     sp+="  ";
//     pattern(n*2,i);
// }



// int main(){
//     pattern(8,0);
// }