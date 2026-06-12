[Setup]
AppName=SFDLSaugerPro
AppVersion={#AppVersion}
DefaultDirName={autopf}\SFDLSaugerPro
DefaultGroupName=SFDLSaugerPro
UninstallDisplayIcon={app}\SFDLSaugerPro.exe
Compression=lzma2
SolidCompression=yes
OutputDir=.
OutputBaseFilename=SFDLSaugerPro-windows-v{#AppVersion}-Installer

[Tasks]
Name: installvc; Description: "Visual C++ 2015-2022 Redistributable (x64) installieren"; Flags: checkedonce

[Files]
Source: "release\*"; DestDir: "{app}"; Flags: recursesubdirs createallsubdirs
Source: "release\vc_redist.x64.exe"; DestDir: "{tmp}"; Flags: deleteafterinstall

[Icons]
Name: "{group}\SFDLSaugerPro"; Filename: "{app}\SFDLSaugerPro.exe"
Name: "{autodesktop}\SFDLSaugerPro"; Filename: "{app}\SFDLSaugerPro.exe"

[Run]
Filename: "{tmp}\vc_redist.x64.exe"; Parameters: "/passive /norestart"; StatusMsg: "Installiere Microsoft Visual C++ Runtime..."; Tasks: installvc; Flags: waituntilterminated
