//Shortest path in binary matrix
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int ShortestPath(vector<vector<int>>& grid){

  int rows = grid.size();
  int cols = grid[0].size();

  if(rows == 0 || cols == 0)
    return -1;

  if(grid[0][0] == 1 || grid[rows-1][cols-1] == 1)
    return -1;

  vector<vector<int>> path = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};   //8 traversing directions

  queue<pair<int,int>> queue;

  queue.push(make_pair(0,0));

  grid[0][0] = 1;

  while(!queue.empty()){
    auto curr = queue.front();
    queue.pop();
    int x = curr.first, y = curr.second;

    if(x == rows-1 && y == cols-1)
      return grid[x][y];

    for(auto p:path){
      int dx = x+p[0];
      int dy = y+p[1];

      if(dx >= 0 && dx<rows && dy>=0 && dy<cols && grid[dx][dy] == 0){
        queue.push(make_pair(dx,dy));
        grid[dx][dy] = grid[x][y] + 1;
      }
    }
    //queue.pop();
  }

  return -1;

}

int main(){
  vector<vector<int>> grid = {{0,0,0},{1,1,0},{1,1,0}};

  int result = ShortestPath(grid);

  cout << "Shorted Path from top-left to bottom-right is: " << result << "\n";

  return 0;
}
