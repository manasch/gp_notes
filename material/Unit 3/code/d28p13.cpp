#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Define the matrix and the vector
    std::vector<std::vector<int>> matrix{ {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    std::vector<int> vector{ 2, 3, 4 };

    // Define the output vector with the same size as the number of rows in the matrix
    std::vector<int> output(matrix.size());

    // Perform the matrix to vector multiplication
    std::transform(matrix.begin(), matrix.end(), output.begin(),
        [&](const std::vector<int>& row) {
            int sum = 0;
            for (int i = 0; i < vector.size(); i++) {
                sum += row[i] * vector[i];
            }
            return sum;
        });

    // Print the output vector
    for (auto i : output) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
