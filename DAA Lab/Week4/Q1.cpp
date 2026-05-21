#include<iostream>
#include<vector>
using namespace std;

long long comparisons=0,inversions=0;

void merge(vector<int>& arr,int left,int mid,int right){
 vector<int> temp(right-left+1);

 int i=left,j=mid+1,k=0;

 while(i<=mid && j<=right){
  comparisons++;

  if(arr[i]<=arr[j]){
   temp[k++]=arr[i++];
  }
  else{
   temp[k++]=arr[j++];
   inversions+=(mid-i+1);
  }
 }

 while(i<=mid) temp[k++]=arr[i++];
 while(j<=right) temp[k++]=arr[j++];

 for(int i=left,k=0;i<=right;i++,k++){
  arr[i]=temp[k];
 }
}

void mergeSort(vector<int>& arr,int left,int right){
 if(left<right){
  int mid=(left+right)/2;

  mergeSort(arr,left,mid);
  mergeSort(arr,mid+1,right);
  merge(arr,left,mid,right);
 }
}

int main(){
 int t; cin>>t;

 while(t--){
  int n; cin>>n;

  vector<int> arr(n);

  for(int i=0;i<n;i++) cin>>arr[i];

  comparisons=0;
  inversions=0;

  mergeSort(arr,0,n-1);

  for(int x:arr) cout<<x<<" ";
  cout<<endl;

  cout<<comparisons<<endl;
  cout<<inversions<<endl;
 }

 return 0;
}
