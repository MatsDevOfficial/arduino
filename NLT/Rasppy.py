import RPi.GPIO as GPIO
import time
import subprocess

START_PIN = 17

GPIO.setmode(GPIO.BCM)
GPIO.setup(START_PIN, GPIO.OUT)

while True:
    GPIO.output(START_PIN, GPIO.HIGH)
    subprocess.Popen(["aplay", "sound.wav"])  # optioneel
    time.sleep(1.0)        # servo actief

    GPIO.output(START_PIN, GPIO.LOW)
    time.sleep(15)         # wacht 15 s
