#include <bits/stdc++.h>

using namespace std;

double xn;
vector<vector<double> > m;

double func(double x)
{
	return -2.3*x;
}

vector<vector<double> > eeuler(double h, double x, double a,  double b) {
	vector<double>  v;
	v.push_back(a);
	v.push_back(x);
	m.push_back(v);
	v.clear();
	for (double k = a + h; k <= b; k += h){
		xn = x + h*func(x); 
		v.push_back(a + h);
        v.push_back(xn);
        m.push_back(v);
        v.clear();
		x = xn;
        a += h;
	}
	return m;
}			