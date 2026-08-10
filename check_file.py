import sys
with open(r'E:\mcla pc\mcla extracted cache\resources\vehicle\va_taxi_rust1_96\0x7b0cd281', 'rb') as f:
    data = f.read(128)
    print(' '.join(f'{b:02x}' for b in data))
    print(f"Length: {len(open(r'E:\mcla pc\mcla extracted cache\resources\vehicle\va_taxi_rust1_96\0x7b0cd281', 'rb').read())} bytes")