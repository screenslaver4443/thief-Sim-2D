CXX = g++
CXXFLAGS = -Iinclude -Wall -std=c++11

SRC = src/main.cpp src/Game.cpp
OUT = game.out

$(OUT): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT)

clean:
	rm -f $(OUT)
