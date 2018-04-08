#ifndef yx5300_h
#define yx5300_h

#include <Arduino.h>
#include <SoftwareSerial.h>

class yx5300{
	public:
		yx5300(int rx, int tx);
		int play();
		int pause();
		int next();
		int prev();
		int volume_up();
		int volume_down();
		int set_volume();
	private:
		int rx_pin, tx_pin;
		int8_t send_buffer;
		uint8_t reply_buffer;
};

#endif