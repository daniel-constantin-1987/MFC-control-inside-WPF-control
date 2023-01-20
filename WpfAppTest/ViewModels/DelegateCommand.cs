using System;
using System.Threading;
using System.Windows.Input;

namespace WpfAppTest.ViewModels
{
    public class DelegateCommand : ICommand
    {
        private SynchronizationContext _synchronizationContext;

        public virtual event EventHandler CanExecuteChanged;

        private Action _executeMethod;
        private Func<bool> _canExecuteMethod;

        public DelegateCommand(Action executeMethod) : this(executeMethod, () => true)
        {
        }

        public DelegateCommand(Action executeMethod, Func<bool> canExecuteMethod)
        {
            _executeMethod = executeMethod ?? throw new ArgumentNullException(nameof(executeMethod));
            _canExecuteMethod = canExecuteMethod;

            _synchronizationContext = SynchronizationContext.Current;
        }

        public void RaiseCanExecuteChanged()
        {
            EventHandler handler = CanExecuteChanged;
            if (handler != null)
            {
                if (_synchronizationContext != null && _synchronizationContext != SynchronizationContext.Current)
                {
                    _synchronizationContext.Post(delegate
                    {
                        handler(this, EventArgs.Empty);
                    }, null);
                }
                else
                {
                    handler(this, EventArgs.Empty);
                }
            }
        }

        public void Execute()
        {
            _executeMethod();
        }

        public bool CanExecute()
        {
            return _canExecuteMethod();
        }

        void ICommand.Execute(object parameter)
        {
            Execute();
        }

        bool ICommand.CanExecute(object parameter)
        {
            return CanExecute();
        }
    }
}
