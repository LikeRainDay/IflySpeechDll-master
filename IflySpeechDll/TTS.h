#pragma once
#ifndef __TTS_SPEECH
#define __TTS_SPEECH


#ifdef __cplusplus
extern "C" {
#endif // !__cplusplus
	//������ʼ����ǰ��TTS
	extern bool initalTTS();
	//����ע����ǰ��TTS
	extern void onDestoryTTS();
	//�����ı�ת����
	extern void onTextToSpeech(const char* content);

#ifdef __cplusplus
}
#endif // !__cplusplus




#endif // !__ISE_SPEECH
