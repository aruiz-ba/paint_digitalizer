import  tkinter as tk
import  os

root = tk.Tk()

def select_slot(row, col):
    abc = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H']

    root.destroy()
    print(abc[col] + str(row + 1))

item_list = [['A1', 'A2', 'A3', 'A4', 'A5', 'A6'],
             ['B1', 'B2', 'B3', 'B4'],
             ['C1', 'C2', 'C3'],
             ['D1', 'D2', 'D3', 'D4'],
             ['E1', 'E2', 'E3', 'E4'],
             ['F1', 'F2', 'F3', 'F4', 'F5', 'F6'],
             ['G1', 'G2', 'G3', 'G4', 'G5', 'G6'],
             ['H1', 'H2', 'H3', 'H4', 'H5', 'H6']]

max_cols = len(item_list)

col = 0
row = 0

while col < max_cols:  # Any number bigger than anticipated number of rows
    max_rows = len(item_list[col])
    while row < max_rows:
        file_n = len(os.listdir("./db/" + item_list[col][row] + "/"))
        if (file_n > 0):
            b = tk.Button(root, font=('Arial', 15), padx = 30, pady = 30, text=item_list[col][row] + "\n Cuadros:" + str(file_n), bg = "Green", command = lambda row=row,col=col: select_slot(row, col))
        else:
            b = tk.Button(root, font=('Arial', 15), padx = 30, pady = 30, text=item_list[col][row] + "\n Cuadros:" + str(file_n), command = lambda row=row,col=col: select_slot(row, col))
        b.grid(row=row, column=col)
        row += 1
    row = 0
    col += 1

root.mainloop() 
