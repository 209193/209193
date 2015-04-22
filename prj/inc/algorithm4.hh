#ifndef ALGORITHM4_HH
#define ALGORITHM4_HH

/*!
 *\brief Klasa Algorithm4 modelujaca algorytm sortowania stosu.
 *Obiekt tego typu reprezentuje algorytm wykonujacy
 *sortowanie szybkie po optymalizacji na elementach stosu.
 */
class Algorithm4: public Benchmark {

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
   *\brief Konstruktor obiektu Algorithm4.
   */
  Algorithm4() {};

  /*!
   *\brief Konstruktor parametryczny obiektu Algorithm4.
   *\param[in] _tab - tablica przechowujaca dane wejsciowe.
   */
  Algorithm4(int *_tab): tab(_tab) {};
  
  /*!
   *\brief Destruktor obiektu Algorithm4.
   */
  ~Algorithm4() {};

  /*!
   *\brief Metoda testowania algorytmu.
   *Metoda sluzy do testowania szybkosci dzialania algorytmu.
   *W klasie Algorithm4 nie ma konkretnego dzialania.
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
