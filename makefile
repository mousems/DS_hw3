hw3: hw3.o
	g++ hw3.o -o hw3
	./hw3
test: test.o
	g++ test.cpp -o test
	./test
hw3.o: hw3.cpp
	g++ hw3.cpp -c
clean:
	rm -rf hw3.o 
	rm -rf hw3
	rm -rf test.o test
