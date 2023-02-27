CXX = clang
CXXFLAGS = -pedantic -std=c11 -framework CoreGraphics
LDFLAGS =  -fsanitize=address
BIN=/usr/local/bin

VPATH = SRC INCLUDE 

output: main.o
	$(CXX) $(CXXFLAGS) -o penguin main.o

main.o: main.c
	$(CXX) $(CXXFLAGS) -c src/main.c

install:
	@sudo cp penguin $(BIN)

clean:
	rm -f *.o

# Path: penguin/src/main.c

