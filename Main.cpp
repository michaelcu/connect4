#pragma once

#include <vector>
#include <random>
#include <iostream>
#include <ctime>
#include "ConnectMatrix.h"
#include "PlayGame.h"
using namespace std;





int main() {

	int x;
	int y;


	//Vector for "Actual" Games
	vector <vector<int>> vec1;
	vec1.resize(7);
	for (auto& row : vec1)
		row.resize(6);

	//Vector for "Fake" Games
	vector <vector<int>> vec2;
	vec2.resize(7);
	for (auto& row : vec2)
		row.resize(6);

	//Vector for highest payout positions
	vector <int> hP;


	ConnectMatrix cm;
	cm.setVector(vec1);

	
	//cm.printVector();
	//cout << vec[6][vec[6].size() - 1];

	//Vector for new node placement
	vector <PlayGame> games;
	//Vector for current win group
	vector <PlayGame> tG;

	//Vector for saving scores
	PlayGame s;



	//Best Play
	vector<vector<int>> bP;
	bP.resize(7);
	for (auto& row : bP)
		row.resize(6);


	vector<vector<int>> a;

	//valid set of numbers/ not full indexes
	vector<int> vS;
	vS.resize(7);
	for (int i = 0; i < 7; i++) {
		vS[i] = i;
	}

	ConnectMatrix bPm;
	bPm.setVector(bP);
	s.setMatrix(bPm);

	ConnectMatrix tm;
	tm.setVector(vec2);
	PlayGame * t;

	for (int i = 0; i < 7; i++) {
		t = new PlayGame(tm);
		games.push_back(*(t));
	}

	//Random
	int r;
	
	int i = 0;
	int j = 0;
	int k = 0;
	
	//Current Player
	int n = 1;
	int max = 0;
	int highestPayout = 0;

	while (!(s.winCheck(1)) || s.drawCheck() || !(s.winCheck(2))) {


		//Iterate through children 50 times
		while (j < 50 &&  vS.size() > 0) {



			//Currently no winners
			while(i < vS.size()){
				vec2 = bPm.getVector();
				tm.setVector(vec2);


				if (tm.inboundMove(vS[i]) != true) {
					vS.erase(vS.begin() + i);
					for (int i = vS[0]; i < vS.size(); i++) {
						cout << vS[i];
					}
					cout << endl << endl;
					i = 0;
				}


				tm.placeMove(i, n);
				games[vS[i]].setMatrix(tm);
				if (games[vS[i]].playFullGame() >= max) {
					max = 1;
					games[vS[i]].setIndex(vS[i]);
					tG.push_back(games[vS[i]]);
				}
				vec2.clear();
				vec2.resize(7);
				for (auto& row : vec2)
					row.resize(6);
				i++;
			}

			i = 0;

			//From winners
			while (tG.size() != 0 && j < 50) {
				if (tG[k].playFullGame() == 0) {

					tG.erase(tG.begin() + k);
					k = 0;
				}
				k++;
				if (k + 1 > tG.size()) {
					j++;
					k = 0;
				}
			}

			max = 0;
			j++;
		}

		i = 0;
		j = 0;

		//Gets the highest payout
		while (j < 7) {
			if (highestPayout <= games[j].calcPayOut()) {
				highestPayout = games[j].calcPayOut();
				hP.push_back(j);
			}
			j++;
		}

		//Places the best move in the vector
		bPm.placeMove(games[hP[rand() % hP.size()]].getIndex(), n);
		s.setMatrix(bPm);
		s.getMatrix().printVector();
		cout << endl << endl;

		n = (n % 2) + 1;
	}

	getchar();
	return 0;
}