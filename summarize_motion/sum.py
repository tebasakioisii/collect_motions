import serial
import csv
import time
import threading


def get_motion(port = '/dev/ttyACM0'):
    s = serial.Serial(port, 115200, timeout=0.1)
    time.sleep(1)
    s = serial.Serial(port, 115200)

    s.reset_output_buffer()
    s.reset_input_buffer()
    s.write(b'aa')
    time.sleep(1)
    s.write(b'0')
    time.sleep(2)
    s.readline()

    d = []
    with open('motion1.csv', 'w') as f:
        writer = csv.writer(f)
        for i in range(10):
            value = s.readline().decode('utf-8').rstrip('\r\n')
            d.append(value)
            print(value, file=f)
        f.close
    print(d)

def main():
    thread_1 = threading.Thread(target=get_motion, args=('/dev/ttyACM0',))
    thread_1.start()

if __name__ == '__main__':
    main()