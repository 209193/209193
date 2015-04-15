#include <iostream>

#include "lista.hh"
#include "benchmark.hh"
#include "algorithm_lista.hh"


/* Funkcja wykonujaca algorytm wczytywania elementow do listy */
void AlgorithmLista::runAlgorithm(int _border){

  for(int i=0; i<_border; ++i)
    lista.insert(tab[i]);
}
