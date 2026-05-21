#include<iostream>
#include<vector>
using namespace std;
int main(){
 int t; cin>>t;
 while(t--){
  int n; cin>>n;
  vector<int> arr(n);

  for(int i=0;i<n;i++) cin>>arr[i];

  long long comparisons=0,shifts=0;

  for(int i=1;i<n;i++){
   int key=arr[i];
   int j=i-1;

   while(j>=0){
    comparisons++;

    if(arr[j]>key){
     arr[j+1]=arr[j];
     shifts++;
     j--;
    }
    else break;
   }

   arr[j+1]=key;

   if(i!=j+1) shifts++;
  }

  for(int x:arr) cout<<x<<" ";
  cout<<endl;

  cout<<comparisons<<endl;
  cout<<shifts<<endl;
 }
 return 0;
}
