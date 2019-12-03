#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include "Input_Validation_Extended.h"
#include "monthlyBudgetClass.h"
#include "functions.h"

using namespace std;

void splashScreen(vector<double> &income, vector<double> &expenses, double &incomeTotal, double &expenseTotal, int &p1Percent, int &p2Percent, vector<string> &expenseList){
  int i;
  double d;

  string clearScreen = "\033[2J\033[1;1H";
  string colorB = "\x1b[94;1m";
  string colorR = "\x1b[31;1m";
  string reset = "\x1b[0m";

  cout << clearScreen;
  cout << "Hello, how many incomes would you like to enter: " << colorB;
  i = validateInt(i);
  cout << endl;
  for(int n = 0; n < i; n++){
    cout << reset <<  "Enter income " << n+1 << ": " << colorB;
    d = validateDouble(d);
    income.push_back(d);
  }

  cout << reset << "Enter tips (0.00 if N/A): " << colorB;
  d = validateDouble(d);
  income.push_back(d);

  cout << reset << "Enter refund check (0.00 if N/A): " << colorB;
  d = validateDouble(d);
  income.push_back(d);

  cout << reset <<  "Enter Amazon refund (0.00 if N/A): " << colorB; // Assuming its an amazon refund. couldn't think of why else this would be in income.
  d = validateDouble(d);
  income.push_back(d);

  for(int i = 0; i < income.size(); i++){
   incomeTotal += income[i]; 
  }


  cout << clearScreen << reset;
  cout << "Enter expenses for the following (0.00 if N/A)" << endl;
  cout << endl;
  for(int i = 0; i < 27; i++){
    cout << reset << expenseList[i] << ": " << colorB;
    d = validateDouble(d);
    expenses.push_back(d);

  }
  for(int i = 0; i < 27; i++){
   expenseTotal += expenses[i]; 
  }
  cout << clearScreen << reset;
  cout << "Percentage Split" << endl;
  d = 0.0;
  do {
    cout << "\nEnter percentage for Person 1 (0-100): " << colorB;
    i = validateInt(i);
    if(i < 0 || i > 100){
      cout << colorR << "Number must be between 0 and 100" << reset;
    }
  } while (i < 0 || i > 100);
  p1Percent = i;
  p2Percent = 100 - i;
  cout << reset << "\nPerson 1: " << fixed << setprecision(2) << p1Percent << endl;
  cout << "Person 2: " << p2Percent << clearScreen;

}

