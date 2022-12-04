#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
     // reading from input file 
    fstream calorieFile("aoc_2022_d1.txt");
  
    string calories;
  
     // vector declaration
    vector<int> elfCalories;

     // vector Intialisation
    int currentElfCalories = 0;

    // read data
    while (getline(calorieFile, calories)) {
        if (calories.empty()) {
            elfCalories.push_back(currentElfCalories);
            currentElfCalories = 0;
            continue;
        }

        currentElfCalories += stoi(calories);
    }
    
  elfCalories.push_back(currentElfCalories);

    int32_t top3[3] = {};
    for (auto calories : elfCalories) {
        for (size_t i = 0; i < 3; i++) {
            if (calories > top3[i]) {
                for (size_t j = 2; j > i; j--) 
                    top3[j] = top3[j - 1];

                top3[i] = calories;
                break;
            }
        }
    }

    cout << top3[0] + top3[1] + top3[2] << "\n";
}
