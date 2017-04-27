using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Runtime.InteropServices;

namespace IflyDemoTest
{
    public partial class Form1 : Form
    {

        //停止当前的识别
        [DllImport(@"E:\GitHubSample\IflySpeechDll-master\x64\Release\IflySpeechDll.dll", EntryPoint= "StopRecognier", SetLastError = true, CharSet = CharSet.Ansi, ExactSpelling = false, CallingConvention = CallingConvention.Cdecl)]
        extern static void  StopRecognier();
        //委托事件
        [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        public delegate void Resoult(string resoult);
        static Resoult mResoult;
        static void CSCallResoult(string resoult)
        {
            
            Console.WriteLine("委托结果的数据"+resoult);
        }
        [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        public delegate void SpeechBegin();
        static SpeechBegin mSpeechBegin;
        static void CSCallSpeechBegin()
        {
            Console.WriteLine("SpeechBegin" );
        }
        [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        public delegate void SpeechEnd();
        static SpeechEnd mSpeechEnd;
        static void CSCallSpeechEnd()
        {
            Console.WriteLine("SpeechEnd");
        }
        //开启当前的识别
        [DllImport(@"E:\GitHubSample\IflySpeechDll-master\x64\Release\IflySpeechDll.dll", EntryPoint = "StartRecognier", SetLastError = true, CharSet = CharSet.Ansi, ExactSpelling = false, CallingConvention = CallingConvention.Cdecl)]
        extern static void StartRecognier(Resoult resolut, SpeechBegin speechBegin,SpeechEnd speechEnd);


        [DllImport(@"E:\GitHubSample\IflySpeechDll-master\x64\Release\IflySpeechDll.dll", EntryPoint = "InitIflyISE", SetLastError = true, CharSet = CharSet.Ansi, ExactSpelling = false, CallingConvention = CallingConvention.Cdecl)]
        extern static int InitIflyISE();



        //[DllImport(@"E:\GitHubSample\IflySpeechDll\Release\CplugplugDemo.dll", EntryPoint = "StopRecognier")]
        //extern static void StopRecognier();
        //[DllImport(@"E:\GitHubSample\IflySpeechDll\Release\CplugplugDemo.dll", EntryPoint = "StopRecognier")]
        //[DllImport(@"E:\GitHubSample\IflySpeechDll\Release\CplugplugDemo.dll", EntryPoint = "StopRecognier")]
        //extern static void StopRecognier();
        //extern static void StopRecognier();


        public Form1()
        {
            InitializeComponent();
            Console.WriteLine("11111");
            int i= InitIflyISE();
            Console.WriteLine("22222---{0}" ,i);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            mResoult =   new Resoult(Form1.CSCallResoult);
            mSpeechEnd =   new SpeechEnd(Form1.CSCallSpeechEnd) ;
            mSpeechBegin = new SpeechBegin(Form1.CSCallSpeechBegin);
            StartRecognier(mResoult, mSpeechBegin, mSpeechEnd);
        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }



    }
}
