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

  std::ofstream ret_data(nazwy[_n]);
  if (ret_data.is_open()){
    ret_data << "elem\ttime" << std::endl;//zapisujemy naglowek pliku
    for(int i=1; i<=LENGTH; ++i ){
      for(int k=1; k<=REPEATS; ++k){

	_algorithm -> load(j);

	std::chrono::high_resolution_clock::time_point start_time = std::chrono::high_resolution_clock::now();
  
	_algorithm -> runAlgorithm(j);
  
	std::chrono::high_resolution_clock::time_point end_time = std::chrono::high_resolution_clock::now();

	_algorithm -> unload(j);

	std::chrono::high_resolution_clock::duration time_period = end_time - start_time;

	//std::cout << "Czas: " << std::chrono::duration_cast<std::chrono::microseconds>(time_period).count() << "mikrosek" << std::endl;
	average += std::chrono::duration_cast<std::chrono::microseconds>(time_period).count();//dodajemy czas dzialania algorytmu
      }
      average /= REPEATS;//suma czasow dzielona przez powtorzenia

      ret_data << j << "\t" << average << std::endl;//zapisujemy do pliku j - ilosc elementow, average - sredni czas dzialania

      j*=10;//ilosc wczytywanych elementow
      average=0;//zerowanie sredniej
    }
    ret_data.close();
  }
  else std::cerr << "Unable to open ret_data file" << std::endl;
}
