#ifndef STOS_HH
#define STOS_HH

/*!
 *\brief Klasa Stos modelujaca strukture danych typu stos.
 *Obiekt tego typu reprezentuje strukture danych typu stos
 *wraz z operacjami mozliwymi do wykonania na tej strukturze.
 */
class Stos {

  /*!
   *\brief Wskaznik na tablice elementow stosu.
   */ 
  int *tab;
  /*!
   *\brief Rozmiar stosu.
   */ 
  long size;
  /*!
   *\brief Indeks ostatniego wolnego pola.
   */ 
  long last;

  /*!
   *\brief Metoda powiekszania stosu.
   *Metoda ta dodaje do stosu 8 kolejnych wolnych pol.
   */
  void increase();

  /*!
   *\brief Metoda pomniejszania stosu.
   *Metoda ta odejmuje od stosu jedno pole.
   */
  int decrease();

public:

  /*!
   *\brief Konstruktor obiektu Stos.
   */
  Stos();

  /*!
   *\brief Konstruktor parametryczny obiektu Stos.
   *\param[in] _size - rozmiar tworzonego stosu.
   */
  Stos(long _size);

  /*!
   *\brief Destruktor obiektu Stos.
   */
  ~Stos();

  /*!
   *\brief Metoda dodawnia elementu.
   *Metoda sluzy do dodawania elementu do stosu.
   *\param[in] _elem - dodawany element.
   */
  void push(int _elem);

  /*!
   *\brief Metoda usuwania elementu.
   *Metoda sluzy do usuwania elementu ze stosu.
   *\return - usuwany element.
   */
  int pop();

  /*!
   *\brief Sortowanie przez scalanie.
   *\param[in] poczatek - poczatek tablicy.
   *\param[in] koniec - koniec tablicy.
   */
  void mergesort(int poczatek, int koniec);
};

#endif
