
#include "ConnectMatrix.h"
using namespace std;

ConnectMatrix::ConnectMatrix() {
	x = 0;
	y = 0;
}

int ConnectMatrix::getX() {
	return x;
}
int ConnectMatrix::getY() {
	return y;
}

void ConnectMatrix::setVector(vector<vector<int>> vec) {
	this->vec = vec;
}

vector<vector<int>> ConnectMatrix::getVector() {
	return this->vec;
}

bool ConnectMatrix::inboundMove(int row) {
	if (vec[row][vec[row].size() - 1] != 0) {
		return false;
	}
	return true;
}
void ConnectMatrix::printVector() {
	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < vec[i].size(); j++) {
			cout << vec[i][j] << " ";
		}
		cout << endl;
	}
}

//X is up and down
//Y is Left and Right
bool ConnectMatrix::placeMove(int row, int player) {
	if (inboundMove(row)) {
		for (int i = 0; i < vec.size(); i++) {
			if (vec[row][i] == 0) {
				vec[row][i] = player;
				this->x = row;
				this->y = i;
				return true;
			}
		}
		cout << endl;
	}
	return false;
}