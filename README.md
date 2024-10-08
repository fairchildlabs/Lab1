# Lab1

## 1.0 Install SD Card in PI, boot

```
(Demonstration)
$      - copy and paste into SSH or PI terminal (only the charecters after the $) 
PI>    - means PI terminal ONLY (Touchscreen or VNC)
//This is a comment in code, for information only, don't type
LABPC>  0This means type this into the cmd window on your labpc
$$$ This means the lines that follow can be copied and pasted all at once (multiple lines)
```

## Rename your PI (YOURPINAME - something you can remember)
``` 
PI> sudo hostnamectl set-hostname YOURPINAME 
```


## 1.1  - Shutdown PI and install USB Camera (video.....)

`$ lsusb`

Bus 002 Device 001: ID 1d6b:0003 Linux Foundation 3.0 root hub


Take a picture

`$ fswebcam -r 1280x720 --no-banner /var/www/html/1.jpg`

View it in browser (<YOUR_PI_NAME> is your PI IP address or name)

http://<YOUR_PI_NAME>/1.jpg  

Look at the file it created 

`$ ls -l /var/www/html/1.jpg`

-rw-r--r-- 1 root root 185255 Aug  4 14:11 /var/www/html/1.jpg

(Size in bytes 185255)


`$ fswebcam -r 3840x288 --no-banner /var/www/html/1s.jpg`

`$ ls -l /var/www/html/1s.jpg`

-rw-r--r-- 1 root root 130609 Aug  4 14:19 /var/www/html/1s.jpg

## 1.2 Get more detail about camera

`$ v4l2-ctl --list-formats-ext > /var/www/html/usbresolution.txt`

Check it out in browser (for future reference)
http://<YOUR_PI_NAME>/usbresolution.txt

```
$ mkdir /var/www/html/jpg_sizes

$$$
fswebcam -r 640x480 --no-banner /var/www/html/jpg_sizes/640x480.jpg
fswebcam -r 1920x1080 --no-banner /var/www/html/jpg_sizes/1920x1080.jpg
fswebcam -r 1280x960 --no-banner /var/www/html/jpg_sizes/1280x960.jpg
fswebcam -r 1280x720 --no-banner /var/www/html/jpg_sizes/1280x720.jpg
fswebcam -r 1024x576 --no-banner /var/www/html/jpg_sizes/1024x576.jpg
fswebcam -r 800x600 --no-banner /var/www/html/jpg_sizes/800x600.jpg
fswebcam -r 640x360 --no-banner /var/www/html/jpg_sizes/640x360.jpg
fswebcam -r 640x480 --no-banner /var/www/html/jpg_sizes/640x480.jpg

$  ls -l /var/www/html/jpg_sizes

-rw-r--r-- 1 root root 167068 Aug 19 12:10 1024x576.jpg
-rw-r--r-- 1 root root 225826 Aug 19 12:10 1280x720.jpg
-rw-r--r-- 1 root root 223167 Aug 19 12:10 1280x960.jpg
-rw-r--r-- 1 root root 504530 Aug 19 12:09 1920x1080.jpg
-rw-r--r-- 1 root root 110898 Aug 19 12:10 640x360.jpg
-rw-r--r-- 1 root root 115160 Aug 19 12:10 640x480.jpg
-rw-r--r-- 1 root root 152399 Aug 19 12:10 800x600.jpg

```

look at your picture on browser

http://<YOUR_PI_NAME>/jpg_sizes/1920x1080.jpg


## 1.3 Record Videos

`$ mkdir /var/www/html/video_13/`


### 1.3.1 Record a single video
`$ ffmpeg -f v4l2 -framerate 30 -video_size 640x480 -i /dev/video0 /var/www/html/video_13/640x480.mp4`

[CTRL-C] to Stop

http://<YOUR_PI_NAME>/video_13/640x480.mp4

### 1.3.2 Record a single video with sound

Get the card # of USB Audio (Webcam) [card 2: in example]
```
$ arecord -l
```

**** List of CAPTURE Hardware Devices ****
card 2: W4DS [W4DS], device 0: USB Audio [USB Audio]
  Subdevices: 1/1
  Subdevice #0: subdevice #0

### 1.3.3 Record video and audio in same capture

`$ ffmpeg -f alsa -ac 2 -i hw:2 -f v4l2 -framerate 30 -video_size 640x480 -i /dev/video0 /var/www/html/video_13/640x480_sound.mp4`

http://<YOUR_PI_NAME>/video_13/640x480_sound.mp4

## 1.4 Clone Git Repo

Use git to clone repository
```
$ cd ~
$ git clone https://github.com/fairchildlabs/Lab1.git
$ cd Lab1
$ cd code

//Makes the scootd program in C language

$ make
//Run - Open Terminal Window on PI (top banner >_ symbol)
PI> cd Lab1/code
PI> ./scootcam
//Push Stop and Record Buttons.  <CTRL><TAB> to see background window changing values to the scootd C Program

```
## 1.5. On PC, load the Copilot AI conversation into your PC Browser

### Houston Statistics
https://copilot.microsoft.com/sl/bFlaxeH3ffE

### Sharing data between C program and python

https://copilot.microsoft.com/sl/ienmTv87E96

