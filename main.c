
#include "mcc_generated_files/system.h"
#include "mcc_generated_files/uart1.h"
#include <string.h>
#include "mcc_generated_files/delay.h"
#include "mcc_generated_files/spi1.h"



/*
                         Main application
 */
int main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    uint8_t dummy_read[] = {0x80, 0x00};
    uint8_t clearFifoBuffer[] = {0x0A, 0x80};
    uint8_t write_fifo[] = {0x09, 0x24};
    uint8_t getBytesInFifoCmd[] = {(0x0A + 0x800), 0x00};   
    
    uint8_t dummyReadResponse[2];
    uint8_t write_fifo_response1[3];
    uint8_t write_fifo_response2[3];  
    uint8_t write_fifo_response3[3];      
    uint8_t clearResponse[1];
    
    uint8_t bytesInFifoResponse[3];  
    uint8_t bytesInFifoResponse2[3];
    uint8_t bytesInFifoResponse3[3];  
    uint8_t bytesInFifoResponse4[3];  
    
    _LATB11 = 0;
        SPI1_Exchange8bitBuffer(dummy_read, 2, dummyReadResponse);
    _LATB11 = 1;
        _LATB11 = 0;

        SPI1_Exchange8bitBuffer(getBytesInFifoCmd, 3, bytesInFifoResponse);
    _LATB11 = 1;
    _LATB11 = 0;
        SPI1_Exchange8bitBuffer(write_fifo, 3, write_fifo_response1);
        _LATB11 = 1;
            _LATB11 = 0;

        SPI1_Exchange8bitBuffer(getBytesInFifoCmd, 3, bytesInFifoResponse2);
            _LATB11 = 1;
    _LATB11 = 0;
        SPI1_Exchange8bitBuffer(write_fifo, 3, write_fifo_response2);
            _LATB11 = 1;
    _LATB11 = 0;
        SPI1_Exchange8bitBuffer(getBytesInFifoCmd, 3, bytesInFifoResponse3);
            _LATB11 = 1;
    _LATB11 = 0;

        SPI1_Exchange8bitBuffer(write_fifo, 3, write_fifo_response3);
            _LATB11 = 1;
                _LATB11 = 0;


        SPI1_Exchange8bitBuffer(getBytesInFifoCmd, 3, bytesInFifoResponse4);
    _LATB11 = 1;
    
    /*
    _LATB11 = 0;
    SPI1_Exchange8bitBuffer(dummy_read, 2, &dummyReadResponse);    //Clear FIFO buffer
    _LATB11 = 1;
        
    _LATB11 = 0;
    SPI1_Exchange8bitBuffer(clearFifoBuffer, 3, &clearResponse);    //Clear FIFO buffer
    _LATB11 = 1;
    DELAY_milliseconds(2);
  
    
    _LATB11 = 0; 
        SPI1_Exchange8bitBuffer(write_fifo, 2, write_fifo_response);
    _LATB11 = 1;
    
    DELAY_milliseconds(2);
  
    _LATB11 = 0;
    SPI1_Exchange8bitBuffer(getBytesInFifoCmd, 20, bytesInFifoResponse); //Get bytes in FIFO
    _LATB11 = 1;
     
   */
   
    int k = 8;
    while(1){
             UART1_Write('D');
    }

    return 1;
}
/**
 End of File
*/

