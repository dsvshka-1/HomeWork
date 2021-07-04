#include <iostream>

using namespace std;

int test1(){
	int i = 0;
	while(i >= 0){
		++i;
	}
	return i;
}

int test2(int init){
	int i = init;
	while(i < 0){
		++i;
	}
	return i;
}

int main(){
	
	char* arr = new char[128];
	delete[] arr; 
	
	arr = new char[128];		
	delete[] arr;
	
	cout << test1() << endl;
	cout << test2(test1()) << endl;
	
	return 0;
}