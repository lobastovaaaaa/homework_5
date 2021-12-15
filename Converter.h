#ifndef HOMEWORK_5_CONVERTER_H
#define HOMEWORK_5_CONVERTER_H
#include <map>
#include <string>
using namespace std;


class Converter {
public:
    map <int, std::string> code_dictionary = { { 20, "a"}, {12, "b"}, {49, "c"},
        { 43, "d"}, { 33, "e"}, { 44, "f"}, { 40, "g"}, { 27, "h"},
        { 37, "i"}, { 17, "j"}, { 38, "k"}, { 41, "l"}, { 22, "m"},
        { 11, "n"}, { 28, "o"}, { 25, "p"}, { 13, "q"}, { 49, "r"},
        { 24, "s"}, { 15, "t"}, { 16, "u"}, { 26, "v"}, { 46, "w"}, 
        { 14, "x"}, { 30, "y"}, { 23, "z"}, { 0, " "}};
    bool ifKey(int input);
    string intToString(int input);
};

#endif //HOMEWORK_5_CONVERTER_H