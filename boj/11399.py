# [실버4] ATM
import sys
from itertools import accumulate

data = sys.stdin.read().splitlines()

times = list(map(int, data[1].split()))
times.sort()


acc_times = list(accumulate(times))
print(sum(acc_times))