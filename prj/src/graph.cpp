#include <iostream>

#include "graph.hh"

GNode::GNode(int _elem) {
  elem = _elem;
  colour = 1;
}

Graph::Graph(int _vertexCount) {
  vertexCount = _vertexCount;
  adjacencyMatrix = new bool*[vertexCount];
  for (int i = 0; i < vertexCount; i++) {
    adjacencyMatrix[i] = new bool[vertexCount];
    for (int j = 0; j < vertexCount; j++)
      adjacencyMatrix[i][j] = false;
  }
}

void Graph::addNode(int _elem) {
  GNode *temp = new GNode(_elem);
  nodes.push_back(temp);
  temp -> id = nodes.size();
}

void Graph::addEdge(int _i, int _j) {
  if (_i >= 0 && _i < vertexCount && _j > 0 && _j < vertexCount) {
    adjacencyMatrix[_i][_j] = true;
    adjacencyMatrix[_j][_i] = true;
  }
}

void Graph::removeEdge(int _i, int _j) {
  if (_i >= 0 && _i < vertexCount && _j > 0 && _j < vertexCount) {
    adjacencyMatrix[_i][_j] = false;
    adjacencyMatrix[_j][_i] = false;
  }
}

bool Graph::isEdge(int _i, int _j) {
  if (_i >= 0 && _i < vertexCount && _j > 0 && _j < vertexCount)
    return adjacencyMatrix[_i][_j];
  else
    return false;
}

Graph::~Graph() {
  for (int i = 0; i < vertexCount; i++)
    delete[] adjacencyMatrix[i];
  delete[] adjacencyMatrix;
}

GNode* Graph::visitNode(GNode *_node) {
  _node -> colour = 2;
  int i = _node -> id;
  for (int j=0; j<vertexCount; ++j) {
    if (adjacencyMatrix[i][j] && nodes[j] -> colour == 1)
      visitNode(nodes[j]);
  }
  _node -> colour = 3;
  return _node
}

void DFS() {
  for (int i=0; i<vertexCount; ++i)
    nodes[i] -> colour = 1;

}
