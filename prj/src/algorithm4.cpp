#include <iostream>

#include "tablicowe.hh"
#include "stos.hh"
#include "observer.hh"
#include "subject.hh"
#include "benchmark.hh"
#include "algorithm4.hh"


void Algorithm4::runAlgorithm(int _border) {

  //mergesort(0, _border-1);
}


void Algorithm4::load(int _border) {

  for (int i=0; i<_border; ++i) stos.push(tab[i]);
}


void Algorithm4::unload(int _border) {

  for (int i=0; i<_border; ++i) stos.pop();
}
