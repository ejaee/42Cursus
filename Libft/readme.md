# Libft

> 42에서 필요한 라이브러리를 직접 구현하는 프로젝트

[라이브러리 만들기]()

## Contents

- [Libft](#libft)
  - [Contents](#contents)
  - [Part 1 - functions](#part-1---functions)
    - [ft_strchr](#ft_strchr)

## Part 1 - functions

---

### ft_strchr
> string chracter

**Prototype Declaration**  
```c
char    *ft_strchr(const char *s, int c);
```

**Description**  
문자열 `s`에서 문자 `c`가 처음 발견된 곳의 포인터를 반환한다.
`s` 가 정상적인 문자열이 아닐 경우, 문제가 생길 수 있음.


**Return**  
문자 `c`가 처음 발견된 곳의 포인터
문자열 `s`에 문자 `c`가 없으면 NULL 포인터


**Ussage**  
문자열 앞에서부터 특정 문자를 찾을 떄

<div align = "right">
    <b><a href = "#Contents">↥ back to top</a></b>
</div>

---