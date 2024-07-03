#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>


double calculateAverage(int totalSteps, int daysInMonth) {
    return static_cast<double>(totalSteps) / daysInMonth;
}

int main() {
    std::ifstream inFile("steps.txt");
    if (!inFile) {
        std::cerr << "Error: Unable to open file steps.txt\n";
        return 1;
    }

    std::vector<int> steps(31);

    std::string months[12] = {"January", "February", "March", "April", "May", "June", 
                              "July", "August", "September", "October", "November", "December"};

    int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int currentMonth = 0;
    int currentDay = 0;
    int totalSteps = 0;

    while (inFile >> steps[currentDay]) {
        totalSteps += steps[currentDay];
        currentDay++;
        if (currentDay == monthDays[currentMonth]) {
            double average = calculateAverage(totalSteps, monthDays[currentMonth]);
            std::cout << months[currentMonth] << ": Total: " << totalSteps << ", Average: " << std::fixed << std::setprecision(2) << average << " steps." << std::endl;
            totalSteps = 0;
            currentMonth++;
            currentDay = 0;
            if (currentMonth == 12)
                break;
        }
    }

    inFile.close();

    return 0;
}
