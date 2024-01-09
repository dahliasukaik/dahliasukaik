[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/LgzAViJR)
# Homework 5: Implementing Tree Traversl Algorithms
In this homework assignment, you will implement Depth Wise and Breadth Wise Tree Traversal algorithms.
- Depth Wise
    1. InOrder
    2. PreOrder
    3. PostOrder
- Breadth Wise

For better understanding of how you can implement these algorithms, I have already added the code for `InOrder` traversal. (Feel free to change it if you want)

Your task will be to implement other functions defined in cpp files, located under src folder.
1. _preorder(TreeNode* node, vector<int> answer)
2. _postorde(TreeNode* node, vector<int> answer)
3. _breadth_first(TreeNode* node, vector<int> answer)


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
git clone https:github.com/csuf-cpsc335/homework5-username.git
```
make sure that you change the `username` in the link above, 
e.g. if I want to clone my homework5, my command will be
```bash
git clone https:github.com/csuf-cpsc335/homework5-HarinKhakhi.git
```

3. **Navigate to the Homework Repository**: Move into the directory for this specific homework assignment:
```bash
cd homework5-username
```

4. **Implement Traversal Algorithms**: In `src` folder, you will find files named `depth_first.cpp`, `breadth_first.cpp`. Your task is to finish implementing functions defined in those files.  <br>
The functions definitions are already defined in `src/tree_algorithms.h`. Your task is to implement the functions in their respective files in `src` folder. <br>
**DO NOT** change the files in any other folder.

## Testing Guidelines
Once you have successfully implemented algorithms, follow these steps to see if your implementation is correct.

### Run Tests
`test` folder contains `grader.cpp` file, which will run your test. `input_generator.cpp` and `tests_generator.cpp` files will generate input set to test your implementations. (You do not need to understand the code in these files). <br>
To run the test, go to `homework5-username` directory (if you are in `src` folder, you need to go back) and run the command
```bash
g++ -std=c++11 -I/src ./src/*.cpp ./test/*.cpp -o grader
```
If your code compiles successfully, you will have a `grader` file in your `homework5-username` folder.
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
