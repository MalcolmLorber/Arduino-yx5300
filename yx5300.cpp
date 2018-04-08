#include "yx5300.h"
#include "yx5300_defines.h"
yx5300::yx5300(int rx, int tx): mp3_stream(rx,tx){
    
}
//yx5300::yx5300(Stream s){
//    mp3_stream = s;
//}
int yx5300::play(){
    return executeCommand(CMD_PLAY);
}
int yx5300::pause(){
    return executeCommand(CMD_PAUSE);
}
int yx5300::next(){
    return executeCommand(CMD_NEXT_SONG);
}
int yx5300::prev(){
    return executeCommand(CMD_PREV_SONG);
}
int yx5300::volume_up(){
    return executeCommand(CMD_VOLUME_UP);
}
int yx5300::volume_down(){
    return executeCommand(CMD_VOLUME_DOWN);
}
int yx5300::set_volume(int8_t volume){
    return executeCommand(CMD_SET_VOLUME, 0, volume);
}

void yx5300::startup()
{
    mp3_stream.begin(9600);
    delay(500);
    sendCommand(CMD_SEL_DEV, 0, 0x02);
    delay(500);
}

int yx5300::executeCommand(int8_t command, int8_t arg1, int8_t arg2)
{
    //send the command, receive an answer
    sendCommand(command, arg1, arg2);
    while(!mp3_stream.available()){}
    receiveAnswer();
    //for(int i=0;i<10;i++){
    //Serial.print(reply_buffer[i]);
    //}
    //Serial.println();
    //parse the answer to check for errors and status
}

void yx5300::sendCommand(int8_t command, int8_t arg1, int8_t arg2){
    delay(20);
    send_buffer[0] = 0x7e;   // Starting byte, always 7E
    send_buffer[1] = 0xff;   // second byte, always FF
    send_buffer[2] = 0x06;   // Length of command
    send_buffer[3] = command;// command byte
    send_buffer[4] = 0x01;   // 0x00 NO, 0x01 feedback
    send_buffer[5] = arg1;  //arg1 byte
    send_buffer[6] = arg2;  //arg2 byte
    send_buffer[7] = 0xef; // ending byte is always EF
    for(uint8_t i = 0; i<8; i++){
	mp3_stream.write(send_buffer[i]);
    }
}
void yx5300::receiveAnswer(){
    int bytes_received = 0;
    while (mp3_stream.available() && bytes_received < 10){
	uint8_t i = mp3_stream.read();
	//Serial.print(i);
	reply_buffer[bytes_received] = i;
	bytes_received++;
	
    }
}
