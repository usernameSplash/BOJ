## 조합 0의 개수

조합`nCm`의 끝자리 0의 개수를 출력해야 하는 문제이다.

예를 들어 `25C12` = 52003**00** 이므로 2가 정답이다.

## 풀이

조합 `nCr` = `n! / (r! * (n-r)!)`

조합 `nCr` 내의 5의 개수 = `fives` = (`n!` 내의서의 5의 개수) - (`r!` 내의서의 5의 개수 - (`(n-r)!` 내의서의 5의 개수)

단, 팩토리얼 0의 개수 문제에서는 항상 `n!`를 소인수분해하였을 때 2가 5보다 많음이 보장되었지만, 조합은 **그렇지 않다**. 2의 개수도 구해야 한다.

조합 `nCr` 내의 2의 개수 = `twos` = (`n!` 내의서의 2의 개수) - (`r!` 내의서의 2의 개수 - (`(n-r)!` 내의서의 2의 개수)

## 해답

`min(fives, twos)`가 해답이 된다.