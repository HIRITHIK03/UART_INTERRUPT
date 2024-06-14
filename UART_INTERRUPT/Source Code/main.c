#define SYSCTL_RCGCUART_R (*((volatile unsigned long *)0x400FE618))
#define SYSCTL_RCGCGPIO_R (*((volatile unsigned long *)0x400FE608))

#define UART0_BASE_ADDR   0x4000C000
#define UART0_DR_R        (*((volatile unsigned long *)(0x4000C000)))
#define UART0_FR_R        (*((volatile unsigned long *)(0x4000C018)))
#define UART0_IBRD_R      (*((volatile unsigned long *)(0x4000C024)))
#define UART0_FBRD_R      (*((volatile unsigned long *)(0x4000C028)))
#define UART0_LCRH_R      (*((volatile unsigned long *)(0x4000C02C)))
#define UART0_CTL_R       (*((volatile unsigned long *)(0x4000C030)))
#define UART0_CC_R        (*((volatile unsigned long *)(0x4000CFC8)))
#define UART0_IM_R        (*((volatile unsigned long *)(0x4000C038)))
#define UART0_ICR_R       (*((volatile unsigned long *)(0x4000C044)))

#define GPIOA_BASE_ADDR   0x40058000
#define GPIOA_DATA_R      (*((volatile unsigned long *)(0x400583FC)))
#define GPIOA_DIR_R       (*((volatile unsigned long *)(0x40058400)))
#define GPIOA_DEN_R       (*((volatile unsigned long *)(0x4005851C)))
#define GPIOA_AFSEL_R     (*((volatile unsigned long *)(0x40058420)))
#define GPIOA_AMSEL_R     (*((volatile unsigned long *)(0x40058528)))
#define GPIOA_PCTL_R      (*((volatile unsigned long *)(0x4005852C)))

#define NVIC_EN0_R        (*((volatile unsigned long *)0xE000E100))

#define UART_CLK_FREQ     16000000
#define BAUD_RATE         9600

char transmit_buffer[100] = "!!!";
volatile int transmit_index = 0;

int main(void) {

    /* UART0 initialization */
    UART0_Init();

    //Infinite Loop
          while(1);
}
// UART0 interrupt handler
void UART0_Handler(void) {
    // Clear UART interrupt
    UART0_ICR_R |= 0x20;

    // Check if there are more characters to transmit
    if (transmit_buffer[transmit_index] != '\0') {
        // Transmit next character
        UART0_Transmitter(transmit_buffer[transmit_index++]);
    }
}
