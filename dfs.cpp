//Depth first search

#include <iostream>
#include <list>

using namespace std;

class Graph{
private:
  int v; //Number of vertices

  list<int> *adj;  //Ponter to adjacency list

  void DFS_helper(int s, bool *visited);   //DFS recursive helper function

public:
  Graph(int x);  //Constructor

  void addEdge(int x, int w);  //Method to add an edge

  void DFS(int s);   //Method for DFS traversal given a source s
};

Graph::Graph(int x){
  v=x;
  adj = new list<int>[x];
}

void Graph::addEdge(int x, int w){
  adj[x].push_back(w);
}

void Graph::DFS_helper(int s, bool *visited){
  //Mark the current node as visited
  cout << "Visiting Node " << s << endl;
  visited[s] = true;

  //Go throught the adjacency list
  for(auto i=adj[s].begin();i!=adj[s].end();i++){
    //If not visited travel through the vertex
    if(!visited[*i]){
      cout << "Going to vertex " << *i << "from vertex" << s << endl;
      DFS_helper(*i,visited);
    }
  }
}

void Graph::DFS(int s){
  //Start with all the vertices as not visited
  bool *visited = new bool[v];
  for(int i=0; i<v;i++){
    visited[i] =  false;
  }

  //Beginning of recursive call
  DFS_helper(s,visited);
}

int main(){
  Graph g(6);

  g.addEdge(0,1);
  g.addEdge(0,2);

  g.addEdge(1,0);
  g.addEdge(1,3);
  g.addEdge(1,4);

  g.addEdge(2,0);
  g.addEdge(2,4);

  g.addEdge(3,1);
  g.addEdge(3,4);
  g.addEdge(3,5);

  g.addEdge(4,1);
  g.addEdge(4,2);
  g.addEdge(4,3);
  g.addEdge(4,5);

  g.addEdge(5,3);
  g.addEdge(5,4);

  g.DFS(0);

  return 0;
}
