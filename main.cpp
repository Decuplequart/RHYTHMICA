#include <iostream>       // cout, cerr
#include <fstream>        // ifstream
#include <string>         // string
#include <vector>         // vector
#include <unordered_map>  // unordered_map
#include <algorithm>      // transform など

int main() {
    std::ifstream file("_testwr_04_another.txt");

    if (!file) {
        std::cout << "ファイルを開けませんでした\n";
        return 1;
    }

    std::string line;

    while (std::getline(file, line)) {
        if (line.empty()) continue;

        if (line[0] != '#') continue;

        if (line.find("#TITLE ") == 0) {
            std::string title = line.substr(7);
            std::cout << "TITLE: " << title << "\n";
        }
        else if (line.find("#BPM ") == 0) {
            std::string bpmText = line.substr(5);
            std::cout << "BPM: " << bpmText << "\n";
        }
        else if (line.find("#WAV") == 0) {
            auto spacePos = line.find(' ');
            std::string wavID = line.substr(4, 2);
            std::string wavFile = line.substr(spacePos + 1);
            //書き直す
            std::cout << "WAV定義行: " << line << "\n";
        }
        else if (line.find(':') != std::string::npos) {
            std::cout << "譜面データ行: " << line << "\n";
        }
    }

    return 0;
}