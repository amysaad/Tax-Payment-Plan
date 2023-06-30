
# Author

Name: Amy Saad

# Project Title

Title: Greedy vs Dynamic Algorithm Tax Payment Plan Program

Use/purpose of project: The purpose of this project is to use both greedy and dynamic programming algorithms to determine the best payment plan for a given tax due amount. It is designed to help users decide how to split their tax payments into different denominations of bills.



# Description

Overview of use: This project provides a C++ implementation to calculate how to split a given tax amount using predefined bill denominations: The Greedy Approach, which selects the largest possible denomination repeatedly until the due amount is met. The Dynamic Programming Approach, which builds a solution progressively ensuring the minimum number of bills is used for any amount.



# Directories and Files

- main.cpp: This file contains the main logic of the application, including user interface and integration of the payment plan algorithms



# Dependencies

- C++ compiler: C++ compiler installed on system to compile the source code

- Standard Template Library (STL): The program utilizes standard C++ libraries

- Compatible with various operating systems (Windows, macOS, Linux, etc)



# Installing / Compiling

- Download the project from the repository to your computer

- Open the project in JetBrains CLion IDE

- Make sure that CLion and CMake build are updated to the most recent version

- Ensure that you have a C++ compiler and Standard Template Library (STL) installed

- Build the project using the CMakeLists.txt file


# Executing Program

- Enter your name or the name you want to use

- Enter the tax due amount 

- The program will display the payment plan tables

- Enter your preferred payment plan

Sample input:

Welcome to the IR$ of Banana Republic! 
Please enter your name: Amy 
What is your tax $$$ due? 98223

Plan 1: The Greedy Approach
Tax Due: $  98223
                    Bills                Num                  Subtotal
                      $95000   x     1 = $  95000                   $  95000
                      $32001   x     0 = $      0                   $  95000
                      $ 5001   x     0 = $      0                   $  95000
                      $  701   x     4 = $   2804                   $  97804
                      $  101   x     4 = $    404                   $  98208
                      $    1   x    15 = $     15                   $  98223

Total number of bills needed: 1 + 0 + 0 + 4 + 4 + 15 = 24
—-----------------------------------------------------------------
Plan 2: The Dynamic Programming Approach
Tax Due: $  98223
                    Bills                Num                  Subtotal
                      $95000   x     0 = $      0                   $      0
                      $32001   x     3 = $  96003                   $  96003
                      $ 5001   x     0 = $      0                   $  96003
                      $  701   x     3 = $   2103                   $  98106
                      $  101   x     1 = $    101                   $  98207
                      $    1   x    16 = $     16                   $  98223

Total number of bills needed: 0 + 3 + 0 + 3 + 1 + 16 = 23
—-----------------------------------------------------------------
Which payment plan do you want to choose (1 or 2)? 2
Dear Amy , thank you for paying your tax ON TIME!
—-----------------------------------------------------------------

Process finished with exit code 0



# Test Cases

Test Case 1: Exact Denomination 

- Input:

Welcome to the IR$ of Banana Republic! 
Please enter your name: Amy
What is your tax $$$ due? 95000

- Greedy Output: 1 $95000 bill

- Dynamic Output: 1 $95000 bill


Test Case 2: Small Amount

- Input:

Welcome to the IR$ of Banana Republic! 
Please enter your name: Amy
What is your tax $$$ due? 102

- Greedy Output: 1 $101 bill, 1 $1 bill

- Dynamic Output: 1 $101 bill, 1 $1 bill


Test Case 3: Large Amount 

- Input: 

Welcome to the IR$ of Banana Republic! 
Please enter your name: Amy
What is your tax $$$ due? 200000


- Greedy Output: 2 $95000 bills, 1 $5001 bill, 7 $701 bills, 92 $1 bills

- Dynamic Output: 6 $32001 bills, 1 $5001 bill, 4 $701 bills, 1 $101 bill, 88 $1 bills



# Approach Evaluation

- The dynamic programming approach often yields a payment plan with fewer bills, making it generally more efficient regarding the number of transactions. However, it is computationally and spatially more demanding than the greedy approach. However, this is not always the case, for amounts that align closely with high denominations, both approaches perform similarly well. The distinction becomes significant when dealing with amounts that do not align with available bill denominations.


# Version

CLion Info: CLion 2023.3.4, build CL-233.14475.31. Copyright JetBrains s.r.o., (c) 2000-2024

CMake Info: Version 3.29.0


# License

# Acknowledgements
