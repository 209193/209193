#include <iostream>

#include "observer.hh"
#include "subject.hh"
#include "benchmark.hh"
#include "writing_observer.hh"


WritingObserver::WritingObserver(Benchmark *_benchmark, int _id) {

  benchmark = _benchmark;
  id = _id;
  ret_data.open("ret_data.txt", std::ofstream::out | std::ofstream::trunc);

  if (ret_data.is_open()) {
    ret_data << "elem\ttime" << std::endl;//zapisujemy naglowek pliku
  }
  else std::cerr << "Unable to open ret_data file" << std::endl;
}


WritingObserver::~WritingObserver() {

  ret_data.close();
}


void WritingObserver::update() {

  ret_data << (benchmark -> getTime());
  ret_data << '\t';
  ret_data << (benchmark -> getSize());
}
