## 차이를 최대로

문제 설명 : https://www.acmicpc.net/problem/10819

## 풀이

N이 8이므로 모든 경우의 수는 `8! = 40320` 해결 가능한 범위이다.

## 주의할 점

C++의 `next_permutation`함수는 index 기반이 아니라 값 기반이다. 

따라서 맨 처음 데이터를 정렬해주어야 한다.