<?php
// Set the source and destination paths
$srcPath = '../cut_image/latest.jpg';
$fileName = uniqid() . '_' . bin2hex(random_bytes(8)) . '.jpg';
$destPath = '../uploads/' . $fileName;

// Copy the file
if (copy($srcPath, $destPath)) {
  echo $fileName;
} else {
  echo 'Error saving image';
}

?>
