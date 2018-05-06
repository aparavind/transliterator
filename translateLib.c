/*
    this is a library file which actaully doest teh transliteration
    the main function is TranslateT
    written in C linux from https://github.com/forevergenin/phtranslator/blob/master/PhTranslateLib/PhTranslateLib.cpp
*/

include "translatelib.h"

inline size_t TranslateT(void* Translator, const T szInput, wstring& retStr)
{
	transliterator* Transliterator = (transliterator*) Translator;
	if(Transliterator != NULL && szInput != NULL)
	{
		// Do the Translation using the Translator
		return Translate(szInput, retStr);
	}
	return 0;
}
