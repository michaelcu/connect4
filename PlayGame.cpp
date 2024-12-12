#include "PlayGame.h"
using namespace std;

PlayGame::PlayGame() {
	ConnectMatrix m;
	int wins = 0;
	int losses = 0;
	int draws = 0;
	vector<vector<int>> vec;
}

PlayGame::PlayGame(ConnectMatrix m) {
	this->m = m;
	this->vec = m.getVector();
}

PlayGame::PlayGame(ConnectMatrix m, int wins, int losses, int draws, int index) {
	this->m = m;
	this->vec = m.getVector();
	this->wins = wins;
	this->losses = losses;
	this->draws = draws;
	this->index = index;
}

float PlayGame::calcPayOut() {
	return (wins + (.5 * draws) / (wins + draws + losses));
}

void PlayGame::incrementW() {
	wins++;
}
void PlayGame::incrementL() {
	losses++;
}

void PlayGame::setMatrix(ConnectMatrix m) {
	this->m = m;
	this->vec = m.getVector();
}

void PlayGame::setVector() {
	vec = m.getVector();
}

vector<vector<int>> PlayGame::getVector() {
	return m.getVector();
}

int PlayGame::getIndex() {
	return index;
}
void PlayGame::setIndex(int i) {
	index = i;
}

ConnectMatrix PlayGame::getMatrix() {
	return m;
}

bool PlayGame::vertCheck(int player) {
	int count = 0;
	//cout << "Y: " << m.getY()<< endl << endl;
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i][m.getY()] == player) {
			count++;
		}
		else {
			count = 0;
		}
		if (count == 4) {
			return true;
		}
	}
	return false;
}

bool PlayGame::horizCheck(int player) {
	int count = 0;
	//cout << "X: " << m.getX() << endl << endl;
	for (int i = 0; i < vec[i].size(); i++) {
		if (vec[m.getX()][i] == player) {
			count++;
		}
		else {
			count = 0;
		}
		if (count == 4) {
			return true;
		}
	}
	return false;
}

//Checks the Diagonals for a Win Condition
bool PlayGame::diagCheck(int player) {

	int i = 0;
	int j = 0;
	int count = 0;

	//Top-Left to Bottom-Right, Lower half
	for (int k = 0; k < vec.size() - 4; k++) {
		for (i = k, j = 0; i < vec[0].size() && j < vec.size(); i++, j++) {
			if (vec[j][i] == player) {
				count++;
			}
			else {
				count = 0;
			}
			if (count == 4) {
				return true;
			}
		}
	}

	//Top-Left to Bottom-Right, Upper half
	for (int k = 0; k < vec[0].size() - 4; k++) {
		for (i = 0, j = k; i < vec[0].size() && j < vec.size(); i++, j++) {
			if (vec[j][i] == player) {
				count++;
			}
			else {
				count = 0;
			}
			if (count == 4) {
				return true;
			}
		}
	}

	//Top-Right to Bottom-Left, Lower half
	for (int k = vec.size(); k > 4; k--) {
		for (i = k, j = 0; i < vec[0].size() && j > 0; i++, j--) {
			if (vec[j][i] == player) {
				count++;
			}
			else {
				count = 0;
			}
			if (count == 4) {
				return true;
			}
		}
	}

	//Top-Right to Bottom-Left, Lower half
	for (int k = vec[0].size(); k > 4; k--) {
		for (i = 0, j = k; i < vec[0].size() && j > 0; i++, j--) {
			if (vec[j][i] == player) {
				count++;
			}
			else {
				count = 0;
			}
			if (count == 4) {
				return true;
			}
		}
	}


	return false;

}


bool PlayGame::drawCheck() {
	for (int i = 0; i < vec[i].size(); i++) {
		if (vec[i][vec[i].size() - 1] == 0) {
			return false;
		}
	}
	return true;
}

bool PlayGame::winCheck(int player) {

	//cout << "Win Check: " << horizCheck(player) << " " << vertCheck(player) << " " << diagCheck(player) << endl;
	if (horizCheck(player) || vertCheck(player) || diagCheck(player)) {
		return true;
	}
	return false;
}


float PlayGame::playFullGame() {

	int n = (2 % 2) + 1;
	int j = rand() % 7;
	srand(time(NULL));

	for (int i = 0; i < 100; i++) {
		j = rand() % 7;

		m.placeMove(j, n);
		setVector();
		if (winCheck(n) || drawCheck()) {
			break;
		}
		n = (n % 2) + 1;
	}

	if (drawCheck() == true) {
		draws++;
		return 1;
	}
	if (n == 1) {
		wins++;
	}
	else {
		losses++;
		return 0;
	}
}