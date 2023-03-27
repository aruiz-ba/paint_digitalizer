FROM php:7.4-apache

RUN docker-php-ext-install mysqli && docker-php-ext-enable mysqli

# Instalar gphoto2 y sus dependencias
RUN apt-get update && \
    apt-get install -y libgphoto2-dev gphoto2 vim && \
    rm -rf /var/lib/apt/lists/*


COPY . /var/www/html/

RUN mkdir /var/www/html/uploads && \
    chmod 777 /var/www/html/uploads && \
	chown -R www-data:www-data /var/www/html/uploads

EXPOSE 80

