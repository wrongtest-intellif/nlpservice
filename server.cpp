#include "NlpService.h"
using namespace nlpservice;

int main() {
  boost::shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());
  boost::shared_ptr<NlpService> handler(new NlpService());
  boost::shared_ptr<TProcessor> processor(new NlpServiceProcessor(handler));
  boost::shared_ptr<TServerTransport> serverTransport(new TServerSocket(9090));
  boost::shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);

  std::cout << "Starting the server..." << std::endl;
  server.serve();
  std::cout << "Done." << std::endl;
  return 0;
}
