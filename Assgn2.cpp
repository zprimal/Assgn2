//Assign.cpp
// Compile as:
// g++ -std=c++11 Vertex.cpp ShapeTwoD.cpp Rectangle.cpp Assgn2.cpp -o Assgn2.exe

#include "Assgn2.h"

int main(){
   printWelcomeMsg();
   startMenu();
}

void printWelcomeMsg(){
   printf("=================================================\n");
}

void printMenu(){
   printf("\n\n\n  | Name:  | Joshua Tan Jun Jie  |\n");
   printf("  | ID:    | ███████             |\n");
   printf("=================================================\n");
   printf("       ---Welcome to 2D33 SpaceFleet!---\n");
   printf("=================================================\n");
   printf(" 1. Add new data\n");
   printf(" 2. Compute Area of All Shapes\n");
   printf(" 3. Print Shape Report\n");
   printf(" 4. Print Shapes sorted according to warp\n");
   printf(" 5. Display All Shapes\n");
   printf(" 6. Check if point is on/in a shape\n");
   printf(" 7. Terminate Program\n");
   printf("=================================================\n");
   printf(" Select an option: ");
}

int startMenu(){
   string menuChoice;
   int runInt = 0;
   while (runInt != 1) {
      printMenu();
      getline(cin,menuChoice);
      if (menuChoice == "1") {
         addData();
      } else if (menuChoice == "2") {
         computeAllArea();
      } else if (menuChoice == "3") {
         printReport();
      } else if (menuChoice == "4") {
         printSortedData();
      } else if (menuChoice == "5") {
         printAllData();
      } else if (menuChoice == "6") {
         isPoint();
      } else if (menuChoice == "7") {
         runInt = 1;
         printf("--- Shutting down! ---\n");
         exit(0);
      } else {
         printf("Error: Enter a number from 1-7 corresponding with the options in the menu\n");
      }
   } // End of while looop
}

int addData(){
   string addString, addName, addSpaceType;
   int addNoVTX, addX, addY;

   printf("Enter number of vertices on shape. (4, 12)\n");
   getline(cin,addString);
   if (addString.empty() ){
      printf("No input detected.\n Returning to menu.\n");
      return 1;
   } else if (((!isdigit(addString[0])) && (addString[0] != '-') && (addString[0] != '+'))) {
      printf("Non-numeric characters detected.\n Returning to menu.");
      return 1;
   } else if (addString != "4" && addString != "12") {
      printf("Unrecognizable input detected.\n Returning to menu.");
      return 1;
   }
   addNoVTX = stoi(addString);
   addString = "";

   printf("Enter name of shape.\n");
   getline(cin,addString);
   if (addString.empty() ){
      printf("No input detected.\n Returning to menu.\n");
      return 1;
   }
   addName = addString;
   addString = "";

   printf("Does shape contain warp-space? (y/n)\n");
   getline(cin,addString);
   if (addString.empty()){
      printf("No input detected.\n Returning to menu.\n");
      return 1;
   } else if (addString == "y" || addString == "Y") {
      addSpaceType = "WS";
   } else if (addString == "n" || addString == "N") {
      addSpaceType = "NS";
   } else {
      printf("Incorrect input detected.\n Returning to menu.\n");
      return 1;
   }
   addString = "";

   Vertex addVTX[addNoVTX];
   printf("=== INFO: Enter coordinates in clockwise/anti-clockwise order ====\n");
   for (int i = 0; i < addNoVTX; i++) {
      printf("Enter X%d coordinate\n", i);
      getline(cin,addString);
      if (addString.empty() ){
         printf("No input detected.\n Returning to menu.\n");
         return 1;
      } else if (((!isdigit(addString[0])) && (addString[0] != '-') && (addString[0] != '+'))) {
         printf("Non-numeric characters detected.\n Returning to menu.");
         return 1;
      }
      addX = stoi(addString);
      addString = "";

      printf("Enter Y%d coordinate\n", i);
      getline(cin,addString);
      if (addString.empty() ){
         printf("No input detected.\n Returning to menu.\n");
         return 1;
      } else if (((!isdigit(addString[0])) && (addString[0] != '-') && (addString[0] != '+'))) {
         printf("Non-numeric characters detected.\n Returning to menu.");
         return 1;
      }
      addY = stoi(addString);

      addVTX[i] = Vertex(addX, addY);
   }

   if (addNoVTX == 4) {
      globalS2D[GS2Dcap] = new Rectangle(addName, addSpaceType, addVTX);
      GS2Dcap++;
      return 0;
   } else if (addNoVTX == 12) {
      // TODO
      // globalS2D[GS2Dcap] = new Cross(addName, addSpaceType, addVTX);
      // GS2Dcap++;
      // return 0;
   }
   printf("This cannot continue!\n");
}

int computeAllArea(){
   for (int i = 0; i < GS2Dcap; i++) {
      printf("Shape [%d]\n", i);
      cout << globalS2D[i]->getName() << ": " << globalS2D[i]->computeArea() << "\n======\n" << endl;
   }
}

int printReport(){
   //TODO
}

int printSortedData(){
   //TODO
}

int printAllData(){
   //TODO
   for (int i = 0; i < GS2Dcap; i++) {
      printf("Shape [%d]\n", i);
      cout << globalS2D[i]->toString() << "\n======\n" << endl;
   }
   return 0;
}

int isPoint(){
   //TODO
   string isString;
   int isX, isY;
   printf("Enter X coordinate\n");
   getline(cin,isString);
   if (isString.empty() ){
      printf("No input detected.\n Returning to menu.\n");
      return 1;
   } else if (((!isdigit(isString[0])) && (isString[0] != '-') && (isString[0] != '+'))) {
      printf("Non-numeric characters detected.\n Returning to menu.");
      return 1;
   }
   isX = stoi(isString);
   isString = "";

   printf("Enter Y coordinate\n");
   getline(cin,isString);
   if (isString.empty() ){
      printf("No input detected.\n Returning to menu.\n");
      return 1;
   } else if (((!isdigit(isString[0])) && (isString[0] != '-') && (isString[0] != '+'))) {
      printf("Non-numeric characters detected.\n Returning to menu.");
      return 1;
   }
   isY = stoi(isString);


   for (int i = 0; i < GS2Dcap; i++) {
      globalS2D[i]->isPointOnShape(Vertex(isX, isY));
   }

}
