#!/bin/sh

if !(pidof -x ktether > /dev/null); then
	./ktether/ktether &
fi

#hacer un creador de carpetas

COORD=$(python ./gui/menu_coord.py)
#sxiv ./latest.jpg &
python ./gui/save_photo.py $COORD 

pkill sxiv

./paint_digitalizer.sh

pkill ktether


#This to exit the application
#if [ $(python ./gui/save_photo.py $COORD) -eq "Menu" ]
#then
#	pkill sxiv
#	./paint_digitalizer.sh
#fi
#pkill sxiv
#pkill ktether


#Proteger boton de guardar para que solo guarde si no es el tick verde

#Preparar un script que se corra cada vez que se abra el programa que reinicie
#el numero de cuadros por si se ha borrado alguno

#Aniadir los botones tag para las imagenes que aniada metadatos, el boton de
#guardar no debe funcionar sin tener esto seleccionado
#
#Aniadir para poner medidas
