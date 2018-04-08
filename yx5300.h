#ifndef yx5300_h
#define yx5300_h

#include <Arduino.h>
#include <SoftwareSerial.h>

class yx5300{
	public:
		yx5300(int rx, int tx);
		yx5300(Stream s);
		int play();
		int pause();
		int next();
		int prev();
		int volume_up();
		int volume_down();
		int set_volume(int volume);
	private:
		void sendCommand(int8_t command, int16_t arguments);
		String receiveAnswer();
		Serial mp3_stream;
		int8_t send_buffer[8];
		uint8_t reply_buffer[10];
};

#endif