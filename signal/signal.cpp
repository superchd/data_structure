#include <iostream>
#include <algorithm>
#include<fstream>
#include<string>
#include<cstdbool>
#include <sstream>
#include <vector>
using namespace std;

vector<int> data;

bool has_zero(string line){
	int cnt = 0;
	//line.erase(line.begin());
	if (line[0] == '0'){return true;}
	else {return false;}
}

void my_input(){
	string line;
	ifstream myfile ("zsignal.txt");
	int i = 0 ;
	int first;
	if (myfile.is_open()) {
		getline(myfile, line);
		stringstream s2(line);
		string x;
		s2 >> x;
		first = stoi(x);
		data.push_back(first);
		while (getline (myfile,line)) {
			stringstream s2(line);
			string x, y;
			if (has_zero(line)){
				s2 >> x >> y;
				int repeat;
				repeat = stoi(y);
				for (int j = 0; j < repeat; j++){
					data.push_back(first);
				}
			}
			else {
				s2 >> x; 
				first += stoi(x);
				data.push_back(first);}
		}
	}
        myfile.close();
}
void my_sol(){
	char flag;
	int t, start, end;
	while (cin >> flag){
		if (flag == 'T'){
			cin >> t;
			if (t < 0 || t >= data.size()){cout << "-1" << endl;}
			else{cout << data[t] << endl;}
		}
		else{
			cin >> start >> end;
			if (start < 0 || end >= data.size()) {cout << -1 << endl; continue;}
			int max = *max_element(data.begin() + start, data.begin() + end);
			int min = *min_element(data.begin() + start, data.begin() + end);
			cout << min << " " << max << endl;
		}
	}
	return;
}

int main () {
	my_input();
	my_sol();
        return 0;
} 
