# 🌀 Push_Swap - 42 School Project

## 🌟 Overview
      Push_Swap is a C programming project from the 42 School curriculum. It challenges you to sort a stack of integers       using a limited set of operations and two stacks (a and b). The goal is to find an efficient algorithm to output the      shortest sequence of instructions to sort the stack.
      The program takes a list of integers as arguments and prints the operations (e.g., sa, pb, ra) needed to sort them     in ascending order.
### Example:
    ./push_swap 2 1 3 6 5 8
    Output might be: sa pb ra pa.
## ✨ Features
    - Sorting Algorithm: Sorts integers using two stacks.
    - Operation Set: Supports sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr.
    - Bonus (if implemented):
        Checker program (checker) to validate the sorting instructions.
## 🚀 Installation
    - Clone the repo:
        git clone https://github.com/b-kolani/push_swap.git
    - Enter the directory:
        cd push_swap
    - Compile:
        make
    - Run make bonus for the checker program (if included).
## 🖥️ Usage
    Run Push_Swap with a list of integers:
          ./push_swap 3 2 1 5 4
    With Checker (bonus):
          ./push_swap 3 2 1 5 4 | ./checker 3 2 1 5 4
    **Outputs OK if sorted correctly, KO if not,or Error if an error occurs.**

## 📂 Project Structure
    - push_swap.c: Main logic for sorting algorithm
    - utils files:	Helper functions (e.g., parsing)
    - Makefile:	Build rules for compilation

## 🎓 Learning Outcomes
    - Developed an efficient sorting algorithm for constrained conditions.
    - Mastered stack data structures and operations.
    - Improved skills in algorithm optimization and debugging.

## ⚙️ Requirements
    - OS: UNIX-based (Linux, macOS).
    - Compiler: GCC or similar.
    - libft.

## 👤 Author
    [Kolani Biman / b-kolani]
