//BIT MANIPULATION
#include <iostream>
using namespace std;

void printBinary(int num){
    for(int i=10;i>=0;i--){
        cout<<((num>>i) & 1);
    }
    cout<<endl;
}
void checkIthBitSet(int num,int i){
    int a = num;
    if((a& (1<<i)) != 0){
        cout<< "set bit";
    }
    else cout<<"not set bit";
}
void setIthBit(int num,int i){
    int a = num;
    cout<<(a | (1<<i));
    cout<<endl;
}
void unsetIthBit(int num,int i){
    int a = num;
    cout<<(a&(~(1<<i)));
    cout<<endl;
}
void toggle(int num,int i){
    int a = num;
    cout<<(a ^ (1<<i))<<endl;
}
void countSetBits(int num){
    int a = num; int cnt=0;
    for(int i=32;i>=0;i--){
        if((a& (1<<i)) !=0){
            cnt++;
        }
    }
    cout<<cnt<<endl;
    // inbuilt functions can also be used...
    // cout<<__buitlin_popcount(a)<<endl; (works only for int data type)
    // cout<<__builtin_popcountll(a)<<endl (works for long integers)
}
void checkOddEven(int n){
    if(n&1){
        cout<<"odd"<<endl;
    }
    else cout<<"even"<<endl;
}
void MulAndDivideBy2(int n){
    cout<<(n<<1); // Multiply by 2
    cout<<(n>>1); // Divide by 2
}
void caseConversion(){
    char B = 'B';
    //uppercase to lowercase
    char b = B | ' ';
    cout<<b<<endl;

    //lowercase to uppercase
    char d = 'd';
    char D = (d & '_');
    cout<<D<<endl;
}
void clearLSBs(int a,int i){
    int b = (a & (~((1<<(i+1)) - 1)));
    cout<<b;
}
void clearMSBs(int a,int i){
    int b = (a & ((1<<(i+1)) - 1));
    cout<<b;
}
void checkPowerOf2(int n){

    if(n &(n-1)){
        cout<<"not power of 2";
    }
    else cout<<"power of 2";
}
void swapUsingXOR(int a,int b){
    cout<<"before swapping"<<endl;
    cout<<a<<" "<<b<<endl;
    a = a ^ b;
    b = b ^ a;
    a = a ^ b;
    cout<<"after swapping"<<endl;
    cout<<a<<" "<<b<<endl;
}
void additional(){
    /* some additional inbuilt functions....
    1) __builtin_clz(x): the number of zeros at the beginning of the number
    2) __builtin_ctz(x): the number of zeros at the end of the number
    3) __builtin_popcount(x): the number of ones in the number
    4) __builtin_parity(x): the parity (even or odd) of the number of ones*/
}
int main(){

    printBinary(50);
    printBinary(22);

}
