# Microsoft Developer Studio Project File - Name="pppcontroller" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=pppcontroller - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "pppcontroller.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "pppcontroller.mak" CFG="pppcontroller - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "pppcontroller - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "pppcontroller - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "pppcontroller - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD BASE RSC /l 0x809 /d "NDEBUG"
# ADD RSC /l 0x809 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386

!ELSEIF  "$(CFG)" == "pppcontroller - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /I "..\..\External\source_for_build\oncrpc" /I "..\include" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /FR /YX /FD /GZ /c
# ADD BASE RSC /l 0x809 /d "_DEBUG"
# ADD RSC /l 0x809 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 oncrpcms.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept /libpath:"..\..\BinInternal" /libpath:"..\..\External\binaries_for_build"

!ENDIF 

# Begin Target

# Name "pppcontroller - Win32 Release"
# Name "pppcontroller - Win32 Debug"
# Begin Group "RPC Generated Files"

# PROP Default_Filter ""
# Begin Group "include - nomod"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\pppcontroller.h
# End Source File
# End Group
# Begin Group "source - nomod"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\pppcontroller_svc.c
# End Source File
# Begin Source File

SOURCE=.\pppcontroller_svc_stub_impl.cpp
# End Source File
# Begin Source File

SOURCE=.\pppcontroller_xdr.c
# End Source File
# End Group
# Begin Group "modified"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\CSPppcontroller.cpp
# End Source File
# Begin Source File

SOURCE=.\CSPppcontroller.h
# End Source File
# Begin Source File

SOURCE=.\CSvcPppcontroller.cpp
# End Source File
# Begin Source File

SOURCE=.\CSvcPppcontroller.h
# End Source File
# End Group
# End Group
# Begin Group "include"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\include\CComponentManager.h
# End Source File
# Begin Source File

SOURCE=..\DynamicsConfigurationLibrary\file_utilities.h
# End Source File
# Begin Source File

SOURCE=..\ProcessLibrary\proclib.h
# End Source File
# Begin Source File

SOURCE=..\include\standard_service_manager.h
# End Source File
# Begin Source File

SOURCE=..\include\standard_unix.h
# End Source File
# End Group
# Begin Group "source"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\pdsnc_service.cpp

!IF  "$(CFG)" == "pppcontroller - Win32 Release"

!ELSEIF  "$(CFG)" == "pppcontroller - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\pppcontroller.x

!IF  "$(CFG)" == "pppcontroller - Win32 Release"

!ELSEIF  "$(CFG)" == "pppcontroller - Win32 Debug"

# Begin Custom Build
InputPath=.\pppcontroller.x

"pppcontroller.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	..\..\BinInternal\rpcgen -server  -component_base -wrapstring pppcontroller.x

# End Custom Build

!ENDIF 

# End Source File
# End Group
# End Target
# End Project
