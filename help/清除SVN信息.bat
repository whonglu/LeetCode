@echo off
cls
color 1f
echo -------------------------------------------------------------------------------
echo.
echo      ���������ǰĿ¼����������Ŀ¼�����SVN��ʱ�ļ���Ϣ���Ƿ�Ҫ����......
echo.     
echo -------------------------------------------------------------------------------

:cl
echo.
set /p no=          ������ Y (����)�� N (�˳�)��
echo.
if /I "%no%"=="y" goto ks
if /I "%no%"=="n" exit
echo           �����������������...
goto cl

:ks
for /f "delims=" %%k in ('dir /a:d /s/b ".svn"') do ( 
            echo "%%k"
	    rd /s/q "%%k"
	)
)

rd /s/q .svn

echo ������SVN��ʱ�ļ���
pause