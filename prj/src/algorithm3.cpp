#include <iostream>

#include "stos.hh"
#include "benchmark.hh"
#include "algorithm3.hh"


void Algorithm3::runAlgorithm(int _border) {

  stos.heapsort(_border-1);
}


void Algorithm3::load(int _border) {

  for (int i=0; i<_border; ++i) stos.push(tab[i]);
}


void Algorithm3::unload(int _border) {

  for (int i=0; i<_border; ++i) stos.pop();
}
