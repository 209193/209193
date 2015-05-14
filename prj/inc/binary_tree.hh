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

  bool operator== (TNode *_node);

  bool operator== (int _elem);

  bool operator> (TNode *_node);

  bool operator> (int _elem);

  bool operator< (TNode *_node);

  bool operator< (int _elem);
};

struct BinaryTree {
private:
  /*!
   *\brief Wskaznik na korzen drzewa.
   */ 
  TNode* root;

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
   *\brief Metoda dodawnia elementu.
   *Metoda sluzy do dodawania elementu o danej wartosci.
   *\param[in] _elem - dodawany element.
   */
  void add(int _elem);
  /*!
   *\brief Metoda usuwania elementu.
   *Metoda sluzy do usuwania elementu o danej wartosci.
   *\param[in] _elem - wartosc szukanego elementu.
   *\return usuwany element
   */
  int getvar(int _elem);
};
#endif
