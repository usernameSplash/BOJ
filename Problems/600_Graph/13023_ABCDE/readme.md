## ABCDE

어떤 한 정점 A로부터 시작해서 서로 다른 정점 B, C, D, E를 연속으로 순회할 수 있는지 판별해야 한다.

## 반성

### 오답이 나온 경우
```C++
vector<pair<int, int>> edges;
vector<vector<int>> g; //인접 리스트
bool w[2000][2000]; //인접 행렬
```

변수 초기화를 올바르게 하지 않으면 오답이 나온다.

### 정답이 나온 경우
```C++
vector<pair<int, int>> edges;
vector<vector<int>> g(2000); //인접 리스트
bool w[2000][2000] = {0}; //인접 행렬
```

변수 기본값 초기화를 생활화하자.