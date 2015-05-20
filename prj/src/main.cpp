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

  
  Algorithm1 *test1 = new Algorithm1(data, 1);
  WritingObserver *observer1 = new WritingObserver(test1, 2, "ret_1");
  test1 -> add(observer1);
  test1 -> testAlgorithm(test1);
  delete observer1;
  delete test1;
  /*
  Algorithm2 *test2 = new Algorithm2(data, 3);
  WritingObserver *observer2 = new WritingObserver(test2, 4, "ret_2");
  test2 -> add(observer2);
  test2 -> testAlgorithm(test2);
  delete observer2;
  delete test2;
  /*
  Algorithm3 *test3 = new Algorithm3(data, 5);
  WritingObserver *observer3 = new WritingObserver(test3, 6, "ret_3");
  test3 -> add(observer3);
  test3 -> testAlgorithm(test3);
  delete observer3;
  delete test3;
  
  Algorithm4 *test4 = new Algorithm4(data, 7);
  WritingObserver *observer4 = new WritingObserver(test4, 8, "ret_4");
  test4 -> add(observer4);
  test4 -> testAlgorithm(test4);
  delete observer4;
  delete test4;
  */

  return 0;
}
