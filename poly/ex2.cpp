#include <iostream>
#include <stdio.h>
#include <string>
#define MAX_DEGREE 1000
using namespace std;

int max_degree;
int final_degree;
int flag;

template <typename T> 
class Poly {
	int _degree;
	T _coef[MAX_DEGREE];
public:
	Poly() : _degree(0) {}
	void read();
	int read_deg();
	Poly& display(string str = "");
	Poly operator + (Poly& p) const;
	Poly& operator * (Poly& p); 
	friend ostream& operator << (ostream& out,  Poly& p)
	{
		p.display();
		return out;
	}
};

template <typename T>
Poly<T> Poly<T>::operator + (Poly& p) const
{
	Poly temp;
	if (_degree > p._degree) {
		temp = *this;
		for (int i = 0; i <= p._degree; i++)
			temp._coef[i + (temp._degree - p._degree)] += p._coef[i];
		return temp;
	}
	else {
		temp = p;
		for (int i = 0; i <= _degree; i++)
			temp._coef[i + (temp._degree - _degree)] += _coef[i];
		return temp;
	}
}

template <typename T>
Poly<T>& Poly<T>::operator * (Poly& p) 
{
	Poly temp;
	temp._degree = MAX_DEGREE; 
	for (int i = 0; i < MAX_DEGREE; i++)
		temp._coef[i] = 0;

	for (int i = 0; i <= (*this)._degree; i++)
	{
		for (int j = 0; j <= p._degree; j++)
			temp._coef[i + j] += (*this)._coef[i] * p._coef[j];
	}
	return temp;
}

template <typename T>
void Poly<T>::read() {
	_degree = -1;
	for (int j = 0; j < MAX_DEGREE ; j++){
		_coef[j] = 0;
	}
	int n;
	cin >> n;
	int coeff, exp;
	for (int i = 0; i < n; i++){
		cin >> coeff >> exp;
		_coef[exp] = coeff;
		if (exp >= _degree) {_degree = exp;}
	}
}
template <typename T>
int Poly<T>::read_deg() {
	return _degree;
}

template <typename T>
Poly<T>& Poly<T>::display(string str) {
	int cnt = 0;
	if (flag == 1) {_degree = final_degree + 1;}
	for (int i = _degree; i > -1; i--) {
		if (_coef[i] != 0) { cnt++;}	
	}
	cout << cnt << endl;
	for (int i = _degree; i > -1; i--) {
		if (_coef[i] != 0) {
		cout << _coef[i] << " " << i << endl;}
	}
	return *this;
}

int main()
{
	Poly<int> a, b, add, sub, mul; 
	int n; flag = 0;
	cin >> n;
	final_degree = 0;
	Poly<int>* p = new Poly<int>[n];
	for (int i = 0; i < n; i++){
		p[i].read();
		final_degree += p[i].read_deg();
	}
	mul = p[0];
	for (int j = 1; j < n; j++){
		mul = mul * p[j];
	}
	flag = 1;
	cout <<  mul << endl;
	return 0;
}
