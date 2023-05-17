#include<iostream>
using namespace std;

// This macro defines the loop body.
#define LOOP_BODY(n) cout << n << endl;

// This macro defines the loop.
#define LOOP(count, body) LOOP_##count(body)

// This macro defines the loop for 3 iterations.
#define LOOP_3(body) body(3) LOOP_2(body)

// This macro defines the loop for 2 iterations.
#define LOOP_2(body) body(2) LOOP_1(body)

// This macro defines the loop for 1 iteration.
#define LOOP_1(body) body(1)

int main() {
    // This is how you use the loop macro.
    LOOP(3, LOOP_BODY);
    return 0;
}
#define LOOP
#ifdef LOOP
#include <iostream>

#define CONCAT(x, y) x##y
#define BRANCH_TRUE(x, y) x
#define BRANCH_FALSE(x, y) y
#define CONDITIONAL(c, x, y) CONCAT(BRANCH_, c) (x, y)

int main() {
    std::cout << CONDITIONAL(TRUE, "Hello", "World") << std::endl;
    std::cout << CONDITIONAL(FALSE, "Hello", "World") << std::endl;
    return 0;
}

#endif