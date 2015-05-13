#ifndef TABLICOWE_HH
#define TABLICOWE_HH

/*!
 *\brief Klasa Tablicowe modelujaca kontener dla klas pochodnych.
 *Obiekt tego typu stanowi kontener dla struktur pochodnych
 *typu Stos, Kolejka, Tab_Lista.
 *Przeznaczona jedynie do dziedziczenia.
 */
class Tablicowe {
protected:
  /*!
   *\brief Wskaznik na tablice elementow kontenera.
   */ 
  unsigned short *tab;
  /*!
   *\brief Rozmiar kontenera.
   */ 
  long size;
  /*!
   *\brief Wskaznik na ostatni wolny element kontenera.
   */ 
  long last;

public:
  /*!
   *\brief Konstruktor obiektu Tablicowe.
   */
  Tablicowe() {}
  /*!
   *\brief Konstruktor parametryczny obiektu Tablicowe.
   *\param[in] _size - startowy rozmiar struktury;
   */
  Tablicowe(long _size): size(_size) {}
  /*!
   *\brief Destruktor obiektu Tablicowe.
   */
  ~Tablicowe() {}
  /*!
   *\brief Metoda dostepu do tablicy.
   *Metoda ta zwraca wskaznik do tablicy z elementami.
   \return wskaznik do tablicy elementow.
   */
  unsigned short* Tablica();
  /*!
   *\brief Metoda dostepu do rozmiaru tablicy.
   *Metoda ta zwraca wartosc informujaca o rozmiarze tablicy.
   *\return rozmiar tablicy.
   */
  long Rozmiar();
};
#endif
