#include <iostream>
#include <fstream>
#include <chrono>
#include <cassert>

#include "SmartPointers/SmartPtr.h"
#include "SmartPointers/ShrdPtr.h"
#include "SmartPointers/MemorySpan.h"

#include <DynamicArray.h>

int main(int argc, char** argv) {

	if (argc != 2) {
		std::fprintf(stderr, "Wrong number of arguments!");
		return 1;
	}

	size_t AMOUNT = atoi(argv[1]);

	char testPath[] = "../contrib/testdata.input"; 

	std::ifstream inputDataStream;

	inputDataStream.open(testPath);

	if (inputDataStream.fail()) {
		throw std::runtime_error("couldn't open file");
	}

	int* items = new int[AMOUNT];
	for (size_t i = 0; i < AMOUNT; ++i) {
		inputDataStream >> items[i];
	}


	std::chrono::_V2::steady_clock::time_point start;
	std::chrono::_V2::steady_clock::time_point end;

//-------------------------------------------------------------------

	start = std::chrono::steady_clock::now();
	
	SmartPtrDynamicArray<int> array(AMOUNT, items);
	
	end = std::chrono::steady_clock::now();
	
	std::chrono::duration<double> elapsed = end - start;
	
	std::cout << "SmartPtr DynamicArray Allocation" << "\n";
	std::cout << elapsed.count() << "\n";

//-------------------------------------------------------------------

	start = std::chrono::steady_clock::now();
	
	UnqPtrDynamicArray<int> unqArray(AMOUNT, items);
	
	end = std::chrono::steady_clock::now();
	
	elapsed = end - start;
	
	std::cout << "UnqPtr DynamicArray Allocation" << "\n";
	std::cout << elapsed.count() << "\n";


//-------------------------------------------------------------------

	start = std::chrono::steady_clock::now();

	MemorySpanDynamicArray<int> arrayMemorySpan(AMOUNT, items);

	end = std::chrono::steady_clock::now();
	
	elapsed = end - start;

	std::cout << "MemorySpan DynamicArray Allocation" << "\n";
	std::cout << elapsed.count() << "\n";

//-------------------------------------------------------------------

	start = std::chrono::steady_clock::now();
	end = std::chrono::steady_clock::now();

//-------------------------------------------------------------------

	delete[] items;
	return 0;
}