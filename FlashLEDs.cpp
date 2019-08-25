#include "FlashLEDs.h"

#pragma region "Logic functions"
// function to flash LED X times in every Y milliseconds for Z milliseconds.
rtnFlashLED arfcFlashLEDs::flashLED(int LEDpin, int LEDonMills, int LEDoffMills, int LEDnumberOfFlashes, int LEDloopMills, int flashCount){
  int isHigh = digitalRead(LEDpin);
  int setHighLow;
  int setInterval;
  rtnFlashLED returnData;

  if (isHigh != HIGH) {
    setHighLow = HIGH;
    setInterval = LEDonMills;
    flashCount++;
  } else {
    setHighLow = LOW;
    if (flashCount < LEDnumberOfFlashes) {
      setInterval = LEDoffMills;
    } else {
      setInterval = LEDloopMills - (LEDnumberOfFlashes * LEDonMills) - ((LEDnumberOfFlashes - 1) * LEDoffMills);
      flashCount = 0;  // reset flash count
    }
  }

  digitalWrite(LEDpin, setHighLow);
  
  returnData.flashCount = flashCount;
  returnData.setInterval = setInterval;
  return returnData;
}
#pragma endregion // "Logic functions"