if [ -z $1 ]; then
	SLEEP_TIME=0.01
else
	SLEEP_TIME=$1
fi

LINE=0
ARR=()
while IFS= read -r line; do
	for (( i=0; i<${#line}; i++ )); do
		symb="${line:$i:1}"
		ARR+=("$i $LINE $symb")
	done 
	((LINE++))
done

tput clear

while read line col symb; do
	tput cup $col $line; echo -n $symb
	sleep $SLEEP_TIME
done <<< `shuf -e "${ARR[@]}"`
tput cup $LINE 0
