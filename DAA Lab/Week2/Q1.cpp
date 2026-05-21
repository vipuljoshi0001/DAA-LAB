#include<iostream>
#include<vector>
using namespace std;

int firstOcc(vector<int>& arr,int key){
 int l=0,r=arr.size()-1,res=-1;
 while(l<=r){
  int mid=(l+r)/2;
  if(arr[mid]==key){
   res=mid;
   r=mid-1;
  }
  else if(arr[mid]<key) l=mid+1;
  else r=mid-1;
 }
 return res;
}

int lastOcc(vector<int>& arr,int key){
 int l=0,r=arr.size()-1,res=-1;
 while(l<=r){
  int mid=(l+r)/2;
  if(arr[mid]==key){
   res=mid;
   l=mid+1;
  }
  else if(arr[mid]<key) l=mid+1;
  else r=mid-1;
 }
 return res;
}

int main(){
 int t; cin>>t;
 while(t--){
  int n; cin>>n;
  vector<int> arr(n);
  for(int i=0;i<n;i++) cin>>arr[i];
  int key; cin>>key;

  int first=firstOcc(arr,key);

  if(first==-1) cout<<"Key not present"<<endl;
  else{
   int last=lastOcc(arr,key);
   cout<<key<<" "<<last-first+1<<endl;
  }
 }
 return 0;
}
