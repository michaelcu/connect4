#pragma once

#include <vector>
#include <random>
#include <iostream>
#include <ctime>
#include "ConnectMatrix.h"
#include "PlayGame.h"
using namespace std;





int main() {


	vector <vector<int>> vec;
	vec.resize(7);
	for (auto& row : vec)
		row.resize(6);


	ConnectMatrix cm;
	cm.setVector(vec);
	//cm.printVector();
	//cout << vec[6][vec[6].size() - 1];

	PlayGame p(cm);
	//p.getMatrix().printVector();
	//cout << p.getMatrix().getVector().size();

	//int n = (2 % 2) + 1;

	//int j = rand() % 7;
	//srand(time(NULL));

	//while (cm.placeMove(j, n) == true) {
	//	j = rand() % 7;
	//	cm.printVector();
	//	cout << endl;
	//	n = (n % 2) + 1;
	//}

	cout << p.playFullGame();
	


	getchar();
	return 0;
}