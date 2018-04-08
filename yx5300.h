#ifndef yx5300_h
#define yx5300_h

#include <Arduino.h>
#include <SoftwareSerial.h>

class yx5300{
	public:
		yx5300(int rx, int tx);
	private:
		int rx_pin, tx_pin;
};

#endif