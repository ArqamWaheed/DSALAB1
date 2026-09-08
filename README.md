# DSALAB1

CS-250 Data Structures and Algorithms, Lab 1
Revisiting C++, version control and writing test cases.

Arqam Waheed, BSDS 3A

## Files

- hello.cpp - starter program from task 1
- utilities.h / utilities.cpp - add(a, b) from task 2
- task3.cpp - all indices of a key in an array
- task4.cpp - naive string pattern matching
- task5.cpp - pascal's triangle
- task6.cpp - mode of an array
- task7.cpp - strassen's matrix multiplication

Every task has its own test file with the main method, for example task3_test.cpp.

## Compiling

```
g++ task3.cpp task3_test.cpp -o task3_test
./task3_test
```

Same for task4 to task7.

## Some notes

- findAllIndices() fills an array given by the caller and returns how many indices it found.
- findPattern() returns 0 for an empty pattern and -1 when the pattern is not in the text.
- findMode() returns -1 if the array is empty, and the first value if two values are tied.
- Strassen only works for square matrices with size a power of 2, MAX is set to 8.

Status: all tasks done
