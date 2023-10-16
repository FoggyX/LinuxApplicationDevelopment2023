set pagination off

set $i = 0
break range.c:28 if ++$i >= 28 && $i<= 35
	command
	echo @@@
	print {M, S, N, i}
	continue
end

run -100 100 3 > /dev/null
quit
