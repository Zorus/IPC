using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using IPC.Managed;
using ArchonIPC.Managed;

namespace ArchonIPC
{
    public class Server: IDisposable
    {
        public class ServerErrorEventArgs : EventArgs
        {
            private readonly System.Exception _error;
            public ServerErrorEventArgs(System.Exception e)
            {
                _error = e;
            }
            public System.Exception Exception => _error;
        }

        private readonly TransportFactory _factory;
        private readonly ITransport<Request, Response> _transport;
        private readonly IServersAccessor<Request, Response> _serversAccessor;

        public static Server Create(string address, IIPCRequestHandler requestHandler)
        {
            return new Server(address, requestHandler);
        }
        private Server(string address, IIPCRequestHandler requestHandler)
        {
            _factory = new TransportFactory();
            _factory.Register(typeof(ArchonIPC.Managed.Request).Assembly);
            _transport = _factory.Make<Request, Response>();
            _serversAccessor = _transport.AcceptServers(address, (inMemory, outMemory) => new IPCHandler(requestHandler, outMemory).Handle);
            _serversAccessor.Error += (obj, err) => Error(obj, new ServerErrorEventArgs(err.Exception));
        }

        public void Dispose()
        {
            foreach (var server in _serversAccessor.Servers)
            {
                server.Dispose();
            }
            _serversAccessor.Dispose();
            _transport.Dispose();
        }

        public event EventHandler<ServerErrorEventArgs> Error;
    }
}
