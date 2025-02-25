# Program run after Part c
myfile = open("DBMS\\DBMS_1\\01_mynewfile.txt","r")
lines, words, para = 0,1,1
flines, fwords = 0,0
a = myfile.read()
filesize = 0
for i in a:
    filesize += 1
    if i in '.?;!':
        lines += 1
    if i in ' /':
        words += 1
    if i=='\n':
        print(f"Para{para}: Lines: {lines}, Words: {words}")
        para += 1
        flines += lines
        fwords += words
        lines = 0
        words = 1
print(f"Para{para}: Lines: {lines}, Words: {words}")
print(f"In File, Lines: {flines}, Words: {fwords}")
print(f"FileSize: {filesize}B")
myfile.close()
# no. of lines, no. of words, no. of paragraphs