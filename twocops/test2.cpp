#include <iostream>
#include <vector>
#include <numeric>
#include <cstdlib>
#include <algorithm>

using namespace std;
vector<pair<int,int>> coord;
int K; // 창고 경계 꼭짓점의 개수
pair<int,int> cop1, cop2; // 로봇의 현재 위치를 나타낸 시간
int cycle_time; // 한 바퀴 도는 데 걸리는 시간
int first_meet;
int second_meet;

pair<int, int> mid;
pair<int, int> conflict_1;
pair<int, int> conflict_2;

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
    for(int i=1;i<K;i++){
        cin >> x >> y;
	if (i == K / 2 - 1) {mid = {x, y};}
        get_all_pts(coord.back().first, x, coord.back().second, y);
    }
    get_all_pts(coord.back().first, coord.front().first, coord.back().second, coord.front().second);
    coord.pop_back();
}

void setting(){
	vector<pair<int, int>>::iterator vit;
    	vit = find (coord.begin(), coord.end(), mid);
	first_meet = vit - coord.begin();
	second_meet = coord.size() - first_meet;
//   	cout << "first_route index: " << first_meet  << endl;
//    	cout << "second_route index: " << second_meet << endl;

}

pair<int, int> find_pos(int t, int flag){
	if (flag == 1){
		if 	(t >= 0 && t <= first_meet / 2)		{return coord[t];}
		else if	(t > first_meet / 2 && t < first_meet) {return coord[first_meet - t];}  
		else if (t >= first_meet && t <= first_meet + second_meet / 2) {return coord[coord.size() + first_meet - t];}
		else {return coord[t];}
	}
	else{
		if 	(t >= 0 && t <= first_meet / 2)		{return coord[first_meet - t];}
		else if	(t > first_meet / 2 && t < first_meet + second_meet / 2) {return coord[t];}  
		else {return coord[coord.size() + first_meet - t];}
	}
}


int main() {
    int t;
    get_coordinate(); cin>>t;
    setting();
    t %= coord.size();
    cop1 = find_pos(t, 1);
    cop2 = find_pos(t, 2);
    cout << cop1.first << " " << cop1.second << endl;
    cout << cop2.first << " " << cop2.second << endl;
    return 0;
}
