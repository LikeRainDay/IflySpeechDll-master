#pragma once
#ifndef __ISE_SPEECH
#define __ISE_SPEECH
#include "CppInterAnnounce.h"

#ifdef __cplusplus
extern "C" {
#endif // !__cplusplus
	//进行初始化语音识别
	extern void onInitalISE();
	//开启当前的语音识别
	extern void  onStartRecognier(Resoult result, SpeechBegin begin, SpeechEnd end);
	////用来处理当前开始的状态
	//extern  void  Recognier_IsBegin(SpeechBegin begin);
	////s
	//extern  void  Recognier_IsEnd(SpeechEnd end);



	//关闭当前的语音识别
	extern void onStopRecoginer();
	//销毁当前的语音识别
	extern void onDestoryISE();
	
	


#ifdef __cplusplus
}
#endif // !__cplusplus

#endif // !__ISE_SPEECH
