```cpp
template<typename T>
bool eq(T a, T b) {
    return a == b;
}

int main() {
    cout << boolalpha;
    char a[] = "pes";
    char *b = a;
    char c[] = "pes";
    cout << eq(a, b) << endl;
    cout << eq(a, c) << endl;
}
```

Output is 
```
true
false
```

As the pointers are compared to see if they point to the same memory locaiton.

---

```cpp
template<typename T>
T what(T x) {
    return x * x;
}

int main() {
    int a[] = {5, 1, 4, 2, 3};
    // cout << what(a) << endl;
    cout << what(*a) << endl;
}
```

If commented out then it would give an error

---

```cpp
void what(int a[], int n) {
	for (int i = 0; i < n - 1; ++i) {
		a[i + 1] += a[i];
	}
}
```

- This is essentially a prefix sum array. To make it generic just add a template heading and also the component type the array should support is `+=`.

---

