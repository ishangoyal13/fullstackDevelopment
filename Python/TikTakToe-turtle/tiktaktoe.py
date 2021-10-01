"""
TIK TAK TOE Game using Turtle library.

INSTRUCTIONS:

To start the Game,
$ python tiktaktoe.py

0. Please wait till the graphics gets over and a green cursor(a box) appears at the center of the screen.
1. Use ARROW KEYS to move the cursor.
2. Use SPACEBAR to place the shape in the grid.
3. Once results are put out, the program terminates automatically after 3 seconds.

Happy Gaming!!

"""
import turtle
import time
import winsound

#LIST
list=[[0,0,0],[0,0,0],[0,0,0]]

#SCREEN
win =turtle.Screen()
win.bgcolor("aqua")
win.screensize()
win.setup(width=1.0, height=1.0, startx=None, starty=None)
win.title("TIK TAK TOE")

#TITLE
title=turtle.Turtle()
title.color('crimson')
title.shape('triangle')
title.penup()
title.hideturtle()
title.goto(0,300)
title.write("T I K   T A K   T O E",align="center",font=("Agency FB",34,"bold"))

#TITLE BORDER
tb=turtle.Turtle()
tb.shape('triangle')
tb.color('orangered')
tb.pensize(10)
tb.speed(5)
tb.penup()
tb.setposition(-375,280)
tb.pendown()
tb.fd(750)
tb.hideturtle()

#DESIGNER DETAILER
tl=turtle.Turtle()
tl.color('darkmagenta')
tl.shape('triangle')
tl.penup()
tl.hideturtle()
tl.goto(0,300)
tl.goto(400,320)
tl.write("",align="center",font=("Agency FB",24,"normal"))


#tik tak toe border 1
b=turtle.Turtle()
b.color("crimson")
b.shape('triangle')
b.penup()
b.setposition(-150,-50)
b.pendown()
b.pensize(10)
b.fd(300)
b.hideturtle()

#tik tak toe border 2
b=turtle.Turtle()
b.color("crimson")
b.shape('triangle')
b.penup()
b.setposition(-150,50)
b.pendown()
b.pensize(10)
b.fd(300)
b.hideturtle()

#tik tak toe border 3
b=turtle.Turtle()
b.color("crimson")
b.shape('triangle')
b.penup()
b.setposition(-50,150)
b.pendown()
b.pensize(10)
b.setheading(270)
b.fd(300)
b.hideturtle()

#tik tak toe border 4
b=turtle.Turtle()
b.color("crimson")
b.shape('triangle')
b.penup()
b.setposition(50,150)
b.pendown()
b.pensize(10)
b.setheading(270)
b.fd(300)
b.hideturtle()


#CREATING A BOX
box=turtle.Turtle()
box.shape('square')
box.color('mediumspringgreen')
box.penup()
box.shapesize(stretch_wid=3,stretch_len=3,outline=0)
box.d=0

#MOVING THE BOX
def mup():
    if box.ycor()<100:
        y=box.ycor()
        x=box.xcor()
        box.goto(x,y+100)

def mdown():
    if box.ycor()>-100:
        y=box.ycor()
        x=box.xcor()
        box.goto(x,y-100)

def mleft():
    if box.xcor()>-100:
        y=box.ycor()
        x=box.xcor()
        box.goto(x-100,y)

def mright():
    if box.xcor()<100:
        y=box.ycor()
        x=box.xcor()
        box.goto(x+100,y)



#LAUNCHING A SHAPE AND OBTAINING THE RESULT WITH A STRIKE

