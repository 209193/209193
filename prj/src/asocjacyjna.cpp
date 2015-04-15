#include <iostream>
#include <cstring>
#include <cctype>

#include "asocjacyjna.hh"


Asocjacyjna::Asocjacyjna() {

  head = nullptr;
}


Asocjacyjna::Asocjacyjna(const Asocjacyjna &l) {

  ANode *src, **dst;
  head = nullptr;
  src = l.head;
  dst = &head;

  try
    {
      while (src)
	{
	  *dst = new ANode (*src);
	  src = src->next;
	  dst = &((*dst)->next);
	}
    }
  catch (...)
    {
      clear ();
      throw;
    };
}


Asocjacyjna::~Asocjacyjna() {

  clear ();
}


Asocjacyjna & Asocjacyjna::operator=(const Asocjacyjna &l) {

  if (&l == this)
    return *this;

  ANode *src, **dst;
  head = nullptr;
  src = l.head;
  dst = &head;

  try
    {
      while (src)
	{
	  *dst = new ANode (*src);
	  src = src->next;
	  dst = &((*dst)->next);
	}
    }
  catch (...)
    {
      clear ();
      throw;
    }

  return *this;
}


void Asocjacyjna::clear() {

  while (head)
    {
      ANode *t = head->next;
      delete head;
      head = t;
    }
}


void Asocjacyjna::insert(const char *key, int value) {

  ANode *nowy = new ANode(key);
  nowy->next = head;
  head = nowy;
  head->val = value;
}


void Asocjacyjna::swap(Asocjacyjna &l) {

  ANode *t = head;
  head = l.head;
  l.head = t;
}


ANode * Asocjacyjna::find(const char *key) const {

  ANode * c = head;
  while (c)
    {
      if (!strcmp (c->key, key))
	return c;
      c = c->next;
    }
  return nullptr;
}


int & Asocjacyjna::operator[](const char *key) {

  ANode *c = find(key);

  if (!c)
    {
      insert(key, 0);
      c = head;
    }

  return c->val;
}
