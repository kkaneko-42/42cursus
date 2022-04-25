package piscine

func SwapRune(a *rune, b *rune) {
	tmp := *a
	*a = *b
	*b = tmp
}

func StrLen(s string) int {
	var len int = 0

	for i, _ := range s {
		len = i
	}
	return len + 1
}

func StrRev(s string) string {

}
