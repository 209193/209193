#include <iostream>

#include "tablicowe.hh"
#include "stos.hh"
#include "observer.hh"
#include "subject.hh"
#include "benchmark.hh"
#include "algorithm2.hh"


void Algorithm2::runAlgorithm(int _border) {

  //optquicksort(0, _border-1);
}


void Algorithm2::load(int _border) {

  for (int i=0; i<_border; ++i) stos.push(tab[i]);
}


void Algorithm2::unload(int _border) {

  for (int i=0; i<_border; ++i) stos.pop();
}
