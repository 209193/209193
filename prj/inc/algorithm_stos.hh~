#ifndef ALGORITHMSTOS_HH
#define ALGORITHMSTOS_HH

/*!
 *\brief Klasa AlgorithmStos modelujaca algorytm wczytywania do stosu.
 *Obiekt tego typu reprezentuje algorytm wykonujacy wykonujacy
 *wczytywanie zadanej ilosci elementow do stosu.
 */
class AlgorithmStos: public Benchmark {

  /*!
   *\brief Tablica elementow z danymi wejsciowymi.
   */ 
  int tab[SIZE];
  /*!
   *\brief Zmienna przechowujaca stos.
   */ 
  Stos stos;

public:
  /*!
   *\brief Konstruktor obiektu AlgorithmStos.
   */
  AlgorithmStos() {};

  /*!
   *\brief Konstruktor parametryczny obiektu AlgorithmStos.
   *\param[in] _tab - tablica przechowujaca dane wejsciowe.
   */
  AlgorithmStos(int _tab[]) {for(int i=0; i<SIZE; ++i) tab[i]=_tab[i];};
  
  /*!
   *\brief Destruktor obiektu AlgorithmStos.
   */
  ~AlgorithmStos() {};

  /*!
   *\brief Metoda testowania algorytmu.
   *Metoda sluzy do testowania szybkosci dzialania algorytmu.
   *W klasie AlgorithmStos nie ma konkretnego dzialania.
   *\param[in] _algorithm - testowany algorytm.
   */
  virtual void testAlgorithm(Benchmark *_algorithm) {};

  /*!
   *\brief Metoda uruchamiania algorytmu.
   *Metoda sluzy to wykonywania danego algorytmu.
   *Wczytuje elementy do stosu.
   *\param[in] _border - ilosc elementow dla ktorych algorytm ma wykonac swoje dzialanie.
   */
  virtual void runAlgorithm(int _border);
};

#endif
