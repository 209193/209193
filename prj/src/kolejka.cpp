#include <iostream>

#include "kolejka.hh"


Kolejka::Kolejka() {

  size = 8;//poczatkowy rozmiar kolejki
  f = -1;//-1 bo tablica pusta, indeks pierwszego zapisanego miejsca
  r = 0;//indeks nastepnego pustego miejsca
 
  tab = new int[size];
  if(tab == nullptr) std::cerr << "Blad alokacji" << std::endl;
}


Kolejka::Kolejka(long _size) {

  size = _size;
  f = -1;
  r = 0;

  tab = new int[size];
  if(tab == nullptr) std::cerr << "Blad alokacji" << std::endl;
}


Kolejka::~Kolejka() {

  delete []tab;
}


void Kolejka::increase() {

  int *nowa = new int[size + 8];//nowa lista przechowujaca kolejke, wieksza o 8

  for(int i=0; i<r; ++i) nowa[i] = tab[i];//przepisujemy w taki sposob, zeby rozszerzyc tablice pomiedzy
  for(int i=r+8; i<(size+8); ++i) nowa[i] = tab[i];//iteratorami r i f
  
  delete []tab; 
  tab = nowa;

  f += 8;//po rozszerzeniu przesuwamy f o 8 miejsc dalej
  size +=8;//zwiekszamy rozmiar
}


void Kolejka::enqueue(int _elem) {

  if(r == f) increase();//przy zapelnieniu powiekszamy kolejke
  
  tab[r] = _elem;
  if(f == -1) ++f;//sprawdzamy czy kolejka byla inicjalizowana
  ++r;//przesuwamy wolne miejsce o 1 dalej
}


int Kolejka::dequeue() {

  int temp = tab[f];//zmienna przechowujaca usuwany element

  //przesuwamy indeks zapisanego elementu o 1 miejsce dalej
  if(f != -1) {//sprawdzamy czy lista niepusta
    if(f != (size-1)) ++f;//sprawdzamy czy nie jestesmy na koncu listy
    else f = 0;//jezeli tak to przesuwamy sie na poczatek
  }
  else {
    std::cerr << "Blad dequeue! Lista pusta!" << std::endl;
    return -1;
  }

  return temp;//zwracamy usuwany element
}
