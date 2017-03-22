//#include <iostream>
//#include <vector>
//using namespace std;
//int main() {

	//i++ and ++i;

	//int i,j,k;
	//i = 1;
	//j = ++i;
	//i = 1;
	//k = i++;
	//cout << "i is " << i << endl;
	//cout << "j=++i returns " << j << endl;
	//cout << "k=i++ returns " << k << endl;

	//cout << 9 % 5 / 2 <<endl;
	//cout << 12 % 5 / 2 << endl;



	////Test: change the iterated vector when iterating, it is okay?
	//vector<int> test{ -1 }; //create an empty vector
	//test.push_back(0); //insert 5 to the back of the vector
	//cout << test[0];
	//int i = 1;
	//for (auto it = test.begin(); it != test.end();++it) {
	//	test.push_back(i);
	//	i++;
	//	cout << test.size();
	//}
	//cout << "end!";


//
//
//	//end of code
//cin.clear();
//cin.ignore(32767, '\n');
//cin.get();
//
//}

	//class memberfunction overloading and overwriting

	#include <iostream>
	#include <vector>
	using namespace std;

	class B {
	public:
		virtual void foo(int a) { cout << "class B foo(int)" << endl; };
		virtual void foo(double b) { cout << "class B foo(double)" << endl; };
	};
	class D :public B {
	public:
		void foo(int a) { cout << "class D foo(int)" << endl; };
	};
	int main() {
		D d, *pd;
		B b, *pb=&b;
		b.foo(9.5); //calls B::foo(double)
		pb->foo(9.5); // calls B::foo(double)
		pb = &d;
		pd = &d;
		d.foo(9.5); //calls D::foo(int)
		pd->foo(9.5); //calls D::foo(int)
		pb->foo(9.5); //calls B::foo(double)


		//end of code
		cin.clear();
		cin.ignore(32767, '\n');
		cin.get();

		return 0;

	}
