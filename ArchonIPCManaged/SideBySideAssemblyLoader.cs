using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace ArchonIPC
{
    internal class SideBySideAssemblyLoader
    {
        private static SideBySideAssemblyLoader assemblyLoader = null;
        public static void Set()
        {
            if(assemblyLoader == null)
            {
                assemblyLoader = new SideBySideAssemblyLoader();
            }
        }

        private SideBySideAssemblyLoader()
        {
            System.AppDomain.CurrentDomain.AssemblyResolve += CustomResolve;
        }

        private System.Reflection.Assembly CustomResolve(
            object sender,
            System.ResolveEventArgs args)
        {
            var name = GetDLLName(args.Name);
            if (!string.IsNullOrEmpty(name))
            {
                if (Environment.Is64BitProcess)
                {
                    string fileName = System.IO.Path.GetFullPath($"x64\\{name}");
                    System.Console.WriteLine(fileName);
                    if (System.IO.File.Exists(fileName))
                    {
                        return System.Reflection.Assembly.LoadFile(fileName);
                    }
                }
                else
                {
                    string fileName = System.IO.Path.GetFullPath($"x86\\{name}");
                    System.Console.WriteLine(fileName);
                    if (System.IO.File.Exists(fileName))
                    {
                        return System.Reflection.Assembly.LoadFile(fileName);
                    }
                }
            }
            return null;
        }

        private string GetDLLName(string assemblyName)
        {
            if (assemblyName.StartsWith("ArchonIPCInterop"))
            {
                return "ArchonIPCInterop.dll";
            }
            if (assemblyName.StartsWith("IPC.Managed"))
            {
                return "IPC.Managed.dll";
            }
            if (assemblyName.StartsWith("IPC.Containers.Managed"))
            {
                return "IPC.Containers.Managed.dll";
            }
            return null;
        }
    }
}
