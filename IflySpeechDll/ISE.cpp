#pragma once

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#pragma warning(disable:4996)
	/*
	* ������д(iFly Auto Transform)�����ܹ�ʵʱ�ؽ�����ת���ɶ�Ӧ�����֡�
	*/

#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

#include <conio.h>
#include <errno.h>
#include <process.h>

#include "msp_cmn.h"
#include "msp_errors.h"
#include "speech_sample.h"
#include "ISE.h"

#define FRAME_LEN	640 
#define	BUFFER_SIZE	4096

	//����ȫ������
	struct speech_rec iat;
	//��ǰ�Ĵ������  ����Ϊ0
	int errcode;
	//�Ƿ��ʼ���ɹ�
	boolean isInitalSuccess = false;
	enum {
		EVT_START = 0,
		EVT_STOP,
		EVT_QUIT,
		EVT_TOTAL
	};


	inline void isInitSuccess() {
		if (!isInitalSuccess)return;
	}

	Resoult mResult = NULL;
	SpeechBegin mSpeechBegin = NULL;
	SpeechEnd mSpeechEnd = NULL;

	static HANDLE events[EVT_TOTAL] = { NULL,NULL,NULL };

	static COORD begin_pos = { 0, 0 };
	static COORD last_pos = { 0, 0 };
	//������ʾ�����Ľ��
	static void show_result(char *string, char is_over)
	{
		if (mResult)
		{
			printf("��ǰ����Ľ���� %s", string);
			mResult((wchar_t*)string);
			//free(mResult);
		}

		//COORD orig, current;
		//CONSOLE_SCREEN_BUFFER_INFO info;
		//HANDLE w = GetStdHandle(STD_OUTPUT_HANDLE);
		//GetConsoleScreenBufferInfo(w, &info);
		//current = info.dwCursorPosition;

		//if (current.X == last_pos.X && current.Y == last_pos.Y) {
		//	SetConsoleCursorPosition(w, begin_pos);
		//}
		//else {
		//	/* changed by other routines, use the new pos as start */
		//	begin_pos = current;
		//}
		//if (is_over)
		//	SetConsoleTextAttribute(w, FOREGROUND_GREEN);
		//printf("Result: [ %s ]\n", string);
		//if (is_over)
		//	SetConsoleTextAttribute(w, info.wAttributes);

		//GetConsoleScreenBufferInfo(w, &info);
		//last_pos = info.dwCursorPosition;
	}



	static char *g_result = NULL;
	static unsigned int g_buffersize = BUFFER_SIZE;

	void on_result(const char *result, char is_last)
	{
		if (result) {
			size_t left = g_buffersize - 1 - strlen(g_result);
			size_t size = strlen(result);
			if (left < size) {
				g_result = (char*)realloc(g_result, g_buffersize + BUFFER_SIZE);
				if (g_result)
					g_buffersize += BUFFER_SIZE;
				else {
					printf("mem alloc failed\n");
					return;
				}
			}
			strncat(g_result, result, size);
			show_result(g_result, is_last);
		}
	}
	void on_speech_begin()
	{
		if (g_result)
		{
			free(g_result);
		}
		g_result = (char*)malloc(BUFFER_SIZE);
		g_buffersize = BUFFER_SIZE;
		memset(g_result, 0, g_buffersize);

		if (mSpeechBegin)
		{
			mSpeechBegin();
		}

		printf("Start Listening...\n");
	}
	void on_speech_end(int reason)
	{
		if (reason == END_REASON_VAD_DETECT)
			printf("\nSpeaking done \n");
		if (mSpeechEnd)
		{
			mSpeechEnd();
		}
		else
			printf("\nRecognizer error %d\n", reason);



	}

	
	

	//��������ֹͣ��ǰ������ʶ��
	 void onStopRecoginer(){
		 isInitSuccess();
		 if (errcode = sr_stop_listening(&iat)) {
			 printf("stop listening failed %d\n", errcode);
			
		 }
	 
	 }

	 //�������ٵ�ǰ������ʶ��
	 void onDestoryISE(){
		 isInitSuccess();
		 sr_uninit(&iat);
	 }
	
	 void onStartRecognier(Resoult result, SpeechBegin begin, SpeechEnd end) {
		 isInitSuccess();
		 mResult = result;
		 mSpeechBegin =begin;
		 mSpeechEnd = end;
		 if (errcode = sr_start_listening(&iat)) {
			 printf("stop listening failed %d\n", errcode);
		 }
	 }
	 ////��������ǰ��ʼ��״̬
	 //void Recognier_IsBegin(SpeechBegin begin);
	
	 // void  Recognier_IsEnd(SpeechEnd end);



	 //������ʼ��ISE�������ϳ�
	 void onInitalISE() {
		 printf("���г�ʼ��");

		 struct speech_rec_notifier recnotifier = {
			 on_result,
			 on_speech_begin,
			 on_speech_end
		 };

		 int         ret = MSP_SUCCESS;
		 const char* login_params = "appid = 58d4949a, work_dir = .";//��¼����,appid��msc���,��������Ķ�
		 ret = MSPLogin(NULL, NULL, login_params); //��һ���������û������ڶ������������룬�����������ǵ�¼�������û������������http://www.xfyun.cnע���ȡ
		 printf("��Ȩ�ɹ� %d", ret);
		 if (MSP_SUCCESS != ret) {
			 //ע��ɹ�
			 printf("��Ȩ�ɹ�");
		 }

		 /*
		 * sub:				����ҵ������
		 * domain:			����
		 * language:			����
		 * accent:			����
		 * sample_rate:		��Ƶ������
		 * result_type:		ʶ������ʽ
		 * result_encoding:	��������ʽ
		 *
		 * ��ϸ����˵������ġ�iFlytek MSC Reference Manual��
		 */
		 const char* session_begin_params = "sub = iat, domain = iat, language = zh_cn, accent = mandarin, sample_rate = 16000, result_type = plain, result_encoding = gb2312";
		 errcode = sr_init(&iat, session_begin_params, SR_MIC, DEFAULT_INPUT_DEVID, &recnotifier);
		 if (errcode) {
			 printf("speech recognizer init failed\n");
			 isInitalSuccess = false;
			 return;
		 }
		 isInitalSuccess = true;
	 }


	///* main thread: start/stop record ; query the result of recgonization.
	//* record thread: record callback(data write)
	//* helper thread: ui(keystroke detection)
	//*/
	//int main(int argc, char* argv[])
	//{
	//	int			ret = MSP_SUCCESS;
	//	int			upload_on = 1; //�Ƿ��ϴ��û��ʱ�
	//	const char* login_params = "appid = 58d8b9b7, work_dir = ."; // ��¼������appid��msc���,��������Ķ�
	//	int aud_src = 0;

	//	/*
	//	* sub:				����ҵ������
	//	* domain:			����
	//	* language:			����
	//	* accent:			����
	//	* sample_rate:		��Ƶ������
	//	* result_type:		ʶ������ʽ
	//	* result_encoding:	��������ʽ
	//	*
	//	* ��ϸ����˵������ġ�iFlytek MSC Reference Manual��
	//	*/
	//	const char* session_begin_params = "sub = iat, domain = iat, language = zh_cn, accent = mandarin, sample_rate = 16000, result_type = plain, result_encoding = gb2312";

	//	/* �û���¼ */
	//	ret = MSPLogin(NULL, NULL, login_params); //��һ���������û������ڶ������������룬����NULL���ɣ������������ǵ�¼����	
	//	if (MSP_SUCCESS != ret) {
	//		printf("MSPLogin failed , Error code %d.\n", ret);
	//		goto exit; //��¼ʧ�ܣ��˳���¼
	//	}

	//	printf("\n########################################################################\n");
	//	printf("## ������д(iFly Auto Transform)�����ܹ�ʵʱ�ؽ�����ת���ɶ�Ӧ�����֡�##\n");
	//	printf("########################################################################\n\n");
	//	printf("��ʾʾ��ѡ��:�Ƿ��ϴ��û��ʱ�\n0:��ʹ��\n1:ʹ��\n");

	//	scanf("%d", &upload_on);
	//	if (upload_on)
	//	{
	//		printf("�ϴ��û��ʱ� ...\n");
	//		ret = upload_userwords();
	//		if (MSP_SUCCESS != ret)
	//			goto exit;
	//		printf("�ϴ��û��ʱ�ɹ�\n");
	//	}

	//	printf("��Ƶ��������? \n0: ���ļ�����\n1:��MIC˵��\n");
	//	scanf("%d", &aud_src);
	//	if (aud_src != 0) {
	//		demo_mic(session_begin_params);
	//	}
	//	else {
	//		//iflytek02��Ƶ����Ϊ���������ء�������ϴ����û��ʱ�ʶ����Ϊ���������ٿء���;
	//		demo_file("wav/iflytek02.wav", session_begin_params);
	//	}
	//exit:
	//	printf("��������˳� ...\n");
	//	_getch();
	//	MSPLogout(); //�˳���¼

	//	return 0;
	//}



#ifdef __cplusplus
}
#endif // __cplusplus

