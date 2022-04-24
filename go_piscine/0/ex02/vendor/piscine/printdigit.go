package piscine

import "ft"

func PrintDigit() {
	var zero_ascii int = '0'
	limit := 10
	i := 0

	for i < limit {
		ft.PrintRune(rune(zero_ascii + i))
		i++
	}
	ft.PrintRune('\n')
}
