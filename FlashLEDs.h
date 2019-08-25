#ifndef myLib_arfcFlashLEDs
#define myLib_arfcFlashLEDs

#if (ARDUINO >- 100)
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#pragma region "Define structures and types"
typedef struct {
  int setInterval;
  int flashCount;
} rtnFlashLED;
#pragma endregion //"Define structures and types"

class arfcFlashLEDs {
  public:
    // Constructor
  
    // Methods
    rtnFlashLED flashLED(int LEDpin, int LEDonMills, int LEDoffMills, int LEDnumberOfFlashes, int LEDloopMills, int flashCount);

  private:
};
#endif