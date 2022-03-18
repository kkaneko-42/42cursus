import sys, os
import ctypes
import numpy as np
import random

RESET = "\033[0m"
RED = "\033[31m"
GREEN = "\033[42m"
TMP_FILES = {"libmat.so"}

def main():
	if (	build()
		or	make_libso()
		or	function_test()):
		print(RED, "KO", RESET)
	else:
		print(GREEN, "OK", RESET)
	remove_tmpfiles()

def build():
	if (os.system("make affine debug")):
		print(RED, "Build error", RESET)
		return (True)

def make_libso():
	os.system("ld -shared -o libmat.so --whole-archive libmat.a")

def function_test():
	libmat = ctypes.cdll.LoadLibrary("libmat.so")
	if (mat_add_test(libmat)
		or mat_mul_scalar_test(libmat)
		or mat_mul_test(libmat)
		or mat_identity_test(libmat)
		or mat_transpose_test(libmat)
		or mat_dup_test(libmat)
		or mat_submat_test(libmat)
		or mat_det_test(libmat)
		or mat_inv_test(libmat)
		or mat_inner_test(libmat)
		or mat_rotation_x_test(libmat)
		or mat_rotation_y_test(libmat)
		or mat_rotation_z_test(libmat)
		or mat_rotation_any_test(libmat)
		or mat_translation_test(libmat)
		or mat_zoom_test(libmat)
		or mat_vector_col_test(libmat)
		or mat_vector_row_test(libmat)
		or mat_l2norm_test(libmat)
		or mat_print_test(libmat)):
		return (1)
	else
		return (0)

def remove_tmpfiles():
	for file in TMP_FILES:
		if (os.path.exists(file)):
			os.remove(file)
	os.system("make fclean")

if __name__ == "__main__":
	main()
