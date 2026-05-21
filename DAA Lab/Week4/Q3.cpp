#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int>& arr,int left,int right){
 int pivot=arr[right];
 int i=left-1;

 for(int j=left;j<right;j++){
  if(arr[j]<pivot){
   i++;
   swap(arr[i],arr[j]);
  }
 }

 swap(arr[i+1],arr[right]);

 return i+1;
}

int kthSmallest(vector<int>& arr,int left,int right,int k){
 if(left<=right){
  int pi=partition(arr,left,right);

  if(pi==k-1) return arr[pi];
  else if(pi>k-1) return kthSmallest(arr,left,pi-1,k);
  else return kthSmallest(arr,pi+1,right,k);
 }

 return -1;
}

int main(){
 int t; cin>>t;

 while(t--){
  int n; cin>>n;

  vector<int> arr(n);

  for(int i=0;i<n;i++) cin>>arr[i];

  int k; cin>>k;

  if(k<1 || k>n){
   cout<<"Not Present"<<endl;
  }
  else{
   cout<<kthSmallest(arr,0,n-1,k)<<endl;
  }
 }

 return 0;
}
