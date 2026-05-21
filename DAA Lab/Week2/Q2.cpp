#include<iostream>
#include<vector>
using namespace std;
int main(){
 int t; cin>>t;
 while(t--){
  int n; cin>>n;
  vector<int> arr(n);
  for(int i=0;i<n;i++) cin>>arr[i];

  bool found=false;
  int a,b,c;

  for(int k=0;k<n && !found;k++){
   int i=0,j=n-1;

   while(i<j){
    if(i==k){i++; continue;}
    if(j==k){j--; continue;}

    int sum=arr[i]+arr[j];

    if(sum==arr[k]){
     a=i; b=j; c=k;
     found=true;
     break;
    }
    else if(sum<arr[k]) i++;
    else j--;
   }
  }

  if(found) cout<<a<<" "<<b<<" "<<c<<endl;
  else cout<<"No sequence found"<<endl;
 }
 return 0;
}
