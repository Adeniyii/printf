#include "../main.h"

/**
 * @brief main func
 *
 * @return int
 */
int main(void)
{
	int count = _printf("%d How do the %s eat their 50%% %s these days%c\n", 221,"21", "bread", '?');
	printf("\ncount: %d\n", count);
	return (0);
}
