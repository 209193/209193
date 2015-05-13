#ifndef LISTA_HH
#define LISTA_HH

/*!
 *\brief Struktura Komorka.
 *Obiekt tego typu reprezentuje pojedyncza komorke
 *wraz ze wskaznikiem na nastepna komorke listy.
 */
struct Komorka {
  /*!
   *\brief Wartosc elementu w pojedynczej komorce.
   */ 
  int elem;
  /*!
   *\brief Wskaznik na nastepna komorke listy.
   */  
  Komorka* next;
  /*!
   *\brief Konstruktor paramteryczny obiektu Komorka.
   *\param[in] _elem - wartosc przechowywanego elementu.
   */
  Komorka(int _elem);
  /*!
   *\brief Destruktor obiektu Komorka.
   */  
  ~Komorka() {}
};

/*!
 *\brief Klasa Lista modelujaca strukture danych typu lista.
 *Obiekt tego typu reprezentuje strukture danych typu lista
 *wraz z operacjami mozliwymi do wykonania na tej strukturze.
 */
struct Lista {
private:
  /*!
   *\brief Wskaznik na poczatek listy.
   */ 
  Komorka* head;
  /*!
   *\brief Wskaznik na koniec listy.
   */ 
  Komorka* tail;

public:
  /*!
   *\brief Konstruktor obiektu Lista.
   */
  Lista() {}
  /*!
   *\brief Destruktor obiektu Lista.
   */
  ~Lista() {}
  /*!
   *\brief Metoda dodawnia elementu.
   *Metoda sluzy do dodawania elementu do konca listy.
   *\param[in] _elem - dodawany element.
   */
  void insert_last(int _elem);
  /*!
   *\brief Metoda usuwania elementu.
   *Metoda sluzy do usuwania elementu na poczatku listy.
   *\return usuwany element.
   */
  int remove_front();
};

#endif
