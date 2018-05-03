//ShapeTwoD.cpp

#include "ShapeTwoD.h"

ShapeTwoD::ShapeTwoD(){
   name = "";
   noOfVertices = 0;
   spaceType =  "NS";
}

ShapeTwoD::ShapeTwoD(string newName, int newNo, string newST){
   name = newName;
   noOfVertices = newNo;
   spaceType = newST;
}

ShapeTwoD::~ShapeTwoD(){
   //destructor
}

int ShapeTwoD::setValues(string newName, int newNo, string newST){
   name = newName;
   noOfVertices = newNo;
   spaceType = newST;
}

string ShapeTwoD::getName(){
   return name;
}

int ShapeTwoD::getNoOfVertices(){
   return noOfVertices;
}

string ShapeTwoD::getspaceType(){
   return spaceType;
}

string ShapeTwoD::basicToString(){
   string allString = "";
   allString = "Name: " + name + "\nNo. of Vertices: " + to_string(noOfVertices) + "\nSpace Type: " + spaceType;
   return allString;
}

float ShapeTwoD::computeArea(){
   cout << "This should not be printed: ShapeTwoD::computeArea()"<< endl;
   return 0.0;
}

string ShapeTwoD::toString(){
   cout << "This should not be printed: ShapeTwoD::toString()"<< endl;
   return basicToString();
}

bool ShapeTwoD::isPointInShape(Vertex vtx){
   cout << "This should not be printed: ShapeTwoD::isPointInShape()"<< endl;

   return false;
}

bool ShapeTwoD::isPointOnShape(Vertex vtx){
   cout << "This should not be printed: ShapeTwoD::isPointOnShape()"<< endl;
   //TODO
   int pointX = vtx.getVertexX();
   int pointY = vtx.getVertexY();
   return false;
}

// bool ShapeTwoD::isPointOnShape(Vertex vtx){
//    int pointX = vtx.getVertexX();
//    int pointY = vtx.getVertexY();
//
//    for (int i = 0; i < 4; i++) {
//       int j = i + 1;
//       if (i == 3) {
//          j = 0;
//       }
//
//       int pointDist = 0;
//       int aX = vtxArray[i]->getVertexX();
//       int bX = vtxArray[j]->getVertexX();
//       int aY = vtxArray[i]->getVertexY();
//       int bY = vtxArray[j]->getVertexY();
//       string XorY;//Checks which exis is the line parallel to
//
//       if (pointX == aX && pointY == aY) {
//          cout << "Entry [" << pointX << ":" << pointY << "]: " << aX << ":" << aY << endl;
//          return true;
//       } else if (pointX == bX && pointY == bY) {
//          cout << "Entry [" << pointX << ":" << pointY << "]: " << bX << ":" << bY << endl;
//          return true;
//       }
//       //Checks for number of coodinates which describe the edges of the Rectangle
//       if (aX == bX) {
//          pointDist = abs(aY - bY);
//          XorY = "X";
//       } else if (aY == bY) {
//          pointDist = abs(aX - bY);
//          XorY = "Y";
//       } else {
//          cout << "Error: shape cannot be computed!" << endl;
//          return false;
//       }
//
//       if (pointDist == 0) {
//          cout << "Error: shape cannot be computed!" << endl;
//          return false;
//       }
//
//       //Vertex tmpVTXArr[pointDist];
//       if (XorY == "X" && pointX == aX) {
//          for (int p = 0; p < pointDist; p++) {
//             if (pointY == aY+p) {
//                cout << "Entry [" << pointX << ":" << pointY << "]: " << aX << ":" << aY+p << endl;
//                return true;
//             } else if (pointY == bY+p) {
//                cout << "Entry [" << pointX << ":" << pointY << "]: " << aX << ":" << bY+p << endl;
//                return true;
//             }
//          }
//       } else if (XorY == "Y" && pointY == aY) {
//          for (int p = 0; p < pointDist; p++) {
//             if (pointX == aX+p) {
//                cout << "Entry [" << pointX << ":" << pointY << "]: " << aX+p << ":" << aY << endl;
//                return true;
//             } else if (pointX == bX+p) {
//                cout << "Entry [" << pointX << ":" << pointY << "]: " << bX+p << ":" << aY << endl;
//                return true;
//             }
//          }
//       } else {
//          //cout << "Error: shape cannot be computed!" << endl;
//          //return false;
//       }
//       //Next edge
//    }
//    cout << "Point is not on shape!" << endl;
//    return false;
// }
