#include <iostream>
#include <list>

#include "graph.hh"

GNode::GNode(int _elem) {
  elem = _elem;
}

Graph::Graph(int _vertexCount) {
  vertexCount = _vertexCount;
  adjacencyMatrix = new bool*[vertexCount];
  for (int i = 0; i < vertexCount; ++i) {
    adjacencyMatrix[i] = new bool[vertexCount];
    for (int j = 0; j < vertexCount; ++j)
      adjacencyMatrix[i][j] = false;
  }
}

void Graph::addNode(int _elem) {
  GNode *temp = new GNode(_elem);
  nodes.push_back(temp);
  temp -> id = nodes.size();
}

void Graph::addEdge(int _i, int _j) {
  if (_i >= 0 && _i < vertexCount && _j >= 0 && _j < vertexCount) {
    adjacencyMatrix[_i][_j] = true;
    adjacencyMatrix[_j][_i] = true;
  }
}

bool Graph::isEdge(int _i, int _j) {
  if (_i >= 0 && _i < vertexCount && _j >= 0 && _j < vertexCount) {
    return adjacencyMatrix[_i][_j];
  }
  else return false;
}

Graph::~Graph() {
  for (int i = 0; i < vertexCount; i++)
    delete[] adjacencyMatrix[i];
  delete[] adjacencyMatrix;
}

void Graph::runDFS(int _u, vertexState *&_state) {
  _state[_u] = Gray;
  for (int v=0; v<vertexCount; ++v)
    if (isEdge(_u, v) && _state[v] == White)
      runDFS(v, _state);
  _state[_u] = Black;
  std::cout << "Node id: " << _u << " Elem: " << nodes[_u] -> elem << std::endl;
}

void Graph::DFS() {
  std::cout << "DFS run:" << std::endl;
  vertexState *state = new vertexState[vertexCount];
  for (int i=0; i<vertexCount; ++i)
    state[i] = White;
  runDFS(0, state);
  delete []state;
  std::cout << "DFS end." << std::endl;
}


void Graph::BFS(int _id) {
  std::cout << "BFS run:" << std::endl;
  bool *visited = new bool[vertexCount];
  for (int i=0; i<vertexCount; ++i)
    visited[i] = false;

  std::list<int> queue;
  visited[_id] = true;
  queue.push_back(_id);

  while (!queue.empty()) {
    _id = queue.front();
    std::cout << "Node id: " << nodes[_id]->id;
    std::cout << " Elem: " << nodes[_id]->elem << std::endl;

    for (int i = 0; i < vertexCount; ++i) {
      if (isEdge(_id, i)){
	if (!visited[i]) {
	  visited[i] = true;
	  queue.push_back(i);
	}
      }
    }
    queue.pop_front();
  }
  std::cout << "BFS end." << std::endl;
}
