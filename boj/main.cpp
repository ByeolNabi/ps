#include <iostream>
using namespace std;

//18111번 : 마인크래프트
	//구현?, 풀이찾기
class arr_2D {
	//0,0부터 시작
public:
	arr_2D(int row, int colum) {
		_size = row * colum;
		_arr = new int[_size];
		_row = row;
		_colum = colum;
	}
	void save(int row, int colum, int data) {
		_arr[row * _colum + colum] = data;
	}
	int load(int row, int colum) {
		z = _arr[row * _colum + colum];
		return _arr[row * _colum + colum];	
	}
	int z;
	int _size;
	int _row, _colum;
	int* _arr;
};
class minecraft {
//상태
	//int find_top_bottom_floor
	//int blocks_F();
	//bool DorP();		//dig true; place false
//행동
	//int digging();
	//int digging_all();
	//int placing();
//변수
	//int myBlocks;
	//int time;
	//int top_F;
	//int bottom_F;
	//int oneThird;
//다른 클래스
	//arr_2D* arr
public:
//초기화
	minecraft(int row, int colum, int Blocks) {
		arr = new arr_2D(row, colum);
		myBlocks = Blocks;
		time = 0;
		oneThird = (double)row * colum / 3;	//3분의 1에 소수점을 뺀다. 같다면 손실되기 전의 값은 작거나 같다.
		top_F = 0;
		bottom_F = 0;
	}
	void input_all() {
		for (int i = 0; i < arr->_size; i++) {
			cin >> arr->_arr[i];
		}
		find_top_bottom_floor();
	}
//상태값
	void find_top_bottom_floor() {
		top_F = arr->load(0, 0);
		bottom_F = arr->load(0, 0);
		for (int i = 0; i < arr->_size; i++) {
			if (top_F < arr->_arr[i]) {
				top_F = arr->_arr[i];
			}
			if (bottom_F > arr->_arr[i]) {
				bottom_F = arr->_arr[i];
			}
		}
	};
	int blocks_F(int floor) {
		int blocks = 0;
		for (int i = 0; i < arr->_row; i++) {
			for (int j = 0; j < arr->_colum; j++) {
				if (arr->load(i, j) >= floor) {
					blocks++;
				}
			}
		}
		return blocks;
	};
	bool DorP(int floor) {			//dig true; place false
		if (blocks_F(floor) >= oneThird) {
			return false;
		}
		else {
			return true;
		}
	}
//행동
	void digging(){		//무조건 최상위층부터 파내려가야함
		for (int i = 0; i < arr->_row; i++) {
			for (int j = 0; j < arr->_colum; j++) {
				if (arr->load(i, j) == top_F) {
					arr->save(i, j, top_F - 1);
					time += 2;
					myBlocks++;
				}
			}
		}
		top_F--;
	}
	void digging_all(){
		while (top_F > bottom_F) {
			digging();
		}
	}
	void placing(){		//최하위층부터 매꿔야한다.
		for (int i = 0; i < arr->_row; i++) {
			for (int j = 0; j < arr->_colum; j++) {
				if (arr->load(i, j) == bottom_F) {
					arr->save(i, j, bottom_F + 1);
					time += 1;
					myBlocks--;
				}
			}
		}
		bottom_F++;
	}
//변수
	int top_F;		//최상위층
	int bottom_F;	//온전한 최상위층
	double oneThird;
	int time;
	int myBlocks;
	arr_2D* arr;
};

int main() {
	int row, colum, inven;
	cin >> row >> colum >> inven;
	minecraft mc(row, colum, inven);
	mc.input_all();
	while (mc.top_F != mc.bottom_F) {
		if (mc.DorP(mc.bottom_F + 1) == true) {
			mc.digging_all();
		}
		else {
			if (mc.myBlocks >= (mc.arr->_size - mc.blocks_F(mc.bottom_F + 1))) {
				mc.placing();
			}
			else {
				mc.digging();
			}
		}
	} 
	cout << mc.time << " " << mc.top_F;
	return 0;
}

//인벤토리의 블럭이 충분하다고 가정; 한 층의 블럭이 1/3보다 적다면 캐는게 이득이다.
	//정확하게 1/3이 있다면 설치하는 것이 우선순위;
//최하위층의 블럭이 1/3보다 적다면; 무조건 최상위층부터 다 깍아 내려간다.
//최하위층의 블럭이 1/3보다 많다면; 최하위층을 다 매울 갯수를 모을때 까지; 최상위층을 캔다.
//캐는 것 먼저; 그후 갯수가 충분하면 매꾸기;

//최하단 블럭개수; 효율계산
	//디깅 -> 위에서부터 다 파내려감 end	//플레이스 -> (인벤토리 개수 > 최하단 빈블록 개수) ? 최하단 채우기 : 최상단 캐기;
	//전체 반복
