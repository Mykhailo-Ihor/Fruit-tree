#include "FruitTree.h"
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;


void FruitTree::NewYield(int old_yield)
{
	tree_yield = rand() % (max_yield - old_yield + 1) + old_yield;
}

void FruitTree::NewHight()
{
	double NewHight = tree_hight + ((rand() % 50 + 1) / 100.);
	if (NewHight < max_hight)
		tree_hight = NewHight;
}

FruitTree::FruitTree(string type, int age, int yield, double hight) : tree_type(type), tree_age(age), tree_yield(yield), tree_hight(hight)
{
}

FruitTree::FruitTree(const FruitTree& T)
{
	tree_type = T.tree_type;
	tree_age = T.tree_age;
	tree_yield = T.tree_yield;
	tree_hight = T.tree_hight;
}

FruitTree::~FruitTree()
{
}

int FruitTree::getAge() const
{
	return tree_age;
}

double FruitTree::getHight() const
{
	return tree_hight;
}
void FruitTree::Yield() const
{
	if (tree_age >= yield_age)
		cout << tree_type << " yield is " << tree_yield << " kg/year\n";
	else cout << "The " << tree_type << " is not yet fruitful";
}

void FruitTree::print() const
{
	cout << "Tree type: " << tree_type << " -- Age: " << tree_age;
	if (tree_age >= yield_age) cout << " -- Yield: " << tree_yield << " kg/year";
	else cout << " -- The tree is not yet fruitful";
	cout << " -- Hight: " << tree_hight << "m\n";
}

void FruitTree::readFrom(std::istream& in )
{
	in.get();
	getline(in, tree_type);
	in >> tree_age;
	if (tree_age >= yield_age)
		in >> tree_yield;
	in >> tree_hight;
}

void FruitTree::writeTo(std::ostream& out) const
{
	out << tree_type << endl << tree_age << endl;
	if (tree_age >= yield_age) out << tree_yield << endl;
	out << tree_hight << endl;
}



void FruitTree::YearPassed()
{
	++tree_age;
	if (tree_age >= yield_age)
	{
		NewYield(tree_yield);
	}
	NewHight();
}



bool FruitTree::operator<(const FruitTree& T) const
{
	return tree_yield < T.tree_yield;
}

std::ostream& operator<<(std::ostream& out, const FruitTree& T)
{
	T.writeTo(out);
	return out;
}

std::istream& operator>>(std::istream& in, FruitTree& T)
{
	T.readFrom(in);
	return in;
}

FruitTree* createArr(std::string FileName, size_t& n)
{
	ifstream fin(FileName);
	fin >> n;
	FruitTree* arr = new FruitTree[n];
	for (size_t i = 0; i < n; ++i)
	{
		fin >> arr[i];
	}
	fin.close();
	return arr;
}

void printArr(FruitTree* arr, size_t n)
{
	for (size_t i = 0; i < n; ++i)
	{
		arr[i].print();
	}
}

void YearLater(FruitTree* arr, size_t n)
{
	cout << "One year later\n";
	for (size_t i = 0; i < n; ++i)
	{
		arr[i].YearPassed();
	}
}

FruitTree& HighestTree(FruitTree* arr, size_t n)
{
	FruitTree * Highest = &arr[0];
	for (size_t i = 1; i < n; ++i)
	{
		if (Highest->getHight() < arr[i].getHight()) Highest = &arr[i];
	}
	return *Highest;
}

FruitTree& YieldestTree(FruitTree* arr, size_t n)
{
	FruitTree * Yieldest = &arr[0];
	for (size_t i = 1; i < n; ++i)
	{
		if (*Yieldest < arr[i]) Yieldest = &arr[i];
	}
	return *Yieldest;
}

void WriteToFile(FruitTree* arr, size_t n, std::string FileName)
{
	ofstream fout(FileName);
	fout << n << '\n';
	for (size_t i = 0; i < n; ++i)
	{
		if (arr[i].getAge() >= FruitTree::yield_age) fout << arr[i];
	}
	fout.close();
}
