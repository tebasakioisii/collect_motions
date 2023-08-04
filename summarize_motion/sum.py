import serial
import csv
import time
import threading

ev = threading.Event()

def get_motion(port = '/dev/ttyACM0'):
    s = serial.Serial(port, 115200, timeout=0.1)
    time.sleep(1)
    s = serial.Serial(port, 115200)

    s.reset_output_buffer()
    s.reset_input_buffer()
    s.write(b'aa')
    time.sleep(1)

    # wait another thread
    ev.wait()

    s.write(b'0')
    s.readline()
    d = []
    file_name = 'motion_{}.csv'.format(port.split('/')[-1])
    with open(file_name, 'w') as f:
        for i in range(10):
            value = s.readline().decode('utf-8').rstrip('\r\n')
            d.append(value)
            print(value, file=f)
        f.close

def main():
    thread_1 = threading.Thread(target=get_motion, args=('/dev/ttyACM0',))
    thread_1.start()
    thread_2 = threading.Thread(target=get_motion, args=('/dev/ttyACM2',))
    thread_2.start()
    time.sleep(4)
    ev.set()
    

if __name__ == '__main__':
    main()