package piscine

import "ft"

func FtPow10(a int) int {
	var res int = 1

	for a > 0 {
		res *= 10
		a--
	}
	return (res)
}

func PrintNDigitNumber(nbr int, digit int) {
	var zero_ascii int = '0'

	for digit > 0 {
		digit--
	}
}

func PrintSep(i int, j int) {
	if i != 98 || j != 99 {
		ft.PrintRune(',')
		ft.PrintRune(' ')
	}
}

func PrintCombRecursive(nbr int) {

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
