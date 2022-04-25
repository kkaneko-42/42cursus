package piscine

import "ft"

func PrintNumber(nbr int) {
	var zero_ascii int = '0'

	if nbr < 10 {
		ft.PrintRune(rune(nbr + zero_ascii))
	} else {
		PrintNumber(nbr / 10)
		PrintNumber(nbr % 10)
	}
}

func PrintSep(i int, j int) {
	if i != 98 || j != 99 {
		ft.PrintRune(',')
		ft.PrintRune(' ')
	}
}

func PrintCombRecursive(nbr int, n int) {
	var zero_ascii int = '0'

	if nbr/10 == 0 {
		ft.PrintRune(rune(nbr + zero_ascii))
	}
	PrintCombRecursive(nbr / 10)
}

func PrintCombN(n int) {
	if n <= 0 || n >= 10 {
		return
	}

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
