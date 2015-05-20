#include <iostream>

#include "binary_tree.hh"


//TNODE
TNode::TNode(int _elem) {
  elem = _elem;
  top = nullptr;
  left = nullptr;
  right = nullptr;
}

//BINARY TREE
TNode* BinaryTree::look(TNode *_node, int _elem) {
  if (_node == nullptr) return nullptr;

  if (_node -> elem == _elem) return _node;
  else {
    if (_node -> elem < _elem)
      return look(_node -> right, _elem);
    else return look(_node -> left, _elem);
  }
}

TNode* BinaryTree::look(int _elem) {
  TNode *node = root;
  if (node == nullptr) return nullptr;
  
  if (node -> elem == _elem) return node;
  else {
    if (node -> elem < _elem)
      return look(node -> right, _elem);
    else return look(node -> left, _elem);
  }
}

TNode* BinaryTree::min_elem() {
  TNode *node = root;

  if (node == nullptr) return nullptr;
  while (node -> left) node = node -> left;
  return node;
}

TNode* BinaryTree::max_elem() {
  TNode *node = root;

  if (node == nullptr) return nullptr;
  while (node -> right) node = node -> right;
  return node;
}

TNode* BinaryTree::new_node(int _elem) {
  TNode *node = new TNode(_elem);
  
  return node;
}

void BinaryTree::add_elem(TNode *_node, int _elem) {
  TNode *temp;

  if (_node == nullptr) _node = new_node(_elem);
  else if (_node -> elem > _elem) {
    if (_node -> left != nullptr) add_elem(_node -> left, _elem);
    else {
      temp = new_node(_elem);
      temp -> top = _node;
      _node -> left = temp;
    }
  }
  else {
    if (_node -> right != nullptr) add_elem(_node -> right, _elem);
    else {
      temp = new_node(_elem);
      temp -> top = _node;
      _node -> right = temp;
    }
  }
}

void BinaryTree::add_elem(int _elem) {
  TNode *temp;

  if (root == nullptr) root = new_node(_elem);
  else if (root -> elem > _elem) {
    if (root -> left != nullptr) add_elem(root, _elem);
    else {
      temp = new_node(_elem);
      temp -> top = root;
      root -> left = temp;
    }
  }
  else {
    if (root -> right != nullptr) add_elem(root, _elem);
    else {
      temp = new_node(_elem);
      temp -> top = root;
      root -> right = temp;
    }
  }
}

void BinaryTree::clear(TNode *_node) {
  if (_node != nullptr) {
    clear(_node -> left);
    clear(_node -> right);
    delete _node;
  }
}

void BinaryTree::clear() {
  TNode *node = root;

  if (node != nullptr) {
    clear(node -> left);
    clear(node -> right);
    delete node;
  }
}

void BinaryTree::print_tree(TNode *_node) {
  if (_node == nullptr) return;
  print_tree(_node -> left);
  //std::cout << _node -> elem << " ";
  print_tree(_node -> right);
}

void BinaryTree::print_tree() {
  TNode *node = root;

  if (node == nullptr) return;
  print_tree(node -> left);
  //std::cout << node -> elem << " ";
  print_tree(node -> right);
}
