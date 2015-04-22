#include <iostream>

#include "benchmark.hh"
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

  int *data = new int[SIZE];
  for(int i=0; i<SIZE; ++i)
    std::cin >> data[i];

  Benchmark *bench = new Benchmark();//klasa testujaca czas
  Algorithm1 *sort1 = new Algorithm1(data);
  Algorithm2 *sort2 = new Algorithm2(data);
  Algorithm3 *sort3 = new Algorithm3(data);
  Algorithm4 *sort4 = new Algorithm4(data);

  bench -> testAlgorithm(sort1,0);
  bench -> testAlgorithm(sort2,1);
  bench -> testAlgorithm(sort3,2);
  bench -> testAlgorithm(sort4,3);

  return 0;
}
