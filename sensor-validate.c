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

