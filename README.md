# Neoe Arduino Keyboard

## The Story

According to 
[Arduino as a HID Keyboard](http://forum.arduino.cc/index.php?topic=99.0) 
Arduino Uno can used as a usb keyboard, Uno has 2 atmega chips, 1x `atmega328P` as main MCU, 1x `atmega8u2` as USB serial 
processor to link to PC for programming.


I wanna to make a keyboard too. After I soldered stuffs togather, I found a serious problem though.


![front](https://github.com/neoedmund/neoe-arduino-keyboard/raw/master/pic/bback.jpg "front")
![back](https://github.com/neoedmund/neoe-arduino-keyboard/raw/master/pic/bback.jpg "back")


The problem is

1. I used a `Arduino Micro`, not `UNO`
2. All my Arduino, Micro or UNO, are Chinese clones, no atmega8u2 but replaced by `CH340G`.

I checked the CH340G datasheet, found it *not likely** to be turned into a USB-HID.


But I thought again, since PC is so powerful, if it get serial, it's easy to turn them into key strokes.
I can use it as a 2nd class keyboard, which linked by serial instead of USB-HID.
Weak in BIOS boot time, but will be OK when the OS(windows) is started.
What I need is another serial-key software. And I don't need to code myself, because (thanks) someone already did it.
I found it in the sf.net [serialporttokey](http://sourceforge.net/projects/serialporttokey/).

Put all things togather, it worked!
I used my 4x3 keyboard to play a game of [Hero of the Storm](http://us.battle.net/heroes/en/), with mouse of course.


the 4x3 keyboard mapping is : (for `Hero of the Storm`)
```
1	2	3	4
q	w	e	r 
z(mount)	g(pin map)	TAB(talent view)
```


![heroes](https://github.com/neoedmund/neoe-arduino-keyboard/raw/master/pic/bview.jpg "heroes")


because Arduino has 11 IO Pin available, which is D2-D12.  D0,D1 is used for timing, D13 used for LED on board.
So other keys like `a`(attack) and `space`(focus camera) is absent currently.


## TODO
1. use more comfortable buttons.
2. use another MCU to implement real USB keyborad.
3. more keys to make a full keyboard.

