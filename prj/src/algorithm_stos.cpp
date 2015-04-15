#include <iostream>

#include "stos.hh"
#include "benchmark.hh"
#include "algorithm_stos.hh"


/* Funkcja wykonujaca algorytm wczytywania elementow do stosu */
void AlgorithmStos::runAlgorithm(int _border){

  for(int i=0; i<_border; ++i)
    stos.push(tab[i]);
}
