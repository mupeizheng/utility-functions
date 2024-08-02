#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

void findCommonLines(const string& outputFile, const vector<string>& inputFiles) {
    unordered_map<string, int> lineCounts;
    vector<string> lineOrder;
    int fileCount = inputFiles.size();

    for (const auto& inputFile : inputFiles) {
        ifstream infile(inputFile);
        if (!infile.is_open()) {
            cerr << "Could not open the file " << inputFile << endl;
            continue;
        }

        string line;
        while (getline(infile, line)) {
            // Use the entire line as the key
            if (lineCounts[line] == 0) {
                lineOrder.push_back(line);
            }
            lineCounts[line]++;
        }
        infile.close();
    }

    ofstream outfile(outputFile);
    if (!outfile.is_open()) {
        cerr << "Could not open the output file " << outputFile << endl;
        return;
    }

    for (const auto& key : lineOrder) {
        if (lineCounts[key] == fileCount) {
            outfile << key << endl;
        }
    }

    outfile.close();
}

int main() {
    string outputFile = "D:\\soft\\RProjects\\FN\\result";
    vector<string> inputFiles = {
        "D:\\soft\\RProjects\\FN\\ASVCLR_num_stat_private_benchmark",
        "D:\\soft\\RProjects\\FN\\cuteSV_num_stat_private_benchmark",
        "D:\\soft\\RProjects\\FN\\DeBreak_num_stat_private_benchmark",
        "D:\\soft\\RProjects\\FN\\pbsv_num_stat_private_benchmark"
    };

    findCommonLines(outputFile, inputFiles);
    cout << "Finish" << endl;
    return 0;
}
