# sdl_bgi
windows / dos cross platform BGI(Borand Graphics Interface) development system

[Original sdl bgi Code](https://github.com/genpfault/sdl-bgi)  

## BUILD
* visual studio 2019 or higher
* vcpkg
```
git clone https://github.com/microsoft/vcpkg
bootstrap-vcpkg.bat
vcpkg install sdl2
vcpkg integrate install
```

* in release tab, download DOSBOX-X.rar and extract to project folder.

## Sample Tetris Project

### win32 result

<img src="./img/win32.png">

### dos result

<img src="./img/dos.png">