void showMenu(){
  string clearScreen = "\033[2J\033[1;1H";
  string colorTeal = "\x1b[36;1m";
  string colorB = "\x1b[94;1m";
  string colorP = "\x1b[95;1m";
  string colorW = "\x1b[37;1m";
  string underline = "\x1b[0;4m";
  string underlineW = "\x1b[37;4m";
  string reset = "\x1b[0m";

  cout << colorTeal << "MENU" << reset << endl; 
  cout << "\n1. Change income" << endl;
  cout << "2. Change expenses" << endl;
  cout << "3. Change percentages" << endl;
  cout << "4. Export to .txt file" << endl;
  cout << "\n0. Exit program" << endl;
  cout << "Please make a choice: " << colorB;
}
void handleOption(int choice, vector<double> &income, vector<double> &expenses, vector<string> expenseList, int &p1, int &p2){
  string colorTeal = "\x1b[36;1m";
  string clearScreen = "\033[2J\033[1;1H";
  string colorB = "\x1b[94;1m";
  string colorR = "\x1b[31;1m";
  string reset = "\x1b[0m";
  
  cout << reset;
  if (choice == 1) {
    double tempNum;
    cout << colorTeal << "\nChange Income" << reset << endl << endl;
    for(int i = 0; i < income.size()-2; i++){
      if(i < income.size()-3){
        cout << i+1 << ". Paycheck " << i+1 << endl;
      } else {
        cout << i+1 << ". Tips" << endl;
        cout << i+2 << ". Refund Check" << endl;
        cout << i+3 << ". Amazon Refund" << endl;
      }
    }
    cout << "\nPlease make a choice: ";
    choice = validateInt(choice);
    cout << "Enter new value: ";
    tempNum = validateDouble(tempNum);
    income[choice-1] = tempNum;

  } else if (choice == 2) {
    double tempNum;

    cout << colorTeal << "\nChange Expenses" << reset << endl << endl;

    for(int i = 0; i < expenseList.size(); i++){
      cout << i+1 << ". " << expenseList[i] << endl;
    }

    cout << "\nPlease make a choice: ";
    choice = validateInt(choice);
    cout << "Enter new value: ";
    tempNum = validateDouble(tempNum);
    expenses[choice-1] = tempNum;
  } else if (choice == 3) {
    int i;
    cout << colorTeal << "\nChange Percentage" << reset << endl;
    do {
      cout << "\nEnter new percentage for Person 1 (0-100): " << colorB;
      i = validateInt(i);
        if(i < 0 || i > 100){
          cout << colorR << "Number must be between 0 and 100" << reset;
        }
    } while (i < 0 || i > 100);
  p1 = i;
  p2 = 100 - i;
  }
}
void showBudget(MonthlyBudget p1, MonthlyBudget p2, vector<double> income, vector<double> expenses, vector<string> expenseList, int percent1, int percent2){
  string clearScreen = "\033[2J\033[1;1H";
  string colorTeal = "\x1b[36;1m";
  string colorB = "\x1b[34;1m";
  string colorP = "\x1b[95;1m";
  string colorW = "\x1b[37;1m";
  string underline = "\x1b[0;4m";
  string underlineW = "\x1b[37;4m";
  string reset = "\x1b[0m";

  vector<double> vPercent1;
  vector<double> vPercent2;
  double doubleP1Perc, doubleP2Perc, incomeTotal, expensesTotal, person1Total, person2Total;

  cout << endl;
  cout << colorTeal << setw(65) << "MONTHLY BUDGET - PROPORTIONAL" << reset << endl << endl;
  cout << colorB << setw(58) << percent1 << "%" << setw(15) << percent2 << "%" << reset << endl;
  cout << setw(27) << underlineW << setw(12) << "Income" << setw(14) << "Expenses" << setw(16) << "Person 1" << setw(16) << "Person 2"<< setw(9) << reset << endl << endl;

  for (int i = 0; i < income.size()-3; i++){
    string money = "$" + to_string(income[i]);
      for(int i =0; i < 4; i ++){
          money.pop_back();
      }
    cout << colorW << setw(19) << "Paycheck " << i+1 << ":" << reset << setw(11) << money << endl;
  }
  string money = "$" + to_string(income[income.size()-3]);
    for(int i =0; i < 4; i ++){
            money.pop_back();
        }
  cout << colorW << setw(21) << "Tips:" << reset << setw(11) << money << endl;
  money = "$" + to_string(income[income.size()-2]);
    for(int i =0; i < 4; i ++){
            money.pop_back();
        }       
  cout << colorW << setw(21) << "Refund Check:" << reset << setw(11) << money << endl;
  string money2 = "$" + to_string(income[income.size()-1]);
    for(int i =0; i < 4; i ++){
            money2.pop_back();
        }       
  
  double dP1Perc = percent1/100.00;
  double dP2Perc = percent2/100.00;
  for(int i = 0; i < expenseList.size(); i++){
    vPercent1.push_back(expenses[i]*dP1Perc);
    vPercent2.push_back(expenses[i]*dP2Perc);
    string per1 = "$" + to_string(vPercent1[i]);
    string per2 = "$" + to_string(vPercent2[i]);
    money = "$" + to_string(expenses[i]);

    for(int i =0; i < 4 ; i ++){
          money.pop_back();
          per1.pop_back();
          per2.pop_back();
      }
    
    cout << colorW << setw(20) << expenseList[i] << ":" << reset;

    if(i == expenseList.size() -1){
      cout << underline << setw(11) << money2 << setw(14);
    } else {
      cout << setw(25);
    }
    cout << money << setw(16) << per1 << setw(16) << per2 << setw(9) << reset << endl;
  }
  cout << endl;

  for(int i = 0; i < income.size(); i++) {
    incomeTotal += income[i];
  }
  for(int i = 0; i < expenses.size(); i++) {
    expensesTotal += expenses[i];
  }
  for(int i = 0; i < vPercent1.size(); i++){
    person1Total += vPercent1[i];
  }
  for(int i = 0; i < vPercent2.size(); i++){
    person2Total += vPercent2[i];
  }
  string strIncomeTotal = "$" + to_string(incomeTotal);
  string strExpensesTotal = "$" + to_string(expensesTotal);
  string strP1Total = "$" + to_string(person1Total);
  string strP2Total = "$" + to_string(person2Total);
  string remainder = "$" + to_string(incomeTotal - expensesTotal);
  for(int i =0; i < 4 ; i ++){
      strIncomeTotal.pop_back();
      strExpensesTotal.pop_back();
      strP1Total.pop_back();
      strP2Total.pop_back();
      remainder.pop_back();
  }
  cout << colorP << setw(21) <<  "Totals:" << setw(11) << strIncomeTotal << setw(14) << strExpensesTotal << setw(16) << strP1Total << setw(16) << strP2Total << endl;
  cout << setw(21) <<  "What's Left:" << setw(11) << remainder << reset << endl;
}
int main() {
  ofstream out("monthlyBudget.txt");
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
      
    }
    cout << "\033[2J\033[1;1H";
  } while (choice != 0);
}