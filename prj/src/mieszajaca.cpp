#include <iostream>
#include <cstring>

#include "mieszajaca.hh"


//STRUKTURA MNODE
MNode::MNode() {

  key = nullptr;
  val = 0;
}


MNode::MNode(const char *_k) {

  key = new char[strlen(_k) + 1];
  strcpy(key, _k);
}


MNode::MNode(const MNode &_s) {

  if (_s.key == nullptr)
    key = nullptr;
  else {
    key = new char[strlen(_s.key) + 1];
    strcpy(key, _s.key);
  }
  val=_s.val;
}


MNode::~MNode() {

  delete []key;
}


//KLASA MIESZAJACA
Mieszajaca::Mieszajaca() {

  size = 100;
  tab_l = new MNode*[size];
  tab_p = new MNode*[size];

  if (tab_l == nullptr) std::cerr << "Blad alokacji tab_l" << std::endl;
  if (tab_p == nullptr) std::cerr << "Blad alokacji tab_p" << std::endl;
}


Mieszajaca::Mieszajaca(long _size) {

  size = _size;
  tab_l = new MNode*[size];
  tab_p = new MNode*[size];

  if (tab_l == nullptr) std::cerr << "Blad alokacji tab_l" << std::endl;
  if (tab_p == nullptr) std::cerr << "Blad alokacji tab_p" << std::endl;
}


Mieszajaca::~Mieszajaca() {

  delete []tab_l;
  delete []tab_p;
}


unsigned Mieszajaca::sax_hash(const char *_key) const {
  const char *p = _key;
  unsigned len = (strlen(p) + 1);
  unsigned h = 0;
  unsigned i;

  for (i = 0; i < len; ++i) {
    h ^= (h << 5) + (h >> 2) + p[i];
  }
  h %= this->size;

  return h;
}


unsigned Mieszajaca::fnv_hash(const char *_key) const {
  const char *p = _key;
  unsigned len = (strlen(p) + 1);
  unsigned h = 2166136261;
  unsigned i;

  for (i = 0; i < len; ++i) {
      h = (h * 16777619) ^ p[i];
    }
  h %= this->size;

  return h;
}

void Mieszajaca::insert(const char *_key, int _value) {
  
  unsigned i = sax_hash(_key);
  unsigned j = fnv_hash(_key);

  MNode *nowy = new MNode(_key);
  nowy -> val = _value;

  if (!tab_l[i]) tab_l[i] = nowy;
  else if (!tab_p[j]) tab_p[i] = nowy;
  
  for (; i<size; ++i)
    if (!tab_l[i]) tab_l[i] = nowy;

  for (; j<size; ++j)
    if (!tab_p[j]) tab_p[j] = nowy;
}


MNode* Mieszajaca::find(const char *_key) const {

  unsigned i = sax_hash(_key);
  unsigned j = fnv_hash(_key);

  if (!strcmp (tab_l[i] -> key,_key)) return tab_l[i];
  else if (!strcmp(tab_p[j] -> key,_key)) return tab_p[i];

  for (; i<size; ++i)
    if (!strcmp(tab_l[i] -> key, _key)) return tab_l[i];

  for (; j<size; ++j)
      if (!strcmp(tab_p[j] -> key, _key)) return tab_p[j];

  return nullptr;
}


int& Mieszajaca::operator[](const char *key) {

  MNode *c = find(key);

  if (!c) insert(key, 0);

  return c -> val;
}

std::ostream& operator<< (std::ostream &_stream, Mieszajaca &_l) {

  int i;
  for (i=0; i<_l.size; ++i)
    if (_l.tab_l[i]) _stream << _l.tab_l[i] -> val << " ";
  for (i=0; i<_l.size; ++i)
    if (_l.tab_p[i]) _stream << _l.tab_p[i] -> val << " ";

  return _stream;
}
