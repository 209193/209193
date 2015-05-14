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

  /*
  Algorithm1 *test = new Algorithm1(data, 1);
  WritingObserver *observer = new WritingObserver(test, 2);

  test -> add(observer);
    
  test -> testAlgorithm(test);

  delete observer;
  delete test;
  */

  BinaryTree *tree = new BinaryTree;

  tree -> add(5);
  tree -> add(6);
  tree -> add(3);
  tree -> add(4);

  std::cout << tree -> getvar(6);

  return 0;
}
