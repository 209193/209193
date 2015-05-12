#ifndef STOS_HH
#define STOS_HH

/*!
 *\brief Klasa Stos modelujaca strukture danych typu stos.
 *Obiekt tego typu reprezentuje strukture danych typu stos
 *wraz z operacjami mozliwymi do wykonania na tej strukturze.
 *Dziedziczy po klasie Tablicowe.
 */
struct Stos: public Tablicowe {
private:
  /*!
   *\brief Metoda powiekszania stosu.
   *Metoda ta podwaja ilosc pol.
   */
  void increase();
  /*!
   *\brief Metoda pomniejszania stosu.
   *Metoda ta odejmuje od stosu jedno pole.
   *\return usuwany element.
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
   *\return usuwany element.
   */
  int pop();
};
#endif
