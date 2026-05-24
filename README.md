## Fraction OOP Exercis
---

### 1. Introduction
---
This project is a small OOP exercise for my course. It builds a `PhanSo` (fraction) class and shows how to work with fractions in a clean, object oriented way.

### 2. Tech Stack
---
- C++ (standard library: iostream, cmath)

### 3. Key Features
---
- Fraction class with numerator and denominator
- Automatic reduction using GCD and sign normalization
- Operator overloading for +, -, *, / and comparisons
- Input and output operators for easy console use
- Compound assignment and prefix/postfix increment

### 4. System Architecture (optional)
---
- Utility function: GCD (`ucln`) for fraction reduction
- Core class: `PhanSo` with constructors, reduction, and operator overloads
- I/O layer: stream operators `>>` and `<<`

### 5. Setup & Usage
---
This file only defines the fraction class and its operators. You can either:
1) Add your own `main()` to test, or
2) Include this file in another program.

Example usage:
```cpp
#include <iostream>

int main() {
	PhanSo a, b;
	std::cin >> a >> b;
	std::cout << (a + b) << "\n";
	return 0;
}
```

Compile example (if you add a `main()`):
```bash
g++ main.cpp -o app
./app
```

### 6. Contribution
---
- Use unaccented Vietnamese or English for variable and function names
- Follow Conventional Commits for new commits (e.g. `feat: add fraction compare`)
- Be careful with pointers and avoid memory leaks if you extend the project
