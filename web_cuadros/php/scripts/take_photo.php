<?php
// Ruta donde se guardará la foto temporalmente en el servidor
$tempFilePath = 'uploads/temp.jpg';

// Comando para tomar la foto con gphoto
$cmd = 'gphoto2 --capture-image-and-download --filename ' . $tempFilePath;

// Ejecutar el comando y capturar la salida
$output = shell_exec($cmd);

// Verificar si se guardó la foto exitosamente
if (file_exists($tempFilePath)) {
    echo 'Foto tomada y guardada temporalmente en ' . $tempFilePath;
} else {
    echo 'Error al tomar la foto';
}
?>
