## 토마토

철수의 토마토 농장에서는 토마토를 보관하는 큰 창고를 가지고 있다. 토마토는 격자 모양 상자의 칸에 하나씩 넣어서 창고에 보관한다. 

창고에 보관되는 토마토들 중에는 잘 익은 것도 있지만, 아직 익지 않은 토마토들도 있을 수 있다. 보관 후 하루가 지나면, 익은 토마토들의 인접한 곳에 있는 익지 않은 토마토들은 익은 토마토의 영향을 받아 익게 된다. 하나의 토마토의 인접한 곳은 왼쪽, 오른쪽, 앞, 뒤 네 방향에 있는 토마토를 의미한다. 대각선 방향에 있는 토마토들에게는 영향을 주지 못하며, 토마토가 혼자 저절로 익는 경우는 없다고 가정한다. 철수는 창고에 보관된 토마토들이 며칠이 지나면 다 익게 되는지, 그 최소 일수를 알고 싶어 한다.

토마토를 창고에 보관하는 격자모양의 상자들의 크기와 익은 토마토들과 익지 않은 토마토들의 정보가 주어졌을 때, 며칠이 지나면 토마토들이 모두 익는지, 그 최소 일수를 구하는 프로그램을 작성하라. 단, 상자의 일부 칸에는 토마토가 들어있지 않을 수도 있다.

## 풀이

[2178 - 미로](https://github.com/usernameSplash/BOJ/tree/main/Problems/600_Graph/2178_Maze)와 유사하게 해결할 수 있는 문제이다.

익은 토마토들의 좌표를 기점으로 모두 BFS(DFS는 안됩니다.)를 돌린 후 전체 map에서 0이 존재하면 실패, 존재하지 않으면 성공이다.

## 더 나은 풀이

**사실 위 풀이로 풀면 시간 초과가 나온다.**

익은 토마토들의 좌표를 기점으로 BFS를 돌리는 것이 아니라,

BFS를 수행하기 전, 큐에 익은 토마토들의 좌표를 push 한 채로 BFS를 한 번만 수행하면 된다.