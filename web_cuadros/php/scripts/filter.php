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
        echo '<img src="../uploads/' . $row["filename"] . '"><br>';
    }
} else {
    echo "0 results";
}
$conn->close();
?>

