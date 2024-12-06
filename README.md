# 💰 Expense Tracker using C Programming

## 🚀 Overview
A simple console-based expense tracking application developed in C to help you manage personal finances efficiently.

## ✨ Features
- 📝 Add Expenses
- 📊 View Expense List
- 🗑️ Delete Expenses
- 💲 Generate Expense Summary
- ✅ Input Validation

## 🛠️ Prerequisites
- GCC Compiler
- Basic C programming environment

## 💻 Installation

### Compilation
```bash
gcc expense_tracker.c -o expense_tracker
```

### Run
```bash
./expense_tracker
```

## 📂 Project Structure
```
expense_tracker/
├── expense_tracker.c     # Main source code
└── README.md             # Project documentation
```

## Usage
When you run the application, you'll see a menu with the following options:

1. **Add Expense**: 
   - Enter expense details
   - Provide title, category, date, and amount
   - Date format: DD/MM/YYYY

2. **View Expenses**: 
   - See a list of all recorded expenses
   - Displays ID, title, category, date, and amount

3. **Delete Expense**: 
   - Remove an expense by its unique ID
   - Select the ID from the expense list

4. **Expense Summary**: 
   - View total expenses across all recorded entries

5. **Exit**: 
   - Close the application

### Example Workflow
```
--- Expense Tracker ---
1. Add Expense
2. View Expenses
3. Delete Expense
4. Expense Summary
5. Exit
Enter your choice: 1

Enter Expense Title: Groceries
Enter Category: Food
Enter Date (DD/MM/YYYY): 15/12/2024
Enter Amount: 55.30
Expense added successfully!
```

## Code Structure

### Key Components
- **Expense Structure**: 
  - Stores individual expense details
  - Includes ID, amount, title, category, and date

- **Core Functions**:
  - `addExpense()`: Record new expenses
  - `viewExpenses()`: Display expense list
  - `deleteExpense()`: Remove expenses
  - `expenseSummary()`: Calculate total expenses

### Limitations
- In-memory storage (expenses reset on program exit)
- Limited to 100 total expenses
- Basic input validation

## Potential Improvements
- Persistent file storage
- More advanced reporting
- Enhanced input validation
- Sorting and filtering expenses

## ## 🤝 Contributing
Contributions are welcome! Please follow these steps:
1. Fork the repository
2. Create a feature branch
3. Commit your changes
4. Push to the branch
5. Create a pull request

## License
This project is open-source. Consider adding an appropriate license file.

## Acknowledgments
- C Programming Language
- GCC Compiler
- Open-source community

## 📞 Contact
For questions or suggestions, please open an issue in the repository.
