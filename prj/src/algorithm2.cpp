#include <iostream>

#include "binary_tree.hh"
#include "observer.hh"
#include "subject.hh"
#include "benchmark.hh"
#include "algorithm2.hh"


Algorithm2::Algorithm2(unsigned short *_tab, int _id) {
  tab = _tab;
  id = _id;
  std::cerr << "Algorithm created. Id: " << id << std::endl;
}


Algorithm2::~Algorithm2() {
  std::cerr << "Algorithm deleted. Id: " << id << std::endl;
}


void Algorithm2::runAlgorithm(int _border) {
  std::cerr << "Algorithm run." << std::endl;
  tree.print_tree();
}


void Algorithm2::load(int _border) {
  for (int i=0; i<_border; ++i)
    tree.add_elem(tab[i]);
  std::cerr << "Algorithm loaded." << std::endl;
}


void Algorithm2::unload(int _border) {
  std::cerr << "Algorithm unloaded." << std::endl;
  tree.clear();
}
