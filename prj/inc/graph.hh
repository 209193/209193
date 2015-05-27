#ifndef GRAPH_HH
#define GRAPH_HH

#include <vector>

struct GNode {
  /*!
   *\brief Identyfikator wierzcholka.
   */ 
  int id;
  /*!
   *\brief Wartosc elementu w pojedynczym wierzcholku.
   */  
  int elem;
  /*!
   *\brief Konstruktor paramteryczny obiektu GNode.
   *\param[in] _elem - wartosc przechowywanego elementu.
   */
  GNode(int _elem);
};


struct Graph {
private:
  /*!
   *\brief Wskaznik na liste wierzcholkow.
   */ 
  std::vector <GNode*> nodes;
  /*!
   *\brief Wskaznik na tablice krawedzi miedzy wierzcholkami.
   */ 
  bool** adjacencyMatrix;
  /*!
   *\brief Ilosc krawedzi pomiedzy wierzcholkami.
   */ 
  int vertexCount;
  /*!
   *\brief Wyliczeniowy typ dla stanu wierzcholka.
   */ 
  enum vertexState {White, Gray, Black};

public:
  /*!
   *\brief Konstruktor paramteryczny obiektu Graph.
   *\param[in] _vertexCount - ilosc przechowywanych wierzcholkow.
   */
  Graph(int _vertexCount);
  /*!
   *\brief Metoda dodawania wierzcholka.
   *Metoda sluzy do dodawania wierzcholka o zadanej wartosci.
   *\param[in] _elem - wartosc tworzonego wierzcholka.
   */
  void addNode(int _elem);
  /*!
   *\brief Metoda dodawania krawedzi.
   *Metoda sluzy do dodawania krawedzi pomiedzy wierzcholkami.
   *\param[in] _i - identyfikator pierwszego wierzcholka.
   *\param[in] _j - identyfikator drugiego wierzcholka.
   */
  void addEdge(int _i, int _j);
  /*!
   *\brief Metoda sprawdzania krawedzi.
   *Metoda sluzy do sprawdzania istnienia
   *krawedzi pomiedzy wierzcholkami.
   *\param[in] _i - identyfikator pierwszego wierzcholka.
   *\param[in] _j - identyfikator drugiego wierzcholka.
   *\return stan istnienia krawedzi.
   */
  bool isEdge(int _i, int _j);
  /*!
   *\brief Metoda wykonywania DFS.
   *Metoda sluzy do przeszukiwania grafu w głąb.
   *\param[in] _u - identyfikator komorki odniesienia.
   *\param[in] _state - tablica stanow komorek.
   */
  void runDFS(int _u, vertexState *&_state);
  /*!
   *\brief Metoda rozpoczynania DFS.
   *Metoda sluzy do uruchamiania przeszukiwania grafu w głąb.
   */
  void DFS();
  /*!
   *\brief Metoda wykonywania BFS.
   *Metoda sluzy do przeszukiwania grafu wszerz.
   *\param[in] _s - identyfikator komorki odniesienia.
   */
  void BFS(int _s);
  /*!
   *\brief Destruktor obiektu Graph.
   */
  ~Graph();
};

#endif
