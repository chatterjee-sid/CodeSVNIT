import easyocr

# Initialize the OCR reader (English language)
reader = easyocr.Reader(['en'])

# Read text from the image
result = reader.readtext('HW1.pdf', detail=0)  # detail=0 gives plain text

# Save the extracted text into a file
with open('HW1.txt', 'w') as f:
    f.write("\n".join(result))

print("Text extracted and saved to HW1.txt!")
