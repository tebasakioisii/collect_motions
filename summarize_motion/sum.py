import serial
import csv
import time

s = serial.Serial('/dev/ttyACM0', 115200)

# s.reset_output_buffer()
# s.reset_input_buffer()
s.write(b'aa\n')
b = s.readline()
print(b)
time.sleep(1)
s.write(b'0')
print(s.readline())

time.sleep(2)

with open('motion1.csv', 'w') as f:
    writer = csv.writer(f)
    # print(s.read_until(size=100).decode('utf-8'))
    for i in range(10):
        value = s.readline().decode('utf-8')
        print(value)
        writer.writerow(value)
    f.close