#ifndef SORT_HH
#define SORT_HH

/*!
 *\brief Klasa Sort modelujaca algorytmy sortowania.
 *Obiekt tego typu zawiera jedynie algorytmy sortujace.
 *Moze dzialac na dowolnych potomkach klasy Tablicowe.
 */
class Sort {
  /*!
   *\brief Metoda przywracajaca porzadek kopca.
   *\param[in] _struct - wskaznik na strukture.
   *\param[in] _i - indeks elementu kopca.
   *\param[in] _max - indeks ostatniego elementu kopca.
   */
  void heapify(Tablicowe *_struct, int _i, int _max);
  /*!
   *\brief Tworzenie struktury kopca z nieuporzadkowanej tablicy.
   *\param[in] _struct - wskaznik na strukture.
   */
  void build_heap(Tablicowe *_struct);
public:
  /*!
   *\brief Sortowanie szybkie.
   *\param[in] _struct - wskaznik na strukture.
   *\param[in] _poczatek - poczatek tablicy.
   *\param[in] _koniec - koniec tablicy.
   */
  void quicksort(Tablicowe *_struct, int _poczatek, int _koniec);
  /*!
   *\brief Sortowanie szybkie po optymalizacji.
   *\param[in] _struct - wskaznik na strukture.
   *\param[in] _poczatek - poczatek tablicy.
   *\param[in] _koniec - koniec tablicy.
   */
  void optquicksort(Tablicowe *_struct, int _poczatek, int _koniec);
  /*!
   *\brief Sortowanie przez scalanie.
   *\param[in] _struct - wskaznik na strukture.
   *\param[in] _poczatek - poczatek tablicy.
   *\param[in] _koniec - koniec tablicy.
   */
  void mergesort(Tablicowe *_struct, int _poczatek, int _koniec);
  /*!
   *\brief Sortowanie przez kopcowanie.
   *\param[in] _struct - wskaznik na strukture.
   *\param[in] _koniec - koniec tablicy.
   */
  void heapsort(Tablicowe *_struct, int _koniec);
};
#endif
