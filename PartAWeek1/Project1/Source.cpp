#include <iostream>

using namespace std;
const int N = 40;

inline void sum(int*p, int n, int d[]) { //Sum adds up first n item in array d and return it to address *p.
	*p = 0;
	for (int i = 0; i < n; ++i)
		*p = *p + d[i];
}

int main() {

	int accum = 0;
	int data[N];
	for (int i = 0; i < N; ++i) {
		data[i] = i;
		cout << i;
	}
	sum(&accum, N, data);
	cout << "sum is" << accum << endl;
	return 0;
}