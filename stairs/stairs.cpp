#include <sstream>
#include <algorithm>
#include <vector>
#include <iostream>
#include <numeric>
#include <string>
using namespace std;
vector<string> stairs;
vector<int> x_stair;
vector<int> y_stair;
vector<int> whole_stair;
int dx[2] = {0, 1};
int dy[2] = {-1, 0};
int dirNum = 0;
struct point{int x;int y;int more_y;};
vector<point> points;
vector<vector<int>> r_p;
vector<point> range_arr;
void init(){
	int num, _x, _y;
	int flag = 1;
	while (cin >> num){
		if (num == 0) {break;}
		if(flag == 1) {x_stair.push_back(num);}
		else {y_stair.push_back(num);}
		flag *= -1;
		whole_stair.push_back(num);
	}
	while (cin >> _x >> _y){
		point ex;
		ex.x = _x;
		ex.y = _y;
		points.push_back(ex);
	}
	return;
}
void draw(){
	int curr_x = 0;
	int curr_y = 0;
	int x_sum = accumulate(x_stair.begin(), x_stair.end(), 0);
	int y_sum = accumulate(y_stair.begin(), y_stair.end(), 0);
	int repeat;
	vector<int> c;
	curr_y = y_sum;
	point start;
	start.x = 0; start.y = y_sum;
	c.push_back(y_sum);
	r_p.push_back(c);
	dirNum = 1;
	for (int i = 0; i < whole_stair.size(); i++){
		point ex;
		c.clear();
		for(int j = 0; j < whole_stair[i]; j++){
			ex.x = curr_x + j * dx[dirNum];
			ex.y = curr_y + j * dy[dirNum];
			if (i % 2 == 0 && j != whole_stair[i] - 1) {
				c.clear();
				c.push_back(ex.y);
				r_p.push_back(c);
			}
			else {c.push_back(ex.y);}
		}
		if (i % 2 == 1){
		r_p.push_back(c);}
		curr_x += whole_stair[i] * dx[dirNum];
		curr_y += whole_stair[i] * dy[dirNum];
		dirNum = (dirNum + 1) % 2;
	}
}
void calculate(point p){
	if (p.x >= r_p.size()) {cout << "out" << endl;return;}
	int min = *min_element(r_p[p.x].begin(), r_p[p.x].end());
	int max = *max_element(r_p[p.x].begin(), r_p[p.x].end());
	if (min - 1 > p.y) {cout << "in" << endl;}
	else {
		if (max < p.y) {cout << "out" << endl;}
		else{cout << "on" <<endl;}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    init();
    draw();
    for (auto p:points){calculate(p);}
}
