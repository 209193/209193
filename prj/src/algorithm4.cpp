#include <iostream>

#include "stos.hh"
#include "benchmark.hh"
#include "algorithm4.hh"


void Algorithm4::runAlgorithm(int _border) {

  stos.mergesort(0, _border-1);
}


void Algorithm4::load(int _border) {

  for (int i=0; i<_border; ++i) stos.push(tab[i]);
}


void Algorithm4::unload(int _border) {

  for (int i=0; i<_border; ++i) stos.pop();
}
