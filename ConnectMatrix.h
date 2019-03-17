#pragma once

#include <vector>
#include <random>
#include <iostream>
#include <ctime>
using namespace std;


class ConnectMatrix {


private:
	int x;
	int y;
	vector<vector<int>> vec;

public:
	ConnectMatrix();
	int getX();
	int getY();
	void setVector(vector<vector<int>> vec);
	vector<vector<int>> getVector();
	bool inboundMove(int row);
	void printVector();
	bool placeMove(int row, int player);

	//bool inboundMove(vector <vector<int>> & vec, int row);
	//void printVector(vector <vector<int>> & vec);
	//void placeMove(vector <vector<int>> & vec, int row, int player);
	//bool vertCheck(vector<vector<int>> & vec, int col, int player);
	//bool horizCheck(vector<vector<int>> & vec, int row, int player);
	//bool diagCheck(vector<vector<int>> & vec, int row, int col, int player);
	//bool drawCheck(vector<vector<int>> & vec);
	//bool winCheck(vector<vector<int>> & vec, int row, int col, int player);
};