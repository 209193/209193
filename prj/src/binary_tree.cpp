#include <iostream>

#include "binary_tree.hh"


//TNODE
TNode::TNode(int _elem) {
  elem = _elem;
  top = nullptr;
  left = nullptr;
  right = nullptr;
}


bool TNode::operator== (TNode *_node) {
  if (this -> elem == _node -> elem) return true;
  else return false;
}


bool TNode::operator== (int _elem) {
  if (this -> elem == _elem) return true;
  else return false;
}


bool TNode::operator> (TNode *_node) {
  if (this -> elem > _node -> elem) return true;
  else return false;
}


bool TNode::operator> (int _elem) {
  if (this -> elem > _elem) return true;
  else return false;
}


bool TNode::operator< (TNode *_node) {
  if (this -> elem < _node -> elem) return true;
  else return false;
}


bool TNode::operator< (int _elem) {
  if (this -> elem < _elem) return true;
  else return false;
}

//BINARY TREE
void BinaryTree::add(int _elem) {

  if (root != nullptr) {
    TNode *temp = new TNode(_elem);
    temp -> top = root;
    if (temp == nullptr) std::cerr << "Blad alokacji" << std::endl;

    if (temp -> top -> left == nullptr || temp -> top -> right != nullptr) {
      std::cerr << "Seeking place" << std::endl;
      if (*(temp -> top) > temp && temp -> top -> left != nullptr) {
	temp -> top = temp -> top -> left;
	std::cerr << "Went lvl down to the left" << std::endl;
      }
      else if (*(temp -> top) < temp && temp -> top -> right != nullptr) {
	temp -> top = temp -> top -> right;
	std::cerr << "Went lvl down to the right" << std::endl;
      }
      else if (*(temp -> top) > temp) {
	temp -> top -> left = temp;
	std::cerr << "Elem " << _elem << " added to left" << std::endl;
	return;
      }
      else if (*(temp -> top) < temp) {
	temp -> top -> right = temp;
	std::cerr << "Elem " << _elem << " added to right" << std::endl;
	return;
      }
    }
    
    while (temp -> top -> left != nullptr || temp -> top -> right != nullptr) {
      std::cerr << "Seeking place" << std::endl;
      if (*(temp -> top) > temp && temp -> top -> left != nullptr) {
	temp -> top = temp -> top -> left;
	std::cerr << "Went lvl down to the left" << std::endl;
      }
      else if (*(temp -> top) < temp && temp -> top -> right != nullptr) {
	temp -> top = temp -> top -> right;
	std::cerr << "Went lvl down to the right" << std::endl;
      }
      else if (*(temp -> top) > temp) {
	temp -> top -> left = temp;
	std::cerr << "Elem " << _elem << " added to left" << std::endl;
	return;
      }
      else if (*(temp -> top) < temp) {
	temp -> top -> right = temp;
	std::cerr << "Elem " << _elem << " added to right" << std::endl;
	return;
      }
    }
  }
  else {
    root = new TNode(_elem);
    std::cerr << "Node created with elem " << root -> elem << std::endl;
    return;
  }
  
  std::cerr << "Something went wrong with elem " << _elem << std::endl;
}


int BinaryTree::getvar(int _elem) {
  TNode *temp;
  temp = root;

  if (*temp == _elem)
    return temp -> elem;
  
  while (temp -> left != nullptr || temp -> right != nullptr) {
    if (*temp > _elem && temp -> left != nullptr) {
      temp = temp -> left;
      if (*temp == _elem) return temp -> elem;
    }
    else if (*temp < _elem && temp -> right != nullptr) {
      temp = temp -> right;
      if (*temp == _elem) return temp -> elem;
    }
  }

  return -1;
}
