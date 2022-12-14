#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <cassert>

using namespace std;

char getShared(const string& compartment1, const string& compartment2)
{
	for(const auto& item: compartment1)
	{
		for(const auto& compare_item: compartment2)
		{
			if(item == compare_item)
			{
				return item;
			}
		}
	}
	throw runtime_error("Shared item not found!");
}

int getPrioriy(const string& backpack)
{
	assert(!(backpack.size() % 2) && "Backpack size must be even!");
	string compartment1 = backpack.substr(0, backpack.size() / 2);
	string compartment2 = backpack.substr(backpack.size() / 2, backpack.size() / 2);

	char shared = getShared(compartment1, compartment2);

	return isupper(shared) ? (shared - 'A') + 27 : (shared - 'a') + 1;
}

int main()
{
	ifstream input("aoc_d3_1.txt");
	string line;

	int total_priorty = 0;
	while(getline(input, line))
	{
		total_priorty += getPrioriy(line);
	}
	input.close();

	cout << "Total: " << total_priorty << '\n';

	return EXIT_SUCCESS;
}
