#include <iostream>

#include "kolejka.hh"
#include "benchmark.hh"
#include "algorithm_kolejka.hh"


/* Funkcja wykonujaca algorytm wczytywania elementow do kolejki */
void AlgorithmKolejka::runAlgorithm(int _border){

  for(int i=0; i<_border; ++i)
    kolejka.enqueue(tab[i]);
}
