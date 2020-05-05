#include <iostream>
#include <vector>
#include <unordered_map>
//#include <tclDecls.h>

std::string longestCommonPrefix(std::vector<std::string>&);


int main() {

    std::vector<std::string> setA {"flower","flow","flight", "flex", "florist"};
    std::vector<std::string> setB {"dog","cat","bird", "giraffe", "fish"};
    std::vector<std::string> setC;


    std::cout << "\n-------\n";
    std::cout << "Result A: " << longestCommonPrefix(setA);

    std::cout << "\n-------\n";
    std::cout << "Result B: " << longestCommonPrefix(setB);

    return 0;
}

// revised attempt
// 0ms runtime (100%), 8.9mb memory usage (62.90%)
std::string longestCommonPrefix(std::vector<std::string>& strs) {

    if (strs.empty()) return "";

    std::string target = strs[0];
    std::string prefix;

    for (int i = 0; i < target.length(); ++i) {
        for (int j = 1; j < strs.size(); ++j) {
            if (strs[j][i] != target[i]) {
                return prefix;
            }
        }
        prefix += target[i];
    }
    return prefix; // shouldn't end up here.
}


// initial attempt
// 4ms runtime (96.33%), 9mb memory usage (25.81%)
//std::string longestCommonPrefix(std::vector<std::string>& strs) {
//
//    if (strs.empty()) return "";
//
//    std::string target = strs[0];
//    std::string prefix;
//
//    for (int i = 0; i < target.length(); ++i) {
//        for (int j = 1; j < strs.size(); ++j) {
//            if (target[i] == strs[j][i]) {
//            } else {
//                return prefix;
//            }
//        }
//        prefix += target[i];
//    }
//    return prefix;
//}

