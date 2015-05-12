#include <algorithm>

#include "tablicowe.hh"
#include "sort.hh"

void Sort::quicksort(Tablicowe *_struct,int _poczatek, int _koniec) {

  int x = _struct -> Tablica()[_poczatek];
  int i = _poczatek;
  int j = _koniec;
  do {
    while (_struct -> Tablica()[i] < x)
      ++i;
    while (_struct -> Tablica()[j]>x)
      --j;
    if (i <= j) {
      std::swap(_struct -> Tablica()[i], _struct -> Tablica()[j]);
      ++i;
      --j;
    }
  } while (i <= j);
  if (_poczatek < j) quicksort(_struct, _poczatek, j);
  if (_koniec > i) quicksort(_struct, i, _koniec);
}


void Sort::optquicksort(Tablicowe *_struct,int _poczatek, int _koniec) {

  int x = (_struct -> Tablica()[_poczatek] + _struct -> Tablica()[(_poczatek + _koniec)/2] + _struct -> Tablica()[_koniec])/3;
  int i = _poczatek;
  int j = _koniec;
  do {
      while (_struct -> Tablica()[i] < x) ++i;
      while (_struct -> Tablica()[j]>x) --j;
      if (i <= j) {
	std::swap(_struct -> Tablica()[i], _struct -> Tablica()[j]);
	++i;
	--j;
      }
  } while (i <= j);
  if (_poczatek < j) optquicksort(_struct, _poczatek, j);
  if (_koniec > i) optquicksort(_struct, i, _koniec);
}


void Sort::mergesort(Tablicowe *_struct, int _poczatek, int _koniec) {
  int *temptab = new int[_struct -> Rozmiar()];
  int ip = _poczatek;
  int ik = _koniec;
  int is = (ip + ik + 1)/2;

  if (is-ip > 1) mergesort(_struct, ip, is-1);
  if (ik-is > 0) mergesort(_struct, is, ik);
  int i1 = ip;
  int i2 = is;

  for (int i=ip; i<=ik; ++i) {
    if ((i1==is) || ((i2<=ik) && (_struct -> Tablica()[i1] > _struct -> Tablica()[i2]))) {
      temptab[i] = _struct -> Tablica()[i2];
      ++i2;
    }
    else {
      temptab[i] = _struct -> Tablica()[i1];
      ++i1;
    }
  }
  for (int i=ip; i<=ik; ++i) _struct -> Tablica()[i] = temptab[i];
}


void Sort::heapify(Tablicowe *_struct, int _i, int _max) {
  int largest, c1, c2;
  while (_i < _max) {
    largest = _i;
    c1 = (2*_i) + 1;
    c2 = c1 + 1;
    if (c1 < _max && _struct -> Tablica()[c1] > _struct -> Tablica()[largest]) largest = c1;
    if (c2 < _max && _struct -> Tablica()[c2] > _struct -> Tablica()[largest]) largest = c2;
    if (largest == _i) return;
    std::swap(_struct -> Tablica()[_i], _struct -> Tablica()[largest]);
    _i = largest;
  }
}


void Sort::build_heap(Tablicowe *_struct) {
  int i = (_struct -> Rozmiar()/2) - 1;
  while (i >= 0) {
    heapify(_struct, i, _struct -> Rozmiar());
    --i;
  }
}


void Sort::heapsort(Tablicowe *_struct, int _koniec) {
  build_heap(_struct);
  int end = _koniec;
  while (end > 0) {
    std::swap(_struct -> Tablica()[0], _struct -> Tablica()[end]);
    heapify(_struct, 0, end);
    --end;
  }
}
