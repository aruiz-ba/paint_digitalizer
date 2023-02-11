import  tkinter as tk
import  os, shutil, sys

abc = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H']
index = 0

root = tk.Tk()

tag = tk.StringVar()
id_num = tk.StringVar()

tag.set('Tematica:')
id_num.set('Numero: 1')

def set_tag(tag_name):
    tag.set("Tematica: " + tag_name)

def save_photo(coord):

    #if file didnt got updated
    global index
    index += 1
    id_num.set("Numero: " + str(index))
    shutil.copy("./latest.jpg", "./db/" + coord + "/" + coord + "_cuadro_" + str(index) + ".jpg")
    os.system('exiftool -keywords=' + tag_name + "./db/" + coord + "/" + coord + "_cuadro_" + str(index) + ".jpg")

def back_menu():
    exit()


def photo_gui(coord):
    index= 1

    coordenada = tk.Label(root, font=('Arial', 30),text = "Coordenada:" + coord)
    id_number = tk.Label(root, font=('Arial', 30), textvariable = id_num)
    label_tag = tk.Label(root, font=('Arial', 30), textvariable = tag)

    paisaje = tk.Button(root, padx = 60, pady = 30, text = "Paisaje", bg = "White", command = lambda: set_tag("Paisaje"))
    retrato = tk.Button(root, padx = 60, pady = 30, text = "Retrato", bg = "White", command = lambda: set_tag("Retrato"))
    arquitectura = tk.Button(root, padx = 60, pady = 30, text = "Arquitectura", bg = "White", command = lambda: set_tag("Arquitectura"))

    change = tk.Button(root, padx = 60, pady = 30, text = "CAMBIAR ESTANTE", bg = "Red", command = back_menu)
    confirm = tk.Button(root, padx = 60, pady = 30, text = "CONFIRMAR FOTO", bg = "Green", command = lambda coord=coord: save_photo(coord))

    coordenada.pack()
    id_number.pack()
    label_tag.pack()

    paisaje.pack()
    retrato.pack()
    arquitectura.pack()

    confirm.pack()
    change.pack()

    root.mainloop() 


photo_gui(sys.argv[1])
