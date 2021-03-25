#include "sensor-validate.h"



int IsThereSuddenJump(double value, double nextValue, double maxDelta) {
  if(nextValue - value > maxDelta) {
    return 0;
  }
  return 1;
}

int validateSensorreadings(double* values, int numOfValues,double thresholdofJump)
{
  
  int lastButOneIndex = numOfValues - 1;
  int IsValidJump = 1;
  
  if(NULL != values)
  {
    IsValidJump = IfNotNullCheckForJump(values,lastButOneIndex,thresholdofJump);
  }
  
  return IsValidJump;
  
  /*int lastButOneIndex = numOfValues - 1; 
  int temp = 1; 
  
  if (NULL != values)
  {  
   /*Perform sensor validation individually */ 
   //temp = IfNotNullCheckForJump(values,lastButOneIndex,thresholdofJump);
  //}
  /*Retruns TRUE if there is NULL pointer is sent*/
  //return temp;*/
  
}

int IfNotNullCheckForJump(double* values, int numOfValues,double thresholdofJump) {
  
  int lastButOneIndex = numOfValues - 1;
  
  for(int i = 0; i < lastButOneIndex; i++) {
    
    if(!IsThereSuddenJump(values[i], values[i + 1], thresholdofJump)) {
      
      return 0;
    
    }
  
  }
  return 1;
}
/*
int validateCurrentreadings(double* values, int numOfValues) {
  int lastButOneIndex = numOfValues - 1;
  for(int i = 0; i < lastButOneIndex; i++) {
    if(!IsThereSuddenJump(values[i], values[i + 1], 0.1)) {
      return 0;
    }
  }
  return 1;
}*/
