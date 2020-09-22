/*
 * BLINK
 * From: https://www.linkedin.com/learning/c-programming-for-embedded-applications/bit-masking-with-arduino
 * 
 * Motivation:
 * Manipulating bits in embedded systems impacts in memory economy, 
 * always critical in embedded applications.
 * This sketch uses only 640 bytes (1%); 
 * Compared without using bit manipulation
 * The Arduino Example > 01.Basics > Blink uses 924 bytes(2%). 
 * occupying twice the space in the arduino's 32k-bytes memory
 * 
 * Theory:
 * There are 3 main operation we can perform w/ bit manipulation:
 * 1- SET/CLEAR BITS
 * mask=0b00001000
 * byte = byte | mask;
 * byte = byte &~ mask;
 * 
 * 2- READ BITS
 * mask=0b00001000
 * if(byte & mask)
 * // bit 3 is set
 * else
 * // bit 3 is clear
 * 
 * 3-INVERT BITS
 * mask=0b00001000
 * byte = bite ^ mask
 * 
 * Description:
 * Blinks an LED by bit Masking
 * The On board LED on The Arduino UNO is at PortB 5.
 * 
 * Date: Sept/2020
*/

// Macro function providing a mask for a single bit 
// This is not expesive at all because it happens at compile time
// So your target CPU will never know about this shifting
#define MASK(x) ((unsigned char)(1<<x))

void setup() {
  
DDRB |= MASK(5); 
}


void loop() {
  
 // Setting & clearing bit 5 of PORTB of the Arduino Atmega328p Chip
 PORTB |= MASK(5);
 delay(500);
 PORTB &= ~MASK(5);
 delay(500); 
 
}
