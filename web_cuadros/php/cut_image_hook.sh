#!/bin/bash
#
if [ "$ACTION" = "download" ]; then
	/var/www/html/cut_image/paint_cutter "$ARGUMENT"
fi
