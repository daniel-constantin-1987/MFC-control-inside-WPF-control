using System.Windows;
using WpfAppTest.ViewModels;
using WpfAppTest.Views.Controls;

namespace WpfAppTest
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private NativeControlHost _nativeControlHost;

        public MainWindow()
        {
            InitializeComponent();

            MfcBorderHost.Loaded += MfcBorderHost_Loaded;
        }

        public MainWindowViewModel Vm => DataContext as MainWindowViewModel;

        private void MfcBorderHost_Loaded(object sender, RoutedEventArgs e)
        {
            _nativeControlHost = new NativeControlHost(MfcBorderHost.ActualHeight, MfcBorderHost.ActualWidth, Vm.PluginNotificationHandler);

            MfcBorderHost.Child = _nativeControlHost;

            Vm.PropertyChanged += Vm_PropertyChanged;
        }

        private void Vm_PropertyChanged(object sender, System.ComponentModel.PropertyChangedEventArgs e)
        {
            if (e.PropertyName == nameof(MainWindowViewModel.IsMessageInMfcVisible))
            {
                _nativeControlHost.ShowMfcText(Vm.IsMessageInMfcVisible);
            }
        }
    }
}
