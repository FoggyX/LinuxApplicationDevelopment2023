set pagination off

break range.c:28 if i % 5 == 0
	command 1
	echo @@@
	print {M, S, N, i}
	continue
end

run 1 12 > /dev/null
quit
