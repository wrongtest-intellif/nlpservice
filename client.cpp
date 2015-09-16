#include <iostream>

#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TTransportUtils.h>

#include "thrift/gen-cpp/NlpService.h"

using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;


int main() {
  boost::shared_ptr<TTransport> socket(new TSocket("localhost", 9090));
  boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
  boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
  nlpservice::NlpServiceClient client(protocol);

  try {
    transport->open();
	std::string result;
	
	nlpservice::IctclasWork work;
	work.posmap = nlpservice::PosMap::ICT1;
	work.sentence = "linux下有很多工具可以制作启动盘";
	client.wordcut_ictclas(result, work);
    client.fan2jian_opencc(result, work.sentence);
	std::cout << result << std::endl;

  } catch (TException& tx) {
    std::cout << "ERROR: " << tx.what() << std::endl;
  }
}