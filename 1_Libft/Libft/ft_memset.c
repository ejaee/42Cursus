/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejachoi <ejachoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:36:54 by ejachoi           #+#    #+#             */
/*   Updated: 2022/07/09 19:03:04 by ejachoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	while (len--)
		*((unsigned char *)b + len) = (unsigned char)c;
	return (b);
}
/*
#include <string.h>
#include <stdio.h>
int main(void)
{
	int arr[10] = {0,};
	int i;

	printf("==설정 전 ==\n");
	for(i=0;i<10;i++)
		printf("%d",arr[i]);//쓰레기 값 출력
	printf("\n");
	memset(arr,1, 3);//arr의 메모리를 0으로 설정   
	//ft_memset(arr,1,sizeof(arr));//arr의 메모리를 0으로 설정   
	printf("==설정 후 ==\n");
	for(i=0;i<10;i++)
		printf("%d",arr[i]);
	printf("\n");
	return 0;
}
*/
