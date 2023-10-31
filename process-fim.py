import serial
import time
import picamera

if __name__ == '__main__':
    ser = serial.Serial('/dev/ttyACM0', 9600, timeout=1)
    ser.reset_input_buffer()
    dir = '' # e.g. "/home/<your_name>/Pictures/clip-"
    with picamera.PiCamera() as camera:
        camera.resolution = (1280,720)
        camera.vflip = True
        camera.contrast = 10
        index = 1;
        while True:
            line = ser.readline().decode('utf-8').rstrip()
            ser.write("2\n".encode('utf-8'))
           
            if(line == "Take picture"):
                camera.capture(dir + str(index) + ".jpg")
                print(line + str(index))
            index = index + 1
   
            if index % 25 == 0:
                ser.write("1\n".encode('utf-8'))
                print(line)
                     
            time.sleep(5)