def launch():

    c=box.d
    for i in range(5):
        box.hideturtle()
        time.sleep(0.01)

    box.showturtle()

    if c % 2==0:
        bullet=turtle.Turtle()
        bullet.shape('triangle')
        bullet.setheading(90)
        bullet.color('darkmagenta')
        bullet.penup()
        bullet.shapesize(stretch_wid=3,stretch_len=3,outline=0)
        x=box.xcor()
        y=box.ycor()
        bullet.goto(x,y)
        box.d=box.d+1

        if x==-100 and y==100:
           list[0][0]=100

        if x==0 and y==100:
           list[0][1]=100

        if x==100 and y==100:
           list[0][2]=100

        if x==-100 and y==0:
           list[1][0]=100

        if x==0 and y==0:
           list[1][1]=100

        if x==100 and y==0:
           list[1][2]=100

        if x==-100 and y==-100:
           list[2][0]=100

        if x==0 and y==-100:
           list[2][1]=100

        if x==100 and y==-100:
           list[2][2]=100

    else:
        bullet=turtle.Turtle()
        bullet.shape('circle')
        bullet.color('orangered')
        bullet.penup()
        bullet.shapesize(stretch_wid=3,stretch_len=3,outline=0)
        x=box.xcor()
        y=box.ycor()
        bullet.goto(x,y)
        box.d=box.d+1
        if x==-100 and y==100:
           list[0][0]=1000

        if x==0 and y==100:
           list[0][1]=1000

        if x==100 and y==100:
           list[0][2]=1000

        if x==-100 and y==0:
           list[1][0]=1000

        if x==0 and y==0:
           list[1][1]=1000

        if x==100 and y==0:
           list[1][2]=1000

        if x==-100 and y==-100:
           list[2][0]=1000

        if x==0 and y==-100:
           list[2][1]=1000

        if x==100 and y==-100:
           list[2][2]=1000



    #RESULT ANALYSIS

    s1=list[0][0]+list[0][1]+list[0][2]
    s2=list[1][0]+list[1][1]+list[1][2]
    s3=list[2][0]+list[2][1]+list[2][2]
    s4=list[0][0]+list[1][0]+list[2][0]
    s5=list[0][1]+list[1][1]+list[2][1]
    s6=list[0][2]+list[1][2]+list[2][2]
    s7=list[0][0]+list[1][1]+list[2][2]
    s8=list[0][2]+list[1][1]+list[2][0]

    #STRIKE
    strike =turtle.Turtle()
    strike.hideturtle()
    if s1==300 or s2==300 or s3==300 or s4==300 or s5==300 or s6==300 or s7==300 or s8==300:
        strike.color("darkmagenta")
    else:
        strike.color("orangered")
    strike.shape('triangle')
    strike.pensize(10)
    strike.hideturtle()

    if s1==300 or s1==3000:
        strike.penup()
        strike.goto(-150,100)
        strike.pendown()
        strike.forward(300)

    if s2==300 or s2 ==3000:
        strike.penup()
        strike.goto(-150,0)
        strike.pendown()
        strike.forward(300)

    if s3==300 or s3==3000:
        strike.penup()
        strike.goto(-150,-100)
        strike.pendown()
        strike.forward(300)

    if s4==300 or s4==3000:
        strike.penup()
        strike.goto(-100,150)
        strike.pendown()
        strike.setheading(270)
        strike.forward(300)

    if s5==300 or s5==3000:
        strike.penup()
        strike.goto(0,150)
        strike.pendown()
        strike.setheading(270)
        strike.forward(300)

    if s6==300 or s6==3000:
        strike.penup()
        strike.goto(100,150)
        strike.pendown()
        strike.setheading(270)
        strike.forward(300)

    if s7==300 or s7==3000:
        strike.penup()
        strike.goto(-125,125)
        strike.pendown()
        strike.setheading(315)
        strike.forward(350)

    if s8==300 or s8==3000:
        strike.penup()
        strike.goto(125,125)
        strike.pendown()
        strike.setheading(225)
        strike.forward(350)

    #TRIANGLE WINS

    if s1==300 or s2==300 or s3==300 or s4==300 or s5==300 or s6==300 or s7==300 or s8==300:
        box.hideturtle()
        text=turtle.Turtle()
        text=turtle.Turtle()
        text.color('crimson')
        text.shape('triangle')
        text.penup()
        text.speed(0)
        text.goto(0,-300)
        text.write("TRIANGLE WINS!!",align="center",font=("Agency FB",34,"normal"))
        text.hideturtle()
        winsound.PlaySound('wd.wav',winsound.SND_FILENAME)
        time.sleep(3)
        turtle.bye()


    #CIRCLE WINS

    elif s1==3000 or s2==3000 or s3==3000 or s4==3000 or s5==3000 or s6==3000 or s7==3000 or s8==3000:
        box.hideturtle()
        text=turtle.Turtle()
        text.color('crimson')
        text.shape('triangle')
        text.penup()
        text.speed(0)
        text.goto(0,-300)
        text.write("CIRCLE WINS!!",align="center",font=("Agency FB",34,"normal"))
        text.hideturtle()
        winsound.PlaySound('wd.wav',winsound.SND_FILENAME)
        time.sleep(3)
        turtle.bye()


    #GAME DRAWS

    elif list[0][0]!=0 and list[0][1]!=0 and list[0][2]!=0 and list[1][0]!=0 and list[1][1]!=0 and list[1][2]!=0 and list[2][0]!=0 and list[2][1]!=0 and list[2][2]!=0:
        box.hideturtle()
        text=turtle.Turtle()
        text.color('crimson')
        text.shape('triangle')
        text.penup()
        text.hideturtle()
        text.goto(0,-300)
        text.write("GAME DRAW !!",align="center",font=("Agency FB",34,"normal"))
        time.sleep(3)
        turtle.bye()



# KEYBOARD BINDINGS
win.listen()
win.onkey(mup,'Up')
win.onkey(mdown,'Down')
win.onkey(mleft,'Left')
win.onkey(mright,'Right')
win.onkey(launch, "space")


turtle.done()
