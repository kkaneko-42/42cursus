package piscine

func UltimateDivMod(a *int, b *int) {
	var div, mod int

	if *b == 0 {
		*a = 0
	} else {
		div = *a / *b
		mod = *a % *b
		*a = div
		*b = mod
	}
}
