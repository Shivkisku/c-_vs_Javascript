#include <iostream>
#include <cctype> // For toupper and tolower functions
#include <algorithm> // For transform function

int main() {
    // Initialize the strings
    std::string text1 = "HellO WorlD";
    std::string text2 = "hello world";

    // Convert text1 to uppercase and lowercase
    std::transform(text1.begin(), text1.end(), text1.begin(), ::toupper);
    std::transform(text1.begin(), text1.end(), text1.begin(), ::tolower);

    // Check if text2 is in uppercase
    bool isUpperCase = std::all_of(text2.begin(), text2.end(), ::isupper);

    // Find the index of 'W' in text1
    size_t indexW = text1.find("W");

    // Replace "HellO" with "Hi" in text1
    size_t replacePos = text1.find("HellO");
    if (replacePos != std::string::npos) {
        text1.replace(replacePos, 5, "Hi");
    }

    // Print the results
    std::cout << text1 << std::endl;
    std::cout << text2 << std::endl;
    std::cout << std::boolalpha << isUpperCase << std::endl;
    std::cout << indexW << std::endl;
    std::cout << text1 << std::endl;

    return 0;
}
