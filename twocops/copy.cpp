#include <iostream>
#include <vector>
#include <numeric>
#include <cstdlib>
#include <algorithm>
using namesapce std;

int K; // 창고 경계 꼭짓점의 개수
int cop1, cop2; // 로봇의 현재 위치를 나타낸 시간
int cycle_time; // 한 바퀴 도는 데 걸리는 시간
int dx[] = {1, -1, 0, 0}; // x 좌표 이동
int dy[] = {0, 0, 1, -1}; // y 좌표 이동
vector<pair<int, int>> house; // 창고의 {x, y} 좌표
vector passed_time, // 좌표마다 경과 시간
direction; // 좌표마다 움직이는 방향
vector<pair<int,int>> coord;
pair<int, int> start;
pair<int, int> mid;
int counter_clock;
int clock_way;
vector<pair<int, int>> first_coord;
vector<pair<int, int>> second_coord;
void get_all_pts(int x1, int x2, int y1, int y2) {
    int x_gap = x2-x1, y_gap = y2-y1;
    vector<int> x_arr(abs(x_gap)), y_arr(abs(y_gap));
    iota(begin(x_arr),end(x_arr),1);
    iota(begin(y_arr),end(y_arr),1);
    if(x_gap>0) for(auto i:x_arr) coord.push_back({x1+i,y1});
    else if(x_gap<0) for(auto i:x_arr) coord.push_back({x1-i,y1});
    else if(y_gap>0) for(auto i:y_arr) coord.push_back({x1,y1+i});
    else for(auto i:y_arr) coord.push_back({x1,y1-i});
}

void get_coordinate() {
    int K;
    int x,y;
    cin >> K;
    cin >> x >> y;
    coord.push_back({x,y});
    start = coord[0];
    for(int i=1;i<K;i++){
        cin >> x >> y;
        get_all_pts(coord.back().first, x, coord.back().second, y);
	if (i == K/2 - 1) { mid = coord.back();}
    }
    get_all_pts(coord.back().first, coord.front().first, coord.back().second, coord.front().second);
    coord.pop_back();
}


void first_route(){
	counter_clock = find(coord.begin(), coord.end(), mid) - coord.begin() - 1;
	clock_way = coord.size() - counter_clock;
	if (counter_clock % 2 == 1) {counter_clock += 1;}
	if (clock_way % 2 == 1) {clock_way += 1;}
//	cout << endl << counter_clock << " " << clock_way << endl;
	for (int i = 0; i < counter_clock / 2 ; i++)				{first_coord.push_back(coord[i]);}
	for (int i = counter_clock / 2; i > -1; i--)				{first_coord.push_back(coord[i]);}
	for (int i = coord.size() - 1; i > coord.size() - clock_way / 2  ; i--)	{first_coord.push_back(coord[i]);}
	for (int i = coord.size() - clock_way / 2 + 1; i < coord.size(); i++)	{first_coord.push_back(coord[i]);}
	return;
}

void second_route(){
	for (int i = counter_clock + 1; i > counter_clock / 2; i--)			{second_coord.push_back(coord[i]);}
	for (int i = counter_clock / 2 + 1; i < coord.size() - clock_way/2 ; i++)	{second_coord.push_back(coord[i]);}
	for (int i = coord.size() - clock_way / 2; i > coord.size() - clock_way+1; i--)	{second_coord.push_back(coord[i]);}
	return;
}

int main() {
    int t;
    int first_t;
    int second_t;
    get_coordinate();
    first_route();
    second_route();
    cin >> t;
    first_t = t % first_coord.size();
    second_t = t % second_coord.size();
/*
    for (auto c : coord){
	cout << c.first << " " << c.second << endl;
    }
    cout << "--------------------------------" << endl;

    for (auto f : first_coord){
	cout << f.first << " " << f.second << endl;
    }
    cout << "============================+" << endl;
    */
    cout << first_coord[first_t].first << " " << first_coord[first_t].second  << endl;
    cout << second_coord[second_t].first << " " << second_coord[second_t].second;
    return 0;
}
