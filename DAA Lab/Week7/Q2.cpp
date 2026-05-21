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

 int src;
 cin>>src;

 vector<int> dist(v,INT_MAX);
 vector<int> parent(v,-1);

 dist[src]=0;

 for(int count=0;count<v-1;count++){
  for(int u=0;u<v;u++){
   if(dist[u]!=INT_MAX){
    for(int vv=0;vv<v;vv++){
     if(adj[u][vv]!=0){
      if(dist[u]+adj[u][vv]<dist[vv]){
       dist[vv]=dist[u]+adj[u][vv];
       parent[vv]=u;
      }
     }
    }
   }
  }
 }

 bool neg=false;

 for(int u=0;u<v;u++){
  if(dist[u]!=INT_MAX){
   for(int vv=0;vv<v;vv++){
    if(adj[u][vv]!=0){
     if(dist[u]+adj[u][vv]<dist[vv]){
      neg=true;
     }
    }
   }
  }
 }

 if(neg){
  cout<<"Graph contains negative cycle"<<endl;
  return 0;
 }

 for(int i=0;i<v;i++){
  cout<<"Vertex "<<i<<": Distance = ";

  if(dist[i]==INT_MAX) cout<<"INF";
  else cout<<dist[i];

  cout<<", Path: ";

  vector<int> path;

  int curr=i;

  while(curr!=-1){
   path.push_back(curr);
   curr=parent[curr];
  }

  for(int j=path.size()-1;j>=0;j--){
   cout<<path[j];
   if(j!=0) cout<<" -> ";
  }

  cout<<endl;
 }

 return 0;
}
