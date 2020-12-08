## 이친수
문제 설명 : https://www.acmicpc.net/problem/2193

## 해답

`dp[i]` = 길이가 i인 이친수의 경우의 수

`dp[1] = 1` (기저조건)

* 0은 앞의 숫자가 무엇이든 상관 없이 올 수 있다.
* 1은 앞의 숫자가 0이어야만 올 수 있다. -> 즉, **[01]** 을 하나로 묶어서 세트로 볼 수 있다.

이러면 이제 2*N 타일링 문제와 유사하게 풀 수 있다.

## 정답
`dp[i] = dp[i-2] + dp[i-1]`

## 주의
이 문제도 마찬가지로 피보나치 수열이다. 그러나 문제에선 정답을 나머지 연산하여 줄여서 출력하지 않을 것을 요구한다.

N의 최댓값은 90이므로, 피보나치 수열의 90번째 항의 값은 2880067194370816120이다.

따라서 자료형을 `long long`으로 해 주어야 한다.