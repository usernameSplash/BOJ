## 날카로운 눈

정수가 여러 개 모여 있는 정수더미가 있다. 그 안에 어떤 특정한 정수 하나만 홀수개 존재하고 나머지 정수는 모두 짝수개 존재한다. 정수더미 속에서 날카로운 눈을 이용해 홀수개 존재하는 정수를 찾아야 하는 문제이다.

입력이 n 줄 주어지며 각 줄마다 정수가 3개 입력된다.

입력되는 정수를 각각 **A, C, B**(순서에 유의할 것)이라고 하면, A, A+B, A+2B, ..., A+kB (단, A+kB ≦ C) 의 정수들이 정수더미 안에 있다는 것을 나타낸다.

예를 들어 `1 10 1`은 1, 2, 3... 9, 10이 있다는 의미이다.

## 풀이

어떤 한 정수를 제외한 모든 정수는 짝수 개 존재한다.

정수더미 안의 최댓값은 `2,147,483,647`으로 `2의 32제곱 - 1`이다. 

정수더미 안에서 어떤 정수 n을 골랐을 때, n이하의 정수의 개수를 구하면 홀수 또는 짝수개가 된다.

예를 들어 [문제 설명](https://www.acmicpc.net/problem/1637)에 소개된 케이스는

정수의 개수는 각각 아래와 같다.

```
1 2 3 4 5 6 7 8 9 10
2 2 2 3 2 2 2 2 2 2
```


그리고 어떤 정수 이하의 정수의 개수(예를 들면 n이 4면 1, 2, 3, 4의 개수)는 다음과 같다.

```
1 2 3 4  5  6  7  8  9 10
2 4 6 9 11 13 15 17 19 21
```

4부터 홀수, 3까지는 짝수가 됨을 알 수 있다.

따라서 이분탐색을 통해 문제를 해결할 수 있다.

범위의 중간값을 mid라고 하면, 정수더미 내에서 mid 이하의 정수의 개수를 모두 찾고

정수의 개수가 홀수라면 왼쪽, 정수의 개수가 짝수라면 오른쪽으로 범위를 좁히면 된다.

## 주의할 점

int 변수를 long long으로 형 변환 시 오류가 발생할 수 있으므로 주의할 것.