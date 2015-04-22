#ifndef ALGORITHM3_HH
#define ALGORITHM3_HH

/*!
 *\brief Klasa Algorithm3 modelujaca algorytm sortowania stosu.
 *Obiekt tego typu reprezentuje algorytm wykonujacy
 *sortowanie szybkie na elementach stosu.
 */
class Algorithm3: public Benchmark {

  /*!
   *\brief Wskaznik na tablice elementow z danymi wejsciowymi.
   */ 
  int *tab;
  /*!
   *\brief Zmienna przechowujaca stos.
   */ 
  Stos stos;

public:
  /*!
   *\brief Konstruktor obiektu Algorithm3.
   */
  Algorithm3() {};

  /*!
   *\brief Konstruktor parametryczny obiektu Algorithm3.
   *\param[in] _tab - tablica przechowujaca dane wejsciowe.
   */
  Algorithm3(int *_tab): tab(_tab) {};
  
  /*!
   *\brief Destruktor obiektu Algorithm3.
   */
  ~Algorithm3() {};

  /*!
   *\brief Metoda testowania algorytmu.
   *Metoda sluzy do testowania szybkosci dzialania algorytmu.
   *W klasie Algorithm3 nie ma konkretnego dzialania.
   *\param[in] _algorithm - testowany algorytm.
   */
  virtual void testAlgorithm(Benchmark *_algorithm) {};

  /*!
   *\brief Metoda przygotowywania algorytmu.
   *Metoda sluzy do przygotowania warunkow do przeprowadzenia testu.
   *\param[in] _border - ilosc elementow dla ktorych metoda ma wykonac swoje dzialanie.
   */
  virtual void load(int _border);

  /*!
   *\brief Metoda sprzatania.
   *Metoda sluzy do oproznienia struktury.
   *\param[in] _border - ilosc elementow dla ktorych metoda ma wykonac swoje dzialanie.
   */
  virtual void unload(int _border);

  /*!
   *\brief Metoda uruchamiania algorytmu.
   *Metoda sluzy do wykonywania danego algorytmu.
   *Sortuje elementy stosu.
   *\param[in] _border - ilosc elementow dla ktorych algorytm ma wykonac swoje dzialanie.
   */
  virtual void runAlgorithm(int _border);
};

#endif
