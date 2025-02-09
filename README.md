CS213 Object Oriented Programming - Assignment 3
Table of Contents
Overview
Project Structure
Part 1: Problem Solving
Part 2: OOP Design and Development
Game Descriptions
How to Run
Contributors
Overview
This project is divided into two parts:

1-Problem Solving: Implementation of individual problems from Sheet 3 in C++.
2-OOP Design and Development: Extension of a generic board game framework to create various Tic-Tac-Toe variations.
The project demonstrates OOP principles such as inheritance, polymorphism, and code reuse by building different board games on top of an existing framework.

Project Structure
The repository contains the following:

Part 1: Problem Solving
Each problem is solved in a separate C++ file, using standard C++ and STL (no third-party libraries).
File naming convention: A3_SheetPbXX_YourID.cpp where XX is the problem number.
Each team member is responsible for solving specific problems from Sheet 3:
Smallest ID: Problems 1 and 4
Middle ID: Problems 2 and 5
Largest ID: Problems 3 and 6

Part 2: OOP Design and Development
The OOP section of the project extends a generic board game framework to implement three Tic-Tac-Toe variations:
-Pyramic Tic-Tac-Toe: A pyramid-shaped board with three-in-a-row as the winning condition.
-Four-in-a-row: A 7x6 grid where players mark the lowest possible square in each column. The goal is to form a line of four.
-5x5 Tic-Tac-Toe: Played on a 5x5 grid. Players aim to form multiple three-in-a-row sequences.

How to Run
To run the project:

Clone the repository:
git clone https://github.com/your-username/CS213-OOP-Assignment3.git

Navigate to the relevant part (problem solving or OOP game) and compile the C++ files:
g++ A3_SheetPbXX_YourID.cpp -o problem_solution
./problem_solution
For the OOP section, compile the game files and run the game:
g++ GameManager.cpp X_O_App.cpp RandomPlayer.cpp -o xo_game
./xo_game
Contributors
-Reem Ahmed 
-Mariam Assem 
-Ganna Mohammed
