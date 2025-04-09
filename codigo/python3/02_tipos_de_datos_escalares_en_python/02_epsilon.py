import sys

print('sys.float_info.epsilon = ', sys.float_info.epsilon) 

if 1.0 + sys.float_info.epsilon   > 1.0:
   print('1.0+eps > 1.0');
if 1.0 + sys.float_info.epsilon/2 > 1.0:
   print('1.0+eps/2 > 1.0');

