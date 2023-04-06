FROM php:7.4-apache

RUN docker-php-ext-install mysqli && docker-php-ext-enable mysqli

# Instalar gphoto2 y sus dependencias
RUN apt-get update && \
	apt-get install -y libgphoto2-dev gphoto2 vim usbutils && \
	rm -rf /var/lib/apt/lists/*

# Instalar opencv y sus dependencias
RUN apt-get update && \
	apt-get -y install git cmake build-essential wget unzip g++

#Installation of opencv
WORKDIR /home/
RUN wget -O opencv.zip https://github.com/opencv/opencv/archive/4.x.zip
RUN unzip opencv.zip
RUN mv opencv-4.x opencv
WORKDIR opencv
RUN mkdir -p build
WORKDIR build
RUN cmake ../
RUN make -j4
RUN make install

#ADD ./paint_digitalizer/ /home/
#ADD ./test_green_file.jpeg /home/

# Installation of all the web stuff
COPY . /var/www/html/

RUN mkdir /var/www/html/uploads && \
    chmod 777 /var/www/html/uploads && \
    chmod o+w /var/www/html/* && \
	chown -R www-data:www-data /var/www/html/uploads

EXPOSE 80

# Compile cut_image
WORKDIR /var/www/html/cut_image/
RUN cmake .
RUN make

# Copy the start script and make it executable
COPY ./start.sh /usr/local/bin/

RUN chmod +x /usr/local/bin/start.sh
RUN chmod +x /var/www/html/cut_image_hook.sh

# Use the start script as the entrypoint
#ENTRYPOINT ["/usr/local/bin/start.sh"]

CMD ["/bin/bash", "-c", "/usr/local/bin/start.sh > /dev/null 2>&1 & apache2-foreground"]
