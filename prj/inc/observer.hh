#ifndef OBSERVER_HH
#define OBSERVER_HH

/*!
 *\brief Klasa Observer modelujaca obserwatora.
 *Jest to klasa modelujaca ogolnego obserwatora.
 *Przeznaczona jedynie do dziedziczenia.
 */
class Observer {
public:
  /*!
   *\brief Metoda aktualizujaca stan obserwatora.
   *W klasie Observer nie ma konkretnego dzialania.
   */
  virtual void update() = 0;
  };
#endif
