using System;
using System.Runtime.InteropServices;
using System.Windows.Interop;
using Wrapper;

namespace WpfAppTest.Views.Controls
{
    public class NativeControlHost : HwndHost
    {
        internal const int WS_CHILD = 0x40000000, WS_VISIBLE = 0x10000000, HOST_ID = 0x00000002, WS_MAXIMIZE = 0x01000000;

        private IntPtr _hwndHost, _hwndControl;
        private int _hostHeight, _hostWidth;
        private PluginNotificationHandler _pluginNotificationHandler;

        private WrappedDialog _wrappedDialog;

        public NativeControlHost(double height, double width, PluginNotificationHandler pluginNotificationHandler)
        {
            _hostHeight = (int)height;
            _hostWidth = (int)width;
            _pluginNotificationHandler = pluginNotificationHandler;
        }

        protected override HandleRef BuildWindowCore(HandleRef hwndParent)
        {
            _hwndControl = IntPtr.Zero;
            _hwndHost = IntPtr.Zero;

            _hwndHost = CreateWindowEx(0, "static", "", WS_CHILD | WS_VISIBLE | WS_MAXIMIZE, 0, 0, _hostWidth, _hostHeight, hwndParent.Handle, (IntPtr)HOST_ID, IntPtr.Zero, 0);

            _wrappedDialog = new WrappedDialog(_hwndHost, _pluginNotificationHandler);

            return new HandleRef(this, _hwndHost);
        }

        public void ShowMfcText(bool show)
        {
            _wrappedDialog.ShowMfcText(show);
        }

        protected override void DestroyWindowCore(HandleRef hwnd)
        {
            DestroyWindow(hwnd.Handle);
        }

        protected override IntPtr WndProc(IntPtr hwnd, int msg, IntPtr wParam, IntPtr lParam, ref bool handled)
        {
            handled = false;
            return IntPtr.Zero;
        }

        //PInvoke declarations
        [DllImport("user32.dll", EntryPoint = "CreateWindowEx", CharSet = CharSet.Unicode)]
        internal static extern IntPtr CreateWindowEx(int dwExStyle, string lpszClassName, string lpszWindowName, int style, int x, int y, int width, int height, 
            IntPtr hwndParent, IntPtr hMenu, IntPtr hInst, [MarshalAs(UnmanagedType.AsAny)] object pvParam);

        [DllImport("user32.dll", EntryPoint = "DestroyWindow", CharSet = CharSet.Unicode)]
        internal static extern bool DestroyWindow(IntPtr hwnd);
    }
}
