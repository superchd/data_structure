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
vector<vector<int>> numbers;

int dx[2] = {1, 0};
int dy[2] = {0, -1};
// dirNum = 1 -> east , dirNum = 0 -> south
int dirNum = 0;

struct point{
	int x;
	int y;
};

vector<point> points;

void init(){

	ifstream iFile("01.inp");    // input.txt has integers, one per line
	int i,x;

	while ( 1 ) {
	    iFile >> x;
	    if( iFile.eof( )) break ;

	    cerr << "i= " << ++i << "  numbers = " << x << endl;
	}
	return 0;
}


void draw(){
	for (int i = 0; i < numbers.size(); i++){
		x_stair.push_back(numbers[i][0]);
		y_stair.push_back(numbers[i][1]);
	}

	int curr_x = 0; 
	int curr_y = 0;
	int x_sum = accumulate(x_stair.begin(), x_stair.end(), 0);
	int y_sum = accumulate(y_stair.begin(), y_stair.end(), 0);
	
	curr_x = x_sum;
	point start;
	start.x = 0; start.y = y_sum;
	points.push_back(start);

	for (int i = 1; i < x_stair.size() - 1; i++){
		curr_x += x_stair[i] * dx[dirNum];
		curr_y += y_stair[i] * dy[dirNum];
		dirNum = (dirNum + 1) % 2;
		point ex;
		ex.x = curr_x;
		ex.y = curr_y;
		points.push_back(ex);
	}

	point end;
	end.x = x_sum; end.y = 0;

}

int main(){
    ios_base :: sync_with_stdio(false);
    init();
    draw();
    for (auto a: points){
	    cout << a.x << ", " << a.y << endl;
    }
    //for (auto ex: numbers) {location(ex);}
}
