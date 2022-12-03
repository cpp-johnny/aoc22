#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{

    // reading from input file  
    ifstream calorieFile("aoc_2022_d1.txt");
    
    string calories;

    // vector declaration
    vector<int> elfCalories;

  
    // vector Intialisation 
    int newElfCalories = 0;

    // read data
    while (getline(calorieFile, calories)) {
        if (calories.empty()) {
            elfCalories.push_back(newElfCalories);
            newElfCalories = 0;
            continue;
        }
        // increases += 1; or increases++;
        newElfCalories += stoi(calories); 
    }
    // insert element 
    elfCalories.push_back(newElfCalories);

    cout << *max_element(elfCalories.begin(), elfCalories.end()) << "\n";
}
