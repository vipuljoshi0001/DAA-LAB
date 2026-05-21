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

 vector<bool> visited(v,false);
 vector<int> key(v,INT_MIN);

 long long totalCost=0;

 key[0]=0;

 for(int count=0;count<v;count++){
  int u=-1;

  for(int i=0;i<v;i++){
   if(!visited[i]){
    if(u==-1 || key[i]>key[u]){
     u=i;
    }
   }
  }

  visited[u]=true;

  if(key[u]!=INT_MIN){
   totalCost+=key[u];
  }

  for(int vv=0;vv<v;vv++){
   if(adj[u][vv]!=0 && !visited[vv]){
    if(adj[u][vv]>key[vv]){
     key[vv]=adj[u][vv];
    }
   }
  }
 }

 cout<<totalCost<<endl;

 return 0;
}
