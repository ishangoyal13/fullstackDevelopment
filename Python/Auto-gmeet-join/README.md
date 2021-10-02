# Auto-gmeet-join
***
This python script uses selenium to login to your gmail account and attend your meets as per your schedule. It automatically joins the meet with mic and camera off and leaves when the number of participants is <10(or any number of your choice)
***
# Installation
***
Navigate to the directory where you want to have this file.
Clone this repo with `$ git clone https://github.com/import-sarbottam/Auto-gmeet-join.git`

Then open your terminal and get the following modules

`pip install schedule`

`pip install selenium`

`pip install webdriver-manager`

Then go to line 75 of the code and enter the class/meet links as per your requirement

Then go to line 86 and replace email and password with your email and password

Then go to line 143 and schedule your class as required

In line 64 you can change after how much time the number of participants will be checked and in line 69 you can change at howmany participants remaining will the program leave the meet
