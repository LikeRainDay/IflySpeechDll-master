#pragma once
#ifndef __ISE_SPEECH
#define __ISE_SPEECH
#include "CppInterAnnounce.h"

#ifdef __cplusplus
extern "C" {
#endif // !__cplusplus
	//���г�ʼ������ʶ��
	extern void onInitalISE();
	//������ǰ������ʶ��
	extern void  onStartRecognier(Resoult result, SpeechBegin begin, SpeechEnd end);
	////��������ǰ��ʼ��״̬
	//extern  void  Recognier_IsBegin(SpeechBegin begin);
	////s
	//extern  void  Recognier_IsEnd(SpeechEnd end);



	//�رյ�ǰ������ʶ��
	extern void onStopRecoginer();
	//���ٵ�ǰ������ʶ��
	extern void onDestoryISE();
	
	


#ifdef __cplusplus
}
#endif // !__cplusplus

#endif // !__ISE_SPEECH
