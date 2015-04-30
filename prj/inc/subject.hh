#ifndef SUBJECT_HH
#define SUBJECT_HH

class Subject {
protected:
  std::list<Observer*> observers;
public:
  void add(Observer *obs) {
    observers.push_back (obs);
  }
  void remove(Observer *obs) {
    observers.remove (obs);
  }

  void tell() {
    std::list<Observer *>::iterator it;
    for (it = observers.begin(); it != observers.end(); it++) {
      (*it)->update ();
    }
  }
}

#endif
