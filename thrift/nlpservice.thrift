namespace cpp nlpservice
namespace java nlpservice
namespace php nlpservice

enum PosMap {
	PKU1,
	PKU2,
	ICT1,
	ICT2
}

struct IctclasWork {
  1: string sentence,
  2: PosMap posmap = PosMap.PKU1
}

exception InvalidOperation {

}

service NlpService {

   string wordcut_ictclas(1:IctclasWork work)

   string fan2jian_opencc(1:string sentence)
   
   string jian2fan_opencc(1:string sentence)
}
