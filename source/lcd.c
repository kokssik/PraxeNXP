//-----------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------
#include "board.h"

#include "lcd.h"
//#include "fsl_pit_driver.h"

//-----------------------------------------------------------------------
// Macros
//-----------------------------------------------------------------------

#define LCDdata(dat) LCD_write(dat)


//-----------------------------------------------------------------------
// Variables
//-----------------------------------------------------------------------


const unsigned char  initLCD[8]={0x02, 0x28, 0x0C,0x06,0x01,0x00};
volatile long 		 count;
volatile bool 		 pitIsrFlag[2] = {false};

gpio_pin_config_t lcdPins[6] =
{
  {
    kGPIO_DigitalOutput,
    0,
  },
  {
    kGPIO_DigitalOutput,
    0,
  },
  {
    kGPIO_DigitalOutput,
    0,
  },
  {
    kGPIO_DigitalOutput,
    0,
  },
  {
    kGPIO_DigitalOutput,
    0,
  },
  {
    kGPIO_DigitalOutput,
    0,
  }
};

//-----------------------------------------------------------------------
// Function Prototypes
//-----------------------------------------------------------------------

void LCD_init()
{
  
  unsigned char i = 0;  
  LCD_Pin_Enable(); 	// Enable pins
  
  delay(100); 		//Display initialization

  
  while(initLCD[i])
  {
    LCD_inst(initLCD[i]);
    i++;
  }

  //LCD_inst(0x0F); //Cursor on blinking

  
}

//-----------------------------------------------------------------------

void LCD_en_togle(void){
  LCD_ENABLE_ON;
  delay(1);
  LCD_ENABLE_OFF;
  
  
}

//-----------------------------------------------------------------------

void SetUp(){
  unsigned char a = 0;
  
  while(initLCD[a])
  {
    LCD_inst(initLCD[a]);
    a++;
  }
}

//-----------------------------------------------------------------------

void LCD_inst(unsigned char x){
  LCD_RS_OFF;
  
  LCD_data_to_port(x&0xF0);
  LCD_en_togle();
  
  LCD_data_to_port((x<<4)&0xF0);
  LCD_en_togle();
}

//-----------------------------------------------------------------------
void LCD_clr(void)
{ //function for clearing the screen
  
  LCD_inst(0x01);
  //LCD_init(); TODO 
  
}

void LCD_soft_Clr(void)
{
  unsigned char i;
  for(i=0;i<80;i++)
    LCD_write(' ');
  LCD_to_xy(1,1);
}

void LCD_to_xy(unsigned char line,unsigned char column){
  unsigned char cmd=0x80;
  unsigned char position;
  position = column-1 + (line-1)*20;
  
  if (position > 59)
  {
    position += 0x18;
  } else
    {   if (position > 39) position -= 0x14;
      else
      {  if (position > 19) position += 0x2c;
      }
    }
  cmd = cmd | position;
  
  LCD_inst(cmd);
  
}

void LCD_data_to_port(unsigned char x)
{
  //Bit 7
  if (x&0x80)
  {
    LCD_D7_ON;
  }
  else
  {
    LCD_D7_OFF;
  }
  
  //Bit 6
  if (x&0x40)
  {
    LCD_D6_ON;
  }
  else
  {
    LCD_D6_OFF;
  }
  
  //Bit 5
  if (x&0x20)
  {
    LCD_D5_ON;
  }
  else
  {
    LCD_D5_OFF;
  }
  
  //Bit 4
  if (x&0x10)
  {
    LCD_D4_ON;
  }
  else
  {
    LCD_D4_OFF;
  }
}

//-----------------------------------------------------------------------
void LCD_string(char* msg)
{
  unsigned int i,j;
  unsigned int line=1;
  for(i=0,j=0;msg[i];i++,j++)
  {
    
    if(j==16){
      if(line==1){
        LCD_to_xy(2,1);
        line=2;	
      }else {// if(line==2)
        LCD_to_xy(1,1);
        line=1;
      }				
      j=0;
    }			
    
    if(msg[i]!='\n')
    {
      LCD_write(msg[i]);
    }else if(line==1)
    {
      LCD_to_xy(2,1);
      j=0;
      line=2;
    }else
    {
      LCD_to_xy(1,1);
      j=0;
      line=1;
    }						
  }
}

//-----------------------------------------------------------------------

void LCD_write(unsigned char x)
{
  LCD_RS_ON;
  
  LCD_data_to_port( x&0xF0 );
  LCD_en_togle();
  
  LCD_data_to_port( (x<<4)&0xF0 );
  LCD_en_togle();
}

//-----------------------------------------------------------------------

void LCD_Pin_Enable(void){
  LCD_ENABLE_EN;
  LCD_RS_EN;
  LCD_D7_EN;
  LCD_D6_EN;
  LCD_D5_EN;
  LCD_D4_EN;
}

//-----------------------------------------------------------------------

void delay(unsigned long time){
  
 count = 0;
  while (count <= time){}

}

/********************** AVR LCD ***********************************************/


//////////////////////////////////////////////////////////////////
////                                                            //
////                   EEPROM Constants (LCD new characters)    //
////                   ----------------                         //
//////////////////////////////////////////////////////////////////
//const unsigned char r[8] =             {0b01010,
//										0b00100,
//										0b10110,
//										0b11001,
//										0b10000,
//										0b10000,
//										0b10000,
//										0b00000}; //czech: r s hackem
//
//const unsigned char e0[8] =            {0b01010,
//										0b00100,
//										0b01110,
//										0b10001,
//										0b11111,
//										0b10000,
//										0b01110,
//										0b00000};  //czech: e s hackem
//
//

//////////////////////////////////////////////////////////////////
////                                                            //
////                   LCD functions                            //
////                   -------------                            //
//////////////////////////////////////////////////////////////////

//void LCDinit(void){   // initialisation of LCD 4bit mode
//
//
//	_delay_ms(16);
//
//	LCDPORT = 0x30>>SHIFT; //0x30>>2
//
//
//	LCDen();
//
//	_delay_ms(5);
//
//	LCDen();
//
//	_delay_us(6);
//
//	LCDen();
//
//	LCDPORT = 0x20>>SHIFT; //0x20>>2
//
//
//	LCDen();
//
//	LCDcmd(0x28);                         
//	LCDcmd(0x06); 	                    
//	LCDcmd(0x0c); 	                    
//	LCDcmd(0x01); 	            
//	                    
//	_delay_ms(3);
//
//}
//
//void LCDnewChar(unsigned char ddramaddr,const unsigned char Char[8]){
//	LCDcmd(64+8*ddramaddr);
//
//	LCDdata(Char[0]);
//	LCDdata(Char[1]);
//	LCDdata(Char[2]);
//	LCDdata(Char[3]);
//	LCDdata(Char[4]);
//	LCDdata(Char[5]);
//	LCDdata(Char[6]);
//	LCDdata(Char[7]);
//
//	LCDtoxy(1,1);
//
//}





