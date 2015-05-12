#ifndef MIESZAJACA_HH
#define MIESZAJACA_HH

#include <cstring>

/*!
 *\brief Struktura ANode.
 *Obiekt tego typu reprezentuje pojedyncza komorke
 *tablicy mieszajacej;
 */
struct MNode {
  /*!
   *\brief Wskaznik na klucz.
   */ 
  char *key;
  /*!
   *\brief Wartosc klucza.
   */ 
  int val;

  MNode();
  /*!
   *\brief Konstruktor paramteryczny struktury MNode.
   *\param[in] _k - wskaznik na klucz.
   */
  MNode(const char *_k);
  /*!
   *\brief Konstruktor paramteryczny struktury MNode.
   *\param[in] _s - referencja do pary klucz-wartosc.
   */
  MNode(const MNode &_s);
  /*!
   *\brief Destruktor struktury MNode.
   */
  ~MNode ();

private:

  /*!
   *\brief Przeladowanie operatora przypisania.
   *Zabezpieczenie przed automatycznym operatorem przypisania.
   */
  MNode& operator= (const MNode &);
};

/*!
 *\brief Klasa Mieszajaca.
 *Obiekt tego typu reprezentuje pojedyncza strukture danych typu
 *tablica mieszajaca wraz z operacjami mozliwymi do wykonania na
 *tej strukturze.
 */
class Mieszajaca {

  /*!
   *\brief Wskaznik na lewa tablice elementow.
   */ 
  MNode **tab_l;
  /*!
   *\brief Wskaznik na prawa tablice elementow.
   */ 
  MNode **tab_p;
  /*!
   *\brief Rozmiar tablic.
   */ 
  long size;

protected:
  /*!
   *\brief Funkcja haszująca Shift-Add-XOR.
   *\param[in] _key - wskaznik na wyszukiwany klucz.
   *\return indeks.
   */
  unsigned sax_hash(const char *_key) const;
  /*!
   *\brief Funkcja haszująca Fovler/Voll/No.
   *\param[in] _key - wskaznik na wyszukiwany klucz.
   *\return indeks.
   */
  unsigned fnv_hash(const char *_key) const;
  /*!
   *\brief Metoda wyszukiwania elementu o podanym kluczu.
   *\param[in] _key - wskaznik na wyszukiwany klucz.
   *\return wskaznik na szukana pare klucz-wartosc, nullprt gdy nie znalezniono klucza.
   */
  MNode* find (const char *_key) const;
  /*!
   *\brief Metoda wstawiania nowej pary klucz-wartosc.
   *\param[in] _key - wskaznik na klucz.
   *\param[in] _value - wartosc klucza.
   */
  void insert (const char *_key, int _value);

public:
  /*!
   *\brief Konstruktor obiektu Mieszajaca.
   */
  Mieszajaca();
  /*!
   *\brief Konstruktor parametryczny obiektu mieszajaca.
   *\param[in] _size - rozmiar tworzonej tablicy mieszajacej.
   */
  Mieszajaca(long _size);
  /*!
   *\brief Destruktor obiektu Mieszajaca.
   */
  ~Mieszajaca();

  /*!
   *\brief Przeladowanie operatora nawiasu kwadratowego.
   *Sluzy do wpisywania klucza oraz wartosci.
   *\param[in] _key - wskaznik na klucz.
   *\return wartosc klucza.
   */
  int& operator[] (const char *_key);
  /*!
   *\brief Przeladowanie operatora przesuniecia bitowego.
   *Sluzy do wypisywania zawartosci tablicy mieszajacej na strumien wyjsciowy.
   *\param[in] _stream - referencja do strumienia wyjsciowego.
   *\param[in] _l - referencja do tablicy.
   *\return strumien wyjsciowy.
   */
  friend std::ostream& operator<< (std::ostream &_stream, Mieszajaca &_l);
};

#endif
