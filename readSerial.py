##############
## Script listens to serial port and writes contents into a file
##############
## requires pySerial to be installed 
import serial

serial_port = '/dev/cu.usbmodem1101'; ## Change to your correct serial port, check in Arduino IDE
baud_rate = 9600; #In arduino, Serial.begin(baud_rate)
write_to_file_path = "output.txt";

ser = serial.Serial(serial_port, baud_rate)
while True:
    line = ser.readline();
    line = line.decode("utf-8") #ser.readline returns a binary, convert to string
    output_file = open(write_to_file_path, "w");
    print(line);
    output_file.write(line);
    output_file.close();