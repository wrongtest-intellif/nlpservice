#ifndef _WORDCUT_ICTCLAS_H_
#define _WORDCUT_ICTCLAS_H_

#include "../external/ictclas/include/NLPIR.h"

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
	
	const char* cut(const char*sentence)
	{
		if (!initialed)
			return NULL;
		const char* result = NLPIR_ParagraphProcess(sentence);
		return result;
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