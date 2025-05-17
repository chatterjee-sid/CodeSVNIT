def tobin(data):
    binval = ""
    for i in data:
        binval += bin(ord(i))[2:].zfill(8)
    return binval

def check_crc(message, crc):
    received_bits = tobin(message) + bin(int(crc,16))[2:].zfill(16)
    remainder = bindivision(received_bits)    
    if remainder == '0' * 16:
        print("Message verified. No errors found.")
    else:
        print("CRC does not match, error in message suspected!!")

def bindivision(bitlist):
    data = list(bitlist)
    polynomial = bin(0x11021)[2:]
    i = 0
    while i <= len(data) - 17:
        if data[i] == '1':
            for j in range(17):
                data[i + j] = '0' if data[i + j] == polynomial[j] else '1'
        i += 1
    remainder = ''.join(data[-16:])
    return remainder

X = input("Enter your message: ")
Y = input("Enter CRC value: ")
check_crc(X,Y)