//Breadth first search
#include <iostream>
#include <list>

using namespace std;

class Graph{
private:
  int v; //Number of vertices
  list<int> *adj; //pointer to the adjacency list

public:
  Graph(int x);  //Constrcutor

  void addEdge(int x, int w);  //Method to add an edge

  void BFS(int s);  //Method for bfs traversal given a source s
};

Graph::Graph(int x){
  v=x; //Set the number of vertices
  adj = new list<int>[x];  //create a new adjacency list of size v
}

void Graph::addEdge(int x, int w){
  adj[x].push_back(w);
}

void Graph::BFS(int s){
  //Start with all vertices as not visited
  bool *visited = new bool[v];

  for(int i=0; i<v;i++){
    visited[i] =  false;
  }

  //create a queue for bfs
  list<int> queue;

  //Starting vertex markes as visited and adde to the queue
  visited[s] = true;
  queue.push_back(s);

  //Continue untill the queue is empty
  while(!queue.empty()){
    //Get the front of the queue and remove it;
    s = queue.front();
    queue.pop_front();

    //Get all adjacent vertices from that vertex
    cout << "Checking adjacent vertices for vertex " << s << endl;
    for(auto i = adj[s].begin(); i != adj[s].end();i++){
      //We only care about vertices not visited yet
      if(!visited[*i]){
        //Mark as visited
        cout << "Visited and Enqueue" << *i << endl;
        visited[*i] = true;
        //push back to check this vertex's vertices
        queue.push_back(*i);
      }
    }
  }
}

int main(){
  //create a new graph
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

  g.BFS(2);

  return 0;
}
