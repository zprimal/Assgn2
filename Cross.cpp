//Cross.cpp

#include "Cross.h"

Cross::Cross(void){
   name = "";
   noOfVertices = 12;
   spaceType =  "NS";
   for (int i = 0; i < noOfVertices; i++) {
      vtxArray[i] = new Vertex();
   }
}

Cross::Cross(string setName, string setST, Vertex newVArr[12]){
   name = setName;
   noOfVertices = 12;
   spaceType =  setST;
   for (int i = 0; i < noOfVertices; i++) {
      vtxArray[i] = new Vertex(newVArr[i]);
   }
   cout << toString() << endl;
}

Cross::~Cross(){
   //Destructor
}

int Cross::setVertex(string setName, string setST, Vertex newVArr[12]){
   name = setName;
   noOfVertices = 12;
   spaceType =  setST;
   for (int i = 0; i < noOfVertices; i++) {
      vtxArray[i] = new Vertex(newVArr[i]);
   }
}

string Cross::getVertices(){
   string vtxString = "Vertices:\n";
   for (int i = 0; i < noOfVertices; i++) {
      if (i == 0) {
         vtxString = vtxArray[i]->toString();
      } else {
         vtxString = vtxString + "\n" + vtxArray[i]->toString();
      }
   }
   return vtxString;
}

string Cross::getPtIn(){
   string result = "";
   int xMin, yMin, xMax, yMax;
   //DID YOU THINK IT WOULD BE THIS EASY?
   // gets the 4 X-points which the shape touches on TRUNC
   
   // gets the 4 Y-points which the shape touches on TRUNC


   //Get min/max range of shape
   for (int i = 0; i < noOfVertices; i++) {
      int j = i + 1;
      if (i == noOfVertices-1) {
         j = 0;
      }
      int aX = vtxArray[i]->getVertexX();
      int bX = vtxArray[j]->getVertexX();
      int aY = vtxArray[i]->getVertexY();
      int bY = vtxArray[j]->getVertexY();

      if (i == 0) {
         xMin = aX;
         xMax = aX;
         yMin = aY;
         yMax = aY;
      }

      //Gets the max and min points for the shape
      if (aX < xMin) {
         xMin = aX;
      } else if (bX < xMin) {
         xMin = bX;
      }

      if (aY < yMin) {
         yMin = aY;
      } else if (bY < yMin) {
         yMin = bY;
      }

      if (aX > xMax) {
         xMax = aX;
      } else if (bX > xMax) {
         xMax = bX;
      }

      if (aY > yMax) {
         yMax = aY;
      } else if (bY > yMax) {
         yMax = bY;
      }
   } // END of for loop

   //Get the max and min points for the X and Y ranges TRUNC


   //Get the inbetweens for the XY ranges TRUNC


   //Debug TRUNC


   // Calculate number of points in Shape TRUNC


   Vertex inShapeVtxArr[inShapeSize];
   int inShapeItr = 0;
   int xRange = xMax-xMin-1;
   int yRange = yMax-yMin-1;

   //Obtains points in shape from top-down, left-right TRUNC


   for (int i = 0; i < inShapeSize; i++) {
      result = result + "[" + to_string(inShapeVtxArr[i].getVertexX()) + "," + to_string(inShapeVtxArr[i].getVertexY()) + "]\n";
   }
   return result;
}

