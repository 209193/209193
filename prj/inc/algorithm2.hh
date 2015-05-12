#ifndef ALGORITHM2_HH
#define ALGORITHM2_HH

/*!
 *\brief Klasa Algorithm2 modelujaca algorytm sortowania stosu.
 *Obiekt tego typu reprezentuje algorytm wykonujacy
 *sortowanie szybkie na elementach stosu.
 *Dziedziczy po klasie Benchmark.
 */
class Algorithm2: public Benchmark {
  /*!
   *\brief Zmienna przechowujaca stos.
   */ 
  Stos stos;

public:
  /*!
   *\brief Konstruktor obiektu Algorithm2.
   */
  Algorithm2() {}
  /*!
   *\brief Konstruktor parametryczny obiektu Algorithm2.
   *\param[in] _tab - tablica przechowujaca dane wejsciowe.
   */
  Algorithm2(unsigned short *_tab): Benchmark(_tab) {}
  /*!
   *\brief Destruktor obiektu Algorithm2.
   */
  ~Algorithm2() {}

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
