# VideoPlayer
This video player can play video file using OpenCV and also has Web Server that can control player feature such play, stop and pause via WEB page.

## How to build
### step1. make dependency libraries
### step2. make Applications with Luna

## Build
## STEP1: How to build dependency libraries
### Linux & OS X
```bash
cd ~/VideoPlayer/dependency/Luna
cd dependency
mkdir build
cd build
cmake ..
make
```

## STEP2: How to build Applications with Luna
### Linux & OS X
```bash
cd ~/VideoPlayer
mkdir build  
cd build
cmake ..
make
```

## STEP3: How to test Applications
### Linux & OS X

### VideoPlayer
```bash
cd ./VideoPlayer/build
./bin/VideoPlayer
```
