#include "yx5300.h"

yx5300::yx5300(int rx, int tx){
	mp3_stream = SoftwareSerial(rx, tx);
}
yx5300::yx5300(Stream s){
	mp3_stream = s;
}
yx5300::int play();
yx5300::int pause();
yx5300::int next();
yx5300::int prev();
yx5300::int volume_up();
yx5300::int volume_down();
yx5300::int set_volume(int volume);