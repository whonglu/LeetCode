@echo off
cls
color 1f
echo -------------------------------------------------------------------------------
echo.
echo      即将清楚当前目录及其所有子目录下面的SVN临时文件信息，是否要继续......
echo.     
echo -------------------------------------------------------------------------------

:cl
echo.
set /p no=          请输入 Y (继续)或 N (退出)：
echo.
if /I "%no%"=="y" goto ks
if /I "%no%"=="n" exit
echo           输入错误，请重新输入...
goto cl

:ks
for /f "delims=" %%k in ('dir /a:d /s/b ".svn"') do ( 
            echo "%%k"
	    rd /s/q "%%k"
	)
)

rd /s/q .svn

echo 完成清楚SVN临时文件！
pause