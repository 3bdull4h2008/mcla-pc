import sys
content = open('E:\\mcla pc\\src\\d3d12_backend.cpp', 'r').read()
brace = 0
in_ns = False
for i, line in enumerate(content.split('\n'), 1):
    brace += line.count('{')
    brace -= line.count('}')
    if 'namespace mcla::native' in line and '{' in line:
        in_ns = True
    if in_ns and brace == 0:
        print(f'Namespace closes at line {i}: {line.strip()}')
        break
    if brace < 0:
        print(f'Negative brace at line {i}: {line.strip()}')