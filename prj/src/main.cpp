#include <iostream>

#include "benchmark.hh"
#include "stos.hh"
#include "kolejka.hh"
#include "lista.hh"
#include "tab_lista.hh"
#include "algorithm_stos.hh"
#include "algorithm_kolejka.hh"
#include "algorithm_lista.hh"
#include "algorithm2.hh"
#include "asocjacyjna.hh"
#include "mieszajaca.hh"

/*!
 *\brief Funkcja tworzaca i testujaca algorytm.
 *Wczytuje dane otrzymane na strumien wejsciowy do tablicy data[].
 *Nastepnie tworzy obiekt Benchmark oraz obiekt Potegowanie.
 *Pozniej uruchamia metode testujaca w obiekcie klasy Benchmark
 *dla obiektu klasy Potegowanie.
 *\retval 0 - domyslna wartosc zwracana przez funkcje.
 */
int main() {

  int data[SIZE];

  for(int i=0; i<SIZE; ++i)
    std::cin >> data[i];

  Benchmark *bench = new Benchmark();//klasa testujaca czas
  AlgorithmStos *stos = new AlgorithmStos(data);
  //AlgorithmKolejka *kolejka = new AlgorithmKolejka(data);
  //AlgorithmLista *lista = new AlgorithmLista(data);
  //Algorithm2 *tablista = new Algorithm2(data);

  bench -> testAlgorithm(stos,0);
  //bench -> testAlgorithm(kolejka,1);
  //bench -> testAlgorithm(lista,2);
  //bench -> testAlgorithm(tablista,3);

  /*
  Asocjacyjna tab1;
  tab1["Kot"] = 15;
  tab1["Cycek"] = 12;
  std::cout << tab1["Kot"] << tab1["Cycek"];
  */

  /*
  Mieszajaca *miesz = new Mieszajaca(100);
  delete miesz;
  */

  return 0;
}
