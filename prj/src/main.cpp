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

 
  Algorithm1 *test = new Algorithm1(data);
  WritingObserver *observer = new WritingObserver(test, 1);

  test -> add(observer);
    
  test -> testAlgorithm(test);

  /*

    Lista *temp = new Lista;
    temp -> insert_last(3);
  temp -> insert_last(5);
  temp -> insert_last(4);
  int x = temp -> remove_front();
  int y = temp -> remove_front();
  int z = temp -> remove_front();
  std::cout << x << y << z;
    */
  return 0;
}
