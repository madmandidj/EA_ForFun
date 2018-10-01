FLAGS= -g -ansi -pedantic -Wall -Wconversion -m32 -std=c++98 -stdlib=libstdc++ -lcurses
UNIT_NAME = Engine
TEST_NAME = Test_$(UNIT_NAME)
OBJECTS = Coordinate.o Pixel.o Object_t.o Window.o $(UNIT_NAME).o $(TEST_NAME).o
COORD_PATH = ../Coordinate/
PIXEL_PATH = ../Pixel/
OBJECT_T_PATH = ../Object_t/
WINDOW_PATH = ../Window/

$(TEST_NAME).out: $(OBJECTS)
	g++ $(FLAGS) $(OBJECTS) -o $(TEST_NAME).out 

$(TEST_NAME).o: $(TEST_NAME).cpp $(UNIT_NAME).hpp $(PIXEL_PATH)Pixel.hpp $(OBJECT_T_PATH)Object_t.hpp $(WINDOW_PATH)Window.hpp
	g++ -c $(FLAGS) $(TEST_NAME).cpp -o $(TEST_NAME).o 

$(UNIT_NAME).o: $(UNIT_NAME).cpp $(UNIT_NAME).hpp $(PIXEL_PATH)Pixel.hpp $(OBJECT_T_PATH)Object_t.hpp $(WINDOW_PATH)Window.hpp
	g++ -c $(FLAGS) $(UNIT_NAME).cpp -o $(UNIT_NAME).o 

Window.o: $(WINDOW_PATH)Window.cpp $(WINDOW_PATH)Window.hpp $(OBJECT_T_PATH)Object_t.hpp $(PIXEL_PATH)Pixel.hpp $(COORD_PATH)Coordinate.hpp
	g++ -c $(FLAGS) $(WINDOW_PATH)Window.cpp -o Window.o 

Object_t.o: $(OBJECT_T_PATH)Object_t.cpp $(OBJECT_T_PATH)Object_t.hpp $(PIXEL_PATH)Pixel.hpp $(COORD_PATH)Coordinate.hpp
	g++ -c $(FLAGS) $(OBJECT_T_PATH)Object_t.cpp -o Object_t.o 

Pixel.o: $(PIXEL_PATH)Pixel.cpp $(PIXEL_PATH)Pixel.hpp $(COORD_PATH)Coordinate.hpp
	g++ -c $(FLAGS) $(PIXEL_PATH)Pixel.cpp -o Pixel.o

Coordinate.o: $(COORD_PATH)Coordinate.cpp $(COORD_PATH)Coordinate.hpp
	g++ -c $(FLAGS) $(COORD_PATH)Coordinate.cpp -o Coordinate.o

clean:
	rm $(TEST_NAME).out $(OBJECTS)
