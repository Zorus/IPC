# IPC

[![MIT licensed](https://img.shields.io/badge/license-MIT-blue.svg)](https://github.com/Microsoft/IPC/blob/master/LICENSE) [![Build status](https://ci.appveyor.com/api/projects/status/dl929xf6rgaj257b/branch/master?svg=true)](https://ci.appveyor.com/project/ara-ayvazyan/ipc/branch/master)

IPC is a C++ library that provides inter-process communication using shared memory on Windows.<br/>
A .NET wrapper is available which allows interaction with C++ as well.

Integration with [Bond](https://github.com/Microsoft/bond) is available at [IPC.Bond](https://github.com/Microsoft/IPC.Bond).

# Build

The library is developed and maintained with [Visual Studio 2019](https://docs.microsoft.com/en-us/visualstudio/windows/?view=vs-2019).
To get started, open the [IPC.sln](https://github.com/Microsoft/IPC/blob/master/IPC.sln) file and build the solution.
To build the ArchonIPCNative.nupkg, run the [ArchonIPCNative\build.bat](https://github.com/zorus/IPC/blob/master/ArchonIPCNative/build.bat) from Developer Comand Prompt.
To build the ArchonIPCManaged.nupkg, run the [ArchonIPCManaged\build.bat](https://github.com/zorus/IPC/blob/master/ArchonIPCManaged/build.bat) from Developer Comand Prompt.
The [Boost package](https://www.nuget.org/packages/boost/) will automatically start downloading during the first build.

# Getting Started

Start with [examples](https://github.com/Microsoft/IPC/tree/master/Examples), [C++](https://github.com/Microsoft/IPC/blob/master/UnitTests/TransportTests.cpp) and [C#](https://github.com/Microsoft/IPC/blob/master/UnitTestsManaged/TransportTests.cs) tests.

# Contributing

This project has adopted the [Microsoft Open Source Code of Conduct](https://opensource.microsoft.com/codeofconduct/). For more information see the [Code of Conduct FAQ](https://opensource.microsoft.com/codeofconduct/faq/) or contact [opencode@microsoft.com](mailto:opencode@microsoft.com) with any additional questions or comments.

# License

Copyright (c) Microsoft Corporation. All rights reserved.

Licensed under the [MIT](https://github.com/Microsoft/IPC/blob/master/LICENSE) License.
