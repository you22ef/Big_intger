#include <iostream>
using namespace std;

template<class type>
class Smart_array {
private:
    type arr [1000];
    int count;
    void copyInternalData(const Smart_array& cstk) {
        array = new char[cstk.count];
        for (int i = 0; i < cstk.count; i++) {
            array[i] = cstk.array[i];
        }
        count = cstk.count;
    }
public:
    Smart_array () {
        count = 0;
    }
    
    /*Smart_array(Smart_array a[]) {
        for (int i = 0; i < a.count - 1; i++) {
            arr[i] = a.arr[i];
        }
        count = a.count;
        return *this;
    }*/
   
    ~Smart_array() {
        
    }
    type& operator[](int k) {
        count++;
        if (k < 0) {
            cout << "invalid index"<<end;
            exit(0);
        }
        return arr[k];
    }
    int size() {

        return count;
    }
    type& operator=(Smart_array k[]) {
        for (int i = 0; i < k.count-1; i++) {
            arr[i] = k.arr[i];
        }
        count = k.count;
        return *this;
    }
    type& operator=(const Smart_array & k) {
        k.arr = new type[count];
        for (int i = 0; i < count - 1; i++) {
            k.arr[i] = arr[i];
        }
        k.count = count;
        return *this;
    }
    
};

int main()
{
    Smart_array<int>a;
    Smart_array<int>a1;
    for (int i = 0; i < 5; i++) {
        a[i] = i;
    }
    a1 = a2;
    cout << a2[0];
}

