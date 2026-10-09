#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <string>
#include <vector>

#include <chrono>

int main(int argc, char* argv[]) {
    std::string filename = "data.txt";
    
    if (argc > 1) {
        filename = argv[1];
    }
    
    std::ifstream inputFile(filename);
    
    auto start_time = std::chrono::high_resolution_clock::now();


    if (!inputFile.is_open()) {
        std::cerr << "Error opening file \n";
        return 1;
    }
    
    std::map<std::string, std::vector<float>, std::less<std::string>> station_data{};
    std::map<std::string, float> station_mins{};
    std::map<std::string, float> station_maxs{};

    std::string line;
    
    while (std::getline(inputFile, line)) {
        size_t delimiter_pos = line.find(';');

        if (delimiter_pos == std::string::npos) {
            break;
        }

        std::string station_name = line.substr(0, delimiter_pos);
        float temperature = std::stof(line.substr(delimiter_pos + 1));
        station_data[station_name].push_back(temperature);

        if (station_mins.find(station_name) == station_mins.end() || temperature < station_mins[station_name]) {
            station_mins[station_name] = temperature;
        }
        if (station_maxs.find(station_name) == station_maxs.end() || temperature > station_maxs[station_name]) {
            station_maxs[station_name] = temperature;
        }
    }

    inputFile.close();

    std::ofstream outputFile("output.txt");

    if (!outputFile.is_open()) {
        std::cerr << "Error opening output file \n";
        return 1;
    }

    for (const auto& [station_name, temperatures] : station_data) {
        float sum = 0.0f;
        for (float temp : temperatures) {
            sum += temp;
        }
        float average = sum / temperatures.size();
        outputFile << std::fixed << std::setprecision(1) << station_name << ";" << station_mins[station_name] << ";" << average << ";" << station_maxs[station_name] << "\n";
    }

    auto end_time = std::chrono::high_resolution_clock::now();
    auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);

    std::cout << "Elapsed time: " << elapsed_time.count() << " ms\n";

    return 0;
}