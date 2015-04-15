#ifndef LISTA_HH
#define LISTA_HH

/*!
 *\brief Klasa Lista modelujaca strukture danych typu lista.
 *Obiekt tego typu reprezentuje strukture danych typu lista
 *wraz z operacjami mozliwymi do wykonania na tej strukturze.
 */
class Lista {

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
    Komorka(int _elem) {
      elem = _elem;
      next = nullptr;
    }
    ~Komorka() {};
  };

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
  Lista() {};

  /*!
   *\brief Destruktor obiektu Lista.
   */
  ~Lista() {};

  /*!
   *\brief Metoda dodawnia elementu.
   *Metoda sluzy do dodawania elementu do konca listy.
   *\param[in] _elem - dodawany element.
   */
  void insert(int _elem);

  /*!
   *\brief Metoda usuwania elementu.
   *Metoda sluzy do usuwania elementu o wskazanym indeksie.
   *\param[in] _f - indeks elementu do usuniecia.
   *\return - usuwany element.
   */
  int remove(int _f);
};

#endif
