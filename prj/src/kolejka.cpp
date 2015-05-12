#include <iostream>

#include "tablicowe.hh"
#include "kolejka.hh"


Kolejka::Kolejka() {

  size = 8;//poczatkowy rozmiar kolejki
  last = 0;
 
  tab = new short unsigned[size];
  if(tab == nullptr) std::cerr << "Blad alokacji" << std::endl;
}


Kolejka::Kolejka(long _size) {

  size = _size;
  last = 0;

  tab = new short unsigned[size];
  if(tab == nullptr) std::cerr << "Blad alokacji" << std::endl;
}


Kolejka::~Kolejka() {

  delete []tab;
}


void Kolejka::increase() {

  short unsigned *nowa = new short unsigned[size * 2];

  for(long i=0; i<size; ++i) nowa[i] = tab[i];
  
  delete []tab; 
  tab = nowa;
  size *= 2;//zwiekszamy rozmiar dwukrotnie
}


int Kolejka::decrease() {

  int temp = tab[0];//zmienna tymczasowa przechowujaca usuwany element
  --size;//pomniejszamy zmienna przechowujaca informacje o rozmiarze o 1
  short unsigned *nowa = new short unsigned[size];//tworzymy zastepczy stos o 1 mniejszy

  for (long i=0; i<size; ++i) nowa[i] = tab[i+1];//przepisujemy stary stos

  delete []tab;
  tab = nowa;

  return temp;//zwracamy usuwany element
}


void Kolejka::enqueue(int _elem) {

  if(last == size) increase();//przy zapelnieniu powiekszamy kolejke
  
  tab[last] = _elem;
  ++last;
}


int Kolejka::dequeue() {

  int temp = decrease();//zmienna przechowujaca usuwany element
  --last;
  return temp;//zwracamy usuwany element
}
