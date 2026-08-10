import os

path = r'E:\mcla pc\mcla extracted cache\resources\vehicle\va_taxi_rust1_96'

for fname in os.listdir(path):
    path_f = os.path.join(path, fname)
    size = os.path.getsize(path_f)
    with open(path_f, 'rb') as f:
        header = f.read(16)
    print(f"{fname}: {size} bytes, header: {' '.join(f'{b:02x}' for b in open(path_f, 'rb').read(16))}")