//Rectangle.cpp

#include "Rectangle.h"

Rectangle::Rectangle(void){
   name = "";
   noOfVertices = 4;
   spaceType =  "NS";
   for (int i = 0; i < noOfVertices; i++) {
      vtxArray[i] = new Vertex();
   }
}

Rectangle::Rectangle(string setName, string setST, Vertex newVArr[4]){
   name = setName;
   noOfVertices = 4;
   spaceType =  setST;
   for (int i = 0; i < noOfVertices; i++) {
      vtxArray[i] = new Vertex(newVArr[i]);
   }
   cout << toString() << endl;
}

Rectangle::~Rectangle(){
   //destructor
   cout << "Rect dst" << endl;
}

int Rectangle::setVertex(string setName, string setST, Vertex newVArr[4]){
   name = setName;
   noOfVertices = 4;
   spaceType =  setST;
   for (int i = 0; i < noOfVertices; i++) {
      vtxArray[i] = new Vertex(newVArr[i]);
   }
}

string Rectangle::getVertices(){
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

// Vertex* Rectangle::getPtIn(){
//
// }
//
// Vertex* Rectangle::getPtOn(){
//    //TODO
//    int edgePts = 0; // count number of points between vertices, excluding vertices
//
//    // Counts points on each edges, excluding the vertices
//    for (int i = 0; i < 4; i++){
//       int j = i + 1;
//       if (i == 3) {
//          j = 0;
//       }
//
//       int aX = vtxArray[i]->getVertexX();
//       int bX = vtxArray[j]->getVertexX();
//       int aY = vtxArray[i]->getVertexY();
//       int bY = vtxArray[j]->getVertexY();
//
//       if (aX == bX) {
//          edgePts = edgePts + abs(aY - bY) - 1;
//       } else if (aY == bY) {
//          edgePts = edgePts + abs(aX - bX) - 1;
//       } else {
//          cout << "Error: shape cannot be computed!" << endl;
//          return Vertex(0,0);
//       }
//    }
//
//    if (!edgePts > 0) {
//       cout << "Error: shape cannot be computed!" << endl;
//       return Vertex(0,0);
//    }
//
//    cout << "edgePts: " << edgePts << endl;
//    Vertex *totalVTXArr[edgePts+1];
//    totalVTXArr[0] = new Vertex(edgePts, edgePts); //First vertex holds array size;
//    int totalInt = 1;
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
//       string XorY;//Checks which axis is the line parallel to
//
//       //Checks for number of coodinates which describe the edges of the Rectangle
//       if (aX == bX) {
//          pointDist = abs(aY - bY) - 1;
//          XorY = "X";
//       } else if (aY == bY) {
//          pointDist = abs(aX - bY) - 1;
//          XorY = "Y";
//       } else {
//          cout << "Error: shape cannot be computed!" << endl;
//          return Vertex(0,0);
//       }
//
//       if (pointDist == 0) {
//          cout << "Error: shape cannot be computed!" << endl;
//          return Vertex(0,0);
//       }
//
//       if (XorY == "X") { //Parallel to the X-axis
//          for (int p = 1; p < pointDist; p++) {
//             if (aY < bY) {
//                totalVTXArr[totalInt] = new Vertex(aX, aY+p);
//                totalInt++;
//             } else if (aY > bY) {
//                totalVTXArr[totalInt] = new Vertex(aX, bY+p);
//                totalInt++;
//             } else {
//                printf("Huh?\n");
//             }
//          }
//       } else if (XorY == "Y") { //Parallel to the Y-axis
//          for (int p = 1; p < pointDist; p++) {
//             if (aX < bX) {
//                totalVTXArr[totalInt] = new Vertex(aX+p, aY);
//                totalInt++;
//             } else if (aX > bX) {
//                totalVTXArr[totalInt] = new Vertex(bX+p, aY);
//                totalInt++;
//             } else {
//                printf("Huh?\n");
//             }
//          }
//       } else {
//          //cout << "Error: shape cannot be computed!" << endl;
//          //return false;
//       }
//       //Next edge
//    }
//
//    return totalVTXArr;
// }

float Rectangle::computeArea(){
   float rctArea = 0.0;
   int j = noOfVertices-1;
   for (int i = 0; i < noOfVertices; i++) {
      rctArea += (vtxArray[j]->getVertexX() + vtxArray[i]->getVertexX()) * (vtxArray[j]->getVertexY() - vtxArray[i]->getVertexY());
      j = i;
   }

   rctArea = abs(rctArea/2.0);
   //TODO
   return rctArea;
}

string Rectangle::toString(){
   string allString = "";
   allString = basicToString();
   allString = allString + "\n" + getVertices() + "\n\n";
   return allString;
}

bool Rectangle::isPointInShape(Vertex vtx){
   //TODO
   int pointX = vtx.getVertexX();
   int pointY = vtx.getVertexY();
   int xMin, yMin, xMax, yMax;
   int noOfPts = 0;

   //Get range of pts
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

   if (pointX <= xMin || pointY <= yMin || pointX >= xMax || pointY >= yMax) {
      return false;
   } else {
      return true;
   }

   // Vertex ptArr[noOfPts];
   // int counter = 0;
   // for (int i = 0; i < 4; i++) {
   //    int j = i + 1;
   //    if (i == 3) {
   //       j = 0;
   //    }
   //
   //    int pointDist = 0;
   //    int aX = vtxArray[i]->getVertexX();
   //    int bX = vtxArray[j]->getVertexX();
   //    int aY = vtxArray[i]->getVertexY();
   //    int bY = vtxArray[j]->getVertexY();
   //    string XorY;//Checks which exis is the line parallel to
   //
   //    //If point is on vertices
   //    if (pointX == aX && pointY == aY) {
   //       cout << "Entry [" << pointX << ":" << pointY << "]: " << aX << ":" << aY << endl;
   //       return false;
   //    } else if (pointX == bX && pointY == bY) {
   //       cout << "Entry [" << pointX << ":" << pointY << "]: " << bX << ":" << bY << endl;
   //       return false;
   //    }
   //    //Checks for number of points which describe the edges of the Rectangle
   //    if (aX == bX) {
   //       pointDist = abs(aY - bY);
   //       XorY = "X";
   //    } else if (aY == bY) {
   //       pointDist = abs(aX - bY);
   //       XorY = "Y";
   //    } else {
   //       cout << "Error: shape cannot be computed!" << endl;
   //       return false;
   //    }
   //
   //    if (pointDist == 0) {
   //       cout << "Error: Shape contains no points!" << endl;
   //       return false;
   //    }
   //
   //    if (XorY == "X") {
   //       for (int p = 0; p < pointDist; p++) {
   //          if (aY < bY) {
   //             ptArr[counter] = Vertex(aX,aY+p);
   //             counter++;
   //             if (pointY == aY+p) {
   //                cout << "Error: Point is on shape!" << endl;
   //                return false;
   //             }
   //          } else if (aY > bY) {
   //             ptArr[counter] = Vertex(aX,bY+p);
   //             counter++;
   //             if (pointY == bY+p) {
   //               cout << "Error: Point is on shape!" << endl;
   //               return false;
   //            }
   //          }
   //       }
   //    } else if (XorY == "Y") {
   //       for (int p = 0; p < pointDist; p++) {
   //          if (aX < bX) {
   //             ptArr[counter] = Vertex(aX+p,aY);
   //             counter++;
   //             if (pointX == aX+p) {
   //                cout << "Error: Point is on shape!" << endl;
   //                return false;
   //             }
   //          } else if (aX > bX) {
   //             ptArr[counter] = Vertex(bX+p,aY);
   //             counter++;
   //             if (pointX == bX+p) {
   //                cout << "Error: Point is on shape!" << endl;
   //                return false;
   //            }
   //          }
   //       }
   //    }
   //    //Next edge
   // } // END of for loop
   //
   // //puke ptArr[]
   // cout << "counter: " << counter << endl;
   // cout << "noOfPts: " << noOfPts << endl;
   // for (int i = 0; i < noOfPts; i++) {
   //    /* code */
   // }

   //Get points on edge
   return false;
}

bool Rectangle::isPointOnShape(Vertex vtx){
   //TODO
   int pointX = vtx.getVertexX();
   int pointY = vtx.getVertexY();
   // Vertex *vtxPtr = (*this).getPtOn();
   // int noOfPts = *vtxPtr;
   // cout << "noOfPts: " << noOfPts << endl;
   //
   // for (int i = 1; i < noOfPts; i++) {
   //    /* code */
   // }

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
      } else {
         //cout << "Error: shape cannot be computed!" << endl;
         //return false;
      }
      //Next edge
   }
   cout << "Point is not on shape!" << endl;
   return false;
}
