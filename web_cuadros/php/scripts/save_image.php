<?php

// Set the source and destination paths
$srcPath = '../cut_image/latest.jpg';
$destPath = './Bodegon.jpg';

// Copy the file
if (copy($srcPath, $destPath)) {
  echo 'Image saved successfully';
} else {
  echo 'Error saving image';
}

?>
