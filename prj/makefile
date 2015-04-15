CPPFLAGS= -std=gnu++11 -c -g -Iinc -Wall -pedantic
__start__: program
	$(MAKE) -C generate
	./program < generate/data.txt

program: obj/main.o obj/benchmark.o obj/stos.o obj/kolejka.o obj/lista.o obj/tab_lista.o obj/algorithm_stos.o obj/algorithm_kolejka.o obj/algorithm_lista.o obj/algorithm2.o obj/asocjacyjna.o obj/mieszajaca.o
	g++ -Wall -pedantic -o program obj/main.o obj/benchmark.o obj/stos.o obj/kolejka.o obj/lista.o obj/tab_lista.o obj/algorithm_stos.o obj/algorithm_kolejka.o obj/algorithm_lista.o obj/algorithm2.o obj/asocjacyjna.o obj/mieszajaca.o

obj/main.o: src/main.cpp inc/benchmark.hh inc/stos.hh inc/kolejka.hh inc/lista.hh inc/tab_lista.hh inc/algorithm_stos.hh inc/algorithm_kolejka.hh inc/algorithm_lista.hh inc/algorithm2.hh inc/asocjacyjna.hh inc/mieszajaca.hh
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/mieszajaca.o: src/mieszajaca.cpp inc/mieszajaca.hh
	g++ ${CPPFLAGS} -o obj/mieszajaca.o src/mieszajaca.cpp

obj/asocjacyjna.o: src/asocjacyjna.cpp inc/asocjacyjna.hh
	g++ ${CPPFLAGS} -o obj/asocjacyjna.o src/asocjacyjna.cpp

obj/algorithm2.o: src/algorithm2.cpp inc/algorithm2.hh
	g++ ${CPPFLAGS} -o obj/algorithm2.o src/algorithm2.cpp

obj/algorithm_lista.o: src/algorithm_lista.cpp inc/algorithm_lista.hh
	g++ ${CPPFLAGS} -o obj/algorithm_lista.o src/algorithm_lista.cpp

obj/algorithm_kolejka.o: src/algorithm_kolejka.cpp inc/algorithm_kolejka.hh
	g++ ${CPPFLAGS} -o obj/algorithm_kolejka.o src/algorithm_kolejka.cpp

obj/algorithm_stos.o: src/algorithm_stos.cpp inc/algorithm_stos.hh
	g++ ${CPPFLAGS} -o obj/algorithm_stos.o src/algorithm_stos.cpp

obj/tab_lista.o: src/tab_lista.cpp inc/tab_lista.hh
	g++ ${CPPFLAGS} -o obj/tab_lista.o src/tab_lista.cpp

obj/lista.o: src/lista.cpp inc/lista.hh
	g++ ${CPPFLAGS} -o obj/lista.o src/lista.cpp

obj/kolejka.o: src/kolejka.cpp inc/kolejka.hh
	g++ ${CPPFLAGS} -o obj/kolejka.o src/kolejka.cpp

obj/stos.o: src/stos.cpp inc/stos.hh
	g++ ${CPPFLAGS} -o obj/stos.o src/stos.cpp

obj/benchmark.o: src/benchmark.cpp inc/benchmark.hh
	g++ ${CPPFLAGS} -o obj/benchmark.o src/benchmark.cpp

clean:
	rm -f generate/data.txt generate/*.o generate/generate obj/*.o ./ret_*.txt program
