#pragma once
#define CPPDLL_API __declspec(dllexport)

//����ֹͣ��ǰ������
extern "C" CPPDLL_API void __stdcall StopRecognier();


//ί���¼�
//���ݽ��
typedef void (__stdcall *Resoult)(wchar_t*  content );
//���ݿ�ʼ״̬
typedef void (__stdcall *SpeechBegin)();
//���ݽ���״̬
typedef void (__stdcall *SpeechEnd)();

//����������ǰ������

extern "C" CPPDLL_API void  StartRecognier(Resoult result, SpeechBegin begin,SpeechEnd end);
////��������ǰ��ʼ��״̬
//extern "C" CPPDLL_API void  RecognierIsBegin(SpeechBegin begin);
////��������ǰ�Ľ���״̬
//extern "C" CPPDLL_API void  RecognierIsEnd(SpeechEnd end);



//�������õ�ǰ�����ϳ�
extern "C" CPPDLL_API int* __stdcall StartSynthesizer(wchar_t* content);

////����ֹͣ��������
//extern "C" CPPDLL_API void __stdcall StopSynthesizer();

//���г�ʼ���ƴ������ʶ��
extern "C" CPPDLL_API int __stdcall InitIflyISE();


//���г�ʼ���ƴ�������ϳ�
extern "C" CPPDLL_API void __stdcall InitIflyTTS();


//�����ͷŵ�ǰ����Դ �������˳���ǰ  �ƴ�ĵ�½
extern "C" CPPDLL_API void __stdcall onDestory();

