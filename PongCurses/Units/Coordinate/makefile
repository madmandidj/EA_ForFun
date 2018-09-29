FLAGS= -g -ansi -pedantic -Wall -Wconversion -m32
OBJECTS = Coordinate.o Test_Coordinate.o
TEST_NAME = Test_Coordinate

$(TEST_NAME).out: $(OBJECTS)
	g++ $(FLAGS) $(OBJECTS) -o $(TEST_NAME).out

$(TEST_NAME).o: $(TEST_NAME).cpp Coordinate.hpp
	g++ -c $(FLAGS) $(TEST_NAME).cpp -o $(TEST_NAME).o

Coordinate.o: Coordinate.cpp Coordinate.hpp
	g++ -c $(FLAGS) Coordinate.cpp -o Coordinate.o

clean:
	rm $(TEST_NAME).out $(OBJECTS)
