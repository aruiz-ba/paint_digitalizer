#!/bin/bash

# Run gphoto2 with the hook script
gphoto2 --capture-tethered --hook-script=/var/www/html/cut_image_hook.sh &
