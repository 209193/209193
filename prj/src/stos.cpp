#include <iostream>
#include <cstdlib>

#include "tablicowe.hh"
#include "stos.hh"


Stos::Stos() {

  size = 8;
  last = 0;

  tab = new short unsigned[size];

  if (tab == nullptr) std::cerr << "Blad alokacji" << std::endl;
}


Stos::Stos(long _size) {

  size = _size;
  last = 0;

  tab = new short unsigned[size];

  if (tab == nullptr) std::cerr << "Blad alokacji" << std::endl;
}


Stos::~Stos() {

  delete []tab;
}


void Stos::push(int _elem) {

  if (last == size) increase();

  tab[last] = _elem;
  ++last;
}


int Stos::pop() {

  int temp = decrease();
  --last;
  return temp;
}


void Stos::increase() {

  short unsigned *nowa = new short unsigned[size * 2];//tworzymy zastepczy stos o dwukrotnie wiekszy

  for (long i=0; i<size; ++i) nowa[i] = tab[i];//przepisujemy stary stos

  delete []tab;
  tab = nowa;
  size *= 2;//powiekszamy zmienna przechowujaca informacje o rozmiarze dwukrotnie
}


int Stos::decrease() {

  int temp = tab[size-1];//zmienna tymczasowa przechowujaca usuwany element
  --size;//pomniejszamy zmienna przechowujaca informacje o rozmiarze o 1
  short unsigned *nowa = new short unsigned[size];//tworzymy zastepczy stos o 1 mniejszy

  for (long i=0; i<size; ++i) nowa[i] = tab[i];//przepisujemy stary stos

  delete []tab;
  tab = nowa;

  return temp;//zwracamy usuwany element
}
