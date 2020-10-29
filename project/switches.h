#ifndef switches_included
#define switches_included

#define SW1 1		/* switch1 is p2.0 */
#define SW2 2           /* switch2 is p2.1 */
#define SW3 4           /* switch3 is p2.2 */
#define SW4 8           /* switch4 is p2.3 */

void switch_init();
void switch_interrupt_handler();

extern char switch_state_down, switch_state_changed; /* effectively boolean */

#endif // included
