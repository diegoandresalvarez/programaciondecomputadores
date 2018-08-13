import time

a = list(range(10000000))
tic = time.time()
b = a + ['xxx']
toc = time.time()
print('El proceso duró', toc-tic, 'segundos')

tic = time.time()
a.append('xxx')  # Observe que append es más eficiente que +
toc = time.time()
print('El proceso duró', toc-tic, 'segundos')

