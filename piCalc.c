#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/uart.h"

// UART defines
// By default the stdout UART is `uart0`, so we will use the second one
#define UART_ID uart1
#define BAUD_RATE 115200

// Use pins 4 and 5 for UART1
// Pins can be changed, see the GPIO function select table in the datasheet for information on GPIO assignments
#define UART_TX_PIN 1
#define UART_RX_PIN 2


#include <stdio.h>
#include "pico/time.h"


int main() 
{
    stdio_init_all();
    uint32_t msSinceBoot; 

    // Set up our UART
    uart_init(UART_ID, BAUD_RATE);
    // Set the TX and RX pins by using the function select on the GPIO
    // Set datasheet for more information on function select
    gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
    gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);
    // print the time since the board was booted
    msSinceBoot = to_ms_since_boot(get_absolute_time());
    printf("start calculation: %d\n",msSinceBoot);

    // now for the calculation of Pi
    int r[2800 + 1];
    int i, k;
    int b, d;
    int c = 0;
    int iteration = 0;
    // calculate pi 100 times but only print the last time
    while(iteration <= 100){
        for (i = 0; i < 2800; i++) {
            r[i] = 2000;
        }
        r[i] = 0;

        for (k = 2800; k > 0; k -= 14) {
            d = 0;

            i = k;
            for (;;) {
                d += r[i] * 10000;
                b = 2 * i - 1;

                r[i] = d % b;
                d /= b;
                i--;
                if (i == 0) break;
                d *= i;
            }
            if(iteration ==100) {	
                printf("%.4d", c + d / 10000);
                c = d % 10000;
            }
            else {}
         }
        iteration = iteration+1;
    }
    // Print the time since the board was booted
    msSinceBoot = to_ms_since_boot(get_absolute_time());
    printf("\n");
    printf("end calculation: %d\n",msSinceBoot);
    
    return 0;
}
