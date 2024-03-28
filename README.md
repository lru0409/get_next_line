# get_next_line
- 파일 디스크립터로부터 **읽은 한 줄을 반환하는 함수,** `get_next_line`을 프로그래밍하는 프로젝트다.
- 파일로부터 읽어온 데이터를 전역 변수 없이 보존하는 것이 프로젝트의 주목표이고, 이를 위해 **정적 변수**를 활용해 보았다.
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
