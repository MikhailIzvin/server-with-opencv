# server for openCV

This program receives an image via http, processes it and sends the coordinates of the rectangles bounding the face in json format:
    Top left corner x,
    Top left corner y,
    width,
    height

This program requires the following components:
    -- opencv 4.0 and higher
    -- Cmake 3.9 and higner
    -- node js 16.0 and higher
    -- npm 8.0 and higher
    -- clang 13.0 and higher

if opencv not installed in the standard location append in CMakeLists.txt before find_package:
    set (CMAKE_PREFIX_PATH "/path/to/opencv/version")

like this:

set (CMAKE_PREFIX_PATH "/usr/local/Cellar/opencv/4.5.4_4")
find_package( OpenCV REQUIRED )

for install dependencies:
    -- npm install

for compile project from sources:
    -- npm run build

for run server:
    -- npm start

if you don't want open in web browser you can send image with curl like this:
    -- curl -F File=@/path/to/image http://ip:port

example:
    -- curl -F File=@/Users/mikhailizvin/Downloads/rot.jpeg http://192.168.0.188:3000

