package piscine

import "ft"

func PrintTwoDigitNumber(nbr int) {
	var zero_ascii int = '0'

	ft.PrintRune(rune((nbr / 10) + zero_ascii))
	ft.PrintRune(rune((nbr % 10) + zero_ascii))
}

func PrintSep(i int, j int) {
	if i != 98 || j != 99 {
		ft.PrintRune(',')
		ft.PrintRune(' ')
	}
}

func PrintComb2() {
	for i := 0; i < 100; i++ {
		for j := i + 1; j < 100; j++ {
			PrintTwoDigitNumber(i)
			ft.PrintRune(' ')
			PrintTwoDigitNumber(j)
			PrintSep(i, j)
		}
	}
	ft.PrintRune('\n')
}
