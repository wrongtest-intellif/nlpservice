#encoding=utf-8
import sys
sys.path.append('gen-py')

from nlpservice import NlpService
from nlpservice.ttypes import *

from thrift import Thrift
from thrift.transport import TSocket
from thrift.transport import TTransport
from thrift.protocol import TBinaryProtocol

class NlpServiceClient:

    def __init__(self, host, port, posmap=PosMap.PKU1):    
        try:
            transport = TSocket.TSocket(host, port)
            transport = TTransport.TBufferedTransport(transport)
            protocol = TBinaryProtocol.TBinaryProtocol(transport)
            
            self.client = NlpService.Client(protocol)
            self.posmap = posmap
            transport.open()
            
        except Thrift.TException, tx:
            print '%s' % (tx.message)
            
    def wordcut_ictclas(self, sentence):
        work = IctclasWork(sentence, self.posmap)
        return self.client.wordcut_ictclas(work);
    
    def fan2jian_opencc(self, sentence):
        return self.client.fan2jian_opencc(sentence)

    def jian2fan_opencc(self, sentence):
        return self.client.jian2fan_opencc(sentence)
    
    def close(self):
        try:
            transport.close()
        except:
            pass
    
    # with clause
    def __enter__(self):
        return self
    def __exit__(self, exc_type, exc_value, traceback):
        self.close()


if __name__=="__main__":
    with NlpServiceClient('localhost',9090) as client:
        print client.wordcut_ictclas("linux下有很多工具可以制作启动盘")
        print client.fan2jian_opencc("linux下有很多工具可以制作启动盘");
        print client.jian2fan_opencc("linux下有很多工具可以制作启动盘");