package piscine

import "ft"

func PrintComb() {
	var zero_ascii int = '0'

	for i := 0; i < 10; i++ {
		for j := i + 1; j < 10; j++ {
			for k := j + 1; k < 10; k++ {
				ft.PrintRune(rune(zero_ascii + i))
				ft.PrintRune(rune(zero_ascii + j))
				ft.PrintRune(rune(zero_ascii + k))
				if i != 7 || j != 8 || k != 9 {
					ft.PrintRune(',')
					ft.PrintRune(' ')
				}
			}
		}
	}
	ft.PrintRune('\n')
}
