#include "../main.h"

/**
 * @brief main func
 *
 * @return int
 */
int main(void)
{
	int count = _printf(
	    "Lorem ipsum dolor sit amet, consectetur adipiscing elit\
. Quisque id ante dictum, tincidunt lectus nec, tincidunt \
nibh. Phasellus vestibulum sem nulla, ac pulvinar nunc \
commodo laoreet. Vivamus%% placerat eros vel massa aliquet \
porttitor. Morbi non augue felis. Pellentesque pharetra \
finibus ipsum, a suscipit metus lacinia non. Orci varius \
natoque penatibus et magnis dis parturient montes, nascetur \
ridiculus mus. Cras vitae magna sit amet enim sodales pretium \
ut nec arcu. Aenean massa%% tellus, accumsan ac tellus nec, \
pretium condimentum ante. Sed aliquet lorem vitae justo \
varius porttitor. Pellentesque egestas congue ligula \
imperdiet laoreet. Morbi vulputate diam %s sed facilisis \
lobortis. Praesent vel bibendum urna. Nunc euismod tempor \
molestie. %d ligula odio, accumsan sit amet egestas eget, \
congue id lectus. Orci varius natoque penatibus et %s dis \
parturient montes, nascetur%% ridiculus mus. Fusce a diam est. \
Curabitur et rhoncus velit, ut porta sapien. Quisque dapibus \
lobortis turpis sed pellentesque. Proin %s vehicula enim, \
ut fermentum leo. Nunc quis enim vel urna faucibus donec%c \n",
	    "rain", 221, "21", "bread", '?');
	printf("\ncount: %d\n", count);
	return (0);
}
