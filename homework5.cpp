#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <mutex>
#include <chrono>
#include <vector>
#include "converter.h"
using namespace std;

static Converter conv;
void writeToFile(string* result, int number) {
    result->append(conv.intToString(number));
    result->append(" ");
}

int main()
{
    conv = Converter();
    std::cout << "Enter a file name: ";
    std::string filename;
    std::cin >> filename;
    std::ifstream in;
    in.open(filename);

    bool success = false;
    while (!success) {
        if (in.is_open()) {
            success = true;
        }
        if (!success) {
            std::cout << "File does not exist. Please, try again: ";
            std::cin >> filename;
            in.open(filename);
        }
    }


    string line;
    int number, mod;
    vector<int> tasks;
    while (in >> line) {
        try {
            try {
                number = std::stoi(line);
            }
            catch (std::logic_error) {
                throw exception();
            }
            if (line.size() % 2 != 0) {
                throw exception();
            }
            while (number > 0) {
                mod = number % 100;
                number /= 100;
                if (conv.code_dictionary.find(mod) == conv.code_dictionary.end()) throw exception();
            }
            tasks.push_back(std::stoi(line));
            tasks.push_back(0);
        }
        catch (exception e) {
            // interrupt all
            in.close();
            cout << "Invalid data! Conversion stopped.";
            return 0;
        }
    }
    in.close();
    std::ofstream out;
    out.open("out.txt");
    string result = "";
    std::mutex result_mutex;
    thread treads[256];

    for (int i = 0; i < tasks.size(); ++i)
    {
        result_mutex.lock();
        thread th(writeToFile, &result, tasks[i]);
        treads[i] = std::move(th);
        treads[i].join();
        result_mutex.unlock();
    }
    
    out << result;

    std::cout << "File decryption finished successfully. Output file: " << "out.txt" << std::endl;
    return 0;
}