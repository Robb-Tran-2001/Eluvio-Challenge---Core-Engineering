#include <iostream>
#include <vector>
#include <string>
#include <fstream>
// #include "suffix.hpp"

//grabs each file's content into a vector of strings
void init(std::vector<std::string>& files) {
    std::string name = "sample.";
    for(int i = 1; i <= 10; i++) {
        std::string path = name + std::to_string(i);
        std::cout << path << "\n";
        std::ifstream t(path);
        std::string str((std::istreambuf_iterator<char>(t)),
                 std::istreambuf_iterator<char>());
        files.push_back(str);
    }
    for(auto& i : files) {
        std::cout << i.length() << " \n";
    }
}

//recursive DP solution to the problem of common substring between 2 strings. i, j are the length of the 2 strings initially, represents indices
int solution_helper(std::string& str1, std::string& str2, int i, int j, int count) {
    if(i == 0 || j == 0) return count;
    if(str1[i - 1] == str2[j - 1]) {
        count = solution_helper(str1, str2, i - 1, j - 1, count + 1);
    }
    count = std::max(count, std::max(solution_helper(str1, str2, i, j - 1, 0), solution_helper(str1, str2, i - 1, j, 0)));
    return count;
}

//returns the solution in a vector order of (first file index, second file index, string length)
std::vector<int> sol(std::vector<std::string>& files) {
    std::vector<int> tup(3, 0);
    for(int i = 0; i < files.size(); i++) {
        for(int j = 0; j < files.size(); j++) {
            if(i != j) {
                int length = solution_helper(files[i], files[j], files[i].length(), files[j].length(), 0);
                if(length > tup[2])
                {
                    //printf("file1 %d : file2 %d : length %d\n", i, j, length);
                    tup[0] = i;
                    tup[1] = j;
                    tup[2] = length;
                } 
            }
        }
    }
    return tup;
}

int main() {
    std::vector<std::string> file_content;
    init(file_content);
    std::vector<int> result = sol(file_content);
    for(auto& i : result) std::cout << i << "\n";
    return 0;
}