# Bye-Bye
Bye-Bye is a GUI application which can be run through CLI(mainly in linux) to perform various system operation such as lock , cancel, shutdown, logout, reboot, hibernate etc.

## How to compile and Run

```
git clone https://github.com/GOTAM672/Bye-Bye.git
cd Bye-Bye
gcc $( pkg-config --cflags gtk4 ) -o byebye main.c $( pkg-config --libs gtk4 )
./byebye
```


