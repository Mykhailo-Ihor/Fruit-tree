#pragma once
#include <iostream>
#include <string>



class FruitTree
{
private:
	std::string tree_type;
	int tree_age;
	int tree_yield;
	double tree_hight;
	void NewYield(int old_yield);
	void NewHight();
public:
	enum { max_hight = 3, yield_age = 4, max_yield = 200 };
	FruitTree(std::string type = "",int age = 0, int yield = 0, double hight = 0);
	FruitTree(const FruitTree& T);	
	~FruitTree();
	int getAge() const;
	double getHight() const;
	void Yield() const;
	void print() const;
	void readFrom(std::istream& in);
	void writeTo(std::ostream& out) const;
	void YearPassed();
	bool operator< (const FruitTree& T) const;
};

std::ostream& operator<<(std::ostream& out, const FruitTree& T);
std::istream& operator>>(std::istream& in, FruitTree& T);

FruitTree* createArr(std::string FileName ,size_t& n);
void printArr(FruitTree* arr, size_t n);
void YearLater(FruitTree* arr, size_t n);
FruitTree& HighestTree(FruitTree* arr, size_t n);
FruitTree& YieldestTree(FruitTree* arr, size_t n);
void WriteToFile(FruitTree* arr, size_t n, std::string FileName);
