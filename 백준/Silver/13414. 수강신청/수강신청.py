import sys
input = sys.stdin.readline

k, l = map(int, input().split())
std_idx = dict()
idx_std = dict()

for idx in range(l):
    std_num = input().strip()  # 수정: int() 제거
    if std_num in std_idx:
        idx_std.pop(std_idx[std_num])
    idx_std[idx] = std_num
    std_idx[std_num] = idx

ans = list(idx_std.values())

for i in range(min(k, len(ans))):  # 혹시 인원보다 신청자가 적을 때
    print(ans[i])
