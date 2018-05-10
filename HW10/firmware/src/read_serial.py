import serial
import matplotlib.pyplot as plt

ser = serial.Serial('COM4', 9600)
print(ser.name)

s = ser.read(100)
print(s)