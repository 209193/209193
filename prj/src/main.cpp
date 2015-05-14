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
  /*
  int data[SIZE];

  for(int i=0; i<SIZE; ++i)
    std::cin >> data[i];
  */
  
  Asocjacyjna tab1;
  tab1["Kot"] = 15;
  tab1["Cycek"] = 12;
  std::cout << tab1["Kot"] << tab1["Cycek"];


  Mieszajaca *miesz = new Mieszajaca(100);
  miesz["Lot"] = 10;
  miesz["Mamusia"] = 22;
  std::cout << miesz["Lot"] << miesz["Mamusia"];

  return 0;
}
