#ifndef NES_CPU_H
#define NES_CPU_H

#include <stdint.h>

#define MASK_CARRY              0x01
#define MASK_ZERO               0x02
#define MASK_INTERRUPT_DISABLE  0x04
#define MASK_DECIMAL            0x08

#define MASK_BFLAG              0x10
#define MASK_UNUSED             0x20
#define MASK_OVERFLOW           0x40
#define MASK_NEGATIVE           0x80

typedef struct {
	uint8_t A;      /* accumulator */
	uint8_t X, Y;   /* index */
	uint8_t SP;     /* stack pointer */
	uint8_t P;      /* flag register */

	uint16_t PC;    /* program counter */
} mos6502;

uint8_t	get_flag(mos6502 *, uint8_t);
uint8_t	read_from_bus(uint16_t);
void	cpu_init(void);
void	cpu_reset(mos6502 *);
void	set_flag(mos6502 *, uint8_t, uint8_t);
void	write_to_bus(uint16_t, uint8_t);

#endif /* NES_CPU_H */
