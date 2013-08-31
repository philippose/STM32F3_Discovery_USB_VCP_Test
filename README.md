STM32F3_Discovery_USB_VCP_Test
==============================

A basic demonstration of the USB Virtual COM Port facility implemented on an STM32F3Discovery Board

This project is heavily based on the following demonstration present in the STM32_USB-FS-Device_Lib_V4.0.0
library:
* VirtualComport_Loopback

Essentially, it echos data sent from a normal "Hyperterminal" application from a PC via the STM32 Virtual
COM Port back to the PC. The entire communication takes place over USB, without the need for a Serial Port 
(which is now an extreme rarity on Laptops, and new desktops), or a USB-to-Serial Conversion Cable between 
the PC and the STM32F3Discovery Board.
