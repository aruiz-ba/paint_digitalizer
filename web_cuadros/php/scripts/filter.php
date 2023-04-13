<head>
    <link rel="stylesheet" type="text/css" href="../styles/base.css">
</head>

<?php
$servername = "db";
$username = "myuser";
$password = "mypassword";
$dbname = "mydatabase";
$conn = new mysqli($servername, $username, $password, $dbname);

// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

$label = $_GET['label'];
$sql = "SELECT * FROM Objects WHERE label = '$label'";
$result = $conn->query($sql);

if ($result->num_rows > 0) {
    while($row = $result->fetch_assoc()) {
		echo '<h1> Estante: ' . $row["Estante"] . '</h1>';
		echo '<h1> Fila: ' . $row["Columna"] . $row["Fila"] . '</h1>';
		echo '<h1> Carpeta:' . $row["Carpeta"] . '</h1>';
        echo '<img src="../uploads/' . $row["filename"] . '" width="80%"><br>';
    }
} else {
    echo "0 results";
}
$conn->close();
?>

