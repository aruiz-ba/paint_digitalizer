// Set the URL of the image file
const imageUrl = './cut_image/latest.jpg';

// Set the interval for checking for changes (in milliseconds)
const checkInterval = 1000;

// Get the image element on the page
const imageElement = document.querySelector('img');

// Function to check for changes in the image file
function checkForImageChanges() {
  // Create a new Image object
  const newImage = new Image();

  // Set the src attribute of the new Image object to the image URL with a cache-busting query parameter
  newImage.src = `${imageUrl}?${new Date().getTime()}`;

  // When the new Image object loads
  newImage.onload = () => {
    // Update the src attribute of the image element on the page
    imageElement.src = newImage.src;
  };
}

// Check for changes in the image file at the specified interval
setInterval(checkForImageChanges, checkInterval);
const saveButton = document.querySelector('#save-button');
saveButton.addEventListener('click', () => {
  fetch('./scripts/save_image.php')
    .then(response => response.text())
    .then(text => console.log(text))
    .catch(error => console.error(error));
});
