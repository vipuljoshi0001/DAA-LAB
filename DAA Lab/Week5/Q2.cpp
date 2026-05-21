#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
 int t; cin>>t;

 while(t--){
  int n; cin>>n;

  vector<int> arr(n);

  for(int i=0;i<n;i++) cin>>arr[i];

  int key; cin>>key;

  sort(arr.begin(),arr.end());

  int left=0,right=n-1;
  bool found=false;

  while(left<right){
   int sum=arr[left]+arr[right];

   if(sum==key){
    cout<<arr[left]<<" "<<arr[right]<<endl;
    found=true;
    break;
   }
   else if(sum<key) left++;
   else right--;
  }

  if(!found){
   cout<<"No Such Elements Exist"<<endl;
  }
 }

 return 0;
}
