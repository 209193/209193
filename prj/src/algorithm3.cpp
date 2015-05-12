#include <iostream>

#include "tablicowe.hh"
#include "stos.hh"
#include "observer.hh"
#include "subject.hh"
#include "benchmark.hh"
#include "algorithm3.hh"


void Algorithm3::runAlgorithm(int _border) {

  //heapsort(_border-1);
}


void Algorithm3::load(int _border) {

  for (int i=0; i<_border; ++i) stos.push(tab[i]);
}


void Algorithm3::unload(int _border) {

  for (int i=0; i<_border; ++i) stos.pop();
}
