/*
 * BIT_MATH.h
 *
 * Created: 8/19/2023 9:13:47 PM
 *  Author: FAHD9
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(REG,BIT)(REG |= (1<<BIT))
#define CLR_BIT(REG,BIT)(REG &= ~(1<<BIT))
#define READ_BIT(REG,BIT)((REG & (1<<BIT))>>BIT)
#define TOGGLE_BIT(REG,BIT)(REG ^= (1<<BIT))

#endif /* BIT_MATH_H_ */