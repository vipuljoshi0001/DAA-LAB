#include<iostream>
#include<vector>
using namespace std;
int main(){
 int t; cin>>t;
 while(t--){
  int n; cin>>n;
  vector<int> arr(n);

  for(int i=0;i<n;i++) cin>>arr[i];

  long long comparisons=0,swaps=0;

  for(int i=0;i<n-1;i++){
   int minIdx=i;

   for(int j=i+1;j<n;j++){
    comparisons++;

    if(arr[j]<arr[minIdx]){
     minIdx=j;
    }
   }

   if(minIdx!=i){
    swap(arr[i],arr[minIdx]);
    swaps++;
   }
  }

  for(int x:arr) cout<<x<<" ";
  cout<<endl;

  cout<<comparisons<<endl;
  cout<<swaps<<endl;
 }
 return 0;
}
