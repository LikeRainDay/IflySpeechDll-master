#include "CppInterAnnounce.h"
#include <iostream>
//����ʶ��
#include "ISE.h"
//����ת����
#include "TTS.h"



//���г�ʼ���ƴ������ʶ��
CPPDLL_API int __stdcall InitIflyISE() {
	printf("�Ѿ���ʼ��");
	std::cout << "�Ѿ���ʼ���Ѿ���ʼ���Ѿ���ʼ���Ѿ���ʼ���Ѿ���ʼ���Ѿ���ʼ��"<<std::endl;
	onInitalISE();
	return 1;
}
//���г�ʼ���ƴ�������ϳ�
CPPDLL_API void __stdcall InitIflyTTS() {
	bool isTTSSuccess = initalTTS();
	if (isTTSSuccess)
	{
		printf("TTS����ע��ɹ������ڿ���ʹ�ô�ģ��");
	}

}


// ����ֹͣ��ǰ������
CPPDLL_API void __stdcall StopRecognier() {
	onStopRecoginer();
}



//����������ǰ������
CPPDLL_API void  StartRecognier(Resoult result, SpeechBegin begin, SpeechEnd end) {

	/*std::cout << "������" << std::endl;
	if (result&&begin&&end)*/
		onStartRecognier(result, begin, end);
	/*else
		return;*/
 }
////��������ǰ��ʼ��״̬
//CPPDLL_API void  RecognierIsBegin(SpeechBegin begin) {
//
//
// }
////��������ǰ�Ľ���״̬
//CPPDLL_API void  RecognierIsEnd(SpeechEnd end) {
//
// }

//�������õ�ǰ�����ϳ�
CPPDLL_API int* __stdcall StartSynthesizer(wchar_t* content) {

	  onTextToSpeech((const char *)content);
	// TODO  ����ǰ�ϳɺ�Ľ�������û�ʹ��
	return 0;
 }



//����ע����ǰ�Ĳ���
CPPDLL_API void __stdcall onDestory() {
	onDestoryTTS();
	onDestoryISE();

}