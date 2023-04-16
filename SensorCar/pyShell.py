import serial
import time
import csv
import os

SERIAL_PORT = 'A0'  # Change this to your Arduino's serial port
BAUD_RATE = 9600
FILE_NAME = 'sensor_data.csv'

def main():
    ser = serial.Serial(SERIAL_PORT, BAUD_RATE)
    time.sleep(2)  # Allow time for the Arduino to initialize

    while True:
        try:
            line = ser.readline().decode('utf-8').strip()
            data = parse_data(line)

            if data:
                save_to_csv(FILE_NAME, data)

        except KeyboardInterrupt:
            print("Exiting...")
            break

def parse_data(line):
    try:
        '''
        humidity, temperature = line.split(', ')
        humidity_value = float(humidity.split(': ')[1])
        temperature_value = float(temperature.split(': ')[1])
        '''
        
        ambient_light = line.split(', ')
        ambient_value = float(ambient_light.split(': ')[1])
        timestamp = time.strftime('%Y-%m-%d %H:%M:%S')
        return [timestamp, ambient_value]

    except ValueError:
        print("Invalid data received:", line)
        return None

def save_to_csv(file_name, data):
    file_exists = os.path.isfile(file_name)

    with open(file_name, 'a', newline='') as f:
        writer = csv.writer(f)
        
        if not file_exists:
            writer.writerow(['Timestamp', 'Humidity', 'Temperature'])

        writer.writerow(data)
        print(f"Saved data: {data}")

if __name__ == '__main__':
    main()
