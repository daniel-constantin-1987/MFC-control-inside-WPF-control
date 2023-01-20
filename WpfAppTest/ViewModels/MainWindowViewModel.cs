using Wrapper;

namespace WpfAppTest.ViewModels
{
    public class MainWindowViewModel : BaseViewModel
    {
        public PluginNotificationHandler PluginNotificationHandler { get; }

        private bool _isMessageInMfcVisible = true;
        public bool IsMessageInMfcVisible
        {
            get => _isMessageInMfcVisible;
            set
            {
                _isMessageInMfcVisible = value;
                RaisePropertyChanged();
            }
        }

        private bool _isLabelVisible;
        public bool IsLabelVisible
        {
            get => _isLabelVisible;
            set
            {
                _isLabelVisible = value;
                RaisePropertyChanged();
            }
        }

        public MainWindowViewModel()
        {
            PluginNotificationHandler = new PluginNotificationHandler();

            PluginNotificationHandler.HideWpfMessageChanged += OnHideWpfMessageChanged;
            PluginNotificationHandler.ShowWpfMessageChanged += OnShowWpfMessageChanged;
        }

        private void OnShowWpfMessageChanged(object sender, System.EventArgs e)
        {
            IsLabelVisible = true;
        }

        private void OnHideWpfMessageChanged(object sender, System.EventArgs e)
        {
            IsLabelVisible = false;
        }
    }
}
