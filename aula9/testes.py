import subprocess
import time
import os

files = os.listdir("./testes")
files.sort()
print(files)
for file in files:
    print(file)
    with open("./testes/"+file) as f:
        start = time.perf_counter()
        proc = subprocess.run(['./aula8'], input=f.read(), text=True, capture_output=True)
        end = time.perf_counter()

        print('Saída:')
        print(proc.stdout)
        print('Stderr:', proc.stderr)
        print('Tempo total(s):', end - start)
        print("\n")