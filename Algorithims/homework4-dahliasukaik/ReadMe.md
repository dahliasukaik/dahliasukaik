# Homework 4: Implementing Randomized Selection
In this homework assignment, you will implement randomized selection sort algorithm that uses randomized partition.
1. Randomized Partition
2. Randomized Selection

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
git clone https:github.com/csuf-cpsc335/homework4-username.git
```
make sure that you change the `username` in the link above, 
e.g. if I want to clone my homework4, my command will be
```bash
git clone https:github.com/csuf-cpsc335/homework4-HarinKhakhi.git
```

3. **Navigate to the Homework Repository**: Move into the directory for this specific homework assignment:
```bash
cd homework4-username
```

4. **Implement Sorting Algorithms**: In `src` folder, you will find files named `1_partition.cpp`, `2_selection.cpp`. Your task is to finish implementing those functions.  <br>
The functions definitions are already defined in `src/searching_algorithms.h`. Your task is to implement the functions in their respective files in `src` folder. <br>
**DO NOT** change the files in any other folder.

## Testing Guidelines
Once you have successfully implemented both sorting algorithms, follow these steps to see if your implementation is correct.

### Run Tests
`test` folder contains `grader.cpp` file, which will run your test. `input_generator.cpp` file will generate input set to test your implementations. (You do not need to understand the code in these files). <br>
To run the test, go to `homework4-username` directory (if you are in `src` folder, you need to go back) and run the command
```bash
g++ -std=c++11 -I/src ./src/*.cpp ./test/*.cpp -o grader
```
If your code compiles successfully, you will have a `grader` file in your `homework4-username` folder.
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
