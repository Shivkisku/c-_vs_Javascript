#include <iostream>

// Function to print a triangle with a specified height
void printTriangle(int height) {
    for (int i = 1; i <= height; ++i) {
        std::string row = "";
        // Add spaces
        for (int j = height - i; j > 0; --j) {
            row += " ";
        }
        // Add asterisks
        for (int k = 1; k <= i * 2 - 1; ++k) {
            row += "*";
        }
        std::cout << row << std::endl;
    }
}

int main() {
    // Specify the height of the triangle
    const int triangleHeight = 5;

    // Print the triangle
    printTriangle(triangleHeight);

    return 0;
}
