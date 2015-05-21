#ifndef GRAPH_HH
#define GRAPH_HH

#include <vector>

struct GNode {
  int id;
  int elem;
  int colour;

  GNode(int _elem);
};


class Graph {

  std::vector <GNode*> nodes;
  bool** adjacencyMatrix;
  int vertexCount;

public:

  Graph(int _vertexCount);

  void addNode(int _elem);

  void addEdge(int _i, int _j);

  void removeEdge(int _i, int _j);
 
  bool isEdge(int _i, int _j);

  GNode* visitNode(GNode *_node);
 
  void DFS();

  ~Graph();

};

#endif
