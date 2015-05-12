#ifndef TABLISTA_HH
#define TABLISTA_HH

/*!
 *\brief Klasa TabLista modelujaca strukture danych typu lista.
 *Obiekt tego typu reprezentuje strukture danych typu lista
 *zaimplementowana na tablicy dynamicznej. Obiekt zawiera
 *rowniez podstowe metody listy.
 *Dziedziczy po klasie Tablicowe.
 */
struct TabLista: public Tablicowe {
protected:
  /*!
   *\brief Metoda powiekszania listy tablicowej.
   *Metoda ta podwaja ilosc pol w liscie tablicowej.
   */
  void increase();

public:
  /*!
   *\brief Konstruktor struktury TabLista.
   */
  TabLista();
 /*!
   *\brief Konstruktor parametryczny struktury TabLista.
   */
  TabLista(long _size);
  /*!
   *\brief Destruktor struktury TabLista.
   */
  ~TabLista();

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
   *\return usuwany element.
   */
  int remove(long _f);
};
#endif
