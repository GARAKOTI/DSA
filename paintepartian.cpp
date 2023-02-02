#include<iostream>
#include<vector>
using namespace std;


bool isPossible(vector<int> &boards,int n, int k, int mid){
int painterCount = 1; //for storing count of painter 
    int boardSum =0;//inilaizing from 0 so we can add one by one board sum 
    for(int i =0; i<n; i++){
    if(boardSum+boards[i]<=mid){
        boardSum+=boards[i];
    }
        else{
            painterCount++;
     //if have to give partian more then give no of painters or if our one part is bigger then mid return false
                   if(painterCount>k||boards[i]>mid){
                return false;
            }
            boardSum = boards[i];
        }
    
      }return true;
}


int findLargestMinDistance(vector<int> &boards, int k)
{
    int s =0; //finding the starting and ending using Search Space
    int sum = 0;    
    int ans = -1;    
    int n = boards.size();// size of vector
    for(int i =0; i<n; i++){
        sum += boards[i];
    }
    int e =sum;
    int mid = s+(e-s)/2;//finding mid
    
    while(s<=e){
  if (isPossible(boards,n,k,mid)){
      ans = mid; //if solution is possible then ans should mid
          e =mid-1;//and reduse my end to one element bhind the mid and find other solution
     }
        else{  //or if solution isn't possible then increase my start
            s = mid +1;
        }
            mid = s+(e-s)/2;    
    }return ans;

}



int main(){
vector<int>boards{5,5,5,5};
int k =2;
cout<<findLargestMinDistance(boards,k)<<endl;


}