CXX = g++
CXXFLAGS = -Iinclude -Wall -std=c++11
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

SRC = src/*.cpp
OUT = game.out

$(OUT): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT) $(LDFLAGS)

clean:
	rm -f $(OUT)
