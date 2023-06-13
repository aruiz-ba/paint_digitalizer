## Project Description

The main objective of this project is to digitize paintings in an accessible, simple, and efficient manner while keeping resource usage low. The project follows the following workflow:

**Image Cropping using OpenCV in C++:**
- Apply a binary mask using the green background.
- Implement a simple algorithm to detect the edges of the object.
- Use the coordinates obtained in the previous step to crop the original image.

**Connecting the DSLR Camera:**
- Utilize gphoto for tethering and real-time transfer of photos to the computer.
- Automate the process using shell scripts.

**Creating Barcode Labels:**
- Generate barcode labels using GNU Barcode to uniquely identify each painting in a database.

**User Interface:**
- Initially implemented using Qt, but found it to be less user-friendly.
- Transitioned to web technology for a more user-friendly interface.
- Implemented a thematic cataloging menu to create a filtering system for the artwork.

Through this project, we aim to provide a straightforward and efficient solution for the digitalization of paintings, making it accessible to a wider audience.

# Images

![1](https://github.com/aruiz-ba/paint_digitalizer/assets/46310231/70b017a5-e989-4d8c-bc28-46790d9d29b7)

*The overwhelming amount of artwork by the painter in his studio.*

---

![4](https://github.com/aruiz-ba/paint_digitalizer/assets/46310231/6dcfea7e-c800-4d80-a71c-bf19c18b4ef0)

*The green screen device that I designed for the paintings.*

---

![output2](https://github.com/aruiz-ba/paint_digitalizer/assets/46310231/0b531c87-e8b3-440d-898c-7369ad1a8282)

*The barcodes allow the user to keep their collection tidy.*

---

![DSC09817](https://github.com/aruiz-ba/paint_digitalizer/assets/46310231/03aaf465-0091-4d28-896b-90335afa702a)

*A screen that previews the previous search the user has made in the database, whether through barcode or theme.*

---

![qt_version](https://github.com/aruiz-ba/paint_digitalizer/assets/46310231/bb69e953-d581-4679-b577-1704e0fef304)

*I have prototyped a Qt interface that appears clean, but it may not be user-friendly for individuals who are more visually oriented and not accustomed to using computers.*

---

![composed_image1](https://github.com/aruiz-ba/paint_digitalizer/assets/46310231/b47fc50c-3ffa-4276-8613-1ee76dfce421)

*An intuitive interface that provides a new, accessible, and organized vision of the space.*

---

![web_themes](https://github.com/aruiz-ba/paint_digitalizer/assets/46310231/0544bb18-7141-4e8f-8eac-d472fc710cc7)

*A web-based theme selector that is user-friendly and visually intuitive.*

---

# Rembrandt and Manuel: an artistic fusion with Stable Diffusion

By applying Stable Diffusion and Dreambooth to the digitized work, impressive results can be obtained that reinvent a Rembrandt portrait through the style of only landscape works by the artist Manuel Ruiz Ortega. This allows Stable Diffusion to be taught to paint like Manuel, but only understanding Manuel’s world through his landscape painting, completely ignoring his portraits and paintings with human or animal figures. This creates magnificent results where AI fuses natural landscapes from Manuel’s childhood with the clothing of the portrait and completes the face’s unknown with a midpoint between Rembrandt’s portraits and Manuel’s style, achieving an exquisite fusion of both styles.

![comparacion](https://github.com/aruiz-ba/paint_digitalizer/assets/46310231/4e185063-9343-4e13-92d9-42f8a16ac615)
*On the right the original paintings of Manuel, on the left the AI result*
![comparacion2](https://github.com/aruiz-ba/paint_digitalizer/assets/46310231/45e6aebf-a819-4698-b09c-b085cfb8dcfb)
*On the right the original painting of Manuel, on the left the AI result*
![comparacion5](https://github.com/aruiz-ba/paint_digitalizer/assets/46310231/6ade524c-13b7-4a61-9831-ca18ed3aed18)
*On the right the original painting of Manuel, on the left the AI result*
