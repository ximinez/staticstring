## MSBuild

Start the "x86 Native Tools Command Prompt for VS 2019"

```
C:\Program Files (x86)\Microsoft Visual Studio\2019\Community>cd \dev\staticstring

C:\Dev\staticstring>msbuild staticstring.sln
Microsoft (R) Build Engine version 16.7.0+b89cb5fde for .NET Framework
Copyright (C) Microsoft Corporation. All rights reserved.

Building the projects in this solution one at a time. To enable parallel build, please add the "-m" switch.
Build started 8/25/2020 11:46:08 AM.
Project "C:\Dev\staticstring\staticstring.sln" on node 1 (default targets).
ValidateSolutionConfiguration:
  Building solution configuration "Debug|x86".
Project "C:\Dev\staticstring\staticstring.sln" (1) is building "C:\Dev\staticstring\staticstring.vcxproj" (2) on node 1
 (default targets).
InitializeBuildStatus:
  Creating "Debug\staticstring.tlog\unsuccessfulbuild" because "AlwaysCreate" was specified.
ClCompile:
  C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.27.29110\bin\HostX86\x86\CL.exe /c /ZI
   /JMC /nologo /W3 /WX- /diagnostics:column /sdl /Od /Oy- /D WIN32 /D _DEBUG /D _CONSOLE /D _UNICODE /D UNICODE /Gm- /
  EHsc /RTC1 /MDd /GS /fp:precise /permissive- /Zc:wchar_t /Zc:forScope /Zc:inline /Fo"Debug\\" /Fd"Debug\vc142.pdb" /G
  d /TP /analyze- /FC /errorReport:queue staticstring\staticstring.cpp
  staticstring.cpp
Link:
  C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.27.29110\bin\HostX86\x86\link.exe /ERR
  ORREPORT:QUEUE /OUT:"C:\Dev\staticstring\Debug\staticstring.exe" /INCREMENTAL /NOLOGO kernel32.lib user32.lib gdi32.l
  ib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /MANIFE
  ST /MANIFESTUAC:"level='asInvoker' uiAccess='false'" /manifest:embed /DEBUG:FASTLINK /PDB:"C:\Dev\staticstring\Debug\
  staticstring.pdb" /SUBSYSTEM:CONSOLE /TLBID:1 /DYNAMICBASE /NXCOMPAT /IMPLIB:"C:\Dev\staticstring\Debug\staticstring.
  lib" /MACHINE:X86 Debug\staticstring.obj
  staticstring.vcxproj -> C:\Dev\staticstring\Debug\staticstring.exe
FinalizeBuildStatus:
  Deleting file "Debug\staticstring.tlog\unsuccessfulbuild".
  Touching "Debug\staticstring.tlog\staticstring.lastbuildstate".
Done Building Project "C:\Dev\staticstring\staticstring.vcxproj" (default targets).

Done Building Project "C:\Dev\staticstring\staticstring.sln" (default targets).


Build succeeded.
    0 Warning(s)
    0 Error(s)

Time Elapsed 00:00:01.25

C:\Dev\staticstring>Debug\staticstring.exe
a: 00D69B34 test
b: 00D69B34 test
passed at C:\Dev\staticstring\staticstring\staticstring.cpp(31): strcmp(a, b) == 0
passed at C:\Dev\staticstring\staticstring\staticstring.cpp(32): a == b
passed at C:\Dev\staticstring\staticstring\staticstring.cpp(33): a == test
passed at C:\Dev\staticstring\staticstring\staticstring.cpp(34): test == b
passed at C:\Dev\staticstring\staticstring\staticstring.cpp(35): test == test
```

## CMake

Keep the same command prompt open

```
C:\Dev\staticstring>mkdir build

C:\Dev\staticstring>cd build

C:\Dev\staticstring\build>cmake ..
-- Building for: Visual Studio 16 2019
-- Selecting Windows SDK version 10.0.18362.0 to target Windows 10.0.19041.
-- The C compiler identification is MSVC 19.27.29111.0
-- The CXX compiler identification is MSVC 19.27.29111.0
-- Check for working C compiler: C:/Program Files (x86)/Microsoft Visual Studio/2019/Community/VC/Tools/MSVC/14.27.29110/bin/Hostx64/x64/cl.exe
-- Check for working C compiler: C:/Program Files (x86)/Microsoft Visual Studio/2019/Community/VC/Tools/MSVC/14.27.29110/bin/Hostx64/x64/cl.exe - works
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Detecting C compile features
-- Detecting C compile features - done
-- Check for working CXX compiler: C:/Program Files (x86)/Microsoft Visual Studio/2019/Community/VC/Tools/MSVC/14.27.29110/bin/Hostx64/x64/cl.exe
-- Check for working CXX compiler: C:/Program Files (x86)/Microsoft Visual Studio/2019/Community/VC/Tools/MSVC/14.27.29110/bin/Hostx64/x64/cl.exe - works
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done
-- Generating done
-- Build files have been written to: C:/Dev/staticstring/build

C:\Dev\staticstring\build>cmake --build . -- -m
Microsoft (R) Build Engine version 16.7.0+b89cb5fde for .NET Framework
Copyright (C) Microsoft Corporation. All rights reserved.

  Checking Build System
  Building Custom Rule C:/Dev/staticstring/CMakeLists.txt
  staticstring.cpp
  staticstring.vcxproj -> C:\Dev\staticstring\build\Debug\staticstring.exe
  Building Custom Rule C:/Dev/staticstring/CMakeLists.txt

C:\Dev\staticstring\build>Debug\staticstring.exe
a: 00007FF76FA7ADF0 test
b: 00007FF76FA7ADE8 test
passed at C:\Dev\staticstring\staticstring\staticstring.cpp(31): strcmp(a, b) == 0
FAILED at C:\Dev\staticstring\staticstring\staticstring.cpp(32): a == b
FAILED at C:\Dev\staticstring\staticstring\staticstring.cpp(33): a == test
passed at C:\Dev\staticstring\staticstring\staticstring.cpp(34): test == b
passed at C:\Dev\staticstring\staticstring\staticstring.cpp(35): test == test
```

### Only fails in Debug builds

```
C:\Dev\staticstring\build>cmake --build . --config Release -- -m
Microsoft (R) Build Engine version 16.7.0+b89cb5fde for .NET Framework
Copyright (C) Microsoft Corporation. All rights reserved.

  Checking Build System
  Building Custom Rule C:/Dev/staticstring/CMakeLists.txt
  staticstring.cpp
  staticstring.vcxproj -> C:\Dev\staticstring\build\Release\staticstring.exe
  Building Custom Rule C:/Dev/staticstring/CMakeLists.txt

C:\Dev\staticstring\build>Release\staticstring.exe
a: 00007FF614933280 test
b: 00007FF614933280 test
passed at C:\Dev\staticstring\staticstring\staticstring.cpp(31): strcmp(a, b) == 0
passed at C:\Dev\staticstring\staticstring\staticstring.cpp(32): a == b
passed at C:\Dev\staticstring\staticstring\staticstring.cpp(33): a == test
passed at C:\Dev\staticstring\staticstring\staticstring.cpp(34): test == b
passed at C:\Dev\staticstring\staticstring\staticstring.cpp(35): test == test

```

