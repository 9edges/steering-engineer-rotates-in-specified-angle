#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Servo.h"

long double Angle;
int d;

int main(void)
{	
	OLED_Init();
	Servo_Init();
	d=0;
	Angle=0;
	Servo_SetAngle(Angle);
	OLED_ShowString(1,1,"Angle");
	
	
	while (1)
	{	
		if(d==0){
			Angle+=1;
			if(Angle>=180){
				d=1;
			}
		}
		else{
			Angle-=1;
			if(Angle<=0){
				d=0;
			}
		}
		
		Servo_SetAngle(Angle);
		OLED_ShowNum(1,7,Angle,3);
		Delay_ms(1);
	}
}
