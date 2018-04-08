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
void yx5300::sendCommand(int8_t command, int16_t arguments){
    delay(5);
    send_buffer[0] = 0x7e;   //
    send_buffer[1] = 0xff;   //
    send_buffer[2] = 0x06;   // Len
    send_buffer[3] = command;//
    send_buffer[4] = 0x01;   // 0x00 NO, 0x01 feedback
    send_buffer[5] = (int8_t)(arguments >> 8);  //datah
    send_buffer[6] = (int8_t)(arguments);       //datal
    send_buffer[7] = 0xef; //
    for(uint8_t i = 0; i<8; i++){
	mp3_stream.write(send_buffer[i]);
    }
}
void yx5300::receiveAnswer(){
    int bytes_received = 0;
    while (mp3_stream.available() && bytes_received < 10){
	reply_buffer[bytes_received] = mp3_stream.read();
	bytes_received++;
    }
}
