CXX = clang
CXXFLAGS = -pedantic -std=c11
LDFLAGS =  -fsanitize=address

VPATH = SRC INCLUDE 

output: main.o
	$(CXX) $(CXXFLAGS) -o penguin main.o

main.o: main.c
	$(CXX) $(CXXFLAGS) -c main.c

clean:
	rm -f *.o

# Path: penguin/main.c
