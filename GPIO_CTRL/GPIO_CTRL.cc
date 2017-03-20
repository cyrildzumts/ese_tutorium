/**
 * Author : Cyrille Ngassam Nkwenga
 * HAW Hamburg
 * Tutorium Embedded System Programming
 * Description : This code describe how to
 * access the Hardware from C++
 */


#include <hw/inout.h>
#include <sys/neutrino.h>
#include <iostream>
#include <cstdlib>
#include <iostream>
#include <thread>
#include <chrono>

// Sehe Manual M104-DIO-48S.A1i, Kap. 5: Programming
#define CTRL_REG_GROUP0     0x303
/*
 * PORT A : OUTPUT
 * PORT B : INPUT
 * PORT C Lo : OUTPUT
 * PORT C Hi : INPUT
 * Mode Select : 00
 */
#define DEFAULT_PORTS_SETTINGS 0x8A

#define PORTA_ADDR 0x300


int main(int argc, char *argv[])
{

	// Da wir IO nutzen wollen, müssen wir erstmal zugriff Berechtigung auf
	// dem Hardware bekommen.
	if (ThreadCtl(_NTO_TCTL_IO_PRIV, 0) == -1)
	{
		std::cout << "Can't get Hardware access, therefore can't do anything."
				<< std::endl;
		return EXIT_FAILURE;
	}

	// PORTS Setting
	out8(CTRL_REG_GROUP0, DEFAULT_PORTS_SETTINGS);

	// Set Port A pin 5 : Green Light
	unsigned char port_value = in8(PORTA_ADDR);
	out8(PORTA_ADDR, (port_value | (1 << 5)));
	// Set Port A Pin 6 : Yellow Light
	port_value = in8(PORTA_ADDR);
	out8(PORTA_ADDR, (port_value | (1 << 6)));

	// Reset Port A pin 5
	port_value = in8(PORTA_ADDR);
	out8(PORTA_ADDR, (port_value & ~(1 << 5)));
	std::cout << "GPIO_CTRL Demo ... done !" << std::endl;
	return EXIT_SUCCESS;
}

