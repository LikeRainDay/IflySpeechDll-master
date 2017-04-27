#pragma once
#define CPPDLL_API __declspec(dllexport)

//用来停止当前的语音
extern "C" CPPDLL_API void __stdcall StopRecognier();


//委托事件
//传递结果
typedef void (__stdcall *Resoult)(wchar_t*  content );
//传递开始状态
typedef void (__stdcall *SpeechBegin)();
//传递结束状态
typedef void (__stdcall *SpeechEnd)();

//用来开启当前的语音

extern "C" CPPDLL_API void  StartRecognier(Resoult result, SpeechBegin begin,SpeechEnd end);
////用来处理当前开始的状态
//extern "C" CPPDLL_API void  RecognierIsBegin(SpeechBegin begin);
////用来处理当前的结束状态
//extern "C" CPPDLL_API void  RecognierIsEnd(SpeechEnd end);



//用来设置当前语音合成
extern "C" CPPDLL_API int* __stdcall StartSynthesizer(wchar_t* content);

////用来停止语音播放
//extern "C" CPPDLL_API void __stdcall StopSynthesizer();

//进行初始化科大的语音识别
extern "C" CPPDLL_API int __stdcall InitIflyISE();


//进行初始化科大的语音合成
extern "C" CPPDLL_API void __stdcall InitIflyTTS();


//用来释放当前的资源 并进行退出当前  科大的登陆
extern "C" CPPDLL_API void __stdcall onDestory();

