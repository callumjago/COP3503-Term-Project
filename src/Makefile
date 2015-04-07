CXX = g++
CXXFLAGS = -Wall -I ~/src/

SEARCH_TARGET = battleship_sim

LIB = board.o ship.o computer.o user.o

all: $(SEARCH_TARGET)

$(SEARCH_TARGET): battleship_sim.o $(LIB)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f *.o && rm -f $(SEARCH_TARGET)