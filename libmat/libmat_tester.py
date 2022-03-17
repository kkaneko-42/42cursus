import numpy as np
import subprocess
import random

RESET = "\033[0m"
RED = "\033[31m"
GREEN = "\033[42m"

#Build libmat
if (subprocess.run(["make", "affine", "debug"])):
	print(RED, "Build error", RESET)

#
