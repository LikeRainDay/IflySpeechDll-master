#pragma once
#ifndef __TTS_SPEECH
#define __TTS_SPEECH


#ifdef __cplusplus
extern "C" {
#endif // !__cplusplus
	//用来初始化当前的TTS
	extern bool initalTTS();
	//用来注销当前的TTS
	extern void onDestoryTTS();
	//进行文本转文字
	extern void onTextToSpeech(const char* content);

#ifdef __cplusplus
}
#endif // !__cplusplus




#endif // !__ISE_SPEECH
