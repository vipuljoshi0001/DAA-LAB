#include<iostream>
#include<vector>
using namespace std;
int main(){
 int t; cin>>t;
 while(t--){
  int n; cin>>n;
  vector<int> arr(n);
  for(int i=0;i<n;i++) cin>>arr[i];
  int key; cin>>key;
  int left=0,right=n-1,comparisons=0;
  bool found=false;
  while(left<=right){
   int mid=(left+right)/2;
   comparisons++;
   if(arr[mid]==key){
    found=true;
    break;
   }
   else if(arr[mid]<key) left=mid+1;
   else right=mid-1;
  }
  cout<<(found?"Present":"Not Present")<<endl;
  cout<<comparisons<<endl;
 }
 return 0;
}
