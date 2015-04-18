CXX = g++
CXXFLAGS = -Wno-write-strings -I ~/src/

SEARCH_TARGET = battleship_sim

LOOPBACK_TARGET = player_one_reader

SECOND_TARGET = player_two_reader

LIB = board.o ship.o computer.o user.o display.o turn.o

all: $(SEARCH_TARGET) $(LOOPBACK_TARGET) $(SECOND_TARGET)

$(SEARCH_TARGET): battleship_sim.o $(LIB)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(LOOPBACK_TARGET): player_one_reader.o $(LIB)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(SECOND_TARGET): player_two_reader.o $(LIB)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f *.o && rm -f $(SEARCH_TARGET) $(LOOPBACK_TARGET) $(SECOND_TARGET)