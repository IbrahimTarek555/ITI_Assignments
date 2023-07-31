#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(Var,BitNo)	Var |= (1 << BitNo)
#define CLR_BIT(Var,BitNo)	Var &= ~(1 << BitNo)
#define TOG_BIT(Var,BitNo)	Var ^= (1 << BitNo)

#endif