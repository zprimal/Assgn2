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
}

Cross::~Cross(){
   //Destructor
}

int Cross::setVertex(tring setName, string setST, Vertex newVArr[4]){
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

Vertex* Cross::getPtIn(){

}

Vertex* Cross::getPtOn(){

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
   //TODO
   return crsArea;
}

string Cross::toString(){
   string allString = "";
   allString = basicToString();
   allString = allString + "Vertices:\n" + getVertices() + "\n\n";
   return allString;
}

bool Cross::isPointInShape(Vertex vtx){

}

bool Cross::isPointOnShape(Vertex vtx){

}
