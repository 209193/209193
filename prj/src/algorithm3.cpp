#include <iostream>

#include "rb_tree.hh"
#include "observer.hh"
#include "subject.hh"
#include "benchmark.hh"
#include "algorithm3.hh"


Algorithm3::Algorithm3(unsigned short *_tab, int _id) {
  tab = _tab;
  id = _id;
  std::cerr << "Algorithm created. Id: " << id << std::endl;
}


Algorithm3::~Algorithm3() {
  std::cerr << "Algorithm deleted. Id: " << id << std::endl;
}


void Algorithm3::runAlgorithm(int _border) {
  std::cerr << "Algorithm run." << std::endl;
  for (int i=0; i<_border; ++i)
    tree.add_elem(tab[i]);
}


void Algorithm3::load(int _border) {
  std::cerr << "Algorithm loaded." << std::endl;
}


void Algorithm3::unload(int _border) {
  std::cerr << "Algorithm unloaded." << std::endl;
}
