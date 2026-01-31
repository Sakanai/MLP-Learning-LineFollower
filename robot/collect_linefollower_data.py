import serial
import csv
from datetime import datetime

# Ganti COMxx dengan port ESP32 yang terhubung
ser = serial.Serial("COM4", 115200)

filename = "data_robot.csv"

with open(filename, "a", newline="") as f:
    writer = csv.writer(f)

    while True:
        try:
            line = ser.readline().decode().strip()
            if line:
                row = [datetime.now().isoformat()] + line.split(",")
                writer.writerow(row)
                print(row)
        except KeyboardInterrupt:
            print("Selesai.")
            break
