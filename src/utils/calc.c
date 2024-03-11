#include <stdio.h>

long long
exponent(int a, int b)
{
      if (b == 0)
      {
            return (1);
      }
      long long c = a;
      for (int i = 1; i < b; i++)
      {
            c = c*a;
      }
      return (c);
}
/* Calculator for Andesaurux operating system */
int 
main(void)
{
  long long a, b = 0;
  short int c = 0;
  puts("Enter two numbers:\t");
  scanf("%lld %lld", &a, &b);
  puts("Enter operation symbol:\t");
  getchar();
  c = getchar();
  switch(c)
    {
      case '+':
	      printf("%lld+%lld=%lld", a, b, a+b);
	      break;
      case '-':
	      printf("%lld-%lld=%lld", a, b, a-b);
	      break;
      case '*':
	      printf("%lld*%lld=%lld", a, b, a*b);
	      break;
      case '/':
	      printf("%lld/%lld=%lld", a, b, a/b);
	      break;
      case '^':
            printf("%lld^%lld=%lld", a, b, exponent(a, b));
            break;
      default:
	      printf("%c - invalid symbol\n", c);
	      break;
    }
  putchar('\n');
  return (0);
}
