#define GET_FOR_EACH_MACRO(_1,_2,_3,_4,_5,NAME,...) NAME
#define FOR_EACH(action, ...) GET_FOR_EACH_MACRO(__VA_ARGS__, FOR_EACH_5, FOR_EACH_4, FOR_EACH_3, FOR_EACH_2, FOR_EACH_1)(action, __VA_ARGS__)

#define FOR_EACH_1(action, x) action(x)
#define FOR_EACH_2(action, x, ...) action(x); FOR_EACH_1(action, __VA_ARGS__)
#define FOR_EACH_3(action, x, ...) action(x); FOR_EACH_2(action, __VA_ARGS__)
#define FOR_EACH_4(action, x, ...) action(x); FOR_EACH_3(action, __VA_ARGS__)
#define FOR_EACH_5(action, x, ...) action(x); FOR_EACH_4(action, __VA_ARGS__)

#define PRINT(x) cout << x << endl

int main() {
    FOR_EACH(PRINT, 1, 2, 3);
    return 0;
}
