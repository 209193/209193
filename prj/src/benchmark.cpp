#include <chrono>

#include "observer.hh"
#include "subject.hh"
#include "benchmark.hh"

#define LENGTH 1//"ile razy pomnozymy przez 10 - patrz linijka 19 i 35"
#define REPEATS 1//ilosc powtorzen dla obliczenia sredniej - patrz linijka 20"


/* Funkcja testowania szybkosci dzialania algorytmu */
void Benchmark::testAlgorithm(Benchmark *_algorithm) {

  size=100000;//startowa ilosc elementow
  time=0;//sredni czas dzialania
  length = LENGTH;
  repeats = REPEATS;

  for (unsigned short i=1; i<=length; ++i) {
    for (unsigned short k=1; k<=repeats; ++k) {

      _algorithm -> load(size);
      auto start_time = std::chrono::high_resolution_clock::now();
  
      _algorithm -> runAlgorithm(size);
  
      auto end_time = std::chrono::high_resolution_clock::now();
      _algorithm -> unload(size);

      auto time_period = end_time - start_time;
      time += std::chrono::duration_cast<std::chrono::microseconds>(time_period).count();//dodajemy czas dzialania algorytmu
    }

    time /= REPEATS;//suma czasow dzielona przez powtorzenia

    notify();//informujemy obserwatorow o zmianie stanu

    size *= 10;//ilosc wczytywanych elementow
    time = 0;//zerowanie sredniej
  }
}
