# RooftopIQ Software Intern Assessment

Practical assessment solutions for the RooftopIQ Software Intern position.

**Language:** C  
**Compiler:** GCC

---

## How to Run

### Prerequisites
- GCC installed on your machine
- A terminal / command prompt

### Running a script

Navigate into the question's folder, compile, and run:

```bash
cd <folder_name>
gcc <filename>.c -o <filename>
./<filename>
```

**Example — Q1:**
```bash
cd hello
gcc hello.c -o hello
./hello
```

---

## Questions & Thought Process

### Q1 — Hello World (`hello/hello.c`)
A straightforward use of `printf` to print `"Hello, World!"` to the console.

---

### Q2 — Is Even (`is_even/is_even.c`)
Uses the modulo operator: if `n % 2 == 0`, the number is even and the function returns `true`, otherwise `false`.

---

### Q3 — Greater of Two (`greaterOfTwo/greater_of_two.c`)
Since `if`, ternary operators, and `max()` are disallowed, I used **bit manipulation** to determine the larger value.

The idea: subtract `y` from `x` to get `diff`, then extract the sign bit by right-shifting `diff` by 63 bits. The sign bit is `0` if `x >= y` and `1` if `x < y`. The result is then computed as `x - sign * diff` — when `sign = 0` this returns `x`, and when `sign = 1` it returns `x - diff`, which equals `y`.

*Alternative considered:* Using `abs()` arithmetic — but bit manipulation is more low-level and avoids any standard library dependency.

---

### Q4 — Count Digit 3 (`count_digit/count_digit.c`)
Uses **recursion** to process each digit. On each call, the last digit is checked with `n % 10`. If it equals `3`, the count increments. The function then recurses with `n / 10` until `n` reaches `0`.

---

### Q5 — String Reverse (`string_rev/string_rev.c`)
Iterates from the last character of the string to the first using a loop, building the reversed string by index. No standard library reversal methods are used.

*Alternative considered:* Two-pointer in-place swap — equally valid, but iterating from the end into a new buffer felt more readable.

---

### Q6 — Second Largest (`getSecondLargest/get_second_largest.c`)
Uses a **single-pass** approach tracking two variables: `largest` and `second_largest`. For each element, if it exceeds `largest`, `second_largest` is updated to the old `largest` and `largest` is updated. If the element is strictly between the two (i.e. not a duplicate of `largest`), only `second_largest` is updated.

Duplicates equal to the current largest are skipped to ensure uniqueness. If all elements are identical, `second_largest` remains unset and the edge case is handled accordingly.

*Alternative considered:* Quicksort then pick index `n-2` — O(n log n). The single-pass O(n) solution is more efficient and equally readable.

---

### Q7 — FizzBuzz (`fizzbuzz/fizzbuzz.c`)
Iterates from 1 to 100. For each number, divisibility by 3 and 5 is checked first (FizzBuzz), then by 3 alone (Fizz), then by 5 alone (Buzz), otherwise the number is printed. Standard conditionals, no external libraries.

---

### Q8 — Div / Mod (`div_mod/div_mod.c`) *(Bonus)*
Implements integer division and remainder using **repeated subtraction**. Sign handling is done upfront: if exactly one of `x` or `y` is negative, the quotient is negative. If `x` is negative, the remainder is negative. The algorithm works on absolute values and applies the sign at the end.

---

### Q9 — First Unique Character (`firstUniqChar/first_uniq_char.c`) *(Bonus)*
Uses a **two-pass** approach with a frequency array of size 128 (one slot per ASCII character). The first pass counts occurrences of each character. The second pass iterates through the string in order and returns the first character with a count of `1`. Returns `NULL` if none exists.

---

### Q10 — Simple Stack (`simple_stack/simple_stack.c`) *(Bonus)*
Implemented using a **singly linked list** rather than a fixed-size array. Each node holds a value and a pointer to the next node. Push adds a new node at the head, pop removes from the head, and peek reads the head without removing it. A `size` tracker is maintained throughout.

*Alternative considered:* Array with a top index — simpler, but requires a fixed capacity. The linked list approach is more flexible with no predefined size limit.

---