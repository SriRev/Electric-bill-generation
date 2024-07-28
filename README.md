# Login-Based Electric Bill Generation System

## Overview

This C program implements a simple yet effective login-based electric bill generation system. It allows users to register, login, and calculate their electric bills based on units consumed. The system is designed with simplicity and ease of use in mind, making it suitable for small-scale utility management or educational purposes.

## Features

- User Registration: New users can create accounts with unique usernames and passwords.
- Secure Login: Registered users can access the system using their credentials.
- Bill Calculation: Calculates electric bills based on a tiered pricing structure.
- Multi-User Support: Capable of handling multiple user accounts.
- Input Validation: Basic checks to ensure data integrity and prevent common errors.

## Technical Details

- Language: C
- Compilation: Compatible with standard C compilers (e.g., GCC)
- Data Structure: Uses arrays to store user information in memory

## Usage

1. Compile the program using a C compiler.
2. Run the executable.
3. Choose from the following options:
   - Register a new user account
   - Login with existing credentials
   - Exit the program
4. After successful login, enter the number of units consumed to calculate the bill.

## Bill Calculation Logic

The system uses a tiered pricing structure:
- First 100 units: $1 per unit
- Next 100 units: $1.5 per unit
- Beyond 200 units: $2 per unit

## Security Considerations

- Passwords are stored in plaintext. In a production environment, implement proper encryption.
- The system uses in-memory storage and does not persist data between runs.

## Limitations

- Maximum user capacity is set to 100 (adjustable in the code).
- No data persistence between program executions.
- Basic input validation; may need enhancement for production use.

## Future Enhancements

- Implement file-based or database storage for user data persistence.
- Enhance security with password hashing and salting.
- Add administrative features for user management.
- Implement more robust error handling and input validation.
