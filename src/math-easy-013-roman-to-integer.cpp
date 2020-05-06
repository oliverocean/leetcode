#include <iostream>
#include <unordered_map>

int romanToInt(std::string);

int main() {
    std::cout << "\n --- results --- \n";
    std::cout << "test 'III': " << romanToInt("III") << "\n";
    std::cout << "test : 'IV' : " << romanToInt("IV") << "\n";
    std::cout << "test : 'VI' : " << romanToInt("VI") << "\n";
    std::cout << "test : 'IX' : " << romanToInt("IX") << "\n";
    std::cout << "test : 'XI' : " << romanToInt("XI") << "\n";
    std::cout << "test : 'MCXII' : " << romanToInt("MCXII") << "\n";
    std::cout << "test : 'MDCLVI' : " << romanToInt("MDCLVI") << "\n";
    std::cout << "test : 'DXLIXIV' : " << romanToInt("DXLIXIV") << "\n";
    return 0;
}

int romanToInt(std::string s) {

    //if (s.empty()) { return 0; }

    std::unordered_map<char, int> map{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

    int result{map[s.back()]}; // faster to initialize with last char and start loop on 's.length() - 2'

    for (int i = static_cast<int>(s.length() - 2); i >= 0; --i) {
        map[s[i]] >= map[s[i + 1]] ? result += map[s[i]] : result -= map[s[i]];
    }

    return result;
}
