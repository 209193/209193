#include <iostream>

#include "tablicowe.hh"
#include "sort.hh"
#include "stos.hh"
#include "observer.hh"
#include "subject.hh"
#include "benchmark.hh"
#include "algorithm1.hh"


Algorithm1::Algorithm1(unsigned short *_tab, int _id) {
  tab = _tab;
  id = _id;
  std::cerr << "Algorithm created. Id: " << id << std::endl;
}


Algorithm1::~Algorithm1() {
  std::cerr << "Algorithm deleted. Id: " << id << std::endl;
}


void Algorithm1::runAlgorithm(int _border) {
  std::cerr << "Algorithm run." << std::endl;
  sort.quicksort(&stos, 0, _border-1);
}


void Algorithm1::load(int _border) {
  std::cerr << "Algorithm loaded." << std::endl;
  for (int i=0; i<_border; ++i) stos.push(tab[i]);
}


void Algorithm1::unload(int _border) {
  std::cerr << "Algorithm unloaded." << std::endl;
  for (int i=0; i<_border; ++i) stos.pop();
}
