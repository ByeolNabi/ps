// ascode 1123 틱택토
# include<iostream>
using namespace std;

// p가 이겼나요? >> 
int isWinner(int p);
// num줄에 빙고가 있나요?
int rowChecker(int p, int num);
// num줄에 빙고가 있나요?
int colChecker(int p, int num);
// cross에 빙고가 있나요?
int crossChecker(int p);
// 꽉 찼는데 승자가 없어?
int drawChecker();

int board[9] = { 0 };

int main() {
	int tc; cin >> tc;
	// tc만큼 반복
	for (int i = 0; i < tc; ++i) {
		int stone1 = 0, stone2 = 0;
		// 게임 상황판 입력받기
		for (int j = 0; j < 9; ++j) {
			cin >> board[j];
			if (board[j] == 1) ++stone1;
			if (board[j] == 2) ++stone2;
		}
		// 정상 비정상 판단하기
		if (stone1 == stone2 || stone1 == stone2 + 1) { // stone1이 stone2보다 한개가 많거나 같으면 정상
			// 게임이 진행중인지 끝났는지 판단하기 
			if(isWinner(1) && stone1 == stone2) { // 2가 돌을 놓았지만 이긴 사람은 1인 경우
				printf("NO\n");
			}
			else if(isWinner(2) && stone1 == stone2+1) { // 2가 돌을 놓았지만 이긴 사람은 1인 경우
				printf("NO\n");
			}
			// else if(isWinner(1)&&isWinner(2)){ // 두 면이 동시에 이겼으면 망함
			// 	printf("NO\n");
			// }
            else if((stone1 + stone2 == 9) && !(isWinner(1)||isWinner(2))){ // 이긴 사람 없고 and 보드가 꽉 찼어
                printf("DRAW\n");
            }
			else if (isWinner(1)) { // 1이 이겼나?
                printf("1\n");
			}
			else if (isWinner(2)) { // 2이 이겼나?
				printf("2\n");
			}
			else { // 이긴 사람이 없어... >> 게임이 안 끝났다
				printf("YES\n");
			}
		}
		else { // 이외의 상황이면 비정상
			printf("NO\n");
		}

	}

	return 0;
}

int isWinner(int p) {
    // col 순회
	for (int i = 0; i < 3; ++i) {
		if (colChecker(p,i)) {
			return 1;
		}
    }
    // row 순회
    for (int i = 0; i < 3; ++i){
		if (rowChecker(p,i*3)) {
			return 1;
		}
    }
    if (crossChecker(p)) {
        return 1;
    }
	return 0; // 승자가 아니라면
}
int colChecker(int p,int num) {
	if (board[num] == p && board[num+3] == p && board[num+6] == p) {
		return 1;
	}
	return 0;
}
// num줄에 빙고가 있나요?
int rowChecker(int p, int num) {
	if (board[num] == p && board[num + 1] == p && board[num + 2] == p) {
		return 1;
	}
	return 0;
}
// cross에 빙고가 있나요?
int crossChecker(int p) {
	if (board[0] == p && board[0 + 4] == p && board[0 + 8] == p) return 1;
	if (board[2] == p && board[2 + 2] == p && board[2+4] == p) return 1;
	return 0;
}

/*
정상 비정상
정상 >> 게임이 끝났는지, 안 끝났는지
	게임 끝 >> 1, 2, DRAW
	게임 안끝 >> YES
비정상 >> NO

둘다 빙고를 한 상황이면? 그런 tc도 있을까?

4
0 0 0
0 1 0
0 0 0
1 2 2
2 1 1
2 1 1
0 2 2
1 1 2
2 2 0
2 1 1ㅌ
1 2 2
1 2 1

***
1이 놓았지만 2가 이긴 상황
2가 놓았지만 1이 이긴 상황
***
*/