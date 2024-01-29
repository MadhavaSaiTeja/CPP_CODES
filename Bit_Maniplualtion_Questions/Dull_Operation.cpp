/*
Question : An odd number N is given. Find two numbers x and y such that (x | y) * (x ^ y) equals N.


Intuition : For any odd number one less than the odd number gives the correct answer. 
Since bitwise OR of an odd number N and N - 1 gives N while XOR of N and N - 1 will give 1. 
The product of these two will be N. 

Question Link : https://www.codechef.com/START105C/problems/DUPLET
*/

//code :

#include <bits/stdc++.h>
using namespace std;

int main(){

    int N; cin>>N;

    cout<<N<<" "<<N-1<<endl;

}