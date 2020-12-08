## 가장 큰 증가하는 부분 수열

Greatest Increasing Subsequence = GIS

증가하는 부분수열 중, 각 항의 합이 가장 큰 부분 수열의 합을 출력해야 한다.

문제 설명 : https://www.acmicpc.net/problem/11055


## 해설

LIS에서는 dp 테이블에 +1씩 해주었지만, 이번에는 `data[i]`을 더해주면 된다.

당연히 기저조건인 `dp[0]`도 `data[0]`으로 초기화해주어야 한다.