import os
import pandas as pd
from playsound import playsound
from datetime import datetime
from pydub import AudioSegment
from gtts import gTTS

# text-to-speech func in hindi


def textToSpeechHindi(text, filename):
    mytext = str(text)
    language = 'hi'
    myobj = gTTS(text=mytext, lang=language, slow=False)
    myobj.save(filename)

# text-to-speech func in english


def textToSpeechEnglish(text, filename):
    mytext = str(text)
    language = 'en'
    myobj = gTTS(text=mytext, lang=language, slow=False)
    myobj.save(filename)

# This function returns pydub audiosegment


def mergeAudios(audios):
    combined = AudioSegment.empty()
    for audio in audios:
        combined += AudioSegment.from_mp3(audio)
    return combined

#        *****Hindi******


def generateSkeletonHindi():
    audio = AudioSegment.from_mp3('railway.mp3')

    # 1 - Generating Kripya dyaan dijiye
    start = 88000
    finish = 90200
    audioProcessed = audio[start:finish]
    audioProcessed.export("1_hindi.mp3", format="mp3")

    # 2 is from-city

    # 3 - Generate se chalkar
    start = 91000
    finish = 92200
    audioProcessed = audio[start:finish]
    audioProcessed.export("3_hindi.mp3", format="mp3")

    # 4 is via-city

    # 5 - Generate ke raaste
    start = 94000
    finish = 95000
    audioProcessed = audio[start:finish]
    audioProcessed.export("5_hindi.mp3", format="mp3")

    # 6 is to-city

    # Generate ko jaane wali gaadi sakhya
    start = 94000
    finish = 95000
    audioProcessed = audio[start:finish]
    audioProcessed.export("7_hindi.mp3", format="mp3")

    # 8 is train no and name

    # 9 - Generate kuch hi samay mei platform sankhya
    start = 105500
    finish = 108200
    audioProcessed = audio[start:finish]
    audioProcessed.export("9_hindi.mp3", format="mp3")

    # 10 is platform number

    # 11 - Generate par aa rahi hai
    start = 109000
    finish = 112250
    audioProcessed = audio[start:finish]
    audioProcessed.export("11_hindi.mp3", format="mp3")


def generateAnnouncementHindi(filename):
    df = pd.read_excel(filename)
    print(df)
    for index, item in df.iterrows():
        # 2 - Generate from-city
        textToSpeechHindi(item['from'], '2_hindi.mp3')

        # 4 - Generate via-city
        textToSpeechHindi(item['via'], '4_hindi.mp3')

        # 6 - Generate to-city
        textToSpeechHindi(item['to'], '6_hindi.mp3')

        # 8 - Generate train no and name
        textToSpeechHindi(item['train_no'] + " " +
                          item['train_name'], '8_hindi.mp3')

        # 10 - Generate platform number
        textToSpeechHindi(item['platform'], '10_hindi.mp3')

        audios = [f"{i}_hindi.mp3" for i in range(1, 12)]

        announcement = mergeAudios(audios)
        announcement.export(
            f"announcementHindi_{item['train_no']}_{index+1}.mp3", format="mp3")


# ******English*******


def generateSkeletonEnglish():
    audio = AudioSegment.from_mp3('Indian-Railways_Announcement.mp3')

    # 1 attention please...train no
    start = 36950
    finish = 39800
    audioProcessed = audio[start:finish]
    audioProcessed.export('1_English.mp3', format="mp3")

    # 2 train no and name

    # 3 from
    start = 44200
    finish = 44750
    audioProcessed = audio[start:finish]
    audioProcessed.export('3_English.mp3', format="mp3")

    # 4 from city

    # 5 to
    start = 45600
    finish = 46150
    audioProcessed = audio[start:finish]
    audioProcessed.export('5_English.mp3', format="mp3")

    # 6 to city

    # 7 via
    start = 47100
    finish = 47650
    audioProcessed = audio[start:finish]
    audioProcessed.export('7_English.mp3', format="mp3")

    # 8 via city

    # 9 is arriving...platform no
    start = 49000
    finish = 52100
    audioProcessed = audio[start:finish]
    audioProcessed.export('9_English.mp3', format="mp3")

    # 10 platform no

    # 11 thank you...end music
    start = 52800
    finish = 54800
    audioProcessed = audio[start:finish]
    audioProcessed.export('11_English.mp3', format="mp3")


def generateAnnouncementEnglish(filename):
    df = pd.read_excel(filename)
    print(df)
    for index, item in df.iterrows():
        # 2 train no and name
        textToSpeechEnglish(item['train_no'] + " " +
                            item['train_name'], '2_English.mp3')

        # 4 from city
        textToSpeechEnglish(item['from'], '4_English.mp3')
        # 6 to city
        textToSpeechEnglish(item['to'], '6_English.mp3')

        # 8 via city
        textToSpeechEnglish(item['via'], '8_English.mp3')

        # 10 platform no
        textToSpeechEnglish(item['platform'], '10_English.mp3')

        audios = [f"{i}_English.mp3" for i in range(1, 12)]

        announcement = mergeAudios(audios)
        playsound('''announcement.export(f"AnnouncementEnglish_{item['train_no']}_{index+1}.mp3", format="mp3")''')


df = pd.read_excel("announcementList.xlsx")

if __name__ == "__main__":
    while True:
        now = datetime.now().strftime("%H:%M")
        if now in str(df['Timings']):
            
            print("playing....")
            #    ******Hindi******
            print("Generating Skeleton in Hindi...")
            generateSkeletonHindi()
            print("Now Generating Announcement In Hindi...")
            generateAnnouncementHindi("announcementList.xlsx")
            #     ******English*****
            print("Generating Skeleton in English...")
            generateSkeletonEnglish()
            print("Now Generating Announcement In English...")
            generateAnnouncementEnglish("announcementList.xlsx")
