#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<double> exam_scores {98.5, 95.0, 92.5, 90.0, 88.5, 85.0, 82.5};
    double target_score = 90.0;
    
    auto it = std::upper_bound(exam_scores.begin(), exam_scores.end(), target_score);
    if (it != exam_scores.end()) {
        std::cout << "The first score greater than " << target_score
                  << " is " << *it << std::endl;
    } else {
        std::cout << "No score found greater than " << target_score << std::endl;
    }
    
    return 0;
}
