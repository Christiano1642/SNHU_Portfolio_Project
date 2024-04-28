#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5.0 / 9.0;
}

int main() {
    // Open the input file
    ifstream inputFile("FahrenheitTemperature.txt");

    // Check if the file opened successfully
    if (!inputFile) {
        cerr << "Unable to open input file." << endl;
        return 1;
    }

    // Open the output file
    ofstream outputFile("CelsiusTemperature.txt");

    // Check if the file opened successfully
    if (!outputFile) {
        cerr << "Unable to create output file." << endl;
        return 1;
    }

    string city;
    int temperatureFahrenheit;

    // Read data from input file and write converted data to output file
    while (inputFile >> city >> temperatureFahrenheit) {
        // Convert Fahrenheit to Celsius
        double temperatureCelsius = fahrenheitToCelsius(temperatureFahrenheit);

        // Write data to output file
        outputFile << city << " " << temperatureCelsius << endl;
    }

    // Close both input and output files
    inputFile.close();
    outputFile.close();

    return 0;
}
