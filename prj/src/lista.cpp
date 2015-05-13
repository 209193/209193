#include <iostream>

#include "lista.hh"


//KOMORKA
Komorka::Komorka(int _elem) {
  elem = _elem;
  next = nullptr;
}


//LISTA
void Lista::insert_last(int _elem) {

  if (head != nullptr) {
    Komorka *temp = new Komorka(_elem);
    if (temp == nullptr) std::cerr << "Blad alokacji" << std::endl;
    tail->next = temp;
    tail = temp;
  }
  else {
    head = new Komorka(_elem);
    tail = head;
  }
}


int Lista::remove_front() {

  Komorka *temp = head;

  int val = head->elem;//przepisujemy wartosc z komorki do usuniecia
  head = temp->next;
  delete temp;

  return val;//zwracamy usuwany element
}
