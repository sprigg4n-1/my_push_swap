#!/bin/bash
CHECKER=./checker_linux

run() {
	local n=$1 max=$2 runs=$3
	printf "n=%-4d" $n
	for flag in --simple --medium --complex; do
		local sum=0 mx=0
		for ((r = 0; r < runs; r++)); do
			ARG=$(shuf -i 1-$max -n $n | tr '\n' ' ')
			res=$(./push_swap $flag $ARG | $CHECKER $ARG)
			if [[ "$res" != "OK" ]]; then
				echo; echo "$flag n=$n -> $res"; echo "ARG: $ARG"; exit 1
			fi
			ops=$(./push_swap $flag $ARG | wc -l)
			((sum += ops)); ((ops > mx)) && mx=$ops
		done
		printf "  | %-9s avg %6d max %6d" ${flag#--} $((sum / runs)) $mx
	done
	echo
}

run 3   100   20
run 5   100   20
run 100 1000  20
run 500 10000 10
run 1000 10000 5
run 2000 20000 3
