package piscine

import "ft"

func PrintReverseAlphabet() {
	nb_alphs := 26
	var a_ascii int = 'a'
	i := nb_alphs - 1

	for i >= 0 {
		ft.PrintRune(rune(a_ascii + i))
		i--
	}
	ft.PrintRune('\n')
}
