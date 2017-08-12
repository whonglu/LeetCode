@echo off

del /s /f *.aps
del /s /f *.opt
del /s /f *.ncb
del /s /f *.plg
del /s /f *.exp
del /s /f *.ilk
del /s /f *.bak
del /s /f *.bsc
del /s /f *.obj
del /s /f *.res
del /s /f *.idb
del /s /f *.tlb
del /s /f *.pdb
del /s /f *.sbr
del /s /f *.pch
del /s /f *.sdf
del /s /f *.vcproj.*.user
del /s /f *.vcxproj.user
del /s /f *.vcxproj.filters
del /s /f *.tlog
del /s /f version.old
del /a:H /s /f *.suo
del /a:H /s /f _desktop.ini

set keyword=debug release
for %%j in (%keyword%) do (
for /f "delims=" %%k in ('dir /a:d /s/b "%%j"') do ( 
	    del /q /f "%%k"
	    rd /s /q "%%k"
	)
)

echo 完成清楚临时文件！
pause