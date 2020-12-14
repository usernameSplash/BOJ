## 퇴사(2)

[퇴사(1)](https://github.com/usernameSplash/BOJ/tree/main/Problems/530_Recursive_Call/14501_Quit_Job) 문제는 n의 제한이 작아 Brute Force로 해결이 가능했지만 이번 문제는 n이 150만이라서 DP로 해야 한다.

## 풀이

* d[i] : i번째 상담이 걸리는 일수
* p[i] : i번째 상담의 보수
* dp[i] : i번째 날, 상담을 맡기 직전의 보수
i번째 상담을 맡았을 때의 이득인 dp[i] + p[i]를 dp[i + d[i]]에 저장한다. 이미 저장된 값이 있을 경우 max함수를 이용해 계산한다.