#ifndef BENCHMARK_HH
#define BENCHMARK_HH

#define SIZE 100000

/*!
 *\brief Klasa Benchmark modelujaca program benchmarkujacy.
 *Obiekt tego typu reprezentuje program sprawdzajacy szybkosc
 *wykonywania algorytmow.
 *Dziedziczy po klasie Subject.
 */
class Benchmark: public Subject {
  /*!
   *\brief Czas dzialania.
   */
  unsigned int time;
  /*!
   *\brief Ilosc elementow.
   */
  unsigned int size;
  /*!
   *\brief Zakres ilosci elementow.
   */
  unsigned short length;
  /*!
   *\brief Ilosc powtorzen algorytmu dla danej ilosc elementow.
   */
  unsigned short repeats;

protected:
  /*!
   *\brief Wskaznik na tablice elementow z danymi wejsciowymi.
   */ 
  unsigned short *tab;

public:
  /*!
   *\brief Konstrukor obiektu Benchmark.
   */
  Benchmark() {}
  /*!
   *\brief Konstrukor parametryczny obiektu Benchmark.
   *Kopiuje wskazink na wczytana tablice elementow.
   *\param[in] _tab - tablica elementow.
   *\param[in] _id - identyfikator benchmarku.
   */
  Benchmark(unsigned short *_tab, int _id): Subject(_id), tab(_tab) {}
  /*!
   *\brief Destruktor obiektu Benchmark.
   */
  ~Benchmark() {}
  /*!
   *\brief Metoda testowania algorytmu.
   *Metoda sluzy to testowania szybkosci dzialania algorytmu.
   *Wykonuje testowany algorytm dla danych kolejnych ilosci elementow.
   *Wykonanie algorytmu dla danego zestawu liczb powtarza dana razy
   *i usrednia wynik.
   *Powiadamia obserwatorow o kazdej zmianie.
   *\param[in] _algorithm - testowany algorytm.
   */
  void testAlgorithm(Benchmark *_algorithm);
  /*!
   *\brief Metoda przygotowywania algorytmu.
   *Metoda sluzy do przygotowania warunkow do przeprowadzenia testu.
   *W klasie Benchmark nie ma konkretnego dzialania.
   *\param[in] _border - ilosc elementow dla ktorych algorytm ma wykonac swoje dzialanie.
   */
  virtual void load(int _border) = 0;
  /*!
   *\brief Metoda sprzatania.
   *Metoda sluzy do oproznienia struktury.
   *W klasie Benchmark nie ma konkretnego dzialania.
   *\param[in] _border - ilosc elementow dla ktorych algorytm ma wykonac swoje dzialanie.
   */
  virtual void unload(int _border) = 0;
  /*!
   *\brief Metoda uruchamiania algorytmu.
   *Metoda sluzy do wykonywania danego algorytmu.
   *W klasie Benchmark nie ma konkretnego dzialania.
   *\param[in] _border - ilosc elementow dla ktorych algorytm ma wykonac swoje dzialanie.
   */
  virtual void runAlgorithm(int _border) = 0;
  /*!
   *\brief Metoda uruchamiania algorytmu.
   *Metoda sluzy do zwracania czasu podczas ktorego algorytm wykonal swoje dzialanie.
   *\return czas.
   */
  int getTime() {return time;}
  /*!
   *\brief Metoda zwracania ilosci elementow.
   *Metoda sluzy do zwracania ilosci elementow dla ktorych algorytm wykonal dzialanie.
   *\return ilosc elementow.
   */
  int getSize() {return size;}
};

#endif
