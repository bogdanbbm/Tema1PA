build:
	g++ -o task1 walsh.cpp
	g++ -o task2 statistics.cpp
	g++ -g -o task3 prinel.cpp
	g++ -o task4 crypto.cpp
	g++ -o task5 regele.cpp

run-p1:      # nume necesar
	./task1
run-p2:      # nume necesar
	./task2
run-p3:      # nume necesar
	./task3
run-p4:      # nume necesar
	./task4
run-p5:      # nume necesar
	./task5
clean:		 # nume necesar
	rm task1
	rm task2
	rm task3
	rm task4
	rm task5