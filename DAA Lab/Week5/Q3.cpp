#include<iostream>
#include<vector>
using namespace std;

int main(){
 int m; cin>>m;

 vector<int> arr1(m);

 for(int i=0;i<m;i++) cin>>arr1[i];

 int n; cin>>n;

 vector<int> arr2(n);

 for(int i=0;i<n;i++) cin>>arr2[i];

 vector<int> common;

 int i=0,j=0;

 while(i<m && j<n){
  if(arr1[i]==arr2[j]){
   common.push_back(arr1[i]);
   i++;
   j++;
  }
  else if(arr1[i]<arr2[j]) i++;
  else j++;
 }

 for(int k=0;k<common.size();k++){
  cout<<common[k];
  if(k<common.size()-1) cout<<" ";
 }

 cout<<endl;

 return 0;
}
