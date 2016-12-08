clear
echo
i=0
fgbg=38
color=0
for j in {0..31} ; do
	if [ $color -lt 10 ]; then
		echo "\x1B[${fgbg};5;${color}m"' '${color}'   '"\x1B[0m" | tr -d '\n'
	else
		echo "\x1B[${fgbg};5;${color}m"' '${color}'  '"\x1B[0m" | tr -d '\n'
	fi
	i=$(($i + 1))
	color=$(($color + 1))
	if [ $i = 8 ]; then
		echo '     ' | tr -d '\n'
		color=$(($color - 8))
		fgbg=48
	elif [ $i = 16 ]; then
		echo
		fgbg=38
		i=0
	fi
done

i=0
fgbg=38
color=16
for j in {0..478} ; do
	if [ $color -lt 100 ]; then
		echo "\x1B[${fgbg};5;${color}m"' '${color}'  '"\x1B[0m" | tr -d '\n'
	else
		echo "\x1B[${fgbg};5;${color}m"' '${color}' '"\x1B[0m" | tr -d '\n'
	fi
	i=$(($i + 1))
	color=$(($color + 1))
	if [ $i = 6 ]; then
		echo '               ' | tr -d '\n'
		color=$(($color - 6))
		fgbg=48
	elif [ $i = 12 ]; then
		echo
		fgbg=38
		i=0
	fi
done
echo
echo
exit 0
