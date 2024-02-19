#include <fstream>
#include <stdexcept>
#include <iostream>
#include "../headers/Writer.h"
using namespace std;

void Writer::write(std::string &filePath, std::vector<GeomVector> &vectors)
{
    std::ofstream outFile(filePath);

    if (!outFile.is_open())
    {
        cout << "Error while opening the file for writing." << std::endl;
    }

    for (const GeomVector &vector : vectors)
    {

        outFile << 0.0 << " " << 0.0 << " " << 0.0 << endl;
        outFile << vector.X() << " " << vector.Z() << " " << vector.Z() << endl;
    }
    outFile.close();
}
