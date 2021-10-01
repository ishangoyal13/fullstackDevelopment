import tkinter as tk
from tkinter import *

window = tk.Tk()
frame_lbl=tk.Frame(master=window,relief=tk.RIDGE,borderwidth=10,bg="red")
frame_txt=tk.Frame(master=window,relief=tk.SUNKEN,borderwidth=10,bg="green")
frame_btn=tk.Frame(master=window,relief=tk.RAISED,borderwidth=10,bg="violet")

lbl = tk.Label(master=frame_lbl,text="first GUI application".upper(),fg="white",bg="black")
lbl.pack()
def handle_click(event):
    print("The button was clicked!")
btn=tk.Button(master=frame_btn,text="CLICK ME", fg="white",bg="black")
btn.bind("<Button-1>", handle_click)
btn.pack()
txt=tk.Text(master=frame_txt,fg="black",bg="red",height=10)
txt.pack()

frame_lbl.pack(fill = tk.BOTH,expand=True)
frame_txt.pack(fill = tk.BOTH,expand=True)
frame_btn.pack(fill = tk.BOTH,expand=True)
window.mainloop()

