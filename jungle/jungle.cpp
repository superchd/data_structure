#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<int>> inp;
vector<vector<int>> nums;
vector<vector<int>> col_map;
int 	n;

void	my_print(vector<int> vec){
	for (auto v : vec){
		cout << v << " ";
	}
	cout << "0" << endl;
}


void	my_print(vector<vector<int>> inp){

	for (auto k: inp){
		for (auto p : k){
			cout << p << " " ;
		}
		cout << endl;
	}
}

void	my_input(){
	cin >> n;
	int cnt = 0;
	int j = 0;
	string str;
	while (getline(cin, str)){
		vector<int> ex;
		string num = "";
		int flag = 0;
		for (j = 0; j < str.size() ; j++){
			if (str[j] != ' ') {
				flag = 1;
				num = "";
				while (str[j] != ' '){
					num += str[j];
					j++;
				}
				ex.push_back(stoi(num));
			}
			else if(str[j] == '0'){
				flag = 0;
				break;
			}
		}
		inp.push_back(ex);
	}
	return;
}

void	rearrange(){
	for (auto row: inp){
		vector<int> ex;
		for (int i = 0; i < row.size(); i++){
			if (row[0] == 0){
				for (int j = 0; j < row[1]; j++){
					vector<int> no;
					nums.push_back(no);
				}
				break;
			}
			else {
				if(row[i] != 0) {ex.push_back(row[i]);}
			}
		}
		if(ex.size() != 0) {nums.push_back(ex);}
	}
	cout << endl;
//	my_print(nums);
//	cout << "===============111=============" << endl;
}

void	my_sol(){
	int i = 1;
	for(int k = 0; k < n; k++){
		vector<int> ex;
		for(int j = 0; j < nums.size(); j++){
			for(auto r: nums[j]){
				if(k + 1 == r){
					ex.push_back(j + 1);
				}
				else if(k + 1 < r) {break;}
			}
		}
		col_map.push_back(ex);
	}
}

void	convert(){
	int cnt = 0;
	cout << n << endl;
	for(int i = 0; i < col_map.size(); i++){
		if (col_map[i].size() == 0){
			cnt++;
		}
		else {
			if (cnt != 0){
			cout << "0 " << cnt << endl; cnt = 0;}
			my_print(col_map[i]);
		}
	}
}

int 	main(void){
	my_input();
	rearrange();
	my_sol();
//	my_print(col_map);
//	cout << "==================2222================" << endl;
	convert();
}
