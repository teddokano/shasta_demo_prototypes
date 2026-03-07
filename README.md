# shasta_demo_prototypes

## What is this?

This is repo to share sample projects for NAFE33352-UIOM board.  
The code can be built on MCUXpresso IDE or MCUXpresso for VSC and can run on FRDM-MCXN947, FRDM-MCXN236, FRDM-MCXA156, FRDM-MCXA153 and FRDM-MCXC444 boards.  
The NAFE33352-UIOM board is an Arduino-shield type board. So the UIOM board can be attached on the FRDM boards directly.  

The projects are using [`r01lib`](https://github.com/teddokano/r01lib) for MCU hardware access.  
A microcontroller accesses to the UIOM via SPI and gets interrupt. All those interactions are handled by `r01lib` with abstracting hardware.  

This repo is including two sample projects.   

## Sample projects

### operation_basic

This ample code demonstrates ADC input and DAC output on NAFE33352 UIOM board.  

**REQUIRED HARDWARE SETUP**   
Connect a wire between pin1(DUT_AO) and pin5(AIP) on J3 terminal block to loopback the voltage output.  
The DAC output voltage can be seen at logical-channel 0on the ADC input.  

### ADC_and_DAC
This sample code demonstrates ADC input and DAC output on NAFE33352 UIOM board.  
On this demo, the ADC logical-channels are configured as following..  
   - logical-channel[ 0 ] : Voltage input on AIP and VCM(GND)  
   - logical-channel[ 1 ] : Voltage monitoring on VHDD (high-voltage positive supply)  
   - logical-channel[ 2 ] : Voltage monitoring on VHSS (high-voltage negative supply)  
   - logical-channel[ 3 ] : VSNS voltage  
   - logical-channel[ 4 ] : ISNS current  

The DAC output can be configured voltage output or current output by \"VOLTAGE_OUTPUT_SETTING\" difinition.  
Comment-out \"#define VOLTAGE_OUTPUT_SETTING\" to let the DAC in current mode.   
The DAC output will altered to positive and negative at each measurement interval (+/-5V or +/-20mA).  

**REQUIRED HARDWARE SETUP FOR VOLTAGE OUTPUT**  
This sample code demonstrates ADC input and DAC output on NAFE33352 UIOM board.  
CONNECT a wire between pin1(DUT_AO) and pin5(AIP) on J3 terminal block to loopback the voltage output.  
Make sure, UNCONNECT a wire between pin1(GND) and pin5(DUT_AO) on J1 terminal block.  
The DAC output voltage can be seen at logical-channel 0 and 3 on the ADC input.  

 **REQUIRED HARDWARE SETUP FOR CURRENT OUTPUT**  
Make sure CONNECT a wire between pin1(GND) and pin5(DUT_AO) on J1 terminal block to cut current path to AO output to GND.  
The DAC output current can be seen at logical-channel 4 on the ADC input.  

### AIO_input
This sample code demonstrates make AIO (Analog Input/Output) part to work voltage/current input
On this demo, the ADC logical-channels are configured as following..  
   - logical-channel[ 0 ] : Voltage input using VSNS  
   - logical-channel[ 1 ] : Current input using ISNS with CISW on.    
   - logical-channel[ 2 ] : Voltage monitoring on VHDD (high-voltage positive supply)  
   - logical-channel[ 3 ] : Voltage monitoring on VHSS (high-voltage negative supply)  

Apply voltage or current on AO pin and monitor the termial output.  
