CC=arm-none-eabi-gcc
MACH=cortex-m33
INC=-I.\cmsis
CFLAGS= -g3 -c -mcpu=$(MACH) -mthumb -std=gnu11 -Wall -O0 $(INC)
LDFLAGS= -nostdlib -T .\stm32f7_linker.ld -Xlinker -Map=led_blinky.map


all:main.o led.o stm32f7_startup.o led_blinky.elf

main.o:main.c
	$(CC) $(CFLAGS) -o $@ $^

led.o:led.c
	$(CC) $(CFLAGS) -o $@ $^

stm32f7_startup.o:stm32f7_startup.c
	$(CC) $(CFLAGS) -o $@ $^

led_blinky.elf:main.o led.o stm32f7_startup.o
	$(CC) $(LDFLAGS) -o $@ $^

clean:
	del *.o *.elf

load:
	openocd -f board/st_nucleo_f7.cfg

