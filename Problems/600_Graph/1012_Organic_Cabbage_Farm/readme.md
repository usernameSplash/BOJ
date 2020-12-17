## 유기농 배추

(0,0)부터 (x,y)까지의 좌표평면 모양의 배추밭이 존재한다.

각 좌표의 값이 1인 경우 해당 땅에 배추가 존재한다.

해충 방지를 위해 지렁이를 이용하는데, 이 지렁이는 인접한 배추들이 있으면 해당 배추들을 모두 보호할 수 있다.

배추밭이 주어졌을 때 필요한 지렁이의 최소 마릿수를 구해야 한다.

## 풀이

1. (0,0)부터 (x,y)까지 모든 칸에 대해 BFS를 진행한다.
2. (i,j)가 1인 경우 상하좌우를 살핀다.
3. 상하좌우 중 방문하지 않았으며 값이 1인 칸을 다음 방문지로 삼는다.
4. BFS가 종료되었으면 다시 1로 돌아간다.


## 여담
진짜 별거아닌 문제인데 입력받을 때 x, y 위치 헷갈려서 헤맸다.