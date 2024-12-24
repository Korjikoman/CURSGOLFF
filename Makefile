all:
	g++ -std=c++17 Game.cpp Game.h Main.cpp -I"include" -L"lib" -Wall -lmingw32 -lSDL2main -lSDL2 -lSDL2 -o Main