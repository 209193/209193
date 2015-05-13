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
   *Tworzy liste tablicowa o domyslnym rozmiarze rownym 8.
   */
  TabLista();
 /*!
   *\brief Konstruktor parametryczny struktury TabLista.
   *Tworzy liste tablicowa o zadanym rozmiarze rownym _size.
   *\param[in] _size - startowy rozmiar struktury.
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
