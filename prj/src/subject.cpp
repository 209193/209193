#include "observer.hh"
#include "subject.hh"

void Subject::add(Observer *_obs) {
  observers.push_back (_obs);
}


void Subject::remove(Observer *_obs) {

  observers.remove (_obs);
}


void Subject::notify() {
  std::list<Observer *>::iterator it;
  for (it = observers.begin(); it != observers.end(); ++it) {
    (*it) -> update();
  }
}
