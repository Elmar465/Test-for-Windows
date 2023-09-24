/***********************************************************************
// OOP244 Workshop #2 lab (part 1)
//
// File  File.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//    To be completed by students
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
***********************************************************************/
#include "File.h"
#include <cstdio>
#include <cstring>

namespace sdds
{
   FILE *fptr =  nullptr;

   bool openFile(const char filename[] = "employees.csv")
   {
      if (fptr)
      { // if file is already open, close it
         fclose(fptr);
      }
      fptr = fopen(filename, "r");
      return fptr != nullptr;
   }

   void closeFile()
   {
      if (fptr)
      {
         fclose(fptr);
      }
   }

   int noOfRecords()
   {
      int num = 0;
      char ch;
      while (!feof(fptr))
      {
         ch = fgetc(fptr);
         if (ch == '\n')
         {
            num++;
         }
      }
      rewind(fptr);
      return num;
   }

   bool read(char *&name)
   {
      char buffer[128];
      if (fscanf(fptr, "%127[^,],", buffer) == 1)
      {
         name = new char[strlen(buffer) + 1];
         strcpy(name, buffer);
         return true;
      }
      return false;
   }

   bool read(int &empNo)
   {
      return fscanf(fptr, "%d,", &empNo) == 1;
   }

   bool read(double &salary)
   {
      return fscanf(fptr, "%lf,", &salary) == 1;
   }
}
