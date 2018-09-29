FLAGS= -g -ansi -pedantic -Wall -Wconversion -m32
UNIT_NAME = Pixel
TEST_NAME = Test_$(UNIT_NAME)
OBJECTS = Coordinate.o $(UNIT_NAME).o $(TEST_NAME).o
COORD_PATH = ../Coordinate/

$(TEST_NAME).out: $(OBJECTS)
	g++ $(FLAGS) $(OBJECTS) -o $(TEST_NAME).out

$(TEST_NAME).o: $(TEST_NAME).cpp $(UNIT_NAME).hpp $(COORD_PATH)Coordinate.hpp 
	g++ -c $(FLAGS) $(TEST_NAME).cpp -o $(TEST_NAME).o

$(UNIT_NAME).o: $(UNIT_NAME).cpp $(UNIT_NAME).hpp $(COORD_PATH)Coordinate.hpp 
	g++ -c $(FLAGS) $(UNIT_NAME).cpp -o $(UNIT_NAME).o

Coordinate.o: $(COORD_PATH)Coordinate.cpp $(COORD_PATH)Coordinate.hpp
	g++ -c $(FLAGS) $(COORD_PATH)Coordinate.cpp -o Coordinate.o

clean:
	rm $(TEST_NAME).out $(OBJECTS)
