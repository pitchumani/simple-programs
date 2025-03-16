from tkinter import *

window = Tk()
window.title("First python GUI program")

label1 = Label(window, text="Hello World!", font=("Helvetica Bold", 50))
label1.grid(column = 0, row = 0)

window.geometry('400x200')

# track number of times the button is clicked
num_clicks = 0
label2 = Label(window, text="[]", font=("Arial Bold", 20))
label2.grid(column=0, row=2)

# funcion for button click
def button1_clicked():
    global num_clicks
    num_clicks += 1
    label2.configure(text="[Clicked the button " + str(num_clicks) + " times]")
    
button1 = Button(window, text="Click Me", font=("Helvetica Bold", 20), command=button1_clicked)
button1.grid(column=0, row=1)

window.mainloop()

