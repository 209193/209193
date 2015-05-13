#ifndef OBSERVER_HH
#define OBSERVER_HH

/*!
 *\brief Klasa Observer modelujaca obserwatora.
 *Jest to klasa modelujaca ogolnego obserwatora.
 *Przeznaczona jedynie do dziedziczenia.
 */
class Observer {
protected:
  /*!
   *\brief Identyfikator obserwatora.
   */
  int id;
  /*!
   *\brief Zmienna zliczajaca aktualizacje.
   *Sluzy do przechowywania informacji o
   *wykonanych aktualizacjach obserwatora.
   */
  unsigned int state_id = 0;
public:
  /*!
   *\brief Metoda identyfikacji obserwatora.
   *Sluzy do informowania o identyfikatorze obserwatora.
   *\return identyfikator obserwatora.
   */
  int tell_id();
  /*!
   *\brief Metoda aktualizujaca stan obserwatora.
   *W klasie Observer nie ma konkretnego dzialania.
   */
  virtual void update() = 0;
  };
#endif