string Cross::getPtOn(){
   int edgePts = 0;

   for (int i = 0; i < noOfVertices; i++) {
      int j = i + 1;
      if (i == noOfVertices-1) {
         j = 0;
      }

      int pointDist = 0;
      int aX = vtxArray[i]->getVertexX();
      int bX = vtxArray[j]->getVertexX();
      int aY = vtxArray[i]->getVertexY();
      int bY = vtxArray[j]->getVertexY();

      if (aX == bX) {
         edgePts = edgePts + abs(aY - bY) - 1;
      } else if (aY == bY) {
         edgePts = edgePts + abs(aX - bX) - 1;
      } else {
         cout << "Error: shape cannot be computed!" << endl;
         return "1";
      }
   }

   if (!edgePts > 0) {
      cout << "Error: No points on shape!" << endl;
      return "1";
   }

   cout << "edgePts: " << edgePts << endl;
   Vertex totalVTXArr[edgePts];
   int totalInt = 0;
   for (int i = 0; i < noOfVertices; i++) {
      int j = i + 1;
      if (i == noOfVertices-1) {
         j = 0;
      }

      int pointDist = 0;
      int aX = vtxArray[i]->getVertexX();
      int bX = vtxArray[j]->getVertexX();
      int aY = vtxArray[i]->getVertexY();
      int bY = vtxArray[j]->getVertexY();
      string XorY;//Checks which axis is the line parallel to

      //Checks for number of coodinates which describe the edges of the Rectangle
      if (aX == bX) {
         pointDist = abs(aY - bY);
         XorY = "X";
      } else if (aY == bY) {
         pointDist = abs(aX - bX);
         XorY = "Y";
      } else {
         cout << "Error: Side is slanted!" << endl;
         return "1";
      }

      if (pointDist == 0) {
         cout << "Error: Side has no points!" << endl;
         return "1";
      }
      // cout << "pointDist: " << pointDist << endl;
      if (XorY == "X") { //Parallel to the X-axis
         for (int p = 1; p < pointDist; p++) {
            if (aY < bY) {
               // cout << "aX: " << aX << ", aY+p: " << aY+p << "\n";
               totalVTXArr[totalInt] = Vertex(aX, aY+p);
               totalInt++;
            } else if (aY > bY) {
               // cout << "aX: " << aX << ", bY+p: " << bY+p << "\n";
               totalVTXArr[totalInt] = Vertex(aX, bY+p);
               totalInt++;
            } else {
               printf("Huh?\n");
            }
         }
      } else if (XorY == "Y") { //Parallel to the Y-axis
         for (int p = 1; p < pointDist; p++) {
            if (aX < bX) {
               // cout << "aX+p: " << aX+p << ", aY: " << aY << "\n";
               totalVTXArr[totalInt] = Vertex(aX+p, aY);
               totalInt++;
            } else if (aX > bX) {
               // cout << "bX+p: " << bX+p << ", aY: " << aY << "\n";
               totalVTXArr[totalInt] = Vertex(bX+p, aY);
               totalInt++;
            } else {
               printf("Huh?\n");
            }
         }
      }
      //Next edge
   }

   string result = "";
   for (int i = 0; i < edgePts; i++) {
      result = result + "[" + to_string(totalVTXArr[i].getVertexX()) + "," + to_string(totalVTXArr[i].getVertexY()) + "]\n";
   }
   return result;
}

//virtual functions
float Cross::computeArea(){
   float crsArea = 0.0;
   int j = noOfVertices-1;
   for (int i = 0; i < noOfVertices; i++) {
      crsArea += (vtxArray[j]->getVertexX() + vtxArray[i]->getVertexX()) * (vtxArray[j]->getVertexY() - vtxArray[i]->getVertexY());
      j = i;
   }

   crsArea = abs(crsArea/2.0);
   return crsArea;
}

string Cross::toString(){
   string allString = "";
   allString = basicToString();
   allString = allString + "\nVertices:\n" + getVertices() + "\nPoints on shape:\n" + getPtOn() + "\nPoints in shape:\n" + getPtIn();
   return allString;
}

