#pragma once

#include "ConnectMatrix.h"
#include <random>
using namespace std;

class PlayGame {

private:
	int wins;
	int losses;
	int draws;
	ConnectMatrix m;
	vector<vector<int>> vec;

public:

	PlayGame();
	PlayGame(ConnectMatrix m);
	float calcPayOut();
	void setVector();
	vector<vector<int>> getVector();
	ConnectMatrix getMatrix();
	void setMatrix(ConnectMatrix m);
	bool vertCheck(int player);
	bool horizCheck(int player);
	bool diagCheck(int player);
	bool drawCheck();
	bool winCheck(int player);
	float playFullGame();
};

