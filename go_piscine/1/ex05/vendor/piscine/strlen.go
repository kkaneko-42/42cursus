package piscine

func StrLen(s string) int {
	var len int = 0

	for i, _ := range s {
		len = i
	}
	return len + 1
}
