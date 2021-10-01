# pip install speechrecognition
# pip install pyttsx3

import speech_recognition as sr
import pyttsx3

f = open("text_to_speech.py","r+")

engine = pyttsx3.init()
vc = engine.getProperty('voices')
engine.setProperty('voices', vc[1].id)


def speak(audio):
    engine.say(audio)
    engine.runAndWait()

for line in f:
    speak(line)
 
f.close()