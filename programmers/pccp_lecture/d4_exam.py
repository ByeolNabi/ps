def solution(id_list, report, k):
    reports = list(set(report));
    members = id_list; #인덱스 참고를 위한 리스트
    target = [[0 for i in range(len(id_list))] 
              for i in range(len(id_list))]; # 누구를 신고했는가
    reported = [0 for i in range(len(id_list))]; # 얼마나 신고되었는가
    result = [0 for i in range(len(id_list))]; # 메일을 얼마나 받아야 하는가
    
    for report in reports:
        giver, taker = report.split()
        # 얼마나 신고되었는가 +1
        reported[members.index(taker)] = reported[members.index('taker')]+1;
        # 누가 누구를 신고했는가 +1
        target[members.index(giver)][members.index(taker)] = target[members.index(giver)][members.index(taker)]+1;
    
    # reported 2번 이상 받은 사람 찾기
    criminal = list();
    for idx, tiket in enumerate(reported):
        if tiket >= k:
            criminal.append(idx)
    # 정지된 유저를 신고한 사람 찾기
    for idx, t in enumerate(target):
        for i in criminal:
            if t[i] == 1:
                result[idx] = result[idx]+1
    
    return result

a = solution(["con", "ryan"], ["ryan con", "ryan con", "ryan con", "ryan con"], 3)
print(a)