#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int main(){
 int v; cin>>v;

 vector<vector<int>> adj(v,vector<int>(v));

 for(int i=0;i<v;i++){
  for(int j=0;j<v;j++){
   cin>>adj[i][j];
  }
 }

 int src,dest,k;
 cin>>src>>dest>>k;

 vector<vector<int>> dp(k+1,vector<int>(v,INT_MAX));

 dp[0][src]=0;

 for(int edges=0;edges<k;edges++){
  for(int u=0;u<v;u++){
   if(dp[edges][u]!=INT_MAX){
    for(int vv=0;vv<v;vv++){
     if(adj[u][vv]!=0){
      dp[edges+1][vv]=min(dp[edges+1][vv],
      dp[edges][u]+adj[u][vv]);
     }
    }
   }
  }
 }

 if(dp[k][dest]==INT_MAX){
  cout<<"No path of length k is available"<<endl;
 }
 else{
  cout<<dp[k][dest]<<endl;
 }

 return 0;
}
