CPPFLAGS= -std=gnu++11 -c -g -Iinc -Wall -pedantic
__start__: program
	./program < generate/danesort.txt

program: obj/main.o obj/benchmark.o obj/stos.o obj/kolejka.o obj/lista.o obj/tab_lista.o obj/asocjacyjna.o obj/mieszajaca.o obj/algorithm1.o obj/algorithm2.o obj/algorithm3.o obj/algorithm4.o
	g++ -Wall -pedantic -o program obj/main.o obj/benchmark.o obj/stos.o obj/kolejka.o obj/lista.o obj/tab_lista.o obj/asocjacyjna.o obj/mieszajaca.o obj/algorithm1.o obj/algorithm2.o obj/algorithm3.o obj/algorithm4.o

obj/main.o: src/main.cpp inc/benchmark.hh inc/stos.hh inc/kolejka.hh inc/lista.hh inc/tab_lista.hh inc/asocjacyjna.hh inc/mieszajaca.hh inc/algorithm1.hh inc/algorithm2.hh inc/algorithm3.hh inc/algorithm4.hh
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/algorithm4.o: src/algorithm4.cpp inc/algorithm4.hh
	g++ ${CPPFLAGS} -o obj/algorithm4.o src/algorithm4.cpp

obj/algorithm3.o: src/algorithm3.cpp inc/algorithm3.hh
	g++ ${CPPFLAGS} -o obj/algorithm3.o src/algorithm3.cpp

obj/algorithm2.o: src/algorithm2.cpp inc/algorithm2.hh
	g++ ${CPPFLAGS} -o obj/algorithm2.o src/algorithm2.cpp

obj/algorithm1.o: src/algorithm1.cpp inc/algorithm1.hh
	g++ ${CPPFLAGS} -o obj/algorithm1.o src/algorithm1.cpp

obj/mieszajaca.o: src/mieszajaca.cpp inc/mieszajaca.hh
	g++ ${CPPFLAGS} -o obj/mieszajaca.o src/mieszajaca.cpp

obj/asocjacyjna.o: src/asocjacyjna.cpp inc/asocjacyjna.hh
	g++ ${CPPFLAGS} -o obj/asocjacyjna.o src/asocjacyjna.cpp

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
	rm -f generate/*.o generate/generate obj/*.o ./ret_*.txt program
