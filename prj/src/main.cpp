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
  Algorithm1 *alg1 = new Algorithm1(data);
  Algorithm2 *alg2 = new Algorithm2(data);
  Algorithm3 *alg3 = new Algorithm3(data);
  Algorithm4 *alg4 = new Algorithm4(data);

  bench -> testAlgorithm(alg1,0);
  bench -> testAlgorithm(alg2,1);
  bench -> testAlgorithm(alg3,2);
  bench -> testAlgorithm(alg4,3);

  return 0;
}
