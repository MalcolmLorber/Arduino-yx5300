#include "yx5300.h"
#include "yx5300_defines.h"
yx5300::yx5300(int rx, int tx){
    mp3_stream = SoftwareSerial(rx, tx);
}
yx5300::yx5300(Stream s){
    mp3_stream = s;
}
int yx5300::play(){
    return executeCommand(CMD_PLAY, 0);
}
int yx5300::pause(){
     return executeCommand(CMD_PAUSE, 0);
}
int yx5300::next(){
     return executeCommand(CMD_NEXT_SONG, 0);
}
int yx5300::prev(){
     return executeCommand(CMD_NEXT_SONG, 0);
}
int yx5300::volume_up(){
     return executeCommand(CMD_NEXT_SONG, 0);
}
int yx5300::volume_down(){
     return executeCommand(CMD_NEXT_SONG, 0);
}
int yx5300::set_volume(int8_t volume){
     return executeCommand(CMD_SET_VOLUME, volume);
}

int yx5300::executeCommand(int8t_command, int16t_arguments)
{

}

void yx5300::sendCommand(int8_t command, int16_t arguments){
    delay(5);
    send_buffer[0] = 0x7e;   // Starting byte, always 7E
    send_buffer[1] = 0xff;   // second byte, always FF
    send_buffer[2] = 0x06;   // Length of command
    send_buffer[3] = command;// command byte
    send_buffer[4] = 0x01;   // 0x00 NO, 0x01 feedback
    send_buffer[5] = (int8_t)(arguments >> 8);  //high argument data
    send_buffer[6] = (int8_t)(arguments);       //low argument data
    send_buffer[7] = 0xef; // ending byte is always EF
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
