# Libft

> 42에서 필요한 라이브러리를 직접 구현하는 프로젝트입니다.

[라이브러리 만들기]()

man에 기반하여 각 함수들이 어떤 역할을 하는지 정리하였습니다.

## Contents

- [Libft](#libft)
  - [Contents](#contents)
  - [Part 1 - Libc functions](#part-1---libc-functions)
    - [ft_strchr](#ft_strchr)
    - [ft_strrchr](#ft_strrchr)
    - [ft_](#ft_)

## Part 1 - Libc functions

---

### ft_strchr
> string  character

**PROTOTYPE**
```c
char    *ft_strchr(const char *s, int c);
```

**DESCRIPTION**  
문자열 `s`에서 문자 `c`가 처음 발견된 곳의 포인터를 반환한다. c가 '\0'일 경우 종료 Null 문자를 찾는다.


**RETURN VALUE**  
문자 `c`가 처음 발견된 곳의 포인터. 문자열 `s`에 문자 `c`가 없으면 Null 포인터

**ISSUES**  
- 왜 문자열을 다루는 함수인데 int형 매개변수로 받나?
  - [int형으로 매개변수를 받는 이유]()

<div align = "right">
    <b><a href = "#Contents">↥ top</a></b>
</div>

---

### ft_strrchr
> string rear character

**PROTOTYPE**
```c
char    *ft_strrchr(const char *s, int c);
```

**DESCRIPTION**  
문자열 `s`에 문자 `c`가 마지막으로 발견된 곳의 포인터를 반환한다. c가 '\0'일 경우 종료 Null 문자를 찾는다.

**RETURN VALUE**  
문자 `c`가 마지막으로 발견된 곳의 포인터. 문자열 `s`에 문자 `c`가 없으면 Null 포인터

**ISSUES**  

<div align = "right">
    <b><a href = "#Contents">↥ top</a></b>
</div>

---

### ft_
> 

**PROTOTYPE**
```c

```

**DESCRIPTION**  


**RETURN VALUE**  


**ISSUES**  

<div align = "right">
    <b><a href = "#Contents">↥ top</a></b>
</div>

---