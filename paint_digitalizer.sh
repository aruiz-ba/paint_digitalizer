#!/bin/sh

./ktether/ktether &
sxiv ./gui/latest.jpg &
python ./gui/gui.py
pkill gphoto2

#Proteger boton de guardar para que solo guarde si no es el tick verde

#Preparar un script que se corra cada vez que se abra el programa que reinicie
#el numero de cuadros por si se ha borrado alguno

#Aniadir los botones tag para las imagenes que aniada metadatos, el boton de
#guardar no debe funcionar sin tener esto seleccionado
