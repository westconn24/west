#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;
struct Homework {
    int number;
    string date;
};

vector<Homework> parseInput(const string &input) {
    vector<Homework> homeworks;
    istringstream ss(input);
    int hwNumber;
    string date;

    while (ss >> hwNumber >> date) {
        Homework hw;
        hw.number = hwNumber;
        hw.date = date;
        homeworks.push_back(hw);
    }

    return homeworks;
}

int main() {
    string input = "1 1/10 17 2/12 33 3/25 2 1/12 18 2/14 34 3/27 3 1/17 19 2/16 35 3/29 4 1/17 20 2/19 36 4/1 5 1/19 21 2/21 37 4/3 6 1/19 22 2/22 38 4/5 7 1/22 23 2/26 39 4/8 8 1/22 24 2/28 40 4/10 9 1/22 25 3/1 41 4/12 10 1/24 26 3/4 42 4/15 11 1/26 27 3/6 43 4/17 12 1/29 28 3/8 44 4/19 13 2/1 29 3/8 45 4/22 14 2/5 30 3/11 46 4/24 15 2/7 31 3/11 47 4/26 16 2/9 32 3/13 48 4/27"; 
    vector<Homework> homeworks = parseInput(input);

    
    ofstream csvFile("Homework_Calendar.csv");
    csvFile << "Subject,Start Date,End Date\n";

    for (const auto& hw : homeworks) {
        csvFile << "HW #" << hw.number << "," << hw.date << "/2024," << hw.date << "/2024\n";
    }

    csvFile.close();
    cout << "CSV file created" << endl;

    return 0;
}