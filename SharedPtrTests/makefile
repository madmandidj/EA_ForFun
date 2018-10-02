FLAGS = -g -ansi -pedantic -Wall -Wconversion -m32 -std=c++98 -stdlib=libstdc++ -cl-opt-disable
# FLAGS = -g -ansi -pedantic -Wall -Wconversion -m32 -std=c++98 -stdlib=libstdc++ 
OBJECTS = MyClasses.o Test_MyClasses.o

Test_MyClasses.out: $(OBJECTS)
	g++ $(FLAGS) $(OBJECTS) -o Test_MyClasses.out

Test_MyClasses.o: Test_MyClasses.cpp MyClasses.hpp
	g++ $(FLAGS)  -c Test_MyClasses.cpp -o Test_MyClasses.o

MyClasses.o: MyClasses.cpp MyClasses.hpp
	g++ $(FLAGS)  -c MyClasses.cpp -o MyClasses.o

clean:
	rm $(OBJECTS) Test_MyClasses.out
