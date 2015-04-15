#include <iostream>

#include "lista.hh"


void Lista::insert(int _elem) {

  if (head != nullptr) {
    Komorka* temp = new Komorka(_elem);
    if (temp == nullptr)
      std::cerr << "Blad alokacji" << std::endl;
    tail->next = temp;
    tail = temp;
  }
  else {
    head = new Komorka(_elem);
    tail = head;
  }
}


int Lista::remove(int _f) {

  Komorka* temp = head;
  Komorka* prev = nullptr;
  for (int i=0; i<_f; ++i){//przesuwamy sie do wskazanej komorki
    if (temp != nullptr) {
      prev = temp;
      temp = temp->next;
    }
    else
      std::cerr << "Przekroczenie zakresu listy" << std::endl;
  }
  int val = temp->elem;//przepisujemy wartosc z komorki do usuniecia

  prev->next = temp->next;
  delete temp;

  return val;//zwracamy usuwany element
}
