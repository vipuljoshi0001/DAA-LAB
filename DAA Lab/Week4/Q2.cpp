#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
using namespace std;

long long comparisons=0,swapsCount=0;

int partition(vector<int>& arr,int left,int right){
 srand(time(0)+rand());

 int randomIdx=left+rand()%(right-left+1);

 swap(arr[randomIdx],arr[right]);
 swapsCount++;

 int pivot=arr[right];
 int i=left-1;

 for(int j=left;j<right;j++){
  comparisons++;

  if(arr[j]<pivot){
   i++;
   swap(arr[i],arr[j]);
   swapsCount++;
  }
 }

 swap(arr[i+1],arr[right]);
 swapsCount++;

 return i+1;
}

void quickSort(vector<int>& arr,int left,int right){
 if(left<right){
  int pi=partition(arr,left,right);

  quickSort(arr,left,pi-1);
  quickSort(arr,pi+1,right);
 }
}

int main(){
 int t; cin>>t;

 while(t--){
  int n; cin>>n;

  vector<int> arr(n);

  for(int i=0;i<n;i++) cin>>arr[i];

  comparisons=0;
  swapsCount=0;

  quickSort(arr,0,n-1);

  for(int x:arr) cout<<x<<" ";
  cout<<endl;

  cout<<comparisons<<endl;
  cout<<swapsCount<<endl;
 }

 return 0;
}
