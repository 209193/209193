#include <iostream>

#include "observer.hh"
#include "subject.hh"


int Subject::tell_id() {
  return id;
}


void Subject::add(Observer *_obs) {
  std::cerr << "For subject id: " << id;
  std::cerr << ", observer with id: ";
  std::cerr << _obs -> tell_id();
  std::cerr << " added." << std::endl;
  observers.push_back (_obs);
}


void Subject::remove(Observer *_obs) {
  std::cerr << "For subject id: " << id;
  std::cerr << ", observer with id: ";
  std::cerr << _obs -> tell_id();
  std::cerr << " removed." << std::endl;
  observers.remove (_obs);
}


void Subject::notify() {
  std::cerr << "Subject with id: " << id;
  std::cerr << " notifies watching observers." << std::endl;
  std::list<Observer *>::iterator it;
  for (it = observers.begin(); it != observers.end(); ++it) {
    (*it) -> update();
  }
}
