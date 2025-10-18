CXX = g++
CXXFLAGS = -Iinclude -Wall -std=c++11

SRC = src/Game.cpp
OUT = game.out

$(OUT): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) src/main.cpp -o $(OUT)

test: $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) src/tests.cpp -o tests.out

clean:
	rm -f $(OUT)
	rm -f tests.out
