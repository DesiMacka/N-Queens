//8/April/2017
//Hello human!
//This code uses a recursive function to implement the 
//solve the N-Queens problem
//Written by Desi, CIS 2542-001, Homework(4).

#include <iostream>
#include <vector>

using namespace std;

bool IsLegalQueenPlacement(int queen, int position, std::vector<int>& NewVECTOR)
{
	// Test horizontals and diagonals to see if queen
	// placement is legal according to the rules
	// Set the variable to FALSE if it breaks the rules
	for (int i = 0; i < queen; ++i)
	{
		// Check if spot is available
		int newposition = NewVECTOR[i];

		// Check horizonatally for the same position
		if (newposition == position)
			return false;

		//Check diagonally up and diagonally down
		if (newposition == position - (queen - i) || newposition == position + (queen - i))
			return false;
	}
	// If it doesn't break the rules
	return true;
}
void SolveQueensRecursively(std::vector<int>& VECTOR, int TotalQueens, int QueensUsed)
{
	if (QueensUsed == TotalQueens)
	{
		if (VECTOR.size() == TotalQueens)
		{
			for (int v : VECTOR)
			{
				std::cout << v << " ";
			}
			std::cout << "\n";
		}

		return;
	}

	for (int row = 0; row < TotalQueens; ++row)
	{
		VECTOR.push_back(row);
		if (IsLegalQueenPlacement(QueensUsed, row, VECTOR))
		{
			SolveQueensRecursively(VECTOR, TotalQueens, QueensUsed + 1);
		}

		VECTOR.pop_back();
	}
}


void SolveQueensProblem(int n)
{
	SolveQueensRecursively(std::vector<int>(), n, 0);
}

int main()
{
	//call function to solve
	SolveQueensProblem(4);

	system("PAUSE");
	return 0;
}