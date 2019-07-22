cmake . -G "Visual Studio 15 2017" -T v141
del /Q /S "ALL_BUILD.vcxproj" "ALL_BUILD.vcxproj.filters"
pause