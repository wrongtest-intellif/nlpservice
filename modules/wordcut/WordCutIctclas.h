#ifndef _WORDCUT_ICTCLAS_H_
#define _WORDCUT_ICTCLAS_H_

#include <string>
#include "../../external/ictclas/include/NLPIR.h"

namespace wordcut 
{
	
class WordCutIctclas {
public:
	WordCutIctclas(const char* dataPath)
		:initialed(false) 
	{
		if(NLPIR_Init(dataPath, UTF8_CODE))
			initialed = true;	
	}
	
	~WordCutIctclas()
	{
		if (initialed)
			NLPIR_Exit();
	}
	
	void cut(std::string& result, const std::string& sentence)
	{
		if (!initialed)
			return;
		const char* buf = NLPIR_ParagraphProcess(sentence.c_str());
		result = buf;
	}
	
	void setpos(int pos)
	{
		if (pos != ICT_POS_MAP_FIRST &&
			pos != ICT_POS_MAP_SECOND &&
			pos != PKU_POS_MAP_SECOND &&
			pos != PKU_POS_MAP_FIRST)
			return;
		
		NLPIR_SetPOSmap(pos);
	}

private:
	bool initialed;
	
};

}
#endif