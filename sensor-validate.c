#include "sensor-validate.h"


/*---------------------------------------------------------------------------*/
/*     FUNCTION:    IsThereSuddenJump
 */
/*!    \brief      to check if there is a sudden junmp
 * 
 *     \param       current value ,next value and max value
 *     \returns     the status if the jump was abrupt
 *
*//*------------------------------------------------------------------------*/
int IsThereSuddenJump(double value, double nextValue, double maxDelta) {
  if(nextValue - value > maxDelta) {
    return 0;
  }
  return 1;
}
/*---------------------------------------------------------------------------*/
/*     FUNCTION:    validateSensorreadings
 */
/*!    \brief       to check if the sensor readings are null or have values and
 *                  send for check for jump
 * 
 *     \param       sensor values ,number of values  and and threshold of jump
 *     \returns     the status if the jump was abrupt
 *
*//*------------------------------------------------------------------------*/
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
  
/*---------------------------------------------------------------------------*/
/*     FUNCTION:    IfNotNullCheckForJump
 */
/*!    \brief       sending value to check jump
 * 
 *     \param        sensor values ,number of values  and and threshold of jump
 *     \returns    the status if the jump was abrupt
 *
*//*------------------------------------------------------------------------*/
int IfNotNullCheckForJump(double* values, int numOfValues,double thresholdofJump) {
  
  int IsValidTransition = 1;
  
  int lastButOneIndex = numOfValues - 1;
  
  for(int i = 0; i < lastButOneIndex; i++) {
    
    if(!IsThereSuddenJump(values[i], values[i + 1], thresholdofJump)) {
      
      IsValidTransition = 0;
    
    }
  
  }
  return IsValidTransition;
}

