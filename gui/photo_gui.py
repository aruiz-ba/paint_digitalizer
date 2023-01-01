import  tkinter as tk
from PIL import ImageTk, Image
import  os
import shutil

abc = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H']

def save_photo(row,col):
    shutil.copy("passed.jpg", "latest.jpg")

def photo_gui(row, col):
    root = tk.Tk()
    label = tk.Label(root, font=('Arial', 30),text = "Digitalización:" + abc[col] + str(row + 1))

    confirm = tk.Button(root, padx = 60, pady = 30, text = "Confirmar", bg = "Green", command = lambda row=row,col=col: save_photo(row, col))

    label.pack()
    confirm.pack()
    root.mainloop() 

