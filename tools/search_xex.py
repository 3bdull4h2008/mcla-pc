import struct

data = open('E:/mcla pc/game_data/default.xex', 'rb').read()
addresses = [0x8213178C, 0x821BD8C0, 0x824569C8, 0x823F69C8]

for addr in addresses:
    be = struct.pack('>I', addr)
    count = data.count(be)
    print(f'0x{addr:08X}: {count} occurrences')
    offset = 0
    while True:
        idx = data.find(be, offset)
        if idx == -1:
            break
        print(f'  offset 0x{idx:08X}')
        offset = idx + 1