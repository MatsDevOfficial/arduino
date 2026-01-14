import RPi.GPIO as GPIO
import subprocess
import time

START_PIN = 17
STOP_PIN  = 27

GPIO.setmode(GPIO.BCM)
GPIO.setup(START_PIN, GPIO.OUT)
GPIO.setup(STOP_PIN, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)

# Start actie
GPIO.output(START_PIN, GPIO.HIGH)
audio = subprocess.Popen(["aplay", "sound.wav"])

while True:
    if GPIO.input(STOP_PIN) == GPIO.HIGH:
        audio.terminate()        # geluid stoppen
        GPIO.output(START_PIN, GPIO.LOW)
        break
    time.sleep(0.05)

GPIO.cleanup()
