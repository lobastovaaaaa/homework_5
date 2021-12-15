#include "Converter.h"
#include <string>

bool Converter::ifKey(int input) {
    if (code_dictionary.find(input) == code_dictionary.end()) {
        return false;
    }
    return true;
}

std::string Converter::intToString(int input) {
    int mod;
    string to_return = "";
    while (input > 0) {
        mod = input % 100;
        to_return = code_dictionary[mod] + to_return;
        input /= 100;
    }
    return to_return;
}