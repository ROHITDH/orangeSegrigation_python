import RPi.GPIO as GPIO
from picamera import PiCamera
import sys
import numpy as np
import cv2
import time
GPIO.setmode(GPIO.BCM)
ir1=27
ir2=22
mt1=20
mt2=21
GPIO.setup(mt1,GPIO.OUT)
GPIO.setup(ir1, GPIO.IN)
GPIO.setup(ir2, GPIO.IN)
GPIO.setup(mt2,GPIO.OUT)
p1= GPIO.PWM(mt1, 50)
p2= GPIO.PWM(mt2, 50)
p1.start(2.5)
p2.start(2.5)
TRIG = 19
ECHO = 26
GPIO.setup(TRIG,GPIO.OUT)
GPIO.setup(ECHO,GPIO.IN)
GPIO.output(TRIG, False)
print ("Waiting For Sensor To Settle")
time.sleep(2)
while True:
   GPIO.output(TRIG, True)
   time.sleep(0.0001)
   GPIO.output(TRIG, False)
   while GPIO.input(ECHO)==0:
      pulse_start = time.time()
   while GPIO.input(ECHO)==1:
      pulse_end = time.time()
   pulse_duration = pulse_end - pulse_start
   distance = pulse_duration * 17150
   distance = round(distance, 2)
   print ("Distance:",distance,"cm")
   i=0
   if distance<2:
      camera=0
      camera = PiCamera()
      camera.start_preview()
      time.sleep(1)
      camera.capture('/home/pi/Desktop/image.jpg')
      camera.stop_preview()
      camera.close()
      def cv_imread(file_path):
         cv_img = cv2.imdecode(np.fromfile(file_path, dtype=np.uint8), -1)
         return cv_img
      file_path = '/home/pi/Desktop/image.jpg'
      img = cv_imread(file_path)
      print(img)
      hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)
      hue = hsv[0][0][0]
      print 'the fruit value is',hue
      if hue>0:
         a=1
         while a==1:
           a=GPIO.input(ir1)
           print 'orange detecting'
         print ('orange detected')
         time.sleep(0.5)
         p1.start(2.5) # Initialization
         p1.ChangeDutyCycle(20)
         time.sleep(0.5)
         p1.ChangeDutyCycle(2.5)
         time.sleep(0.5)
           else:
         b=1
         while b==1:
           b=GPIO.input(ir2)
           print 'detecting green'
         print ('detected green')
         p2.start(2.5) # Initialization
         p2.ChangeDutyCycle(20)
         time.sleep(0.5)
         p2.ChangeDutyCycle(2.5)
         time.sleep(0.5)
   print ("no fruit")
print("finish")




