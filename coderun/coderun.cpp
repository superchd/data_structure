#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <string>
#include <queue>
#include <array>

using namespace std;

int N, k1, k2;

queue<string> q;
array<queue<string>, 26> matrix;
vector<pair<string, int>> boxes; // row, column
int idx;
char real_first;

void	my_input(){ // make points
    char first;
    string inp;
    idx = 0;
    int flag = 0;
    cin >> N >> k1 >> k2;
    for (int i = 0; i < N; i++){
	cin >> first;
	if(flag == 0) {real_first = first; flag = 1;}
	while(cin >> inp){
		if (inp == "$") {
			matrix[first - 'A'] = q;
			q = queue<string>();
			break;
		}
		q.push(inp);
	}
    }
}

void	process(queue<string> cur_q){
	while(!cur_q.empty()){
		string curr = cur_q.front();
		cur_q.pop();
		if (curr[0] >= 65 && curr[0] <= 90){
			process(matrix[curr[0] - 'A']);
		}
		else{
			boxes.push_back(make_pair(curr, idx)); idx++;
		}
	}
}

int	main(){
	my_input();
	process(matrix[real_first - 'A']);
	cout << boxes[k1-1].first << "-" << boxes[k1-1].second << endl;
	cout << boxes[k2-1].first << "-" << boxes[k2-1].second << endl;
    	return 0;
}
