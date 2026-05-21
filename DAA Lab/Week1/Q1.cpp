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
  int comparisons=0;
  bool found=false;
  for(int i=0;i<n;i++){
   comparisons++;
   if(arr[i]==key){
    found=true;
    break;
   }
  }
  cout<<(found?"Present":"Not Present")<<endl;
  cout<<comparisons<<endl;
 }
 return 0;
}
