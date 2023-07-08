/* *************************************************************
   Encoder driver function definitions - by James Nugen
   ************************************************************ */
   
   
#ifdef ARDUINO_ENC_COUNTER
  #define LEFT_ENCODER_PIN1 17
  #define LEFT_ENCODER_PIN2 18
  #define RIGHT_ENCODER_PIN1 15
  #define RIGHT_ENCODER_PIN2 14
#endif
   
void initEncoders();
long readEncoder(int i);
void resetEncoder(int i);
void resetEncoders();

