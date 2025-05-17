import fitz  # PyMuPDF
import pytesseract
import cv2
import os
from re import sub
from datetime import datetime

start = datetime.now()

pdf_path = 'HW1.pdf'
document = fitz.open(pdf_path) # Load the PDF document

def preprocess_image(image_path): # Function to preprocess the image
    image = cv2.imread(image_path, cv2.IMREAD_GRAYSCALE) # read image in grayscale
    image = cv2.resize(image, (0, 0), fx=2, fy=2) # Resize image to a standard size
    return image

extracted_text = "" # Extract text from each page
for page_number in range(len(document)): # length of document is number of pages
    page = document.load_page(page_number)
    pix = page.get_pixmap(matrix=fitz.Matrix(2,2)) # Render page to an image
    image_path = "Tpage_{}.png".format(page_number)
    pix.save(image_path) # Save the image of the page

    preprocessed_image = preprocess_image(image_path) # Preprocess the image

    page_text = pytesseract.image_to_string(preprocessed_image) # Perform OCR on the preprocessed image
    extracted_text += "---------------\n{}\n".format(page_text) #Add text extracted from page
    extracted_text = sub(r'[^\x00-\x7F]+','',extracted_text) #To avoid gibberish (doesn't help much)

    os.remove("Tpage_{}.png".format(page_number)) #remove saved image

output_path = 'HW1_tesseract.txt'
with open(output_path, 'w') as file:
    file.write(extracted_text) # Save the extracted text to a file

print("Extracted text saved to {}".format(output_path))

end = datetime.now()
print(end-start)