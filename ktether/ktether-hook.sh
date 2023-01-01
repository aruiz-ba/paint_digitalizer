#!/bin/sh
case "$ACTION" in 
            start) 
                echo "$self: READY.." 
                ;; 
            download) 
		# Read the session settings
		. $PWD/session.conf
		this_file_number=$((last_file_number+1))
		file_string=`printf "%04d" $this_file_number`
		this_filename="$file_prefix-$file_string.NEF"
		# Copy latest file to latest.NEF so screen updates
		touch latest.jpg
		cp $ARGUMENT latest.jpg
		# Rename file from camera to our preferred
		echo ":: RENAME to $this_filename"
		#mv -n $ARGUMENT "$this_filename"
		# Update the session.conf with the new counter level
		echo "file_prefix=$file_prefix" > $PWD/session.conf
		echo "last_file_number=$this_file_number" >> $PWD/session.conf
                ;; 
        esac 

		./cut_image/paint_cutter ./latest.jpg
		rm -rf *JPG
        exit 0 

