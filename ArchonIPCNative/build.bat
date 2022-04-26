msbuild ArchonIPCNative.vcxproj /p:configuration=release /p:platform=x64
msbuild ArchonIPCNative.vcxproj /p:configuration=release /p:platform=Win32
msbuild ArchonIPCNative.vcxproj /p:configuration=release /p:platform=ARM64
msbuild ArchonIPCNative.vcxproj /p:configuration=release /p:platform=ARM
msbuild ArchonIPCNative.vcxproj /p:configuration=debug /p:platform=x64
msbuild ArchonIPCNative.vcxproj /p:configuration=debug /p:platform=Win32
msbuild ArchonIPCNative.vcxproj /p:configuration=debug /p:platform=ARM64
msbuild ArchonIPCNative.vcxproj /p:configuration=debug /p:platform=ARM
NuGet.exe pack ArchonIPCNative.nuspec