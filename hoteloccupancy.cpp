#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

void calculateOccupancyRate(const string& filename) {
    ifstream inputFile(filename);
    if (!inputFile) {
        cerr << "Error: Could not open file " << filename << endl;
        return;
    }

    vector<int> floorOccupancy;
    vector<int> floorTotalRooms;

    int totalOccupied = 0;
    int totalRooms = 0;

    string line;
    int room;
    while (getline(inputFile, line)) {
        istringstream stream(line);
        int floorOccupied = 0;
        int floorRooms = 0;

        while (stream >> room) {
            if (room == -1) break;
            floorRooms++;
            if (room == 1) floorOccupied++;
        }

        floorOccupancy.push_back(floorOccupied);
        floorTotalRooms.push_back(floorRooms);

        totalOccupied += floorOccupied;
        totalRooms += floorRooms;
    }

    inputFile.close();

    // Display occupancy table
    cout << "Floor\tOccupied Rooms\tTotal Rooms\tOccupancy Rate (%)" << endl;
    for (size_t i = 0; i < floorOccupancy.size(); ++i) {
        double floorRate = (static_cast<double>(floorOccupancy[i]) / floorTotalRooms[i]) * 100.0;
        cout << i + 1 << "\t" << floorOccupancy[i] << "\t\t" << floorTotalRooms[i] << "\t\t" << fixed << setprecision(1) << floorRate << "\n";
    }

    // Display overall occupancy rate
    double overallRate = (static_cast<double>(totalOccupied) / totalRooms) * 100.0;
    cout << "\nOverall Occupancy Rate: " << fixed << setprecision(1) << overallRate << "%" << endl;
}

int main() {
    string filename = "occupants.txt";
    calculateOccupancyRate(filename);
    return 0;
}