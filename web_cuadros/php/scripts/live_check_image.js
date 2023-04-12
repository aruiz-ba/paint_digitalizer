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

//
//const saveButton = document.querySelector('#save-button');
//saveButton.addEventListener('click', () => {
//  fetch('./scripts/save_image.php')
//    .then(response => response.text())
//    .then(fileName => {
//      window.location.href = '../form.php?file=' + fileName;
//    })
//	.catch(error => {
//      console.error('Error saving file:', error);
//      throw error;
//    });
//    //.catch(error => console.error(error));
//});

const saveButton = document.querySelector('#save-button');

saveButton.addEventListener('click', () => {
  // Extract variables from URL
  const urlParams = new URLSearchParams(window.location.search);
  const columna = urlParams.get('columna');
  const fila = urlParams.get('fila');
  const estante = urlParams.get('estante');
  const temas = urlParams.get('temas');

  // Make fetch request and generate new URL with extracted variables
  fetch('./scripts/save_image.php')
    .then(response => response.text())
    .then(fileName => {
      const newUrl = `../form.php?file=${fileName}&columna=${columna}&fila=${fila}&estante=${estante}&temas=${temas}`;
      window.location.href = newUrl;
    })
    .catch(error => {
      console.error('Error saving file:', error);
      throw error;
    });
});
