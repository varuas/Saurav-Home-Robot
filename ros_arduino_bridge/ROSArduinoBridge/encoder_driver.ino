/* *************************************************************
   Encoder definitions
   
   Add an "#ifdef" block to this file to include support for
   a particular encoder board or library. Then add the appropriate
   #define near the top of the main ROSArduinoBridge.ino file.
   
   ************************************************************ */

#ifdef USE_BASE

#ifdef ARDUINO_ENC_COUNTER
volatile long left_enc_pos = 0L;
volatile long right_enc_pos = 0L;
static const int8_t ENC_STATES[] = { 0, 1, -1, 0, -1, 0, 0, 1, 1, 0, 0, -1, 0, -1, 1, 0 };  //encoder lookup table

ISR(PCINT1_vect) {
  static uint8_t left_enc_last = 0;
  static uint8_t right_enc_last = 0;

  // Right Encoder
  const int rightEnc1 = digitalRead(RIGHT_ENCODER_PIN1);
  const int rightEnc2 = digitalRead(RIGHT_ENCODER_PIN2);
  const int right_enc_current = (rightEnc1 << 1) | rightEnc2; // converting the 2 pin value to single number
  const int right_enc_last_and_current = (right_enc_last << 2) | right_enc_current; // //adding it to the previous encoded value
  right_enc_pos += ENC_STATES[right_enc_last_and_current];
  right_enc_last = right_enc_current;

  // Left Encoder
  const int leftEnc1 = digitalRead(LEFT_ENCODER_PIN1);
  const int leftEnc2 = digitalRead(LEFT_ENCODER_PIN2);
  const int left_enc_current = (leftEnc1 << 1) | leftEnc2; // converting the 2 pin value to single number
  const int left_enc_last_and_current = (left_enc_last << 2) | left_enc_current; // //adding it to the previous encoded value
  left_enc_pos += ENC_STATES[left_enc_last_and_current];
  left_enc_last = left_enc_current;
}



long readEncoder(int i) {
  if (i == LEFT) return left_enc_pos;
  else return right_enc_pos;
}

void resetEncoder(int i) {
  if (i == LEFT) {
    left_enc_pos = 0L;
    return;
  } else {
    right_enc_pos = 0L;
    return;
  }
}
#else
#error A encoder driver must be selected!
#endif

void initEncoders() {
  pinMode(LEFT_ENCODER_PIN1, INPUT);
  pinMode(LEFT_ENCODER_PIN2, INPUT);
  pinMode(RIGHT_ENCODER_PIN1, INPUT);
  pinMode(RIGHT_ENCODER_PIN2, INPUT);
  PCICR |= 0b00000010;   // Enable Port C for interrupts
  PCMSK1 |= 0b00011011;  // Enable Port C pins PC0, PC1, PC3, PC4 mask for interrupts
}

void resetEncoders() {
  resetEncoder(LEFT);
  resetEncoder(RIGHT);
}

#endif