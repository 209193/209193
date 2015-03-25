#include <iostream>

#include "stos.hh"

Stos::Stos() {
  last = 0;
  size = 8;

  tab = new int[size];

  if(tab == nullptr) std::cerr << "Blad alokacji" << std::endl;
}

Stos::Stos(long _size) {
  last = 0;
  size = _size;

  tab = new int[size];

  if(tab == nullptr) std::cerr << "Blad alokacji" << std::endl;
}

Stos::~Stos() {
  delete []tab;
}

void Stos::push(int _elem) {
  if(last == size) increase();

  tab[last] = _elem;
  ++last;
  
}

int Stos::pop() {

  int temp=decrease();
  --last;
  return temp;
}

void Stos::increase() {

  int *nowa = new int[size + 8];//tworzymy zastepczy stos o 8 wiekszy

  for(int i=0; i<size; ++i) nowa[i] = tab[i];//przepisujemy stary stos

  delete []tab;
  tab = nowa;
  size += 8;//powiekszamy zmienna przechowujaca informacje o rozmiarze o 8
}

int Stos::decrease() {
  int temp = tab[size-1];//zmienna tymczasowa przechowujaca usuwany element
  --size;//pomniejszamy zmienna przechowujaca informacje o rozmiarze o 1
  int *nowa = new int[size];//tworzymy zastepczy stos o 1 mniejszy

  for(int i=0; i<size; ++i) nowa[i] = tab[i];//przepisujemy stary stos

  delete []tab;
  tab = nowa;

  return temp;//zwracamy usuwany element
}
