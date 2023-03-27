<?php
$servername = "db";
$username = "myuser";
$password = "mypassword";
$dbname = "mydatabase";

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);

// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

// SQL para eliminar todos los datos de las tablas
$sql = "DELETE FROM files";

// Ejecuta la consulta
if ($conn->query($sql) === TRUE) {
    echo "Base de datos eliminada correctamente";
} else {
    echo "Error al eliminar la base de datos: " . $conn->error;
}

// Cierra la conexión
$conn->close();
?>

