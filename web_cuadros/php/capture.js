const video = document.getElementById('video');
const canvas = document.getElementById('canvas');
const photo = document.getElementById('photo');
const captureButton = document.getElementById('capture');
const uploadButton = document.getElementById('upload');
const imageDataInput = document.getElementById('image-data');

navigator.mediaDevices.enumerateDevices()
  .then(function(devices) {
    let cameras = devices.filter(function(device) {
      return device.kind === 'videoinput';
    });

    if (cameras.length === 0) {
      console.log('No cameras found.');
      return;
    }

    let camera = cameras[cameras.length - 1];

    navigator.mediaDevices.getUserMedia({ video: { deviceId: camera.deviceId } })
      .then(function(stream) {
        video.srcObject = stream;
        video.play();
      })
      .catch(function(err) {
        console.log("Error accessing camera: " + err.message);
      });
  })
  .catch(function(err) {
    console.log("Error enumerating devices: " + err.message);
  });

captureButton.addEventListener('click', function() {
  canvas.getContext('2d').drawImage(video, 0, 0, canvas.width, canvas.height);
  photo.src = canvas.toDataURL('image/png');
  imageDataInput.value = photo.src;
  uploadButton.disabled = false;
});

uploadButton.addEventListener('click', function() {
  document.getElementById('upload-form').submit();
});

