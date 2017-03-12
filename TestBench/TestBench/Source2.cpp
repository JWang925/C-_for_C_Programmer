#include <iostream>
using namespace std;
int main() {
	int i,j,k;
	i = 1;
	j = ++i;
	i = 1;
	k = i++;
	cout << "i is " << i << endl;
	cout << "j=++i returns " << j << endl;
	cout << "k=i++ returns " << k << endl;


	//end of code
	cin.clear();
	cin.ignore(32767, '\n');
	cin.get();

}