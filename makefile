CXX = g++
CXXFLAGS = -Iinclude -Wall -std=c++11

SRC = src/*.cpp
OUT = game.out

$(OUT): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) src/main.cpp -o $(OUT)


clean:
	rm -f $(OUT)
