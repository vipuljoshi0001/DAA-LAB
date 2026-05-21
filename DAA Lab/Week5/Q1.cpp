#include<iostream>
#include<vector>
using namespace std;

int main(){
 int t; cin>>t;

 while(t--){
  int n; cin>>n;

  vector<int> freq(26,0);

  for(int i=0;i<n;i++){
   char c;
   cin>>c;
   freq[c-'a']++;
  }

  int maxFreq=0;
  char maxChar='a';

  for(int i=0;i<26;i++){
   if(freq[i]>maxFreq){
    maxFreq=freq[i];
    maxChar='a'+i;
   }
  }

  if(maxFreq==1){
   cout<<"No Duplicates Present"<<endl;
  }
  else{
   cout<<maxChar<<" "<<maxFreq<<endl;
  }
 }

 return 0;
}
