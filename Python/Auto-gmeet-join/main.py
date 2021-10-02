from selenium import webdriver
from selenium.webdriver.chrome.options import Options
from webdriver_manager.chrome import ChromeDriverManager
import time,schedule

opt = Options()
opt.add_argument('--disable-blink-features=AutomationControlled')
opt.add_argument('--start-maximized')
# 0 is off, 1 is on
opt.add_experimental_option("prefs", {
  
    "profile.default_content_setting_values.media_stream_mic": 1,
    "profile.default_content_setting_values.media_stream_camera": 1,
    "profile.default_content_setting_values.geolocation": 0,
    "profile.default_content_setting_values.notifications": 1
})

browser = webdriver.Chrome(ChromeDriverManager().install(),options=opt)

def google_login(mail_address, password):
    # Login Page
    browser.get('https://accounts.google.com/ServiceLogin?hl=en&passive=true&continue=https://www.google.com/&ec=GAZAAQ')
  
    # input Gmail
    browser.find_element_by_id("identifierId").send_keys(mail_address)
    browser.find_element_by_id("identifierNext").click()
    browser.implicitly_wait(10)
  
    # input Password
    browser.find_element_by_xpath('//*[@id="password"]/div[1]/div/div[1]/input').send_keys(password)
    browser.implicitly_wait(10)
    browser.find_element_by_id("passwordNext").click()
    browser.implicitly_wait(10)

def turnoff():

    # turn off Microphone
    time.sleep(2)
    browser.find_element_by_css_selector('div.U26fgb.JRY2Pb.mUbCce.kpROve.yBiuPb.y1zVCf.M9Bg4d.HNeRed').click()
    browser.implicitly_wait(3000)
  
    # turn off camera
    time.sleep(1)
    browser.find_element_by_css_selector("div.U26fgb.JRY2Pb.mUbCce.kpROve.yBiuPb.y1zVCf.HNeRed.M9Bg4d").click()
    browser.implicitly_wait(3000)

def join():

    # Join meet
    time.sleep(5)
    browser.implicitly_wait(2000)
    browser.find_element_by_css_selector('div.uArJ5e.UQuaGc.Y5sE8d.uyXBBb.xKiqt').click()

def leave():

    # Leave meet
    time.sleep(10)
    browser.implicitly_wait(2000)
    browser.find_element_by_css_selector('button.VfPpkd-Bz112c-LgbsSe.yHy1rc.eT1oJ.tWDL4c.jh0Tpd.Gt6sbf.QQrMi.ftJPW').click()

def get_participants():

    # Get number of participants
    time.sleep(720) #start checking number of participants after 10 mins
    browser.implicitly_wait(2000)
    while(True):
        participants = browser.find_element_by_css_selector("div.uGOf1d").text
        print(participants)
        if(int(participants)<10): #leave the meet if number of participants is less than 10
            leave()
            break
        else:
            time.sleep(60) #check again after 1 min

# Class links here
class1 = "link1"
class2 = "link2"
class3 = "link3"
class4 = "link4"
class5 = "link5"
lab1 = "link6"
lab2 = "link7"
lab3 = "link8"
lab4 = "link9"

google_login("email","password") # Your email and password here
time.sleep(5)

def class_1():
    browser.get(class1)
    turnoff()
    join()
    get_participants()

def class_2():
    browser.get(class2)
    turnoff()
    join()
    get_participants()

def class_3():
    browser.get(class3)
    turnoff()
    join()
    get_participants()

def class_4():
    browser.get(class4)
    turnoff()
    join()
    get_participants()

def class_5():
    browser.get(class5)
    turnoff()
    join()
    get_participants()

def lab_1():
    browser.get(lab1)
    turnoff()
    join()
    get_participants()

def lab_2():
    browser.get(lab2)
    turnoff()
    join()
    get_participants()

def lab_3():
    browser.get(lab3)
    turnoff()
    join()
    get_participants()

def lab_4():
    browser.get(lab4)
    turnoff()
    join()
    get_participants()

schedule.every().tuesday.at("10:01").do(class_1)
schedule.every().tuesday.at("11:01").do(class_2)
schedule.every().tuesday.at("12:01").do(class_3)
schedule.every().tuesday.at("15:05").do(lab_1)
schedule.every().wednesday.at("10:01").do(class_4)
schedule.every().wednesday.at("11:01").do(class_5)
schedule.every().wednesday.at("12:01").do(class_3)
schedule.every().wednesday.at("15:05").do(lab_2)
schedule.every().thursday.at("10:01").do(class_1)
schedule.every().thursday.at("11:01").do(class_5)
schedule.every().thursday.at("12:01").do(class_4)
schedule.every().thursday.at("15:05").do(lab_3)
schedule.every().friday.at("10:01").do(class_1)
schedule.every().friday.at("11:01").do(class_2)
schedule.every().friday.at("12:01").do(class_3)
schedule.every().friday.at("15:05").do(lab_4)
schedule.every().saturday.at("11:01").do(class_4)
schedule.every().saturday.at("12:01").do(class_2)

while(True):
    schedule.run_pending()
    time.sleep(1)