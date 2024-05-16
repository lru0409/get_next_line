# get_next_line
- 파일 디스크립터로부터 **읽은 한 줄을 반환하는 함수,** `get_next_line`을 프로그래밍하는 프로젝트다.
- 파일로부터 읽어온 데이터를 전역 변수 없이 보존하는 것이 프로젝트의 주 목표이고, 이를 위해 **정적 변수**를 활용한다.
- 구현된 함수 `get_next_line`은 다음과 같이 사용 가능하다.

``` c
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
  int fd;
  char *line;

  fd = open("./test.txt", O_RDONLY);

  // test.txt 파일로부터 (더 이상 읽을 내용이 없을 때까지) 한 줄씩 읽어오기
  while ((line = get_next_line(fd)) != NULL)
  {
    printf("%s", line); // 읽어온 한 줄 출력
    free(line);
  }
  close(fd);

  return (0);
}
```
##
학습 내용과 프로젝트 진행 과정에 대한 자세한 이야기는 [여기서](https://velog.io/@ronn/getnextline-%ED%8C%8C%EC%9D%BC-%EB%94%94%EC%8A%A4%ED%81%AC%EB%A6%BD%ED%84%B0%EB%A1%9C%EB%B6%80%ED%84%B0-%EC%9D%BD%EC%9D%80-%ED%95%9C-%EC%A4%84%EC%9D%84-%EB%B0%98%ED%99%98%ED%95%98%EB%8A%94-%ED%95%A8%EC%88%98%EB%A5%BC-%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%B0%8D%ED%95%98%EC%9E%90) 확인할 수 있다.
