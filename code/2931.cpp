#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int di[] = {-1, 1, 0, 0};
int dj[] = {0, 0, -1, 1};

vector<string> mapV;
vector<pair<int, int>> point;
vector<vector<int>> visit;
queue<pair<int, int>> q;
int r, c;

bool inZone(int i, int j) {
	return i >= 0 && j >= 0 && i < r && j < c;
}

void check(pair<int, int> start) {
	int result = 0;
	int i = start.first;
	int j = start.second;
	cout << i + 1 << " " << j + 1;
	if (inZone(i + 1, j))
		switch (mapV[i + 1][j]) {
		case '|':
		case '+':
		case '2':
		case '3':
			result += 8;
		}
	if (inZone(i - 1, j))
		switch (mapV[i - 1][j]) {
		case '|':
		case '+':
		case '1':
		case '4':
			result += 4;
		}
	if (inZone(i, j - 1))
		switch (mapV[i][j - 1]) {
		case '-':
		case '+':
		case '1':
		case '2':
			result += 2;
		}
	if (inZone(i, j + 1))
		switch (mapV[i][j + 1]) {
		case '-':
		case '+':
		case '3':
		case '4':
			result += 1;
		}
	switch (result) {
	// 1 = ㅜㅏ 2 = ㅘ 3 = ㅗㅓ 4 = ㅝ
	// 1 = ㅏ 2 = ㅓ 4 = ㅗ 8 = ㅜ
	case 3:
		cout << " -";
		break;
	case 5:
		cout << " 2";
		break;
	case 9:
		cout << " 1";
		break;
	case 6:
		cout << " 3";
		break;
	case 10:
		cout << " 4";
		break;
	case 12:
		cout << " |";
		break;
	case 15:
		cout << " +";
		break;
	}
}

void merge(pair<int, int> start, bool u, bool r, bool d, bool l) {
	int i = start.first;
	int j = start.second;
	q.push(make_pair(i - u, j));
	q.push(make_pair(i, j + r));
	q.push(make_pair(i + d, j));
	q.push(make_pair(i, j - l));
}

int main() {
	cin >> r >> c;
	mapV.assign(r, "");
	visit.assign(r, vector<int>(c, 0));
	for (int i = 0; i < r; i++) {
		cin >> mapV[i];
    for (int j = 0; j < c; j++) {
			if (mapV[i][j] == 'M' || mapV[i][j] == 'Z')
				point.push_back(make_pair(i, j));
		}
	}
	for (int k = 0; k < 4; k++) {
		int i = point[0].first + di[k];
		int j = point[0].second + dj[k];
		if (inZone(i, j) && mapV[i][j] != '.')
			q.push(make_pair(i, j));
	}
  visit[point[0].first][point[0].second] = 1;
	while (q.size()) {
		pair<int, int> start = q.front();
		if (inZone(start.first, start.second) && !visit[start.first][start.second]++) {
			switch (mapV[start.first][start.second]) {
			case '+':
				merge(start, 1, 1, 1, 1);
				break;
			case '|':
				merge(start, 1, 0, 1, 0);
				break;
			case '-':
				merge(start, 0, 1, 0, 1);
				break;
			case '1':
				merge(start, 0, 1, 1, 0);
				break;
			case '2':
				merge(start, 1, 1, 0, 0);
				break;
			case '3':
				merge(start, 1, 0, 0, 1);
				break;
			case '4':
				merge(start, 0, 0, 1, 1);
				break;
			case '.':
				check(start);
				return 0;
			default:
				break;
			}
		}
		q.pop();
	}
}