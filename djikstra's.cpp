//Dijkstra's algorithm

#include <iostream>
#include <list>
#include <utility>
#include <set>
#include <vector>

#define INF 1000000

using namespace std;

class Graph{
private:
  //Number of vertices
  int v;
  //Pointer to adjacency list
  list<pair<int,int>> *adj;

public:
  //Constrcutor prototype
  Graph(int x);
  //Method to add an edge or weight pair
  void addEdge(int v1, int v2, int w);
  //Method to find the shortest path
  void shortestPath(int s);
};

Graph::Graph(int x){
  v = x;
  adj = new list<pair<int,int>>[x];
}

void Graph::addEdge(int v1, int v2, int w){
  add[v1].push_back(make_pair(v2,w));
}

void Graph::shortestPath(int s){
  //Create a set to store vertices
  //Use this to extract the shortest path
  set<pair<int,int>> extract_set;

  //Vector for all distances
  //All the paths are initialised to a larger value
  vector<int> distances(v,INF);

  //Insert the entry point into the set
  //Initialied distance to 0
  extract_set.insert(make_pair(0,s));
  distances[s] = 0;

  //Continue untill all shortest distance are finalized
  while(!extract_set.empty()){
    //Extract the minimum distance
    pair<int,int> tmp = *(extract_set.begin());
    extract_set.erase(extract_set.begin());

    //Get the vertex number
    u = tmp.second;

    //Go over the adjacency list
    for(auto i = adj[u].begin();i != adj[u].end();i++){
      //Get the vertex and the weight
      int x = (*i).first;
      int w = (*i).second;

      //Check if we found a shorter path to v
      if(distances[x] > distances[u] + w){
        //Remove the current distance if it is in the set
        if(distances[x] != IMF)
          extract_set.erase(extract_set.find(make_pair(distances[x],x)));

        //Update the distance
        distances[x] = distances[u] + w;
        extract_set.insert(make_pair(distances[x], x));
      }
    }
  }

  cout << "Minimum distances from vertex: " << s << endl;
  for(int i = 0; i < v; i++){
      cout << "Vertex: " << i << "\tDistance: " << distances[i] << endl;
  }


}
