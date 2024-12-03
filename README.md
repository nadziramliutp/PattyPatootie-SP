# PATTY PATOOTIE BURGER-ORDERING-SYSTEM 
## TFB1013 Structured Programming : 1st Year 1st Semester

## Overview
This C++ console program simulates a burger ordering system for a fictional restaurant called "Patty Patootie Burger". It allows users to view a menu, place orders for various burger sets and extra items, and generates a receipt with the total cost.

## Features
- **Menu Display**: Displays a list of burger sets with prices (both as sets and à la carte) and extra items available.
- **Order Placement**: Allows users to choose between dining in or takeaway, select menu items, specify quantities, and choose additional items.
- **Receipt Generation**: Generates a detailed receipt showing ordered items, prices, and total amount due, including any applicable charges for takeaway orders.

## Components
### Functions
1. `displayWelcomeMessage()`: Displays a welcome message when the program starts.
2. `displayMenu()`: Prints the menu with burger options and their prices, as well as extra items available.
3. `displayDateTime()`: Shows the current date and time adjusted to Malaysia time (UTC+8).
   
### Structures
- `order`: Stores order type ('D' for dine-in, 'T' for takeaway) and associated charges.
- `menu`: Stores user choices for menu items, including type ('S' for set, 'A' for à la carte), and quantities.

### Main Function
- Initializes menu prices and handles user input for order type, menu selection, and quantities.
- Calculates total costs based on user selections and displays a comprehensive receipt.

### Usage
1. **Compile and Run**: Compile the program and run the executable. Ensure all necessary header files are included (`<iostream>`, `<cctype>`).
2. **Order Placement**: Follow on-screen prompts to select dining option, choose menu items, specify quantities, and optionally add extra items.
3. **Receipt Display**: After completing the order, the program generates and displays a detailed receipt with the total amount due.

### Notes
- Ensure valid inputs are provided to avoid errors. The program currently assumes correct user input for simplicity.
- Customize menu items, prices, and additional charges as needed for different restaurant configurations.
- Additional features such as customer management, payment processing, and error handling can be implemented for real-world applications.

## Future Enhancements
- Implement error handling for invalid inputs and edge cases.
- Add more functionalities like customer management and payment processing.
- Improve code structure and modularity for better readability and maintenance.
