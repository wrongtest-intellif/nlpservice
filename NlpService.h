#ifndef _NLPSERVICE_H_
#define _NLPSERVICE_H_

#include <thrift/concurrency/ThreadManager.h>
#include <thrift/concurrency/PosixThreadFactory.h>
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/server/TThreadPoolServer.h>
#include <thrift/server/TThreadedServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TTransportUtils.h>

#include <string>
#include <iostream>

#include "modules/opencc/OpenCC.h"
#include "modules/wordcut/WordCutIctclas.h"
#include "thrift/gen-cpp/NlpService.h"
#include "thrift/gen-cpp/nlpservice_types.h"

using namespace apache::thrift;
using namespace apache::thrift::concurrency;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;
using namespace apache::thrift::server;

namespace nlpservice 
{
	
class NlpService : public NlpServiceIf {
public:
	NlpService();

	void wordcut_ictclas(std::string& result, const IctclasWork& work);
    
    void fan2jian_opencc(std::string& result, const std::string& sentence);

    void jian2fan_opencc(std::string& result, const std::string& sentence);
    
private:
	int posMapIctclas;
	wordcut::WordCutIctclas wordCutIctclas;
    opencc::OpenCC openCC;
};

}

#endif