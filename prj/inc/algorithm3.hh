#ifndef ALGORITHM3_HH
#define ALGORITHM3_HH

/*!
 *\brief Klasa Algorithm3 modelujaca algorytm sortowania stosu.
 *Obiekt tego typu reprezentuje algorytm wykonujacy
 *sortowanie szybkie na elementach stosu.
 *Dziedziczy po klasie Benchmark.
 */
class Algorithm3: public Benchmark {
  /*!
   *\brief Zmienna przechowujaca drzewo czerwono-czarne.
   */ 
  RBTree tree;

public:
  /*!
   *\brief Konstruktor obiektu Algorithm3.
   */
  Algorithm3() {}
  /*!
   *\brief Konstruktor parametryczny obiektu Algorithm3.
   *\param[in] _tab - tablica przechowujaca dane wejsciowe.
   *\param[in] _id - identyfikator algorytmu.
   */
  Algorithm3(unsigned short *_tab, int _id);
  /*!
   *\brief Destruktor obiektu Algorithm3.
   */
  ~Algorithm3();

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
