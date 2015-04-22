#include <iostream>
#include <fstream>

#include "stos.hh"
#include "benchmark.hh"
#include "algorithm1.hh"


void Algorithm1::runAlgorithm(int _border) {

  stos.quicksort(0, _border-1);
}


void Algorithm1::load(int _border) {

  for (int i=0; i<_border; ++i) stos.push(tab[i]);
}


void Algorithm1::unload(int _border) {

  /*
  std::ofstream ret("danesort.txt");
  if (ret.is_open())
    for (int i=0; i<_border; ++i) ret << stos.pop() << ' ';
  ret.close();
  */

  for (int i=0; i<_border; ++i) stos.pop();
}
