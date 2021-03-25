/*****************************************************************************/
/***    \file        sensor-validate.h
***     \author     Pratik Jaiswal (RBEI/ESP-AS46) 
***
***     \brief       header file for sensor validation project file  
/*****************************************************************************/

//   macros

#define SOCthreshold 0.05
#define Currentthreshold 0.1
/*****************************************************************************

                          Common Functions

*****************************************************************************/

// IsThereSuddenJump()  :  Function to check if there is a sudden Jump in the Sensor values range
// returns integer value 

int IsThereSuddenJump(double value, double nextValue, double maxDelta);

// validateSOCreadings() : function to Validating SOC value
// returns integer
int validateSensorreadings(double* values, int numOfValues,double thresholdofJump);

// validateCurrentreadings() : function to Validating current value
// returns integer
int validateCurrentreadings(double* values, int numOfValues);
