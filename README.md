# Advanced Banking System (C++)

A robust command-line banking application developed in C++ that simulates core banking operations with persistent data storage and user authentication. This project is designed using Object-Oriented Programming (OOP) principles to ensure modularity, scalability, and maintainability.

## Features
- Secure user authentication using PIN verification
- Deposit and withdrawal operations with input validation
- Persistent balance storage using file handling
- Transaction history tracking within the session
- Interactive menu-driven interface
- Error handling for invalid inputs and insufficient funds

## Technologies Used
- C++
- Standard Template Library (STL)
- File Handling (fstream)

## System Design
The application is built around a `BankAccount` class that encapsulates all banking operations, ensuring proper data abstraction and separation of concerns.

## How to Run
1. Compile the program:
   g++ main.cpp -o banking
2. Run the executable:
   ./banking

## Key Learning Outcomes
- Application of Object-Oriented Programming (encapsulation and abstraction)
- File I/O for data persistence
- Managing program state across executions
- Designing interactive console applications
- Writing clean, modular, and maintainable code

## Future Improvements
- Store transaction history in a file
- Support multiple user accounts
- Implement password encryption
- Add graphical user interface (GUI)

## Author
DonUserOn
