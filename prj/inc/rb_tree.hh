#ifndef REDBLACK_TREE_HH
#define REDBLACK_TREE_HH


struct RBNode {
  /*!
   *\brief Wartosc elementu w pojedynczej komorce.
   */ 
  int elem;
  /*!
   *\brief Wskaznik na poprzednia komorke.
   */  
  RBNode* top;
  /*!
   *\brief Wskaznik na lewa nastepna komorke.
   */  
  RBNode* left;
  /*!
   *\brief Wskaznik na prawa nastepna komorke.
   */  
  RBNode* right;
  /*!
   *\brief Kolor komorki.
   */  
  int colour;
  /*!
   *\brief Konstruktor paramteryczny obiektu RBNode.
   *\param[in] _elem - wartosc przechowywanego elementu.
   *\param[in] _node - wskaznik na top.
   */
  RBNode(int _elem, RBNode *_node);
  /*!
   *\brief Destruktor obiektu RBNode.
   */  
  ~RBNode() {}
};

class RBTree {
  /*!
   *\brief Wskaznik na korzen drzewa.
   */ 
  RBNode *root;
  /*!
   *\brief Metoda drukowania drzewa.
   *Metoda sluzy do wypisywania wszystkich elementow
   *z drzewa na std out.
   *\param[in] _node - wskaznik na startowa komorke.
   */
  void print_tree(RBNode *_node);
  /*!
   *\brief Metoda oprozniania drzewa.
   *Metoda sluzy do usuwania wszystkich elementow
   *z drzewa. Wykonuje swoje dzialanie rekurencyjnie.
   *\param[in] _node - wskaznik na startowa komorke.
   */
  void clear(RBNode *_node);
public:
  /*!
   *\brief Konstruktor obiektu RBTree.
   */
  RBTree();
  /*!
   *\brief Destruktor obiektu RBTree.
   */
  ~RBTree();
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
  /*!
   *\brief Metoda rotacji.
   *Metoda sluzy do rotacji w lewo wzgledem komorki _node.
   *\param[in] _node - komorka, wzgledem ktorej wykonywana jest rotacja.
   */
  void rot_left(RBNode *_node);
  /*!
   *\brief Metoda rotacji.
   *Metoda sluzy do rotacji w prawo wzgledem komorki _node.
   *\param[in] _node - komorka, wzgledem ktorej wykonywana jest rotacja.
   */
  void rot_right(RBNode *_node);
  /*!
   *\brief Metoda dodawania elementu.
   *Metoda sluzy do dodawania elementu o zadanej wartosci.
   *\param[in] _elem - wartosc elementu.
   */
  void add_elem(int _elem);
};

#endif
