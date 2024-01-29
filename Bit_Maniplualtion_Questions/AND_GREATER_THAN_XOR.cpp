/*
Question 1 : Given an Array of integers count the number of pairs of integers such that their bitwise AND is greater than or equal to their bitwise XOR....

Intuition : 

The observation is that if the MSB of two numbers is set then their bitwise AND will be greater than or equal to their bitwise XOR. (1 & 1 = 1 but 1 ^ 1 = 0).

If the opposite is asked then take the count as all the pairs (n*(n-1))/2
and subtract the pairs for which the AND is greater than XOR.
*/
//code :
    #include <bits/stdc++.h>
    using namespace std;
    int n; cin>>n;
    vector<int>arr(n); for(int i=0;i<n;i++)cin>>arr[i];
    map<int,int>mp;
    int cnt = 0;
    for(int i=0;i<n;i++){
        int last = -1;
        for(int j=0;j<=31;j++){
            if(arr[i] & (1<<j)){
                last = j;
            }
        }
        mp[last]++;
    }
    for(auto i : mp){
        cnt += (i.second * (i.second - 1)) / 2;
    }
    cout<<cnt<<endl;
