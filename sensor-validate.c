#include "sensor-validate.h"

#define SOCthreshold 0.05
#define Currentthreshold 0.1

int IsThereSuddenJump(double value, double nextValue, double maxDelta) {
  if(nextValue - value > maxDelta) {
    return 0;
  }
  return 1;
}

int validateSensorreadings(double* values, int numOfValues,double thresholdofJump) {
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
