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

Here are some screen results with different sensitivity value (0, 50, 100):

REMEMBER high value for low sensitivity, low value for high sensitivity

Sensitivity value: 0

<img src="https://github.com/meng1994412/ChenyangMeng_ME433_2018/blob/master/HW13/Result/result2.png">

Sensitivity value: 50

<img src="https://github.com/meng1994412/ChenyangMeng_ME433_2018/blob/master/HW13/Result/result3.png">

Sensitivity value: 100

<img src="https://github.com/meng1994412/ChenyangMeng_ME433_2018/blob/master/HW13/Result/result1.png">

As we can see from the results, with sensitivity value 0 (high sensitivity), the app detects lots of green objects or shapes, which many of them are not even green objects or shapes in the reality. With sensitivity value 50 (moderate sensitivity), the app detects green object, the ALIENWARE slogen, decently and resonably. With sensitivity value 100 (low sensitivity), the app does not detect any green objects or shapes.

Here is a demo for how the app works (with adjustable sensitivity) on a RAZER mouse box:

![demo1](https://github.com/meng1994412/ChenyangMeng_ME433_2018/blob/master/HW13/Result/demo.gif)
