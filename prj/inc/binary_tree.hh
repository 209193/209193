#ifndef BINARY_TREE_HH
#define BINARY_TREE_HH


struct TNode {
  /*!
   *\brief Wartosc elementu w pojedynczej komorce.
   */ 
  int elem;
  /*!
   *\brief Wskaznik na poprzednia komorke.
   */  
  TNode* top;
  /*!
   *\brief Wskaznik na lewa nastepna komorke.
   */  
  TNode* left;
  /*!
   *\brief Wskaznik na prawa nastepna komorke.
   */  
  TNode* right;
  /*!
   *\brief Konstruktor paramteryczny obiektu Komorka.
   *\param[in] _elem - wartosc przechowywanego elementu.
   */
  TNode(int _elem);
  /*!
   *\brief Destruktor obiektu Komorka.
   */  
  ~TNode() {}
};

struct BinaryTree {
private:
  /*!
   *\brief Wskaznik na korzen drzewa.
   */ 
  TNode* root;

protected:
  /*!
   *\brief Metoda poszukiwania elementu.
   *Metoda sluzy do szukania elementu o danej wartosci.
   *\param[in] _node - wskaznik na komorke
   *\param[in] _elem - dodawany element.
   *\return poszukiwana komorka.
   */
  TNode* look(TNode *_node,int _elem);
  /*!
   *\brief Metoda tworzenia komorki.
   *Metoda sluzy do tworzenia komorki o zadanej wartosci.
   *\param[in] _elem - wartosc tworzonej komorki.
   *\return wskaznik na tworzona komorke.
   */
  TNode* new_node(int _elem);
  /*!
   *\brief Metoda dodawania elementu.
   *Metoda sluzy do dodawania elementu o zadanej wartosci.
   *\param[in] _node - wskaznik na komorke.
   *\param[in] _elem - wartosc.
   */
  void add_elem(TNode *_node, int _elem);
  /*!
   *\brief Metoda sprawdzania struktury drzewa.
   *Metoda sluzy do sprawdzania czy drzewo ma
   *strukture binarnego drzewa poszukiwan.
   *\param[in] _node - wskaznik na startowa komorke.
   */
  void is_BST(TNode *_node);
  /*!
   *\brief Metoda oprozniania drzewa.
   *Metoda sluzy do usuwania wszystkich elementow
   *z drzewa. Wykonuje swoje dzialanie rekurencyjnie.
   *\param[in] _node - wskaznik na startowa komorke.
   */
  void clear(TNode *_node);
  /*!
   *\brief Metoda drukowania drzewa.
   *Metoda sluzy do wypisywania wszystkich elementow
   *z drzewa na std out. Wykonuje swoje dzialanie rekurencyjnie.
   *\param[in] _node - wskaznik na startowa komorke.
   */
  void print_tree(TNode *_node);

public:
  /*!
   *\brief Konstruktor obiektu BinaryTree.
   */
  BinaryTree() {}
  /*!
   *\brief Destruktor obiektu BinaryTree.
   */
  ~BinaryTree() {}
  /*!
   *\brief Metoda poszukiwania elementu.
   *Metoda sluzy do szukania elementu o danej wartosci.
   *\param[in] _elem - dodawany element.
   *\return poszukiwana komorka.
   */
  TNode* look(int _elem);
  /*!
   *\brief Metoda poszukiwania najmniejszego elementu.
   *Metoda sluzy do poszukiwania najmniejszego elementu drzewa
   *przez poszukiwanie lewego konca drzewa.
   *\return poszukiwana komorka.
   */
  TNode* min_elem();
  /*!
   *\brief Metoda poszukiwania najwiekszego elementu.
   *Metoda sluzy do poszukiwania najwiekszego elementu drzewa
   *przez poszukiwanie prawego konca drzewa.
   *\return poszukiwana komorka.
   */
  TNode* max_elem();
  /*!
   *\brief Metoda dodawania elementu.
   *Metoda sluzy do dodawania elementu o zadanej wartosci.
   *\param[in] _elem - wartosc elementu.
   */
  void add_elem(int _elem);
  /*!
   *\brief Metoda sprawdzania struktury drzewa.
   *Metoda sluzy do sprawdzania czy drzewo ma
   *strukture binarnego drzewa poszukiwan.
   */
  void is_BST();
  /*!
   *\brief Metoda oprozniania drzewa.
   *Metoda sluzy do usuwania wszystkich elementow
   *z drzewa. Wykonuje swoje dzialanie rekurencyjnie.
   */
  void clear();
  /*!
   *\brief Metoda drukowania drzewa.
   *Metoda sluzy do wypisywania wszystkich elementow
   *z drzewa na std out. Wykonuje swoje dzialanie rekurencyjnie.
   */
  void print_tree();


};
#endif
