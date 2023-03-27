<!DOCTYPE html>
<html>
<head>
	<title>My PHP Website</title>
	<style>
		img {
			max-width: 300px;
			max-height: 300px;
			margin: 10px;
			border: 1px solid #ddd;
			border-radius: 5px;
			padding: 5px;
		}
	</style>
</head>
<body>
	<header>
		<h1>Welcome to my PHP website!</h1>
	</header>
	<main>
		<h2>Images</h2>
		<div>
			<?php
				// Retrieve images from database
				$servername = "db";
				$username = "myuser";
				$password = "mypassword";
				$dbname = "mydatabase";
				$conn = new mysqli($servername, $username, $password, $dbname);
				if ($conn->connect_error) {
					die("Connection failed: " . $conn->connect_error);
				}
				$sql = "SELECT * FROM files";
				$result = $conn->query($sql);
				if ($result->num_rows > 0) {
					// Output images as a grid
					echo "<div>";
					while($row = $result->fetch_assoc()) {
						echo "<img src=\"uploads/" . $row["filename"] . "\" alt=\"" . $row["label"] . "\">";
					}
					echo "</div>";
				} else {
					echo "<p>No images found.</p>";
				}
				$conn->close();
			?>
		</div>
	</main>
	<footer>
		<p>&copy; 2023 My PHP Website. All rights reserved.</p>
	</footer>
</body>
</html>

