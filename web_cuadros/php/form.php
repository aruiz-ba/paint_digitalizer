<!DOCTYPE html>
<html>
<head>
	<title>My PHP Website</title>
	<link rel="stylesheet" href="./styles/base.css">
</head>
<body>
	<script>
		window.onload = function() {
			document.getElementById('barcode').focus();
		};
	</script>
	<header>
	</header>
	<main>
		<?php
			//Get from url
			$filename_url = $_GET['file'];
			$columna_url = $_GET['columna'];
			$fila_url = $_GET['fila'];
			$estante_url = $_GET['estante'];
			$carpeta_url = $_GET['carpeta'];
			$temas = explode(",", $_GET["temas"]);

			$file = $filename_url;
			$Columna = $columna_url;
			$Fila = $fila_url;
			$Estante = $estante_url;
			$Carpeta = $carpeta_url;
			echo "<h1> Estante: $Estante Coordenada: $Columna$Fila Carpeta: $Carpeta</h1>";

			// Handle form submission
			if ($_SERVER["REQUEST_METHOD"] == "POST") {
				// Retrieve form data
				$label = $_POST["label"];
				//$file = $_FILES["file"]["name"];

				// Save file to server
				//$target_dir = "uploads/";
				//$target_file = $target_dir . basename($_FILES["file"]["name"]);
				//move_uploaded_file($_FILES["file"]["tmp_name"], $target_file);

				// Save data to database
				$servername = "db";
				$username = "myuser";
				$password = "mypassword";
				$dbname = "mydatabase";
				$conn = new mysqli($servername, $username, $password, $dbname);
				if ($conn->connect_error) {
					die("Connection failed: " . $conn->connect_error);
				}
				$sql = "INSERT INTO Objects (label, filename, Columna, Fila, Estante, Carpeta) VALUES ('$label', '$file', '$Columna', '$Fila', '$Estante', '$Carpeta')";
				if ($conn->query($sql) === TRUE) {
					$object_id = $conn->insert_id; // get the id of the inserted object

					// insert the tags for the object
            		foreach ($temas as $tema) {
            		    $sql = "INSERT INTO ObjectTags (object_id, tag_id) VALUES ('$object_id', (SELECT tag_id FROM Tags WHERE tag_name = '$tema'))";
            		    if ($conn->query($sql) !== TRUE) {
            		        echo "Error: " . $sql . "<br>" . $conn->error;
            		    }
            		}

					echo "<p>El cuadro se ha subido correctamente.</p>";
					echo "<p>¿Quieres seguir subiendo cuadros?</p>";
            		echo "<a class='button-link' href='select_theme.html?columna=$Columna&fila=$Fila&estante=$Estante&carpeta=$Carpeta'>Hacer otro cuadro</a>";
            		echo "<a class='button-link' href='./select_coords.html?estante=$Estante'>Cambiar de coordenadas</a>";
            		echo "<a class='button-link' href='./index.html'>Volver al principio</a>";
					exit();
				} else {
					echo "Error: " . $sql . "<br>" . $conn->error;
				}
				$conn->close();
			}
		?>

		<h2>Pegar código de barras y escanear</h2>
		<form method="post" enctype="multipart/form-data">
			<label for="label">Código de barras:</label>
			<input type="text" id="barcode" name="label" required><br><br>

			<input type="submit" value="Confirmar Cuadro">
		</form>
    	<img src="./cut_image/latest.jpg" alt="Live Image">

<!--		<form method="post" action="delete.php">
		   <input type="submit" name="delete" value="Borrar base de datos">
		</form>

		<a href="grid_view.php">Ver Imagenes</a>
		<a href="table_buttons.php">Button grid</a> -->
	</main>
</body>
