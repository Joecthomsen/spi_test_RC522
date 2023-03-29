
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
    // Write = 0
    // Read = 1
    // initialize the device
    SYSTEM_Initialize();

    uint8_t dummy_read[] = {10000000, 0x00};
    uint8_t clearFifoBuffer[] = {0b00010100, 0x80};
    uint8_t write_fifo1[] = {0b00010010, 0x24};
    uint8_t write_fifo2[] = {0b00010010, 0x25};
    uint8_t write_fifo3[] = {0b00010010, 0x26};
    uint8_t write_fifo4[] = {0b00010010, 0x27};
    
    uint8_t read_fifo[] = {0b10010010};
    uint8_t getBytesInFifoCmd[] = {0b10010100, 0x00};   
    
    uint8_t dummyReadResponse[2];
    uint8_t write_fifo_response1[3];
    uint8_t write_fifo_response2[3];  
    uint8_t write_fifo_response3[3];     
    uint8_t write_fifo_response4[3];
    
    uint8_t read_fifo_response1[3];
    uint8_t read_fifo_response2[3];
    uint8_t read_fifo_response3[3];  
    uint8_t read_fifo_response4[3];  
    uint8_t clearResponse[1];
    
    uint8_t bytesInFifoResponse[3];  
    uint8_t bytesInFifoResponse2[3];
    uint8_t bytesInFifoResponse3[3];  
    uint8_t bytesInFifoResponse4[3];
    uint8_t bytesInFifoResponse5[3];
    
    //Read dummy byte - just because...
    
    _LATB11 = 0;
        SPI1_Exchange8bitBuffer(dummy_read, 2, dummyReadResponse);
    _LATB11 = 1;
 
    //Clear FIFO
    _LATB11 = 0;
        SPI1_Exchange8bitBuffer(clearFifoBuffer, 2, dummyReadResponse);
    _LATB11 = 1;
    
    //Read how many bytes in FIFO (should be 0 after clearing the buffer pointers) 
    _LATB11 = 0;
        SPI1_Exchange8bitBuffer(getBytesInFifoCmd, 3, bytesInFifoResponse);
    _LATB11 = 1;

    //Write one byte with value 0x24 to FIFO 
    _LATB11 = 0;
    SPI1_Exchange8bitBuffer(write_fifo1, 2, write_fifo_response1);
    _LATB11 = 1; 
    
    //Read how many bytes in FIFO (should be 1) 
    _LATB11 = 0;
    SPI1_Exchange8bitBuffer(getBytesInFifoCmd, 3, bytesInFifoResponse2);
    _LATB11 = 1;
    
    //Write one byte with value 0x25 to FIFO 
    _LATB11 = 0;
    SPI1_Exchange8bitBuffer(write_fifo2, 2, write_fifo_response2);
    _LATB11 = 1;
    
    //Read how many bytes in FIFO (should be 2) 
    _LATB11 = 0;
    SPI1_Exchange8bitBuffer(getBytesInFifoCmd, 3, bytesInFifoResponse3);
    _LATB11 = 1;
    
    //Write one byte with value 0x26 to FIFO 
    _LATB11 = 0;
    SPI1_Exchange8bitBuffer(write_fifo3, 2, write_fifo_response3);
    _LATB11 = 1;

    //Read how many bytes in FIFO (should be 3) 
    _LATB11 = 0;
    SPI1_Exchange8bitBuffer(getBytesInFifoCmd, 3, bytesInFifoResponse4);
    _LATB11 = 1;
    
    ///Write one byte with value 0x27 to FIFO 
    _LATB11 = 0;
    SPI1_Exchange8bitBuffer(write_fifo4, 2, write_fifo_response4);
    _LATB11 = 1;
    
    //Read how many bytes in FIFO (should be 4) 
    _LATB11 = 0;
    SPI1_Exchange8bitBuffer(getBytesInFifoCmd, 3, bytesInFifoResponse5);
    _LATB11 = 1;
    
    //Dummy int for break point
    int k = 8;
    
    //Read value from FIFO (should be 0x24))
    _LATB11 = 0;
    SPI1_Exchange8bitBuffer(read_fifo, 3, read_fifo_response1);
    _LATB11 = 1;
    
    _LATB11 = 0;
    SPI1_Exchange8bitBuffer(read_fifo, 3, read_fifo_response2);
    _LATB11 = 1;  
    
    _LATB11 = 0;
    SPI1_Exchange8bitBuffer(read_fifo, 3, read_fifo_response3);
    _LATB11 = 1;  
    
    _LATB11 = 0;
    SPI1_Exchange8bitBuffer(read_fifo, 3, read_fifo_response4);
    _LATB11 = 1;  
    
    k = 9;
    
    
    
    
    
    while(1){
             UART1_Write('D');
    }

    return 1;
}
/**
 End of File
 * 
*/

