## 2xN 타일링 (2)

문제 설명 : https://www.acmicpc.net/problem/11726

## 해답

2 * 2짜리 돼지 타일이 새로 생겼다.

기존 문제에서 크게 달라지는 건 없다.

기저조건도 잘 바꿔주세요. (`a[2] = 3`입니다.) 

아래 점화식의 달라진 부분을 확인하라.

## 정답

`f(n) = f(n-1) + 2 * f(n-2)`

`f(n-2)`에 2를 곱한 모습이다.