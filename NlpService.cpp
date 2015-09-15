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

#include "NlpService.h"

using namespace apache::thrift;
using namespace apache::thrift::concurrency;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;
using namespace apache::thrift::server;

namespace nlpservice 
{

NlpService::NlpService()
	: posMapIctclas(0),
	 wordCutIctclas("external/ictclas")
{
	wordCutIctclas.setpos(posMapIctclas);
}

void NlpService::wordcut_ictclas(std::string& result, const IctclasWork& work)
{
	int curPosMap = -1;
	switch(work.posmap)
	{
		case PosMap::ICT1:
			curPosMap = ICT_POS_MAP_FIRST;
			break;
		case PosMap::ICT2:
			curPosMap = ICT_POS_MAP_FIRST;
			break;ICT_POS_MAP_SECOND;
		case PosMap::PKU1:
			curPosMap = PKU_POS_MAP_FIRST;
			break;
		case PosMap::PKU2:
			curPosMap = PKU_POS_MAP_SECOND;
			break;
	}
	
	if (curPosMap != posMapIctclas)
	{
		wordCutIctclas.setpos(curPosMap);
	}
		
	result = wordCutIctclas.cut(work.sentence.c_str());
	return;
}

}