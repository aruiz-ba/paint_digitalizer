import  tkinter as tk
import  os, shutil, sys

abc = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H']
index = 0

def save_photo(coord):
    global index
    index += 1
    shutil.copy("./latest.jpg", "./db/" + coord + "/" + coord + "_cuadro_" + str(index) + ".jpg")

def back_menu():
    exit()

def photo_gui(coord):
    root = tk.Tk()
    index= 0

    label = tk.Label(root, font=('Arial', 30),text = "Digitalización:" + coord)
    change = tk.Button(root, padx = 60, pady = 30, text = "Cambiar estante", bg = "Red", command = back_menu)
    confirm = tk.Button(root, padx = 60, pady = 30, text = "Confirmar Foto", bg = "Green", command = lambda coord=coord: save_photo(coord))

    label.pack()
    confirm.pack()
    change.pack()
    root.mainloop() 


photo_gui(sys.argv[1])
