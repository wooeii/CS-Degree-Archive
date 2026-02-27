#include <iostream>
#include <cstdlib>
#include <iomanip> // 출력 형식을 조절하기 위한 헤더 파일
#include <ctime>
using namespace std;

int main()
{
	srand(time(NULL));
	float cash, target_money, bets=0, win=0; //초기금액, 목표금액, 배팅횟수, 이긴횟수
	cout << "초기 금액 $";
	cin >> cash; //초기 금액 입력
	cout << "목표 금액 $";
	cin >> target_money; //목표 금액 입력 

	for (int i = 0; i < 1000; i++)
	{
		float initial_cash = cash; //초기금액을 저장 
		while (cash > 0 && cash != target_money) //cash가 목표 금액, 0이 될때까지 반복 
		{
			bets++; //배팅횟수 증가 
			if ((double)rand() / RAND_MAX < 0.5) cash++; //승리 시 cash 증가
			else	cash--; //cash 감소 
		}
		if (cash == target_money) //cash가 목표값에 도달했을경우
		{
			win++; //win을 증가
		}
		cash = initial_cash; //cash를 다시 초기 금액으로 설정.
	}
	cout << "1000 중의" << win << "번 승리" << endl;
	cout << fixed << setprecision(6);	// 소수점 6자리까지 출력
	cout << "이긴 확률 =" << win / 1000.0 * 100.0 << endl; 
	cout << "평균 배팅 횟수 =" << bets / 1000 << endl; 
}