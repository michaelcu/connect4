
#include <vector>
#include <random>
#include <iostream>
#include <ctime>
using namespace std;

int x;

int y;


bool inboundMove(vector <vector<int>> & vec, int row) {
	if (vec[row][vec[row].size() - 1] != 0) {
		return false;
	}
	return true;
}
void printVector(vector <vector<int>> & vec) {
	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < vec[i].size(); j++) {
			std::cout << vec[i][j] << " ";
		}
		std::cout << endl;
	}
}


void placeMove(vector <vector<int>> & vec, int row, int player) {
		if (inboundMove(vec, row)) {
			for (int j = 0; j < vec[row].size(); j++) {
				if (vec[row][j] == 0) {
					vec[row][j] = player;
					y = j;
					break;
				}
			}
			std::cout<< endl;
		}
}



bool vertCheck(vector<vector<int>> & vec, int col, int player) {
	int count = 0;
	for (int i = 0; i < vec.size()-1; i++) {
		if (vec[i][col] == player) {
			count++;
		}
		else {
			count = 0;
		}
		if (count == 4) {
			cout << "vert" << endl;
			return true;
		}
	}
	return false;
}

bool horizCheck(vector<vector<int>> & vec, int row, int player) {
	int count = 0;
	for (int i = 0; i < vec[row].size(); i++) {
		if (vec[row][i] == player) {
			count++;
		}
		else {
			count = 0;
		}
		if (count == 4) {
			cout << "horiz" << endl;
			return true;
		}
	}
	return false;
}

bool diagCheck(vector<vector<int>> & vec, int row, int col, int player) {

	int i = row;
	int j = col;
	int count = 0;
	int k = vec[row].size();

	//Bottom Left Corner
	while (i < vec.size() || j < vec[row].size() ) {
		i--;
		j++;
	}

	while (i < vec.size()-1 || j > 0) {
		if (vec[i][j] == player) {
			count++;
		}
		else {
			count = 0;
		}
		if (count == 4) {
			return true;
		}
		i++;
		j--;
	}

	i = row;
	j = col;
	count = 0;

	//Bottom Right Corner
	while (i > 0 || j > 0) {
		i--;
		j--;
	}

	while (i < vec.size() || j < vec[i].size()) {
		if (vec[i][j] == player) {
			count++;
		}
		else {
			count = 0;
		}
		if (count == 4) {
			cout << "diag " << endl;
			return true;
		}
		i++;
		j++;
	}
	return false;
}

bool drawCheck(vector<vector<int>> & vec) {
	for (int i = 0; i < vec[i].size()-1; i++) {
		if (vec[i][vec[i].size() - 1] == 0) {
			return false;
		}
	}
	cout << "draw" << endl;
	return true;
}

bool winCheck(vector<vector<int>> & vec, int row, int col, int player) {
	cout << "Row: " << row << endl;
	cout << "Col: " << col << endl << endl;
	if (horizCheck(vec, row, player) || vertCheck(vec, col, player) || diagCheck(vec, row, col, player)) {
		return true;
	}
	return false;
}

int main() {

	vector <vector<int>> vec;
	vec.resize(7);
	for (auto& row : vec)
		row.resize(6);

	////Horiz
	//for (int i = 0; i < vec[0].size(); i++) {
	//	placeMove(vec, 0, 1);
	//	printVector(vec);
	//}

	////Vert
	//for (int i = 3; i < vec.size(); i++) {
	//	placeMove(vec, i, 1);
	//	printVector(vec);
	//}

	////Diag
	//for (int i = 0; i < vec[i].size(); i++) {
	//	for (int j = 1; j < i; j++) {
	//		placeMove(vec, j, 1);
	//		printVector(vec);
	//	}
	//}

	////Draw
	//for (int i = 0; i < vec[i].size(); i++) {
	//	for (int j = 0; j < vec.size(); j++) {
	//		placeMove(vec, j, 1);
	//		printVector(vec);
	//	}
	//}

	//Diag
	//for (int i = 0; i < vec[i].size(); i++) {
	//	//for (int j = vec[i].size()-1; j > 0; j--) {
	//		vec[i][i] = 1;
	//		printVector(vec);
	//	//}
	//}

	//int j = vec[0].size()-1;

	//for (int i = 0; i < vec[i].size(); i++) {
	//	//for (int j = vec[i].size()-1; j > 0; j--) {
	//		vec[i][j] = 1;
	//		printVector(vec);
	//	//}
	//		j--;
	//}

	int n = (2 % 2) + 1;

	int j = rand() % 7;
	srand(time(NULL));

	//j = 6;

	for (int i = 0; i < 100; i++) {
		cout << i << endl;
		j = rand() % 7;

		placeMove(vec, j, n);
		printVector(vec);
		if (winCheck(vec, j, y , n) || drawCheck(vec)){
			cout << winCheck(vec, j, y, n) << endl << endl;
			cout << drawCheck(vec) << endl << endl;
			break;
		}
		n = (n % 2) + 1;
	}

	//int j = vec[0].size()-1;

	//for (int i = 0; i < vec.size(); i++) {
	//	
	//	vec[i][j] = 2;
	//	printVector(vec);
	//	cout << endl << endl;
	//	if (diagCheck(vec, i, j, 2)) {
	//		cout << "break";
	//		break;
	//	}
	//	j--;

	//}

	//int i = 0;

	//while (winCheck(vec, j, y, n) || drawCheck(vec)) {
	//	cout << i << endl;
	//	j = rand() % 7;

	//	placeMove(vec, j, n);
	//	printVector(vec);
	//	n = (n % 2) + 1;
	//	i++;
	//}


	//std::cout<< vertCheck(vec, j, n) << endl << endl;
	//std::cout << horizCheck(vec, j, n) << endl << endl;
	//std::cout << drawCheck(vec) << endl << endl;
	//std::cout << diagCheck(vec, j, y, n) << endl << endl;
	//std::cout << winCheck(vec, j, y, n);

	//std::cout << vertCheck(vec, 0, 1) << endl << endl;
	//std::cout << horizCheck(vec, 0, 1) << endl << endl;
	//std::cout << drawCheck(vec) << endl << endl;
	//std::cout << diagCheck(vec, 0, 0, 1) << endl << endl;
	//std::cout << winCheck(vec, 0, 0, 1);


	getchar();
	return 0;
};