#include <iostream>
#include <cmath>

int main() {
    int initialPopulation, days;
    
    // Taking input for initial population and number of days
    std::cout << "Enter initial population: ";
    std::cin >> initialPopulation;
    
    std::cout << "Enter number of days: ";
    std::cin >> days;
    
    // Calculating the population after x days using the formula
    int populationAfterXDays = initialPopulation * pow(3, days);
    
    // Displaying the result
    std::cout << "Population after " << days << " days: " << populationAfterXDays << std::endl;
    
    return 0;
}
