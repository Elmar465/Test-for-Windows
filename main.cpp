/***********************************************************************
// OOP244 Workshop #2 lab (part 1): tester program
//
// File  main.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name    Elmar   Jafarli  ID162895221    Date   22.09.2023         Reason
***********************************************************************/
#include "Employee.h"
#include "File.h"
using namespace sdds;
int main() {
   if(load()) {
      display();
   }
   deallocateMemory();
   return 0;
}