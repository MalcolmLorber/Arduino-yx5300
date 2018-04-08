#include "yx5300.h"

yx5300::yx5300(int rx, int tx){
	mp3_stream = SoftwareSerial(rx, tx);
}
yx5300::yx5300(Stream s){
	mp3_stream = s;
}
int yx5300::play();
int yx5300::pause();
int yx5300::next();
int yx5300::prev();
int yx5300::volume_up();
int yx5300::volume_down();
int yx5300::set_volume(int volume);
void yx5300::sendCommand(int8_t command, int16_t arguments);
String yx5300::receiveAnswer();