#ifndef SUBJECT_HH
#define SUBJECT_HH

#include <list>

/*!
 *\brief Klasa Subject modelujaca obserwowanego.
 *Obiekt tego typu reprezentuje obserwowanego. Definiuje podstawowe
 *metody uzywane w klasach dziedziczacych Subject.
 *Przeznaczona jedynie do dziedziczenia.
 */
class Subject {
protected:
  /*!
   *\brief Identyfikator obserwowanego.
   */
  int id;
  /*!
   *\brief Lista obserwatorow.
   */
  std::list<Observer*> observers;

public:
  /*!
   *\brief Konstruktor bezparametryczny.
   */
  Subject() {}
  /*!
   *\brief Konstruktor parametryczny.
   *\param[in] _id - identyfikator obserwowanego.
   */
  Subject(int _id): id(_id) {}
  /*!
   *\brief Destruktor bezparametryczny.
   */
  ~Subject() {}
  /*!
   *\brief Metoda identyfikacji obserwowanego.
   *Sluzy do informowania o identyfikatorze obserwowanego.
   *\return identyfikator obserwowanego.
   */
  int tell_id();
  /*!
   *\brief Metoda dodawania obserwatorow.
   *Sluzy do dodawania obserwatorow do listy obserwatorow.
   *\param[in] _obs - dodawany obserwator.
   */
  void add(Observer *_obs);
  /*!
   *\brief Metoda usuwania obserwatorow.
   *Sluzy do usuwania obserwatorow do listy obserwatorow.
   *\param[in] _obs - usuwany obserwator.
   */
  void remove(Observer *_obs);
  /*!
   *\brief Metoda powiadamiania obserwatorow o zmianie.
   *Sluzy do powiadamiania obserwatorow o zmianie, ktora
   *zaszla w danym obiekcie typu Subject.
   */
  void notify();
};

#endif
