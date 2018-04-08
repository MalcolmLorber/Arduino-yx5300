#ifndef yx5300_h
#define yx5300_h

#include <Arduino.h>
#include <SoftwareSerial.h>


class yx5300{
 public:
    yx5300(int rx, int tx);
    void startup();
    //yx5300(Stream s);
    int play();
    int play(uint8_t track_number);
    int pause();
    int next();
    int prev();
    int volume_up();
    int volume_down();
    int set_volume(int8_t volume);
 private:
    
    int executeCommand(int8_t command, int8_t arg1 = 0, int8_t arg2 = 0);
    void sendCommand(int8_t command, int8_t arg1, int8_t arg2);
    void receiveAnswer();
    SoftwareSerial mp3_stream;
    int8_t send_buffer[8];
    uint8_t reply_buffer[10];
};

#endif
