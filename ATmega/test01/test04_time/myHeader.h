/*
 * IncFile1.h
 *
 * Created: 2024-03-28 오전 10:59:02
 *  Author: SYSTEM-00
 */ 

#define  F_CPU 16000000L
extern char* Disp(unsigned long num); //외부에 있는 함수를 호출할때는 함수의 프로토타입을 선언해주는게 정석

/*#ifndef INCFILE1_H_ // 중복방지(define은 문제x, 변수는 문제 발생) ifndef : not define,  컴파일러 지시자, 실변수 선언금지
#define INCFILE1_H_



#endif *//* INCFILE1_H_ */