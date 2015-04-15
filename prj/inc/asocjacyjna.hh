#ifndef ASOCJACYJNA_HH
#define ASOCJACYJNA_HH

#include <cstring>

/*!
 *\brief Struktura ANode.
 *Obiekt tego typu reprezentuje pojedyncza komorke
 *wraz ze wskaznikiem na nastepna komorke listy.
 */
struct ANode {

  /*!
   *\brief Wskaznik na nastepna komorke.
   */ 
  ANode *next;
    /*!
     *\brief Wskaznik na klucz.
     */ 
  char *key;
    /*!
     *\brief Wartosc klucza.
     */ 
  int val;

  /*!
   *\brief Konstruktor paramteryczny struktury ANode.
   *\param[in] k - wskaznik na klucz.
   */
  ANode (const char *k):next (nullptr)
  {
    key = new char[strlen (k) + 1];
    strcpy (key, k);
  };
  /*!
   *\brief Konstruktor paramteryczny struktury ANode.
   *\param[in] s - referencja do pary klucz-wartosc.
   */
  ANode (const ANode &s):next (nullptr)
  {
    if (s.key == nullptr)
      key = nullptr;
    else
      {
	key = new char[strlen (s.key) + 1];
	strcpy (key, s.key);
      }

    val=s.val;
  };
  /*!
   *\brief Destruktor struktury node.
   */
  ~ANode ()
  {
    delete[]key;
  }

private:

  /*!
   *\brief Przeladowanie operatora przypisania.
   *Zabezpieczenie przed automatycznym operatorem przypisania.
   */
  ANode & operator= (const ANode &);
};

/*!
 *\brief Klasa Asocjacyjna.
 *Obiekt tego typu reprezentuje strukture danych typu lista
 *asocjacyjna wraz z operacjami mozliwymi do wykonania na
 *tej strukturze.
 */
class Asocjacyjna {

  /*!
   *\brief Wskaznik na pierwsza pare klucz-wartosc.
   */ 
  ANode *head;

protected:
  /*!
   *\brief Metoda usuwania zawartosci listy.
   */
  void clear ();
  /*!
   *\brief Metoda wyszukiwania elementu o podanym kluczu.
   *\param[in] key - wskaznik na wyszukiwany klucz.
   *\return wskaznik na szukana pare klucz-wartosc, nullprt gdy nie znalezniono klucza.
   */
  ANode *find (const char *key) const;
  /*!
   *\brief Metoda wstawiania nowej pary klucz-wartosc.
   *\param[in] key - wskaznik na klucz.
   *\param[in] value - wartosc klucza.
   */
  void insert (const char *key, int value);
  /*!
   *\brief Metoda zamiany dwoch list.
   *\param[in] l - referencja do listy.
   */
  void swap (Asocjacyjna &l);

public:

  /*!
   *\brief Konstruktor bezparametryczny obiektu Asocjacyjna.
   */
  Asocjacyjna ();
  /*!
   *\brief Konstruktor paramteryczny obiektu Asocjacyjna.
   *\param[in] l - referencja do listy.
   */
  Asocjacyjna (const Asocjacyjna &l);
  /*!
   *\brief Przeladowanie operatora przypisania.
   *Sluzy do wstawiania do klasy elementow innego obiektu
   *tego samego typu.
   *\param[in] l - referencja do listy.
   */
  Asocjacyjna & operator= (const Asocjacyjna &l);
  /*!
   *\brief Destruktor obiektu Komorka.
   */
  ~Asocjacyjna ();
  /*!
   *\brief Przeladowanie operatora nawiasu kwadratowego.
   *Sluzy do wpisywania klucza oraz wartosci.
   *\param[in] key - wskaznik na klucz.
   *\return wartosc klucza.
   */
  int &operator[] (const char *key);

  /*!
   *\brief Przeladowanie operatora przesuniecia bitowego.
   *Sluzy do wypisywania zawartosci listy na strumien wyjsciowy.
   *\param[in] stream - referencja do strumienia wyjsciowego.
   *\param[in] l - referencja do listy.
   *\return strumien wyjsciowy.
   */
  friend std::ostream & operator<< (std::ostream &stream, Asocjacyjna &l)
  {
    ANode *c = l.head;
    while (c)
      {
	stream << c->val << " ";
	c = c->next;
      };

    return stream;
  };
};

#endif
