import struct

def ones_complement_sum(data):
    """Compute one's complement sum of 16-bit words."""
    checksum = 0
    for i in range(0, len(data), 2):
        word = (data[i] << 8) + (data[i + 1] if i + 1 < len(data) else 0)
        checksum += word
        checksum = (checksum & 0xFFFF) + (checksum >> 16)  #Wraparound

    return ~checksum & 0xFFFF  #One's complement

def verify_tcp_checksum(ip_header, tcp_segment):
    """Verify TCP checksum using pseudo-header."""
    src_ip = ip_header[12:16]
    dst_ip = ip_header[16:20]
    protocol = 6  #TCP protocol number
    tcp_length = len(tcp_segment)
    pseudo_header = struct.pack("!4s4sBBH", src_ip, dst_ip, 0, protocol, tcp_length)
    received_checksum = struct.unpack(">H", tcp_segment[16:18])[0]
    tcp_segment = bytearray(tcp_segment)
    tcp_segment[16:18] = b'\x00\x00'

    computed_checksum = ones_complement_sum(pseudo_header + tcp_segment)

    return computed_checksum == received_checksum, computed_checksum, received_checksum

packet_hex = input()
packet_bytes = bytes.fromhex(packet_hex)

ihl = (packet_bytes[0] & 0x0F) * 4  
ip_header = packet_bytes[:ihl]
tcp_segment = packet_bytes[ihl:]

tcp_correct, tcp_computed, tcp_received = verify_tcp_checksum(ip_header, tcp_segment)
print(f"TCP Checksum: Computed={hex(tcp_computed)}, Received={hex(tcp_received)}, Match={tcp_correct}")
