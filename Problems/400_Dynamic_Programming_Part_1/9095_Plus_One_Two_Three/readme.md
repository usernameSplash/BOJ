## 1, 2, 3 더하기

어떤 수를 1, 2, 3의 합으로 나타내는 가짓수를 모두 구하여야 한다.

예를 들어 4는 아래와 같이 가짓수가 7이다.

* 1+1+1+1
* 1+1+2
* 1+2+1
* 2+1+1
* 2+2
* 1+3
* 3+1

## 해답

어떻게든 n-1, n-2, n-3을 잘 만들고 그 수들에 1, 2, 3을 더하면 n이 된다.

따라서 n-1, n-2, n-3을 만드는 경우의 수를 더한 결과가 정답이 된다.

## 정답

`f(n) = f(n-1) + f(n-2) + f(n-3)`