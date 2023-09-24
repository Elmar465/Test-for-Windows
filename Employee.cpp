/***********************************************************************
// OOP244 Workshop #2 lab (part 1)
//
// File  Employee.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//    To be completed by students
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
***********************************************************************/
#include <iostream>
#include "Employee.h"
#include "File.h"
using namespace std;
namespace sdds
{

   int noOfEmployees;
   Employee *employees = nullptr;

   void sort()
   {
      int i, j;
      Employee temp;
      for (i = noOfEmployees - 1; i > 0; i--)
      {
         for (j = 0; j < i; j++)
         {
            if (employees[j].m_empNo > employees[j + 1].m_empNo)
            {
               temp = employees[j];
               employees[j] = employees[j + 1];
               employees[j + 1] = temp;
            }
         }
      }
   }
   bool load(Employee &emp)
   {
      bool empNoOk = read(emp.m_empNo);
      bool salaryOk = read(emp.m_salary);
      bool nameOk = read(emp.m_name);
      return empNoOk && salaryOk && nameOk;
   }

   bool load()
   {
      deallocateMemory(); // Deallocate any previously allocated memory

      if (openFile("employees.csv"))
      {
         return false;
      }

      noOfEmployees = noOfRecords();
      employees = new Employee[noOfEmployees];

      for (int i = 0; i < noOfEmployees; i++)
      {
         if (!load(employees[i]))
         {
            cout << "Employee Salary report, sorted by employee number" << endl;
            cout << "no- Empno, Name, Salary" << endl;
            cout << "------------------------------------------------" << endl;
            deallocateMemory();
            closeFile();
            return false;
         }
      }
      closeFile();
      return true;
   }

   void display(const Employee &emp)
   {
      cout << "Employee Salary report, sorted by employee number" << endl;
      cout << "no- Empno, Name, Salary" << endl;
      cout << "------------------------------------------------" << endl;
      cout << emp.m_empNo << ": " << emp.m_name << ", $" << emp.m_salary << endl;
   }

   void display()
   {

      sort();
      for (int i = 0; i < noOfEmployees; i++)
      {
         cout << i + 1 << "- ";
         display(employees[i]);
      }
   }

   void deallocateMemory()
   {
      if (employees)
      { // Check if employees is not nullptr
         for (int i = 0; i < noOfEmployees; i++)
         {
            delete[] employees[i].m_name; // assuming name is dynamically allocated
         }
         delete[] employees;
         employees = nullptr; // Set employees back to nullptr after deallocation
      }                       // Reset to 0
   }

}