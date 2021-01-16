#include <vector>
#include <string>

const std::vector<char> alphabet = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 
                                    'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

std::vector<int> solve(std::vector<std::string> arr){  
    std::vector<int> result;
    for (auto &string : arr) {
        result.push_back(0);
        for (size_t i = 0; i < string.length(); ++i) {
           if (string[i] == alphabet[i] or string[i] == alphabet[i] + 'A' - 'a') {
             result.back()++;
           }
        }
    }
    return result;
};
