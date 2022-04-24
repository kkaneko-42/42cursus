package piscine

import "ft"

func PrintAlphabet() {
	nb_alphs := 26
	var a_ascii int = 'a'

	for i := 0; i < nb_alphs; i++ {
		ft.PrintRune(rune(a_ascii + i))
	}
	ft.PrintRune('\n')
}
