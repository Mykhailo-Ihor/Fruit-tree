#include "FruitTree.h"

using namespace std;

int main()
{
	srand(time(0));
	size_t n;
	FruitTree* arr = createArr("Text.txt",n);
	printArr(arr, n);
	YearLater(arr, n);
	printArr(arr, n);
	cout << "Highest Tree:\n"; HighestTree(arr, n).print();
	cout << "Yieldest Tree:\n"; YieldestTree(arr, n).print();
	cout << "\nCheck your files\n";
	WriteToFile(arr, n, "Result.txt");
	delete[] arr;
	return 0;

}