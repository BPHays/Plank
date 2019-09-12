
game: engine.cpp machine_state.cpp main.cpp player.cpp transition.cpp engine.h game_state.h machine.h machine_state.h oracle.h player.h transition.h
	clang++ -std=c++17 -g -o game engine.cpp machine_state.cpp main.cpp player.cpp transition.cpp
