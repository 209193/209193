#ifndef WRITING_OBSERVER_HH
#define WRITING_OBSERVER_HH

#include <fstream>

/*!
 *\brief Klasa WritingObserver modelujaca zapisujacego obserwatora.
 *Obiekt tego typu reprezentuje obserwatora zapisujacego czas
 *i ilosc elementow dla ktorych dany algorytm sie wykonal.
 *Dziedziczy po klasie Observer.
 */
class WritingObserver: public Observer {
protected:
  /*!
   *\brief Wskaznik na obserwowany algorytm.
   */
  Benchmark *benchmark;
  /*!
   *\brief Plik wyjsciowy.
   */
  std::ofstream ret_data;

public:
  /*!
   *\brief Konstruktor parametryczny obiektu WritingObserver.
   *Sluzy do dodawania obiektu obserwowanego.
   *Nadaje indeks tworzonemu obiektowi WritingObserver
   *oraz otwiera plik z benchmarkiem do zapisu.
   *\param[in] _benchmark - obserwowany benchmark.
   *\param[in] _id - identyfikator obserwatora.
   *\param[in] _string - nazwa pliku do zapisu.
   */
  WritingObserver(Benchmark *_benchmark, int _id, std::string _string);
  /*!
   *\brief Destruktor obiektu WritingObserver.
   *Zamyka plik z benchmarkiem.
   */
  ~WritingObserver();
  /*!
   *\brief Metoda aktualizujaca stan obserwatora.
   *Sluzy do dodawania kolejnych linijek z dana iloscia elementow
   *oraz czasem pobranym z obiektu obserwowanego.
   */
  void update();
};
#endif
