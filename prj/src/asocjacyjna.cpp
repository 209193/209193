#include <iostream>
#include <cstring>

#include "asocjacyjna.hh"


//STRUKTURA ANODE
ANode::ANode(const char *_k) {
  next = nullptr;
  key = new char[strlen(_k) + 1];
  strcpy(key, _k);
}


ANode::ANode(const ANode &_s) {
  next = nullptr;

  if (_s.key == nullptr)
    key = nullptr;
  else {
    key = new char[strlen(_s.key) + 1];
    strcpy(key, _s.key);
  }

  val = _s.val;
}


ANode::~ANode () {
  delete []key;
}


//KLASA ASOCJACYJNA
Asocjacyjna::Asocjacyjna() {

  head = nullptr;
}


Asocjacyjna::Asocjacyjna(const Asocjacyjna &_l) {

  ANode *src, **dst;
  head = nullptr;
  src = _l.head;
  dst = &head;

  try {
    while (src) {
      *dst = new ANode (*src);
      src = src -> next;
      dst = &((*dst) -> next);
    }
  }
  catch (...) {
    clear ();
    throw;
  }
}


Asocjacyjna::~Asocjacyjna() {

  clear ();
}


Asocjacyjna& Asocjacyjna::operator= (const Asocjacyjna &_l) {

  if (&_l == this)
    return *this;

  ANode *src, **dst;
  head = nullptr;
  src = _l.head;
  dst = &head;

  try {
    while (src) {
      *dst = new ANode (*src);
      src = src -> next;
      dst = &((*dst) -> next);
    }
  }
  catch (...) {
    clear ();
    throw;
  }

  return *this;
}


void Asocjacyjna::clear() {

  while (head) {
    ANode *t = head -> next;
    delete head;
    head = t;
  }
}


void Asocjacyjna::insert(const char *_key, int _value) {

  ANode *nowy = new ANode(_key);
  nowy -> next = head;
  head = nowy;
  head -> val = _value;
}


void Asocjacyjna::swap(Asocjacyjna &_l) {

  ANode *t = head;
  head = _l.head;
  _l.head = t;
}


ANode* Asocjacyjna::find(const char *_key) const {

  ANode *c = head;
  while (c) {
    if (!strcmp(c->key, _key))
      return c;
    c = c -> next;
  }
  return nullptr;
}


int& Asocjacyjna::operator[](const char *_key) {

  ANode *c = find(_key);

  if (!c) {
    insert(_key, 0);
    c = head;
  }

  return c -> val;
}


std::ostream& operator<< (std::ostream &_stream, Asocjacyjna &_l) {
  ANode *c = _l.head;
  while (c) {
    _stream << c->val << " ";
    c = c->next;
  }
  return _stream;
}
