#pragma once

#include "ConnectMatrix.h"
#include <random>
using namespace std;

class PlayGame {

private:
	int wins;
	int losses;
	int draws;
	int index;
	ConnectMatrix m;
	vector<vector<int>> vec;

public:

	PlayGame();
	PlayGame(ConnectMatrix m);
	PlayGame(ConnectMatrix m, int wins, int losses, int draws, int index);
	float calcPayOut();
	void incrementW();
	void incrementL();
	void setVector();
	vector<vector<int>> getVector();
	int getIndex();
	void setIndex(int i);
	ConnectMatrix getMatrix();
	void setMatrix(ConnectMatrix m);
	bool vertCheck(int player);
	bool horizCheck(int player);
	bool diagCheck(int player);
	bool drawCheck();
	bool winCheck(int player);
	float playFullGame();
};

