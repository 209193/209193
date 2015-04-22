#include <iostream>
#include <cstdlib>

#include "stos.hh"


Stos::Stos() {

  last = 0;
  size = 8;

  tab = new int[size];

  if (tab == nullptr) std::cerr << "Blad alokacji" << std::endl;
}


Stos::Stos(long _size) {

  last = 0;
  size = _size;

  tab = new int[size];

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

  int *nowa = new int[size + 8];//tworzymy zastepczy stos o 8 wiekszy

  for (int i=0; i<size; ++i) nowa[i] = tab[i];//przepisujemy stary stos

  delete []tab;
  tab = nowa;
  size += 8;//powiekszamy zmienna przechowujaca informacje o rozmiarze o 8
}


int Stos::decrease() {

  int temp = tab[size-1];//zmienna tymczasowa przechowujaca usuwany element
  --size;//pomniejszamy zmienna przechowujaca informacje o rozmiarze o 1
  int *nowa = new int[size];//tworzymy zastepczy stos o 1 mniejszy

  for (int i=0; i<size; ++i) nowa[i] = tab[i];//przepisujemy stary stos

  delete []tab;
  tab = nowa;

  return temp;//zwracamy usuwany element
}


void Stos::quicksort(int poczatek, int koniec) {

  int x = tab[poczatek];
  int i = poczatek;
  int j = koniec;
  do {
      while (tab[i] < x)
	++i;
      while (tab[j]>x)
	--j;
      if (i <= j) {
	std::swap(tab[i], tab[j]);
	++i;
	--j;
      }
  } while (i <= j);
  if (poczatek < j) quicksort(poczatek, j);
  if (koniec > i) quicksort(i, koniec);
}


void Stos::optquicksort(int poczatek, int koniec) {

  int x = (tab[poczatek] + tab[(poczatek + koniec)/2] + tab[koniec])/3;
  int i = poczatek;
  int j = koniec;
  do {
      while (tab[i] < x) ++i;
      while (tab[j]>x) --j;
      if (i <= j) {
	std::swap(tab[i], tab[j]);
	++i;
	--j;
      }
  } while (i <= j);
  if (poczatek < j) optquicksort(poczatek, j);
  if (koniec > i) optquicksort(i, koniec);
}


void Stos::mergesort(int poczatek, int koniec) {
  int *temptab = new int[size];
  int ip = poczatek;
  int ik = koniec;
  int is = (ip + ik + 1)/2;

  if (is-ip > 1) mergesort(ip, is-1);
  if (ik-is > 0) mergesort(is, ik);
  int i1 = ip;
  int i2 = is;

  for (int i=ip; i<=ik; ++i) {
    if ((i1==is) || ((i2<=ik) && (tab[i1] > tab[i2]))) {
      temptab[i] = tab[i2];
      ++i2;
    }
    else {
      temptab[i] = tab[i1];
      ++i1;
    }
  }
  for (int i=ip; i<=ik; ++i) tab[i] = temptab[i];
}


void Stos::heapify(int i, int max) {
  int largest, c1, c2;
  while (i < max) {
    largest = i;
    c1 = (2*i) + 1;
    c2 = c1 + 1;
    if (c1 < max && tab[c1] > tab[largest]) largest = c1;
    if (c2 < max && tab[c2] > tab[largest]) largest = c2;
    if (largest == i) return;
    std::swap(tab[i], tab[largest]);
    i = largest;
  }
}


void Stos::build_heap() {
  int i = (size/2) - 1;
  while (i >= 0) {
    heapify(i, size);
    --i;
  }
}


void Stos::heapsort(int koniec) {
  build_heap();
  int end = koniec;
  while (end > 0) {
    std::swap(tab[0], tab[end]);
    heapify(0, end);
    --end;
  }
}
