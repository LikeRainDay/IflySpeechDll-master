using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Runtime.InteropServices;
namespace IflyDemoTest
{
    static class Program
    {





        //[DllImport(@"E:\GitHubSample\IflySpeechDll\Debug\IflySpeechDll.dll", EntryPoint = "InitIflyISE")]
        //extern static void InitIflyISE();


        /// <summary>
        /// 应用程序的主入口点。
        /// </summary>
        [STAThread]
        static void Main()
        {
          
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new Form1());
            //InitIflyISE();
        }
    }
}
