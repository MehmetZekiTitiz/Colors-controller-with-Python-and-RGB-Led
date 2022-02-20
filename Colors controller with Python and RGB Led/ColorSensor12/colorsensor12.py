import serial

from vpython import *

arduinoSerial = serial.Serial('COM3', 9600)

while True:
    rate(20)

    while (arduinoSerial.inWaiting() == 0):
        pass
        myData = arduinoSerial.read()
        print(myData)
        if myData[0] == bytes("g", "utf-8")[0]:
            print("Color is Green")
            cylinder(length=6, color=color.green, radius=.5, pos=vector(-3, 0, 0))
            label(text='Green Color ')

        if myData[0] == bytes("r", "utf-8")[0]:
            print("Color is Red")
            label(text='Red Color ')
            cylinder(length=6, color=color.red, radius=.5, pos=vector(-3, 0, 0))
        if myData[0] == bytes("b", "utf-8")[0]:
            label(text='Blue Color ')
            print("Color is Blue")
            cylinder(length=6, color=color.blue, radius=.5, pos=vector(-3, 0, 0))

        if myData[0] == bytes("f", "utf-8")[0]:
            print("Color dont know")



