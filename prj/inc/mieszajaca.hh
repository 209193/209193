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

  MNode()
  {
    key = nullptr;
    val = 0;
  };
  /*!
   *\brief Konstruktor paramteryczny struktury MNode.
   *\param[in] k - wskaznik na klucz.
   */
  MNode(const char *k)
  {
    key = new char[strlen (k) + 1];
    strcpy (key, k);
  };
  /*!
   *\brief Konstruktor paramteryczny struktury MNode.
   *\param[in] s - referencja do pary klucz-wartosc.
   */
  MNode(const MNode &s)
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
  ~MNode ()
  {
    delete[]key;
  }

private:

  /*!
   *\brief Przeladowanie operatora przypisania.
   *Zabezpieczenie przed automatycznym operatorem przypisania.
   */
  MNode & operator= (const MNode &);
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
   *\brief Wskaznik na lewa tablice elementow.
   */ 
  MNode **tab_p;
  /*!
   *\brief Rozmiar tablic.
   */ 
  long size;

protected:
  /*!
   *\brief Funkcja haszująca Shift-Add-XOR.
   *\param[in] key - wskaznik na wyszukiwany klucz.
   *\return indeks.
   */
  unsigned sax_hash(const char *key) const;
  /*!
   *\brief Funkcja haszująca Fovler/Voll/No.
   *\param[in] key - wskaznik na wyszukiwany klucz.
   *\return indeks.
   */
  unsigned fnv_hash(const char *key) const;
  /*!
   *\brief Metoda wyszukiwania elementu o podanym kluczu.
   *\param[in] key - wskaznik na wyszukiwany klucz.
   *\return wskaznik na szukana pare klucz-wartosc, nullprt gdy nie znalezniono klucza.
   */
  MNode *find (const char *key) const;
  /*!
   *\brief Metoda wstawiania nowej pary klucz-wartosc.
   *\param[in] key - wskaznik na klucz.
   *\param[in] value - wartosc klucza.
   */
  void insert (const char *key, int value);

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
   *\param[in] key - wskaznik na klucz.
   *\return wartosc klucza.
   */
  int &operator[] (const char *key);

  /*!
   *\brief Przeladowanie operatora przesuniecia bitowego.
   *Sluzy do wypisywania zawartosci tablicy mieszajacej na strumien wyjsciowy.
   *\param[in] stream - referencja do strumienia wyjsciowego.
   *\param[in] l - referencja do tablicy.
   *\return strumien wyjsciowy.
   */
  friend std::ostream & operator<< (std::ostream &stream, Mieszajaca &l)
  {
    int i;
    for (i=0; i<l.size; ++i)
      if(l.tab_l[i]) stream << l.tab_l[i] -> val << " ";
    for (i=0; i<l.size; ++i)
      if(l.tab_p[i]) stream << l.tab_p[i] -> val << " ";

    return stream;
  };
};

#endif
