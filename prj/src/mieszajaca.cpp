#include <iostream>
#include <cstring>

#include "mieszajaca.hh"


Mieszajaca::Mieszajaca() {

  size = 100;

  tab_l = new MNode*[size];
  tab_p = new MNode*[size];

  if(tab_l == nullptr) std::cerr << "Blad alokacji tab_l" << std::endl;
  if(tab_p == nullptr) std::cerr << "Blad alokacji tab_p" << std::endl;
}


Mieszajaca::Mieszajaca(long _size) {

  size = _size;

  tab_l = new MNode*[size];
  tab_p = new MNode*[size];

  if(tab_l == nullptr) std::cerr << "Blad alokacji tab_l" << std::endl;
  if(tab_p == nullptr) std::cerr << "Blad alokacji tab_p" << std::endl;
}


Mieszajaca::~Mieszajaca() {

  delete []tab_l;
  delete []tab_p;
}


unsigned Mieszajaca::sax_hash(const char *key) const
{
  const char *p = key;
  unsigned len = (strlen(p)+1);
  unsigned h = 0;
  unsigned i;

  for (i = 0; i < len; ++i)
    {
      h ^= (h << 5) + (h >> 2) + p[i];
    }
  h %= this->size;

  return h;
}


unsigned Mieszajaca::fnv_hash(const char *key) const
{
  const char *p = key;
  unsigned len = (strlen(p)+1);
  unsigned h = 2166136261;
  unsigned i;

  for (i = 0; i < len; ++i)
    {
      h = (h * 16777619) ^ p[i];
    }
  h %= this->size;

  return h;
}

void Mieszajaca::insert(const char *key, int value) {
  
  unsigned i = sax_hash(key);
  unsigned j = fnv_hash(key);

  MNode *nowy = new MNode(key);
  nowy -> val = value;

  if(!tab_l[i]) tab_l[i] = nowy;
  else if(!tab_p[j]) tab_p[i] = nowy;
  
  for(; i<size; ++i)
    if(!tab_l[i]) tab_l[i] = nowy;

  for(; j<size; ++j)
      if(!tab_p[j]) tab_p[j] = nowy;
}


MNode * Mieszajaca::find(const char *key) const {

  unsigned i = sax_hash(key);
  unsigned j = fnv_hash(key);

  if(!strcmp (tab_l[i]->key,key)) return tab_l[i];
  else if(!strcmp (tab_p[j]->key,key)) return tab_p[i];

  for(; i<size; ++i)
    if(!strcmp (tab_l[i]->key,key)) return tab_l[i];

  for(; j<size; ++j)
      if(!strcmp (tab_p[j]->key,key)) return tab_p[j];

  return nullptr;
}


int & Mieszajaca::operator[](const char *key) {

  MNode *c = find(key);

  if (!c) insert(key, 0);

  return c->val;
}
