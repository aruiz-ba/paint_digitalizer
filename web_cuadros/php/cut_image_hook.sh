#!/bin/bash
#
#
echo "Hook script executed with ACTION=$ACTION and ARGUMENT=$ARGUMENT"
if [ "$ACTION" = "download" ]; then
	/var/www/html/cut_image/paint_cutter "$ARGUMENT"
	rm /var/www/html/cut_image/DSC*JPG
fi
