#include <iostream>

#include "observer.hh"
#include "subject.hh"
#include "benchmark.hh"
#include "writing_observer.hh"
#include "tablicowe.hh"
#include "sort.hh"
#include "stos.hh"
#include "kolejka.hh"
#include "lista.hh"
#include "tab_lista.hh"
#include "asocjacyjna.hh"
#include "mieszajaca.hh"
#include "binary_tree.hh"
#include "rb_tree.hh"
#include "graph.hh"
#include "algorithm1.hh"
#include "algorithm2.hh"
#include "algorithm3.hh"
#include "algorithm4.hh"

/*!
 *\brief Funkcja tworzaca i testujaca algorytm.
 *Wczytuje dane otrzymane na strumien wejsciowy do tablicy data[].
 *Nastepnie tworzy obiekt Benchmark oraz obiekt Potegowanie.
 *Pozniej uruchamia metode testujaca w obiekcie klasy Benchmark
 *dla obiektu klasy Potegowanie.
 *\retval 0 - domyslna wartosc zwracana przez funkcje.
 */
int main() {

  unsigned short *data = new unsigned short[SIZE];
  for(int i=0; i<SIZE; ++i)
    std::cin >> data[i];
  
  Graph *graph = new Graph(6);

  graph -> addNode(5);
  graph -> addNode(3);
  graph -> addNode(4);
  graph -> addNode(2);
  graph -> addNode(7);
  graph -> addNode(11);

  graph -> addEdge(0,1);
  graph -> addEdge(0,2);
  graph -> addEdge(1,2);
  graph -> addEdge(2,5);
  graph -> addEdge(5,3);
  graph -> addEdge(5,4);

  //graph -> DFS();
  graph -> BFS(0);

  return 0;
}
