#include <iostream>
#include <fstream>
#include <chrono>

#include "benchmark.hh"

#define LENGTH 4//"ile razy pomnozymy przez 10 - patrz linijka 19 i 35"
#define REPEATS 3//ilosc powtorzen dla obliczenia sredniej - patrz linijka 20"


/* Funkcja testowania szybkosci dzialania algorytmu */
void Benchmark::testAlgorithm(Benchmark *_algorithm, int _n) const{

  int j=100;//startowa ilosc elementow
  int average=0;//inicjalizacja zmiennej przechowujacej sredni czas dzialania


  for(int i=1; i<=LENGTH; ++i ){
    for(int k=1; k<=REPEATS; ++k){

      _algorithm -> load(j);

      auto start_time = std::chrono::high_resolution_clock::now();
  
      _algorithm -> runAlgorithm(j);
  
      auto end_time = std::chrono::high_resolution_clock::now();

      _algorithm -> unload(j);

      auto time_period = end_time - start_time;

      average += std::chrono::duration_cast<std::chrono::microseconds>(time_period).count();//dodajemy czas dzialania algorytmu
    }
    average /= REPEATS;//suma czasow dzielona przez powtorzenia

    j*=10;//ilosc wczytywanych elementow
    average=0;//zerowanie sredniej
  }
}
