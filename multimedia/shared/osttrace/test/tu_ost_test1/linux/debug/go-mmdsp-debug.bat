@CALL setenv.bat
@IF NOT "%ERRORLEVEL%" == "0" (
@GOTO fatal_error
)


%PERLEXEC% -S ../../../../../launcher/launcher.pl --debug_port T32MMDSP:E04040005911:SVA --mode=hot --platform href_v1-linux 
