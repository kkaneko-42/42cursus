package piscine

func DivMod(a int, b int, div *int, mod *int) {
	if b == 0 {
		*div = 0
		*mod = 0
	} else {
		*div = a / b
		*mod = a % b
	}
}
