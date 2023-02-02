#include<iostream>
#include<vector>
#include<Algorithm>
using namespace std;
bool isPossible(vector<int>stalls,int k,int mid){
    int cowCount = 1;
    int lastPos = stalls[0];
    for(int i =0; i<stalls.size(); i++){
        if(stalls[i]-lastPos>=mid){
     cowCount++;
     if(cowCount==k){
        return true;
         }
         lastPos = stalls[i];
        }
    }
}

 int aggressiveCows(vector<int>stalls,int k){
   sort(stalls.begin(),stalls.end());
    int s =0;
     int maxi = -1;
      int ans = -1; 
         for(int i = 0; i<stalls.size();i++){
           maxi = max(maxi , stalls[i]);
           }
        int e = maxi;
       int mid  = s+(e-s)/2;
       while (s<=e)
       {
         if(isPossible(stalls, k ,mid)){
            ans =mid;
            s = mid +1;   // we go to right side because we have to find the largest value
         }
         else{
            e = mid -1;
         }
         mid = s + (e - s)/2;
       }
     return ans;

 }

int main(){
    vector<int>stalls;
    stalls ={4,3,2,1,6};
    int k = 2;
    cout<<aggressiveCows(stalls,k)<<endl;
}