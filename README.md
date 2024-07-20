# baremetal-stm32f7

terminal 1:

make load

terminal 2:

arm-none-eabi-gdb.exe .\led_blinky.elf

target remote localhost:3333

set $pc=Reset_Handler

frame

monitor flash write_image erase led_blinky.elf

monitor reset halt
