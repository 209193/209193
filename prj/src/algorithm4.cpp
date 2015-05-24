#include <iostream>

#include "rb_tree.hh"
#include "observer.hh"
#include "subject.hh"
#include "benchmark.hh"
#include "algorithm4.hh"


Algorithm4::Algorithm4(unsigned short *_tab, int _id) {
  tab = _tab;
  id = _id;
  std::cerr << "Algorithm created. Id: " << id << std::endl;
}


Algorithm4::~Algorithm4() {
  std::cerr << "Algorithm deleted. Id: " << id << std::endl;
}


void Algorithm4::runAlgorithm(int _border) {
  std::cerr << "Algorithm run." << std::endl;
  tree.print_tree();
}


void Algorithm4::load(int _border){
  for (int i=0; i<_border; ++i)
    tree.add_elem(tab[i]);
  std::cerr << "Algorithm loaded." << std::endl;
}


void Algorithm4::unload(int _border) {
  std::cerr << "Algorithm unloaded." << std::endl;
}
