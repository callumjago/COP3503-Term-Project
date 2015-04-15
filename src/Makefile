CXX = g++
CXXFLAGS = -Wno-write-strings -I ~/src/

SEARCH_TARGET = battleship_sim

LOOPBACK_TARGET = reader

LIB = board.o ship.o computer.o user.o display.o

all: $(SEARCH_TARGET) $(LOOPBACK_TARGET)

$(SEARCH_TARGET): battleship_sim.o $(LIB)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(LOOPBACK_TARGET): reader.o $(LIB)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f *.o && rm -f $(SEARCH_TARGET) $(LOOPBACK_TARGET)