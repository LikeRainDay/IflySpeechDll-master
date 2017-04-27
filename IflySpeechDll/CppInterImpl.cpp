#include "CppInterAnnounce.h"
#include <iostream>
//语音识别
#include "ISE.h"
//文字转语音
#include "TTS.h"



//进行初始化科大的语音识别
CPPDLL_API int __stdcall InitIflyISE() {
	printf("已经初始化");
	std::cout << "已经初始化已经初始化已经初始化已经初始化已经初始化已经初始化"<<std::endl;
	onInitalISE();
	return 1;
}
//进行初始化科大的语音合成
CPPDLL_API void __stdcall InitIflyTTS() {
	bool isTTSSuccess = initalTTS();
	if (isTTSSuccess)
	{
		printf("TTS功能注册成功，现在可以使用此模块");
	}

}


// 用来停止当前的语音
CPPDLL_API void __stdcall StopRecognier() {
	onStopRecoginer();
}



//用来开启当前的语音
CPPDLL_API void  StartRecognier(Resoult result, SpeechBegin begin, SpeechEnd end) {

	/*std::cout << "我走了" << std::endl;
	if (result&&begin&&end)*/
		onStartRecognier(result, begin, end);
	/*else
		return;*/
 }
////用来处理当前开始的状态
//CPPDLL_API void  RecognierIsBegin(SpeechBegin begin) {
//
//
// }
////用来处理当前的结束状态
//CPPDLL_API void  RecognierIsEnd(SpeechEnd end) {
//
// }

//用来设置当前语音合成
CPPDLL_API int* __stdcall StartSynthesizer(wchar_t* content) {

	  onTextToSpeech((const char *)content);
	// TODO  处理当前合成后的结果交给用户使用
	return 0;
 }



//用来注销当前的操作
CPPDLL_API void __stdcall onDestory() {
	onDestoryTTS();
	onDestoryISE();

}