# Homework 3: Implementing Binary Search Variants
In this homework assignment, you will implement two of the variants of binary search algorithm.
1. Lower Bound
2. Upper Bound

## Getting Started

To begin working on this assignment, follow these steps:

1. **Login to Github**: The homework repository will be private, so to clone a private repository you first need to login in your terminal. \
Use following command to login.
```bash
gh auth login
``` 
You can install `gh` from [here](https://cli.github.com/).

2. **Clone the Repository**: Start by cloning this GitHub repository to your local machine using the following command:
```bash
git clone https:github.com/csuf-cpsc335/homework3-username.git
```
make sure that you change the `username` in the link above, 
e.g. if I want to clone my homework3, my command will be
```bash
git clone https:github.com/csuf-cpsc335/homework3-HarinKhakhi.git
```

3. **Navigate to the Homework Repository**: Move into the directory for this specific homework assignment:
```bash
cd homework3-username
```

4. **Implement Sorting Algorithms**: In `src` folder, you will find files named `1_lower_bound.cpp`, `2_upper_bound.cpp`. Your task is to finish implementing those functions.  <br>
The functions definitions are already defined in `src/searching_algorithms.h`. Your task is to implement the functions in their respective files in `src` folder. <br>
**DO NOT** change the files in any other folder.

## Testing Guidelines
Once you have successfully implemented both sorting algorithms, follow these steps to see if your implementation is correct.

### Run Tests
`test` folder contains `grader.cpp` file, which will run your test. `input_generator.cpp` file will generate input set to test your implementations. (You do not need to understand the code in these files). <br>
To run the test, go to `homework3-username` directory (if you are in `src` folder, you need to go back) and run the command
```bash
g++ -std=c++11 -I/src ./src/*.cpp ./test/*.cpp -o grader
```
If your code compiles successfully, you will have a `grader` file in your `homework3-username` folder.
Run the following command to run tests.
```bash
./grader
```

# Submission Guidelines
Make sure to test locally before submitting to the github.

1. **Commit Your Changes**: Use Git to commit your changes to your local repository
```bash
git add .
git commit -m "Submission"
```

2. **Push to Github**: Push your changes to your GitHub repository
```bash
git push
```

**Make sure to submit the homework before deadline, as github won't allow you to commit after the deadline has passed.**
