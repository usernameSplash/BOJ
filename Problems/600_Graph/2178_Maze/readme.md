## 미로 탐색
N×M크기의 배열로 표현되는 미로가 있다.
```
101111
101010
101011
111011
```

미로에서 1은 이동할 수 있는 칸을 나타내고, 0은 이동할 수 없는 칸을 나타낸다. 이러한 미로가 주어졌을 때, (1, 1)에서 출발하여 (N, M)의 위치로 이동할 때 지나야 하는 최소의 칸 수를 구하는 프로그램을 작성하시오. 한 칸에서 다른 칸으로 이동할 때, 서로 인접한 칸으로만 이동할 수 있다.

위의 예에서는 15칸을 지나야 (N, M)의 위치로 이동할 수 있다. 칸을 셀 때에는 시작 위치와 도착 위치도 포함한다.

## 풀이

항상 도착 위치로 이동할 수 있는 경우만 입력으로 주어진다.

즉, (0,0)과 (n,m)은 그래프 상의 같은 ['연결 요소'](https://github.com/usernameSplash/BOJ/tree/main/Problems/600_Graph/11724_Connected_Component)에 속한다고 볼 수 있다.

0,0에서 **BFS**(반드시 BFS여야 합니다.)를 수행하면 인접한 칸에 도달한다.

항상 인접한 칸들을 먼저 순회하는 BFS의 특성을 통해 (n, m)을 방문할 때 까지 BFS를 수행하고 횟수를 출력하면 된다.

