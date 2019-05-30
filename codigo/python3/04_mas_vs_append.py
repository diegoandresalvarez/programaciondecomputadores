import time

a = list(range(10_000_000))
tic = time.perf_counter()
a = a + ['xxx']
toc = time.perf_counter()
print('El proceso duró', toc-tic, 'segundos')

tic = time.perf_counter()
a.append('xxx')  # Observe que append es más eficiente que +
toc = time.perf_counter()
print('El proceso duró', toc-tic, 'segundos')

