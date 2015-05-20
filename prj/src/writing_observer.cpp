#include <iostream>

#include "observer.hh"
#include "subject.hh"
#include "benchmark.hh"
#include "writing_observer.hh"


WritingObserver::WritingObserver(Benchmark *_benchmark, int _id, std::string _string) {
  std::cerr << "WritingObserver created. Id: " << _id << std::endl;

  benchmark = _benchmark;
  id = _id;
  ret_data.open(_string, std::ofstream::out | std::ofstream::trunc);

  if (ret_data.is_open()) {
    ret_data << "elem\ttime" << std::endl;//zapisujemy naglowek pliku
  }
  else std::cerr << "Unable to open ret_data file" << std::endl;
}


WritingObserver::~WritingObserver() {
  std::cerr << "WritingObserver deleted. Id: " << id << std::endl;

  ret_data.close();
}


void WritingObserver::update() {
  ++state_id;
  std::cerr << "WritingObserver with id: " << id;
  std::cerr << " notified by subject with id: ";
  std::cerr << benchmark -> tell_id();
  std::cerr << ". Update no. " << state_id;
  std::cerr << " done." << std::endl;

  ret_data << (benchmark -> getTime());
  ret_data << '\t';
  ret_data << (benchmark -> getSize());
  ret_data << std::endl;
}
