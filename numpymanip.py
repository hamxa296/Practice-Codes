import numpy as np
def create_border_array(a, b):
    arr = np.ones((a, b))
    arr[1:-1, 1:-1] = 0
    return arr

print(create_border_array(4, 4))
