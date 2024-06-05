#include "echo_service.h"
#include "packet.h"
#include <iostream>

void EchoService::send(Packet *packet){
  packet_ = new Packet(host_ -> address(), packet -> srcAddress(), port_, packet -> srcPort(), packet -> data());
  host_ -> send(packet_);
}
void EchoService::execute(Packet *packet){
  std::cout << "EchoService: received \"" << host_ -> getPacket() -> dataString() << "\" from " << host_ -> getPacket() -> srcAddress().toString() << ":" << host_ -> getPacket() -> srcPort() << ", send reply with same data" << std::endl;
  send(packet);
  delete packet;
}

void EchoService::init(){
  packet_ = nullptr;
}