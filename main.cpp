/* Peter Nguyen
   Dr T
   Programming Fundamentals II
   13/3/19
   Proportional Budget
*/

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include "Input_Validation_Extended.h"
#include "monthlyBudgetClass.h"
#include "functions.h"

using namespace std;


int main() {
  
  vector<double> income;
  vector<double> expenses;
  double incomeTotal = 0.00, expenseTotal = 0.00;
  int p1Percent = 0, p2Percent = 0, choice = 5;
  vector<MonthlyBudget> person(2);
  vector<string> expenseList = {"Mortgage/Rent","Electric","Gas (Home)","Water","Savings", "Entertainment", "Clothes", "Shoes", "Vending Machine","Credit Card Payments", "Car Payments", "Car Insurance", "Car Maintenance", "Car Gas", "School Boooks", "Food - Groceries", "Food - Dining Out", "Cleaning Supplies", "Personal Care", "Charity", "Day Care", "Pet Care", "Cell Phone", "Internet","Cable/Sat","Streaming Services", "Amazon.com"};

  splashScreen(income, expenses, incomeTotal, expenseTotal, p1Percent, p2Percent, expenseList);
  
  person[0].setValues(expenses, p1Percent);
  person[1].setValues(expenses, p2Percent);
  
  do{
    string colorB = "\x1b[94;1m";
    string colorR = "\x1b[31;1m";
    string reset = "\x1b[0m";

    showBudget(person[0], person[1], income, expenses, expenseList, p1Percent, p2Percent);
    cout << endl << endl;
    showMenu();
    
    choice = validateInt(choice);
    if(choice > 4){
      do{
      cout << colorR << "ERROR: " << choice << " is not a valid choice" << reset << endl;
      cout << "Please make a choice: " << colorB;
      choice = validateInt(choice);
      cout << reset;
      } while (choice > 4);
    } 

    cout << "\033[2J\033[1;1H";
    showBudget(person[0], person[1], income, expenses, expenseList, p1Percent, p2Percent);
    cout << endl << endl;
    handleOption(choice, income, expenses, expenseList, p1Percent, p2Percent);
    if (choice == 4){
      exportFile(person[0], person[1], income, expenses, expenseList, p1Percent, p2Percent);
    }
    cout << "\033[2J\033[1;1H";
  } while (choice != 0);
  cout << "Goodbye...";
}