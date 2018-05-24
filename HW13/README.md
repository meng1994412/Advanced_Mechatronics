## HW13 Android Camera
### Objectives:
* Write a camera app for your Android phone that when pointing the camera at a green object, the app should identify the green shape and draw lines on top of it.

### Approaches:
* Code instruction (core codes are under `Program/app/src/main`):
  - `MainActivity.java`: Controls the camera to detect the green object with adjustable sensitivity. If the green object is detected, draw lines on top of it. ([Path here](https://github.com/meng1994412/ChenyangMeng_ME433_2018/blob/master/HW13/Program/app/src/main/java/sunnystormborn/colordetector/MainActivity.java))
  - `activity_main.xml`: Contains the layout of text, view of the app. ([Path here](https://github.com/meng1994412/ChenyangMeng_ME433_2018/blob/master/HW13/Program/app/src/main/res/layout/activity_main.xml))
  - `AndroidManifest.xml`: Give the app permission to use the camera. ([Path here](https://github.com/meng1994412/ChenyangMeng_ME433_2018/blob/master/HW13/Program/app/src/main/AndroidManifest.xml))
  
* The sensitivity value shown in the app is actually the reverse sensitivity, which means high value for low sensitivity and low value for high sensitivity.
  
### Results:

Here are some screen results with different sensitivity value (high value for low sensitivity, low value for high sensitivity):

Sensitivity value: 0
<img src="https://github.com/meng1994412/ChenyangMeng_ME433_2018/blob/master/HW13/Result/result2.png">

Sensitivity value: 50
<img src="https://github.com/meng1994412/ChenyangMeng_ME433_2018/blob/master/HW13/Result/result3.png">

Sensitivity value: 100
<img src="https://github.com/meng1994412/ChenyangMeng_ME433_2018/blob/master/HW13/Result/result1.png">
