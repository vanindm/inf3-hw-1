#include "SmartPointers/SmartPtr.h"
#include <cassert>
#include <string>

int main() {
	SmartPointers::SmartPtr<std::string> strTest(new std::string("abcd"));
	{
		SmartPointers::SmartPtr<std::string> inheritanceTest(strTest);
		assert(inheritanceTest == strTest);
		assert(inheritanceTest.getCount() == 2);
		SmartPointers::SmartPtr<std::string> assignTest = inheritanceTest;
		assert(assignTest.getCount() == 3);
	}
	SmartPointers::SmartPtr<int> arrTest(new int[4]{1,2,3,4}, [](int* p){delete[] p;});
	assert(strTest.getCount() == 1);
	return 0;
}