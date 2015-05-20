CPPFLAGS= -std=gnu++11 -c -g -Iinc -Wall -pedantic
__start__: program
	$(MAKE) -C generate
	./program < generate/data.txt

program: obj/main.o\
		obj/observer.o\
		obj/subject.o\
		obj/benchmark.o\
		obj/writing_observer.o\
		obj/tablicowe.o\
		obj/sort.o\
		obj/stos.o\
		obj/kolejka.o\
		obj/lista.o\
		obj/tab_lista.o\
		obj/asocjacyjna.o\
		obj/mieszajaca.o\
		obj/binary_tree.o\
		obj/rb_tree.o\
		obj/algorithm1.o\
		obj/algorithm2.o\
		obj/algorithm3.o\
		obj/algorithm4.o
	g++ -Wall -pedantic -o program\
		obj/main.o\
		obj/observer.o\
		obj/subject.o\
		obj/benchmark.o\
		obj/writing_observer.o\
		obj/tablicowe.o\
		obj/sort.o\
		obj/stos.o\
		obj/kolejka.o\
		obj/lista.o\
		obj/tab_lista.o\
		obj/asocjacyjna.o\
		obj/mieszajaca.o\
		obj/binary_tree.o\
		obj/rb_tree.o\
		obj/algorithm1.o\
		obj/algorithm2.o\
		obj/algorithm3.o\
		obj/algorithm4.o

obj/main.o: src/main.cpp\
		inc/observer.hh\
		inc/subject.hh\
		inc/benchmark.hh\
		inc/writing_observer.hh\
		inc/tablicowe.hh\
		inc/sort.hh\
		inc/stos.hh\
		inc/kolejka.hh\
		inc/lista.hh\
		inc/tab_lista.hh\
		inc/asocjacyjna.hh\
		inc/mieszajaca.hh\
		inc/binary_tree.hh\
		inc/rb_tree.hh\
		inc/algorithm1.hh\
		inc/algorithm2.hh\
		inc/algorithm3.hh\
		inc/algorithm4.hh
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/algorithm4.o: src/algorithm4.cpp inc/algorithm4.hh
	g++ ${CPPFLAGS} -o obj/algorithm4.o src/algorithm4.cpp

obj/algorithm3.o: src/algorithm3.cpp inc/algorithm3.hh
	g++ ${CPPFLAGS} -o obj/algorithm3.o src/algorithm3.cpp

obj/algorithm2.o: src/algorithm2.cpp inc/algorithm2.hh
	g++ ${CPPFLAGS} -o obj/algorithm2.o src/algorithm2.cpp

obj/algorithm1.o: src/algorithm1.cpp inc/algorithm1.hh
	g++ ${CPPFLAGS} -o obj/algorithm1.o src/algorithm1.cpp

obj/rb_tree.o: src/rb_tree.cpp inc/rb_tree.hh
	g++ ${CPPFLAGS} -o obj/rb_tree.o src/rb_tree.cpp

obj/binary_tree.o: src/binary_tree.cpp inc/binary_tree.hh
	g++ ${CPPFLAGS} -o obj/binary_tree.o src/binary_tree.cpp

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

obj/sort.o: src/sort.cpp inc/sort.hh
	g++ ${CPPFLAGS} -o obj/sort.o src/sort.cpp

obj/tablicowe.o: src/tablicowe.cpp inc/tablicowe.hh
	g++ ${CPPFLAGS} -o obj/tablicowe.o src/tablicowe.cpp

obj/writing_observer.o: src/writing_observer.cpp inc/writing_observer.hh
	g++ ${CPPFLAGS} -o obj/writing_observer.o src/writing_observer.cpp

obj/benchmark.o: src/benchmark.cpp inc/benchmark.hh
	g++ ${CPPFLAGS} -o obj/benchmark.o src/benchmark.cpp

obj/subject.o: src/subject.cpp inc/subject.hh
	g++ ${CPPFLAGS} -o obj/subject.o src/subject.cpp

obj/observer.o: src/observer.cpp inc/observer.hh
	g++ ${CPPFLAGS} -o obj/observer.o src/observer.cpp

clean:
	rm -f generate/*.o generate/generate obj/*.o ./ret_*.txt program