bool Cross::isPointInShape(Vertex vtx){
   int pointX = vtx.getVertexX();
   int pointY = vtx.getVertexY();
   int xMin, yMin, xMax, yMax, noOfPts;
   int noOfIntersections = 0;
   cout << "C1" << endl;
   for (int i = 0; i < noOfVertices; i++) {
      int j = i + 1;
      if (i == noOfVertices-1) {
         j = 0;
      }

      int pointDist = 0;
      int aX = vtxArray[i]->getVertexX();
      int bX = vtxArray[j]->getVertexX();
      int aY = vtxArray[i]->getVertexY();
      int bY = vtxArray[j]->getVertexY();

      if (aX == bX) {
         noOfPts = noOfPts + abs(aY - bY);
      } else if (aY == bY) {
         noOfPts = noOfPts + abs(aX - bY);
      } else {
         cout << "Error: shape cannot be computed!" << endl;
         return false;
      }

      //Gets the max and min points for the shape
      if (aX < xMin) {
         xMin = aX;
      } else if (bX < xMin) {
         xMin = bX;
      }

      if (aY < yMin) {
         yMin = aY;
      } else if (bY < yMin) {
         yMin = bY;
      }

      if (aX > xMax) {
         xMax = aX;
      } else if (bX > xMax) {
         xMax = bX;
      }

      if (aY > yMax) {
         yMax = aY;
      } else if (bY > yMax) {
         yMax = bY;
      }
   }

   //Makes a rectangle around shape and checks if the point is within the rectangle
   if (pointX <= xMin || pointY <= yMin || pointX >= xMax || pointY >= yMax) {
      cout << "Point exceeds shape " << name << endl;
      return false;
   }
   for (int i = 0; i < noOfVertices; i++) {
      int j = i + 1;
      if (i == noOfVertices-1) {
         j = 0;
      }

      int pointDist = 0;
      int aX = vtxArray[i]->getVertexX();
      int bX = vtxArray[j]->getVertexX();
      int aY = vtxArray[i]->getVertexY();
      int bY = vtxArray[j]->getVertexY();
      string XorY; //Checks which axis is the line parallel to

      if (aX == bX) {
         pointDist = abs(aY - bY);
         XorY = "X";
      } else if (aY == bY) {
         pointDist = abs(aX - bY);
         XorY = "Y";
      } else {
         cout << "Error: shape cannot be computed!" << endl;
         return false;
      }

      if (XorY == "X") {
         for (int p = 0; p < pointDist; p++) {
            if (aY < bY) {
               if (pointY == aY+p) {
                  cout << "Entry [" << pointX << ":" << pointY << "]: " << aX << ":" << aY+p << endl;
                  noOfIntersections++;
               }
            } else if (aY > bY) {
               if (pointY == bY+p) {
                 cout << "Entry [" << pointX << ":" << pointY << "]: " << aX << ":" << bY+p << endl;
                 noOfIntersections++;
              }
            }
         }
      } else if (XorY == "Y") {
         for (int p = 0; p < pointDist-1; p++) {
            if (aX < bX) {
               if (pointX == aX+p) {
                  cout << "Entry [" << pointX << ":" << pointY << "]: " << aX+p << ":" << aY << endl;
                  noOfIntersections++;
               }
            } else if (aX > bX) {
               if (pointX == bX+p) {
                 cout << "Entry [" << pointX << ":" << pointY << "]: " << bX+p << ":" << aY << endl;
                 noOfIntersections++;
              }
            }
         }
      }
   }
   if (noOfIntersections < 1 || noOfIntersections == 2) {
      cout << "Point is not in shape" << endl;
      return false;
   } else if (noOfIntersections == 1 || noOfIntersections > 2){
      cout << "Point is in shape" << endl;
      return true;
   }
   cout << "C4" << endl;
   cout << "This should not be printed" << endl;
   return false;
}

bool Cross::isPointOnShape(Vertex vtx){
   int pointX = vtx.getVertexX();
   int pointY = vtx.getVertexY();

   for (int i = 0; i < noOfVertices; i++) {
      int j = i + 1;
      if (i == noOfVertices-1) {
         j = 0;
      }

      int pointDist = 0;
      int aX = vtxArray[i]->getVertexX();
      int bX = vtxArray[j]->getVertexX();
      int aY = vtxArray[i]->getVertexY();
      int bY = vtxArray[j]->getVertexY();
      string XorY;//Checks which axis is the line parallel to

      //If point is on vertices
      if (pointX == aX && pointY == aY) {
         cout << "ON VERTICE: Entry [" << pointX << ":" << pointY << "]: " << aX << ":" << aY << endl;
         return false;
      } else if (pointX == bX && pointY == bY) {
         cout << "ON VERTICE: Entry [" << pointX << ":" << pointY << "]: " << bX << ":" << bY << endl;
         return false;
      }
      //Checks for number of points which describe the edges of the Rectangle
      if (aX == bX) {
         pointDist = abs(aY - bY);
         XorY = "X";
      } else if (aY == bY) {
         pointDist = abs(aX - bY);
         XorY = "Y";
      } else {
         cout << "Error: shape cannot be computed!" << endl;
         return false;
      }

      if (pointDist == 0) {
         cout << "Error: shape cannot be computed!" << endl;
         return false;
      }

      //Vertex tmpVTXArr[pointDist];
      if (XorY == "X" && pointX == aX) {
         for (int p = 0; p < pointDist; p++) {
            if (aY < bY) {
               if (pointY == aY+p) {
                  cout << "Entry [" << pointX << ":" << pointY << "]: " << aX << ":" << aY+p << endl;
                  return true;
               }
            } else if (aY > bY) {
               if (pointY == bY+p) {
                 cout << "Entry [" << pointX << ":" << pointY << "]: " << aX << ":" << bY+p << endl;
                 return true;
              }
            }
         }
      } else if (XorY == "Y" && pointY == aY) {
         for (int p = 0; p < pointDist; p++) {
            if (aX < bX) {
               if (pointX == aX+p) {
                  cout << "Entry [" << pointX << ":" << pointY << "]: " << aX+p << ":" << aY << endl;
                  return true;
               }
            } else if (aX > bX) {
               if (pointX == bX+p) {
                 cout << "Entry [" << pointX << ":" << pointY << "]: " << bX+p << ":" << aY << endl;
                 return true;
              }
            }
         }
      }
      //Next edge
   }
   cout << "Point is not on shape!" << endl;
   return false;
}
