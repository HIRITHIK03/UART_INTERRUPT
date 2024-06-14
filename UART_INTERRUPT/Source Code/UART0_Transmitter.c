#include <stdint.h>

#define UART0_BASE      0x4000C000 // Base address of UART0 module
#define UART0_FR        (*((volatile unsigned long *)(UART0_BASE + 0x018))) // UART Flag Register
#define UART0_DR        (*((volatile unsigned long *)(UART0_BASE + 0x000))) // UART Data Register

// Function for UART transmitter
void UART0_Transmitter(char data) {
    while((UART0_FR & 0x20) != 0); // wait until Tx buffer not full
    UART0_DR = data;                // before giving it another byte
}
