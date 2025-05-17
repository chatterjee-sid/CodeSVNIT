def tobin(data):
    binval = ""
    for i in data:
        binval += bin(ord(i))[2:].zfill(8)
    return binval

def crc_ccitt(message):
    msgbin = tobin(message)
    print(f"Input hex: {hex(int(msgbin, 2))}")
    data = msgbin + '0' * 16
    crc = bindivision(data)
    print(f"CRC binary: {crc}")
    print(f"CRC hex: {hex(int(crc, 2))}")
    return crc

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
crc_ccitt(X)
