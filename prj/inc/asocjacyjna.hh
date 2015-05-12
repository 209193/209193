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
   *\param[in] _k - wskaznik na klucz.
   */
  ANode(const char *_k);
  /*!
   *\brief Konstruktor paramteryczny struktury ANode.
   *\param[in] _s - referencja do pary klucz-wartosc.
   */
  ANode(const ANode &_s);
  /*!
   *\brief Destruktor struktury node.
   */
  ~ANode ();

private:
  /*!
   *\brief Przeladowanie operatora przypisania.
   *Zabezpieczenie przed automatycznym operatorem przypisania.
   */
  ANode& operator= (const ANode &);
};

/*!
 *\brief Klasa Asocjacyjna.
 *Obiekt tego typu reprezentuje strukture danych typu lista
 *asocjacyjna wraz z operacjami mozliwymi do wykonania na
 *tej strukturze.
 */
struct Asocjacyjna {
private:
  /*!
   *\brief Wskaznik na pierwsza pare klucz-wartosc.
   */ 
  ANode *head;

protected:
  /*!
   *\brief Metoda usuwania zawartosci listy.
   */
  void clear();
  /*!
   *\brief Metoda wyszukiwania elementu o podanym kluczu.
   *\param[in] _key - wskaznik na wyszukiwany klucz.
   *\return wskaznik na szukana pare klucz-wartosc, nullprt gdy nie znalezniono klucza.
   */
  ANode* find(const char *_key) const;
  /*!
   *\brief Metoda wstawiania nowej pary klucz-wartosc.
   *\param[in] _key - wskaznik na klucz.
   *\param[in] _value - wartosc klucza.
   */
  void insert(const char *_key, int _value);
  /*!
   *\brief Metoda zamiany dwoch list.
   *\param[in] _l - referencja do listy.
   */
  void swap(Asocjacyjna &_l);

public:
  /*!
   *\brief Konstruktor bezparametryczny obiektu Asocjacyjna.
   */
  Asocjacyjna();
  /*!
   *\brief Konstruktor paramteryczny obiektu Asocjacyjna.
   *\param[in] _l - referencja do listy.
   */
  Asocjacyjna(const Asocjacyjna &_l);
  /*!
   *\brief Destruktor obiektu Asocjacyjna.
   */
  ~Asocjacyjna();

  /*!
   *\brief Przeladowanie operatora przypisania.
   *Sluzy do wstawiania do klasy elementow innego obiektu
   *tego samego typu.
   *\param[in] _l - referencja do listy.
   */
  Asocjacyjna& operator= (const Asocjacyjna &_l);
  /*!
   *\brief Przeladowanie operatora nawiasu kwadratowego.
   *Sluzy do wpisywania klucza oraz wartosci.
   *\param[in] _key - wskaznik na klucz.
   *\return wartosc klucza.
   */
  int& operator[] (const char *_key);
  /*!
   *\brief Przeladowanie operatora przesuniecia bitowego.
   *Sluzy do wypisywania zawartosci listy na strumien wyjsciowy.
   *\param[in] _stream - referencja do strumienia wyjsciowego.
   *\param[in] _l - referencja do listy.
   *\return strumien wyjsciowy.
   */
  friend std::ostream& operator<< (std::ostream &_stream, Asocjacyjna &_l);
};

#endif
