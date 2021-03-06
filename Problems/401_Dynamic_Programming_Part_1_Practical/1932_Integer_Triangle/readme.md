## 정수 삼각형

```
        7
      3   8
    8   1   0
  2   7   4   4
4   5   2   6   5
```

위 그림은 크기가 5인 정수 삼각형의 한 모습이다.

맨 위층 7부터 시작해서 아래에 있는 수 중 하나를 선택하여 아래층으로 내려올 때, 이제까지 선택된 수들의 합이 최대가 되는 경우의 합을 출력해야 한다.

아래층에 있는 수는 현재 층에서 선택된 수의 대각선 왼쪽 또는 대각선 오른쪽에 있는 것 중에서만 선택할 수 있다.

## 해설

위 삼각형 숫자들을 이차원 배열의 형태로 저장하면 다음과 같다.
```
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5
```

이차원 배열상의 **(i, j)인덱스의 정수를 마지막으로 선택한** 삼각형 내의 경로에서의 최대 합을 `dp[i][j]`라고 한다면

```
dp[i][j] = max(dp[i-1][j-1] , dp[i-1][j]) + data[i][j]
```

가 된다.