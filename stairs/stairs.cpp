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
struct point{
	int x;
	int y;
	int more_y;
};
vector<point> points;
vector<point> range_points;
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
	int curr_y = 0;
	int x_sum = accumulate(x_stair.begin(), x_stair.end(), 0);
	int y_sum = accumulate(y_stair.begin(), y_stair.end(), 0);
	curr_y = y_sum;
	point start;
	start.x = 0; start.y = y_sum;
	range_points.push_back(start);
	dirNum = 1;
	for (int i = 0; i < whole_stair.size() - 1; i++){
		curr_x += whole_stair[i] * dx[dirNum];
		curr_y += whole_stair[i] * dy[dirNum];
		dirNum = (dirNum + 1) % 2;
		point ex;
		ex.x = curr_x;
		ex.y = curr_y;
		range_points.push_back(ex);
	}
	point end;
	end.x = x_sum; end.y = 0;
	range_points.push_back(end);
}
void	make_range(){
	point start;
	point end;
	point ex;
	ex.x = 0;
	ex.y = accumulate(y_stair.begin(), y_stair.end(), 0);
	range_arr.push_back(ex);
	for(int i = 0; i < range_points.size() - 1; i++){
		if (i % 2 == 0){
			start.x = range_points[i].x;
			start.y = range_points[i].y;
		}
		else {
			end.x = range_points[i].x;
			end.y = range_points[i].y;
			for (int j = start.x + 1; j <= end.x; j++){
				ex.x = j;
				ex.y = start.y;
				range_arr.push_back(ex);
			}
		}	
	}
	for (int i = 0; i < range_arr.size() - 1; i++){
		if (range_arr[i].y != range_arr[i + 1].y){
			range_arr[i].more_y = range_arr[i + 1].y;
		}
		else {range_arr[i].more_y = range_arr[i].y;}	
	}
	range_arr[range_arr.size()-1].more_y = 0;
	return;
}
void calculate(point ex){
	int idx = ex.x;
	int compare = ex.y;
	if (range_arr[idx].y == range_arr[idx].more_y){
		if(range_arr[idx].y > compare) {cout << "in" << endl;}
		else if (range_arr[idx].y < compare) {cout << "out" << endl;}
		else {cout << "on" << endl;}
	}
	else {
		if(range_arr[idx].y >= compare && range_arr[idx].more_y <= compare) {cout << "on" << endl;}
		else if (range_arr[idx].more_y > compare) {cout << "in" << endl;}
		else {cout << "out" << endl;}
	}
	return;
}
int main(){
    ios_base :: sync_with_stdio(false);
    init();
    draw();
    make_range();
    for (auto a: points){calculate(a);}
}
