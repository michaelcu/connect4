
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


//So j is being set as 6 because in the for loop vec[row].sie() is the col which is size 7 therefore returns 6 and needs to be 5 beacuse of how im checking in diag
void placeMove(vector <vector<int>> & vec, int row, int player) {
		if (inboundMove(vec, row)) {
			for (int i = 0; i < vec[row].size(); i++) {
				if (vec[row][i] == 0) {
					vec[row][i] = player;
					y = i;
					break;
				}
			}
			std::cout<< endl;
		}
}



bool vertCheck(vector<vector<int>> & vec, int col, int player) {
	int count = 0;
	for (int i = 0; i < vec.size(); i++) {
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

//Row goes out of bounds 
bool diagCheck(vector<vector<int>> & vec, int row, int col, int player) {


	

	//Rows go up and down
	//Cols go left and right
	//I is set as 6
	int i = col;
	int j = row;
	int count = 0;


	//The because it was formerly i < vec.size() it would go to 7 because there are 7 rows, but we're looking at a singel row.
	//Therefore we need to switch I and J
	//Bottom Left Corner
	//cout << "I Current: " << i << endl << endl;
	//cout << "I size: " << vec[i].size() << endl << endl;
	//cout << "J size: " << vec.size() << endl << endl;

	//vec[vec.size() - 1][vec[0].size() - 3] = 5;
	//printVector(vec);
	//cout << vec[vec.size() - 3][vec[0].size()-1] << endl << endl;

	while (i < vec[i].size() && i > 0 && j > 0 && j < vec.size()) {
		i--;
		j++;
	}
	
	//cout << "Test this3: " << (i < vec.size() && j > 0) << endl << endl;
	//cout << "Test this4: " << (j > 0) << endl << endl;
	//cout << "Test this5: " << (i < vec.size()) << endl << endl;


	//cout << "I size after: " << i << endl << endl;
	//cout << "j size after: " << j << endl << endl;

	//Swapp this
	//Swapped
	//Crashes at i = 1, j = 6
	//And when i = 6 and j = 0, so above while loop doesn't run once because it's false;
	while (i < vec[i].size() && i > 0 && j > 0 && j < vec.size()) {
		if (vec[j][i] == player) {
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
	while (i > 0 && j > 0) {
		i--;
		j--;
	}


	//Review this
	//crashed at i = 5 j = 6
	//thinking j is left right so, vec.size() probably isn't appropriate, that or i's bound isn't appropriate
	//i's size is 6
	//j's size is 7 based on logs
	//THerefore I think I and J need to be switched
	//i may actually be the columns
	// j may actually be the rows
	//so i has to be vec[i].size() and j has to be vec.size()

	//Swap this
	//Swapped
	while (i < vec[i].size() && j < vec.size()) {
		if (vec[j][i] == player) {
			count++;
		}
		else {
			count = 0;
		}
		if (count == 4) {
			return true;
		}
		i++;
		j++;
	}
	return false;
}

bool drawCheck(vector<vector<int>> & vec) {
	for (int i = 0; i < vec.size(); i++) {
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

	//vector<int> v;

	//v.resize(7);

	//for (int i = 0; i < v.size(); i++) {
	//	cout << v[i];
	//}

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
			cout << "Win Check : " << winCheck(vec, j, y, n) << endl << endl;
			cout << "Diag Check : " << diagCheck(vec, j, y, n) << endl << endl;
			cout << "vert Check : " << vertCheck(vec, y, n) << endl << endl;
			cout << "horiz Check : " << horizCheck(vec, j, n) << endl << endl;
			cout << "draw Check : " << drawCheck(vec) << endl << endl;
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