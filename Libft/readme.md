# Libft

> 42에서 필요한 라이브러리를 직접 구현하는 프로젝트입니다.

[라이브러리 만들기]()

man에 기반하여 각 함수들이 어떤 역할을 하는지 정리하였습니다.

## Contents

- [Libft](#libft)
  - [Contents](#contents)
  - [Part 1 - Libc functions](#part-1---libc-functions)
    - [ft_isalpha](#ft_isalpha)
    - [ft_isdigit](#ft_isdigit)
    - [ft_isalnum](#ft_isalnum)
    - [ft_isascii](#ft_isascii)
    - [ft_isprint](#ft_isprint)
    - [ft_toupper](#ft_toupper)
    - [ft_tolower](#ft_tolower)
    - [ft_strchr](#ft_strchr)
    - [ft_strrchr](#ft_strrchr)
    - [ft_strlen](#ft_strlen)
    - [ft_strncmp](#ft_strncmp)
    - [ft_strlcpy](#ft_strlcpy)
    - [ft_strlcat](#ft_strlcat)
    - [ft_strnstr](#ft_strnstr)
    - [ft_atoi](#ft_atoi)
    - [ft_memset](#ft_memset)
    - [ft_bzero](#ft_bzero)
    - [ft_memchr](#ft_memchr)
    - [ft_memcpy](#ft_memcpy)
    - [ft_memcmp](#ft_memcmp)
    - [ft_memmove](#ft_memmove)
    - [ft_calloc](#ft_calloc)
    - [ft_strdup](#ft_strdup)
  - [Part 2 - Additional functions](#part-2---additional-functions)
    - [ft_substr](#ft_substr)
    - [ft_strjoin](#ft_strjoin)
    - [ft_strtrim](#ft_strtrim)
    - [ft_split](#ft_split)
    - [ft_itoa](#ft_itoa)
    - [ft_strmapi](#ft_strmapi)
    - [ft_striteri](#ft_striteri)
    - [ft_putchar_fd](#ft_putchar_fd)
    - [ft_putstr_fd](#ft_putstr_fd)
    - [ft_putendl_fd](#ft_putendl_fd)
    - [ft_putnbr_fd](#ft_putnbr_fd)
  - [Bouns](#bouns)
    - [ft_](#ft_)
  - [Question](#question)

## Part 1 - Libc functions

### ft_isalpha
> is alphabetic character 

**PROTOTYPE**
```c
int ft_isalpha(int c)
```

**DESCRIPTION**  
매개변수 `c`가 문자인지 확인합니다. (`A` == 65, `Z` == 90, `a` == 97, `z` == 122)

**RETURN VALUE**  
문자가 아닐 경우, 0을 반환합니다.  
문자가 맞다면, 0이 아닌 int형을 반환합니다.

**ISSUES**  
문자열을 다루는 함수인데 왜 int형 매개변수로 받나?

- [문자를 다루는 함수의 매개변수가 int형인 이유](#문자를-다루는-함수의-매개변수가-int형인-이유)

<div align = "right">
    <b><a href = "#Contents">↥ top</a></b>
</div>

---------------------------------------------------

### ft_isdigit
> is digit character 

**PROTOTYPE**
```c
int ft_isdigit(int c)
```

**DESCRIPTION**  
매개변수 `c`가 숫자인지 확인합니다. (`0` == 48, `9` == 57)

**RETURN VALUE**  
숫자가 아닐 경우, 0을 반환합니다.  
숫자가 맞다면, 0이 아닌 int형을 반환합니다.

**ISSUES**  
.
<div align = "right">
    <b><a href = "#Contents">↥ top</a></b>
</div>

---------------------------------------------------

### ft_isalnum
> is alphanumeric character 

**PROTOTYPE**
```c
int ft_isalnum(int c)
```

**DESCRIPTION**  
매개변수 `c`가 알파벳 또는 숫자인지 확인합니다.

**RETURN VALUE**  
아닐 경우, 0을 반환합니다.  
맞다면, 0이 아닌 int형을 반환합니다.

**ISSUES**  
.

<div align = "right">
    <b><a href = "#Contents">↥ top</a></b>
</div>

---------------------------------------------------

### ft_isascii
> is ASCII character 

**PROTOTYPE**
```c
int ft_isascii(int c)
```

**DESCRIPTION**  
매개변수 `c`가 ASCII 문자인지 확인합니다. 
확장 아스키가 아닌, 0부터 127까지 문자를 확인한다.

**RETURN VALUE**  
아닐 경우, 0을 반환합니다.  
맞다면, 0이 아닌 int형을 반환합니다.

**ISSUES**  
.

<div align = "right">
    <b><a href = "#Contents">↥ top</a></b>
</div>

---------------------------------------------------

### ft_isprint
> is printable character 

**PROTOTYPE**
```c
int ft_isprint(int c)
```

**DESCRIPTION**  
매개변수 `c`가 출력 가능한 문자인지 확인합니다. 
출력 가능한 문자는 `SP`(32)부터 `~`(126)까지 입니다.

**RETURN VALUE**  
아닐 경우, 0을 반환합니다.  
맞다면, 0이 아닌 int형을 반환합니다.

**ISSUES**  
`DEL`(127)은 delete control character로, 명령어에 해당합니다.

<div align = "right">
    <b><a href = "#Contents">↥ top</a></b>
</div>

---------------------------------------------------

### ft_toupper
> to upper case character 

**PROTOTYPE**
```c
int ft_toupper(int c)
```

**DESCRIPTION**  
매개변수 `c`가 소문자라면 대문자로 바꿔줍니다.  
대문자와 소문자간의 차이는 `32`입니다

**RETURN VALUE**  
소문자는 대문자로 바꿔 반환합니다.
소문자가 아니라면 그대로 반환합니다.

**ISSUES**  
.

<div align = "right">
    <b><a href = "#Contents">↥ top</a></b>
</div>

---------------------------------------------------

### ft_tolower
> to lower case character 

**PROTOTYPE**
```c
int ft_tolower(int c)
```

**DESCRIPTION**  
매개변수 `c`가 대문자라면 소문자로 바꿔줍니다.

**RETURN VALUE**  
대문자는 소문자로 바꿔 반환합니다.
대문자가 아니라면 그대로 반환합니다.

**ISSUES**  
.

<div align = "right">
    <b><a href = "#Contents">↥ top</a></b>
</div>

---------------------------------------------------
### ft_strchr
> string  character

**PROTOTYPE**
```c
char    *ft_strchr(const char *s, int c);
```

**DESCRIPTION**  
문자열 `s`에서 문자 `c`가 처음 발견된 곳의 포인터를 반환한다. c가 '\0'일 경우 종료 Null 문자를 찾습니다.

**RETURN VALUE**  
문자 `c`가 처음 발견된 곳의 포인터. 문자열 `s`에 문자 `c`가 없으면 Null 포인터를 반환합니다.

**ISSUES**  

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

### ft_strlen
> string length

**PROTOTYPE**
```c
size_t  ft_strlen(const char *s)
```

**DESCRIPTION**  
문자열 `s`의 길이를 구한다.

**RETURN VALUE**  
문자열 `s`의 길이

**ISSUES**  
`size_t`형을 반환하므로 count value도 동일한 자료형으로 선언한다.
-   [size_t형에 대하여](#size_t형에-대하여)

<div align = "right">
    <b><a href = "#Contents">↥ top</a></b>
</div>

---

### ft_strncmp
> string n compare

**PROTOTYPE**
```c
int ft_strncmp(const char *s1, const char *s2, size_t n)
```

**DESCRIPTION**  
문자열 s1과 s2를 n만큼 비교합니다.

```.vim
"The comparison is done using unsigned characters, so that ‘\200’ is greater than ‘\0’."
```
8진수 '\200', 즉 10진수 128의 수가 '\0'보다 커야 한다는 말은 char가 아닌 unsigned char형으로 비교해야 한다는 말로 해석하였습니다. (char형 비교 시 128은 오버플로우 발생)

**RETURN VALUE**  
s1가 크면 양수를, s2가 크면 음수를, 같다면 0을 반환합니다.

**ISSUES**  
`const char`형으로 매개변수를 받는 이유
>   ft_strncmp 함수는 비교의 목적으로 쓰이므로 매개변수로 받는 문자열 s1, s2 값이 조작되면 안된다. 따라서 해당 매개변수들의 자료형을 const char형으로 받는다. 

그렇다면 비교를 위해 `unsigned char`형으로 casting 할 때, const unsigned char형이 되어야 할 것 같아 상수화를 유지시켰다.

<div align = "right">
    <b><a href = "#Contents">↥ top</a></b>
</div>

---

### ft_strlcpy
> string length(?) copy

**PROTOTYPE**
```c
size_t  strlcpy(char * restrict dst, const char * restrict src, size_t dstsize)
```
> 해당 `restrict qualifier`는 `c99 standard` 키워드로, 해당 과제에서는 다루지 않습니다.

**DESCRIPTION**  
문자열 src에서 dst로 dstsize bytes 만큼 복사합니다. strncpy 함수에서는 n의 size가 src length보다 작을 경우 NULL이 보장되지 못한다는 단점이 있었습니다. 이를 보완한 함수로, 복사가 끝나면 문자열 끝에 NULL문자(\0)가 보장됩니다.
-   dstsize보다 src의 길이가 클 경우 -> src의 NULL이 복사
-   dstsize보다 src의 길이가 작을 경우 -> src-1만큼 복사 후 NULL 저장

**RETURN VALUE**  
복사를 시도하려고 하는 길이인, src의 길이를 반환합니다.

**ISSUES**  
src는 원본으로, 읽어들이기만 해야하므로(변경되면 안되므로) const인 반면에, dst는 src의 내용을 복사해야 하므로(변경되어야 하므로) const가 아니라고 이해했습니다.     
왜 src의 길이를 반환할까?
> strlcpy 함수는 문자열에 NULL을 보장하는데에 목적이 있습니다. 따라서 복사된 이후에 NULL의 유무가 중요하다고 생각했습니다. 이를 확인하기 위해서는 NULL이 위치한 index 값을 아는 것이 유의미하다고 생각했고 strlcpy의 반환값인 src 길이가 복사된 dst의 NULL 위치를 말해주게 됩니다. 즉, NULL을 확보하는 해당 함수의 의도에 맞게 NULL의 위치를 알려주기 위해 해당 반환 값이 의미를 가진다고 이해했습니다.


<div align = "right">
    <b><a href = "#Contents">↥ top</a></b>
</div>

---

### ft_strlcat
> string length(?) cat

**PROTOTYPE**
```c
size_t  strlcat(char * restrict dst, const char * restrict src, size_t dstsize);
```
> 해당 `restrict qualifier`는 `c99 standard` 키워드로, 해당 과제에서는 다루지 않습니다.

**DESCRIPTION**  
문자열 dst뒤에 src를 dstsize bytes 만큼만 이어붙여줍니다. strlcpy와 마찬가지로 NULL문자(\0)를 보장하는 함수입니다.  
매개변수 dst_size의 크기는 NULL 자리가 `포함된` 크기입니다.
>   dstsize = dest_len + src_len + `1`(NULL);


**RETURN VALUE**  
-   dest_len보다 dstsize가 클 경우
    -   dest_len + src_len을 dstsize - 1만큼 이어 붙인다
    -   그리고 dstsize 번째에 NULL을 저장(dstsize는 NULL의 index)
    -   NULL을 제외한 문자열 길이를 반환
    ```.c
    return (dest_len + src_len);
    ```

-   dst_len보다 dstsize가 작거나 같을 경우
    -   dstsize를 통해 dst의 NULL에 접근할 수 없다
    -   이럴 경우 strlcat은 NULL을 보장할 수 없으므로 실행되지 않는다
    -   src의 길이와 dstsize를 더한 값을 반환한다
    ```.c
    return (src_len + dstsize);
    ```

**ISSUES**  
리턴 값의 의미에 대해 생각해 보았습니다.
-   dest_len보다 dstsize가 클 경우 (cat 실행이 가능)
    > src를 모두 붙여넣지 못하더라도 src의 전체 길이를 더해서 리턴합니다. man에서는 이것을 잘라내기 감지(모두 붙였을 경우 dst_len + src_len에 반해, dstsize가 이보다 작을 경우 src가 잘리게 된다)를 간단히 하기위해 dst와 src의 초기 길이를 더한 값을 리턴한다고 명시되어 있습니다.

    ```.vim
    For strlcat() that means the initial length of dst plus the length of src. While this may seem somewhat confusing, it was done to make truncation detection simple.
    ```
-   dst_len보다 dstsize가 작거나 같을 경우 (cat 실행이 불가)
    > 리턴 값을 받아보면 cat이 안되었기 때문에 dstsize를 수정해야겠다고 생각할 것이고, 이때 src_len + dstsize의 리턴 값은 안전하게 src를 끝까지 cat하도록 하는 값이 됩니다. 즉, src_len + dstsize의 값이 dst_len보다 커진다면 cat이 정상 실행되므로 해당 리턴 값은 의미를 가집니다.

[참조 페이지](https://gawoori.net/strlcat-3-%EB%A6%AC%EB%88%85%EC%8A%A4-%EB%A7%A4%EB%89%B4%EC%96%BC-%ED%8E%98%EC%9D%B4%EC%A7%80/)

<div align = "right">
    <b><a href = "#Contents">↥ top</a></b>
</div>

---

### ft_strnstr
> string n string

**PROTOTYPE**
```c
char    *strnstr(const char *haystack, const char *needle, size_t len)
```

**DESCRIPTION**  
문자열 haystack의 전체 길이 중 len길이 내에서, needle을 찾아줍니다.

**RETURN VALUE**  
문자열 haystack에서 찾은 needle의 시작 주소값을 반환합니다.

**ISSUES**  
len만큼 찾기 때문에 needle을 찾는 과정에서도 len길이를 확인하면서 찾아야 합니다.

<div align = "right">
    <b><a href = "#Contents">↥ top</a></b>
</div>

---

### ft_atoi
> ascii to integer

**PROTOTYPE**
```c
int atoi(const char *str)
```

**DESCRIPTION**  
문자열 str을 int로 변환합니다.

**RETURN VALUE**  
변환된 정수를 반환합니다

**ISSUES**  
문자열 내용이 바뀌면 안되므로 const로 매개변수를 받으며, '++'나 '--'가 sign으로 올 경우 정상적인 int로 변환하지 않고, 0을 반환합니다.

<div align = "right">
    <b><a href = "#Contents">↥ top</a></b>
</div>

---

### ft_memset
> memory set

**PROTOTYPE**
```c
void    *memset(void *b, int c, size_t len);
```

**DESCRIPTION**  
메모리 b를 len 길이만큼 c로 초기화 합니다. bzero 대신, memset으로 대체된 함수로 0으로 초기화 하는데 쓰여집니다.

**RETURN VALUE**  
초기화 된 메모리 b의 주소를 반환합니다.

**ISSUES**  
[void* 형에 대하여](#void*-형에-대하여)     
int형 배열 주소를 전달하고 1으로 바꾸고 싶을 때 이상한 결과가 나오는 이유는?
```.vim
1 대신, 16843009 가 나온다.
```
memset 함수는 1바이트 단위로 값을 초기화 합니다. 컴퓨터는 값을 1바이트 단위로 저장하기 때문에 memset 함수도 1바이트 단위로 읽습니다. 두번째 매개변수에 1 값을 전달하면 1바이트 단위로 1을 만들기 때문에 0000 0001이 네개 이어진 0000 0001 0000 0001 0000 0001 0000 0001 가 됩니다. 이를 십진수로 계산하면 16843009가 나옵니다. 따라서 memset 함수는 동적할당을 받을 경우 메모리의 값에 쓰레기가 들어있기 때문에 memset 함수를 사용해 0으로 초기화할 때 많이 쓰는 것 같습니다.

<div align = "right">
    <b><a href = "#Contents">↥ top</a></b>
</div>

---

### ft_bzero
> byte zero

**PROTOTYPE**
```c
void    ft_bzero(void *s, size_t n);
```

**DESCRIPTION**  
메모리 s의 n byte까지를 0으로 초기화 합니다. memset으로 대체된 함수로 현재는 사용되지 않습니다.

**RETURN VALUE**  
.

**ISSUES**  
memset과는 다르게 bzero는 왜 void형 인가?       

:question:

명확한 느낌이 안드는데 bzeor가 사라진 이유를 확인한다면 더 이해할 수 있지 않을까...

<div align = "right">
    <b><a href = "#Contents">↥ top</a></b>
</div>

---

### ft_memchr
> memory char

**PROTOTYPE**
```c
void *memchr(const void *s, int c, size_t n)
```

**DESCRIPTION**  
메모리 영역 s에서 n bytes 까지 확인하여 문자 c가 처음 발견된 곳의 포인터를 반환합니다.

**RETURN VALUE**  
처음으로 값 c가 나타나는 문자열의 주소를 반환합니다.

**ISSUES**  
.

<div align = "right">
    <b><a href = "#Contents">↥ top</a></b>
</div>

---

### ft_memcpy
> memory copy

**PROTOTYPE**
```c
void    *ft_memcpy(void *dst, const void *src, size_t n);
```

**DESCRIPTION**  
메모리 영역 src의 n bytes만큼을 dst로 복사합니다. 이때 src와 dst의 메모리 영역이 겹쳐서는 안됩니다. 
```.vim
If dst and src overlap, behavior is undefined.
```
메모리 영역이 겹친디면, memcpy 대신 memmove를 사용 합니다.

**RETURN VALUE**  
복사된 메모리 dst 주소를 반환합니다.

**ISSUES**  
strcpy() vs memcpy()
> 가장 큰 특징은 memcpy는 형에 관계없이 임의의 영역을 지정한 byte 수만큼 복사하는 기능을 수행합니다. 'strcpy()'는 매번 '문자 하나씩 읽어서' 그것이 널문자인지 아닌지 확인한 뒤 하나씩 복사해야 하고, 'memcpy()'는 '메모리 관점의 복사'라 꽤 큰 블럭 단위로 복사가 가능하다고 합니다.

strcpy나 memcpy나 속도상 엄청나게 큰 차이는 없지만, strcpy로 전달받은 문자열이 끝에 NULL이 없는 char 배열인 경우 문제가 되기에 안정성 측면에서 memcpy를 선호하는 의견이 많았습니다.     
[출처 사이트](http://blog.naver.com/kihoyaa/10000790352)

[memcpy() vs memmove()](#memcpy()-vs-memmove())

<div align = "right">
    <b><a href = "#Contents">↥ top</a></b>
</div>

---

### ft_memccpy.c
> memory copy until c found

**PROTOTYPE**
```c
void    *ft_memccpy(void *dst, 
                    const void *src, 
                    int c,
                    size_t n);
```

**DESCRIPTION**  
메모리 src를 n bytes만큼 dst로 복사합니다. 이때 src에서 c가 나타날 때까지만 복사합니다(첫번째 c까지 복사합니다). src와 dst의 메모리 영역이 겹쳐서는 안됩니다.

먼저 memchr을 통해서 c를 찾습니다. 다음 c가 위치한 인덱스 + 1만큼 memcpy을 통해 복사하는 방식으로 구현했습니다.

**RETURN VALUE**  
src안에서 c를 찾는다면 그 다음 포인터를 리턴하고 그게 아니라면 NULL을 리턴합니다.

**ISSUES**  
`memcpy` vs `memmcpy`   
`strcpy` vs `memcpy`    
`memcpy` vs `memmove`      
[const에 대하여](#const에-대하여) 
<div align = "right">
    <b><a href = "#Contents">↥ top</a></b>
</div>

---

### ft_memcmp
> memory compare

**PROTOTYPE**
```c
int ft_memcmp(const void *s1, const void *s2, size_t n);
```

**DESCRIPTION**  
메모리 s1과 s2를 n byte까지 비교합니다.

**RETURN VALUE**  
strcmp와 동일합니다.

**ISSUES**  
strcmp() vs memcmp()
-   strcmp에서 "strcmp\0abc" , "strcmp\0123" 는 NULL을 만나면 종료하기 때문에 0을 반환합니다. 그러나 memcmp 로 위의 10 바이트를 검사하면 틀리다고 인식하여 int 값이 나옵니다. `문자열간의 문자상수 int형을 계산`하는 것과 `문자열간의 메모리영역을 비교`한다는 차이가 있습니다.

<div align = "right">
    <b><a href = "#Contents">↥ top</a></b>
</div>

---

### ft_memmove
> memory move

**PROTOTYPE**
```c
void    *ft_memmove(void *dst, const void *src, size_t len);
```

**DESCRIPTION**  
memcpy와 쓰임을 동일하나, src와 dst의 메모리 영역이 겹칠 때 사용합니다. 해당 함수를 사용하지 않고 복사하기 위해서는 반복문을 사용해야 한다는 소요를 줄일 수 있습니다.

src의 주소가 dst보다 클 경우 *dst++ = *src++를 통해 복사하고, 작을 경우 끝에서 거꾸로 복사를 합니다.
> index 0, 1, 2, 3을 1, 2, 3, 4에 복사한다면 0이 1에 저장됨으로써 기존에 있던 인덱스 1의 값을 인덱스 2에 저장할 수 없는 경우가 작을 경우(src < dst)에 해당합니다. 0, 1, 2, 3 인덱스 값을 1, 2, 3, 4에 저장하는 상황이 man에서 언급하는 overlap에 해당됩니다. src의 주소가 dst 보다 작을 경우 거꾸로 저장하므로써 overlap의 문제를 해결할 수 있습니다.



**RETURN VALUE**  
복사된 메모리 dst

**ISSUES**  
memcpy() vs memmove()
> 두 함수 모두 특정 메모리 주소에서 원하는 크기 만큼을 다른 곳으로 복사합니다. 다른 점은 이름 뿐으로, 매개변수도 동일합니다. 메뉴얼에서 메모리 영역이 곂칠 때(overlap) memmove를 사용한다고 명시되어 있습니다.
```.vim
The two strings may overlap;
```

<div align = "right">
    <b><a href = "#Contents">↥ top</a></b>
</div>

---

### ft_calloc
> contiguous allocation

**PROTOTYPE**
```c
void    *ft_calloc(size_t count, size_t size);
```

**DESCRIPTION**  
메모리공간(count x size)을 0으로 초기화하여 할당해줍니다.

**RETURN VALUE**  
할당 성공시 할당된 공간의 포인터를, 할당 실패시 NULL 포인터를 반환합니다.

**ISSUES**  
.

<div align = "right">
    <b><a href = "#Contents">↥ top</a></b>
</div>

---

### ft_strdup
> string duplicate

**PROTOTYPE**
```c
char    *strdup(const char *s1);
```

**DESCRIPTION**  
동적할당 후 문자열 s1을 복제합니다.

**RETURN VALUE**  
복제한 문자열의 포인터를 반환합니다.

**ISSUES**  
.

<div align = "right">
    <b><a href = "#Contents">↥ top</a></b>
</div>

---

## Part 2 - Additional functions

### ft_substr
> subpart of string

**PROTOTYPE**
```c
char    *ft_substr(char const *s, unsigned int start, size_t len);
```

**DESCRIPTION**  
문자열 s에서 두번째 매개변수 start index부터 len개 만큼의 부분 문자열을 새로 만듭니다.

**RETURN VALUE**  
만들어진 부분 문자열의 포인터를 반환합니다.

**ISSUES**  
.

<div align = "right">
    <b><a href = "#Contents">↥ top</a></b>
</div>

---

### ft_strjoin
> string join

**PROTOTYPE**
```c
char    *ft_strjoin(char const *s1, char const *s2);
```

**DESCRIPTION**  
문자열 s1에 문자열 s2를 이어 붙여서 새로운 문자열을 만듭니다.

**RETURN VALUE**  
s1에 s2가 이어 붙여진 새로운 문자열 포인터를 반환합니다

**ISSUES**  
.

<div align = "right">
    <b><a href = "#Contents">↥ top</a></b>
</div>

---

### ft_strtrim
> string trim

**PROTOTYPE**
```c
char    *ft_strtrim(char const *s1, char const *set);
```

**DESCRIPTION**  
문자열 s1의 맨 앞, 뒤로 set에 들어 있는 문자들을 제거하고 새로운 메모리를 할당해 새 문자열을 만들어줍니다.  
`strchr()` 함수를 통해 set을 확인할 수 있습니다.

**RETURN VALUE**  
문자열 s1 맨 앞 뒤로 set에 들어 있는 문자들이 제거된 새로운 문자열을 반환합니다.

예를들어, ft_strtrim("123abc123def312", "123") 이라면   
> return (abc123def);   // 가운데 123은 제거하지 않습니다.

**ISSUES**  
.

<div align = "right">
    <b><a href = "#Contents">↥ top</a></b>
</div>

---

### ft_split
> string split

**PROTOTYPE**
```c
char    **ft_split(char const *s, char c);
```

**DESCRIPTION**  
문자열 s1을 구분자 c 기준으로 나누어 2차원 배열로 만듭니다.

2차원 배열에 단어를 넣을 때마다 ft_substr()를 활용할 수 있습니다. ft_substr(s, (i + 1 - len[n]), len[n])을 통해 다음 넣을 단어의 시작 주소값에 접근할 수 있습니다.

**RETURN VALUE**  
나누어진 2차원 배열을 반환합니다.

**ISSUES**  
기존에 만들었던 split과 다르게 free를 구현합니다.

<div align = "right">
    <b><a href = "#Contents">↥ top</a></b>
</div>

---

### ft_itoa
> integer to ascii character

**PROTOTYPE**
```c
char    *ft_itoa(int n);
```

**DESCRIPTION**  
정수 n을 문자열로 반환해줍니다.

**RETURN VALUE**  
정수 n에서 ascii character로 변환된 문자열을 반환합니다.

**ISSUES**  
.

<div align = "right">
    <b><a href = "#Contents">↥ top</a></b>
</div>

---

### ft_strmapi
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

### ft_striteri
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

### ft_putchar_fd
> put character fd

**PROTOTYPE**
```c
void    ft_putchar_fd(char c, int fd);
```

**DESCRIPTION**  
fd == 1 이라면 문자 c를 출력해줍니다.

**RETURN VALUE**  
.

**ISSUES**  
.

<div align = "right">
    <b><a href = "#Contents">↥ top</a></b>
</div>

---

### ft_putstr_fd
> put string fd

**PROTOTYPE**
```c
void ft_putstr_fd(char *s, int fd);
```

**DESCRIPTION**  
fd == 1 이라면 문자열 s를 출력해줍니다.

**RETURN VALUE**  
.

**ISSUES**  
널가드 문제
-   할당되지 않는 문자열주소가 전달된다면 널가드 체크를 해야한다?

-   개인 의견
>   동적할당이 되는 시점에서 널가드를 잡았을 테니 할당되지 않은채로 전달될 일은 없다고 판단되며 널가드를 해당 함수에 넣을 경우 필요하지 않는 널가드를 이중으로 체크한다는 느낌이 듭니다. 해당 널가드를 써야하는 경우는 매개변수에 문자열 주소를 받는 모든 함수가 시작되기 전에 일괄적인 널가드 체크가 있었어야 한다고 생각합니다.

-   결론...
>   널 포인터를 가리킬 경우 ft_strlen()함수가 터진다는 것을 알게 되었습니다. 사용자가 널 포인터를 가리키게 하는 것 자체가 문제가 있다고 생각하지만 그럴 가능성도 알았으니까 이를 방어하기 위해서는 1. 널가드를 통해 return(NULL) 종료 합니다. 또한 strlen()함수를 터트리는 방법을 쓰는 분들이 계신다 하여... 해당 함수를 쓰지 않도록 했습니다. putchar_fd() 호출해 반복문을 돌려 방어했습니다.

<div align = "right">
    <b><a href = "#Contents">↥ top</a></b>
</div>

---

### ft_putendl_fd
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

### ft_putnbr_fd
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

## Bouns

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

## Question


-   size_t형에 대하여

size_t형은 부호 없는 정수형(`unsigned integer`)으로, `sizeof`, `offsetof`의 반환값이다. 일반적으로, 문자열이나 메모리의 사이즈를 나타낼 때 사용합니다.

```.c
typedef unsigned int size_t;
```

size_t는 `32비트` 운영체제에서는 `부호없는 32비트 정수`, `64비트`에서는 `부호없는 64비트 정수`입니다. 그러나 unsigned int 또는 intsms 64비트 운영체제라고 꼭 64비트 정수가 아닌, 여전히 32비트일 수 있습니다. 이것이 `size_t형과 unsigned int형의 차이`입니다.

size_t가 아닌, unsigned int형에 캐스팅 없이, 문자열 길이를 대입하면 다음과 같은 경고가 발생합니다.

```.c
warning C4267: 'initializing' : conversion from 'size_t' to 'unsigned int', possible loss of data
```

---

- 라이브러리 코드의 읽히는 부분이 const인 이유

메모리 관리의 최소 단위는 1byte입니다. 

포인터는 다소 많은 자원이 필요하므로, 단순 읽기 상황에서는 상수화해서 사용할 때 연산 속도와 자원 효율성에 도움을 줍니다.

---

- 문자를 다루는 함수의 매개변수가 int형인 이유

상당 수의 코드에서 int로 인자를 받아 1byte씩 읽는 경우가 많은데, 내가 찾은 이유들을 열거하자면, 먼저 char형이 없었던 적에 사용됐던 코드라는 이유가 있습니다.(실제로 char형으로 라이브러리를 지원할 경우 올드 코드들은 동작이 멈추거나 의도와는 다른 행동을 합니다) char형이 만들어진 후에도 올드 코드를 모두 수정하는데에 많은 비용을 발생하기 때문에 기존의 함수들을 굳이 수정하지 않는다고 합니다.

메모리 엑세스 단위가 int형으로, 실제로 사용자가 char형을 사용한다 해도 int로 메모리를 받습니다.(char형이 int형 안에 속해 있습니다.)

---

- void* 형에 대하여

보통 동적메모리할당을 해주는 함수(malloc, realloc, calloc ...)들의 자료형은 void* 형을 사용합니다. void *형도 포인터이기 때문에 주소값을 담습니다. void 포인터형은 casting을 통해서 그 어떤 포인터든 될 수 있습니다.
```.vim
int a = 10;
void *p = &a;
```
void *형인 p에 a의 주소를 저장했으므로 p가 int *형이 되는것은 아닙니다. p는 메모리주소 값을 가질 수 있기에 어떠한 변수의 주소를 가질 수 있을 뿐입니다. 주소를 통해 값에 접근하려면 컴퓨터에게 얼마만큼 읽어야하는지(자료형이 무엇인지) 알려줘야하기 때문에 casting을 해야 값에 접근할 수 있습니다.

memset 함수의 경우 특정 값으로 초기화된 메모리의 주소값을 반환하므로 void* 형을 사용하는 것 입니다.

---------------------------------

- const에 대하여

const의 사용은 다음과 같은 경우의 수가 있다.

1. const 키워드가 자료형 앞에 있을 때

포인터가 가리키는 변수의 값(data)을 변경 X

포인터 변수 자신의 값(주소) 변경 O

```.c
char str1[20] = "Hello World";
char str2[20] = "Good Bye";
const char*p1 = str1;
p1[0] = 'A';           -> 컴파일에러
p1 = str2; 
```

하지만 위치에 따라 의미가 달라지므로 주의하자!

2. const 키워드가 포인터 변수명 앞에 있을 때

포인터 변수 자신의 값(주소)를 변경 X 

포인터가 가리키는 변수의 값 변경 O

```.c
char str1[20] = "Hello World";
char str2[20] = "Good Bye";
char *const p2 = str1;
p2[0] = 'A'; 
p2 = str2;         -> 컴파일 에러
```

3. const 키워드가 1, 2 둘 다 있을 때

포인터가 가리키는 변수의 값 변경 X

포인터 변수 자신의 값(주소) 변경 X

```.c
char str1[20] = "Hello World";
char str2[20] = "Good Bye";
const char * const p3 = str1;
p3[0] = 'A';         -> 컴파일 에러
p3 = str2;           -> 컴파일 에러
```

[출처 사이트](https://blog.naver.com/oddish0513/222632469583)