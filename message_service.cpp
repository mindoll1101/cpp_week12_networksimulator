#include "message_service.h"
#include "packet.h"
#include <iostream>
// 메시지를 전송한다

void MessageService::init(){
  packet_ = nullptr;
}
void MessageService::send(std::string message){
  packet_ = new Packet(host_ -> address(), destAddress_, port_, destPort_, message);
  host_ -> send(packet_);
}

void MessageService::execute(Packet *packet){
  std::cout << "MessageService: received \"" << packet -> dataString() << "\" from " << packet -> srcAddress().toString() << ":" << packet -> srcPort() << std::endl;
  delete packet;
}