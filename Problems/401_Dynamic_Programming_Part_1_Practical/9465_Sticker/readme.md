## 동물원

문제 설명 : https://www.acmicpc.net/problem/9465

## 해답

1. i번째 줄에 스티커를 안 뗄 때. 
    * (i-1)번째 줄에 위쪽 스티커를 뗸 경우 +
    * (i-1)번째 줄에 아래쪽 스티커를 뗸 경우 +
    * (i-1)번째 줄에 스티커를 안 뗀 경우
2. i번째 줄에 위쪽 스티커를 뗄 때. 
    * (i-1)번째 줄에 아래쪽 스티커를 뗀 경우 +
    * (i-1)번째 줄에 스티커를 안 뗸 경우
3. i번째 줄에 아래쪽 스티커를 뗄 때. 
    * (i-1)번째 줄에 위쪽 스티커를 뗀 경우 +
    * (i-1)번째 줄에 스티커를 안 뗀 경우


## 정답

점화식은 다음과 같다.

```
dp[i][0] = max(dp[i-1][0], dp[i-1][1], dp[i-1][2])
dp[i][1] = max(dp[i-1][0] + dp[i-1][2]) + data[i][1]
dp[i][2] = max(dp[i-1][0] + dp[i-1][1]) + data[i][2]
```


## 반성

`int dp[3][100001]` dp배열 이렇게 선언해야 하는거

`int dp[100001][3]` 이렇게 했다가 한 시간 날렸다.. 실화냐...

앞으론 문제 형태와 상관없이, 되도록 dp배열은 가로보단 세로로 확장되도록 통일해야겠다.