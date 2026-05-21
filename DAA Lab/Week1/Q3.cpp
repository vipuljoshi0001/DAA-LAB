#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main(){
 int t; cin>>t;
 while(t--){
  int n; cin>>n;
  vector<int> arr(n);
  for(int i=0;i<n;i++) cin>>arr[i];
  int key; cin>>key;
  int step=sqrt(n),prev=0,comparisons=0;
  bool found=false;
  while(arr[min(step,n)-1]<key){
   comparisons++;
   prev=step;
   step+=sqrt(n);
   if(prev>=n) break;
  }
  while(prev<min(step,n) && arr[prev]<key){
   comparisons++;
   prev++;
  }
  comparisons++;
  if(prev<n && arr[prev]==key) found=true;
  cout<<(found?"Present":"Not Present")<<endl;
  cout<<comparisons<<endl;
 }
 return 0;
}
