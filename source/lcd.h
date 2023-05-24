
#define LCD_EN_PORT GPIOC
#define LCD_EN_PIN 11

#define LCD_RS_PORT GPIOC
#define LCD_RS_PIN 10

#define LCD_D7_PORT GPIOB
#define LCD_D7_PIN 2

#define LCD_D6_PORT GPIOB
#define LCD_D6_PIN 3

#define LCD_D5_PORT GPIOB
#define LCD_D5_PIN 10

#define LCD_D4_PORT GPIOB
#define LCD_D4_PIN 11



/* lcd mapping */
// Enable direction 
#define LCD_ENABLE_EN   (GPIO_PinInit(LCD_EN_PORT, LCD_EN_PIN, &lcdPins[0]))//(GPIO_DRV_WritePinOutput(lcdPins[0].pinName, 1)) /*!< Turn on target LCD Enable */
#define LCD_RS_EN       (GPIO_PinInit(LCD_RS_PORT, LCD_RS_PIN, &lcdPins[1]))//(GPIO_DRV_WritePinOutput(lcdPins[1].pinName, 1)) /*!< Turn on target LCD RS */
#define LCD_D7_EN       (GPIO_PinInit(LCD_D7_PORT, LCD_D7_PIN, &lcdPins[2]))//(GPIO_DRV_WritePinOutput(lcdPins[2].pinName, 1)) /*!< Turn on target LCD D7 */
#define LCD_D6_EN       (GPIO_PinInit(LCD_D6_PORT, LCD_D6_PIN, &lcdPins[3]))//(GPIO_DRV_WritePinOutput(lcdPins[3].pinName, 1)) /*!< Turn on target LCD D6 */
#define LCD_D5_EN       (GPIO_PinInit(LCD_D5_PORT, LCD_D5_PIN, &lcdPins[4]))//(GPIO_DRV_WritePinOutput(lcdPins[4].pinName, 1)) /*!< Turn on target LCD D5 */
#define LCD_D4_EN       (GPIO_PinInit(LCD_D4_PORT, LCD_D4_PIN, &lcdPins[5]))//(GPIO_DRV_WritePinOutput(lcdPins[5].pinName, 1)) /*!< Turn on target LCD D4 */


//SET

#define LCD_ENABLE_ON   (GPIO_PortSet(LCD_EN_PORT, 1U << LCD_EN_PIN))//(GPIO_DRV_WritePinOutput(lcdPins[0].pinName, 1)) /*!< Turn on target LCD Enable */
#define LCD_RS_ON       (GPIO_PortSet(LCD_RS_PORT, 1U << LCD_RS_PIN))//(GPIO_DRV_WritePinOutput(lcdPins[1].pinName, 1)) /*!< Turn on target LCD RS */
#define LCD_D7_ON       (GPIO_PortSet(LCD_D7_PORT, 1U << LCD_D7_PIN))//(GPIO_DRV_WritePinOutput(lcdPins[2].pinName, 1)) /*!< Turn on target LCD D7 */
#define LCD_D6_ON       (GPIO_PortSet(LCD_D6_PORT, 1U << LCD_D6_PIN))//(GPIO_DRV_WritePinOutput(lcdPins[3].pinName, 1)) /*!< Turn on target LCD D6 */
#define LCD_D5_ON       (GPIO_PortSet(LCD_D5_PORT, 1U << LCD_D5_PIN))//(GPIO_DRV_WritePinOutput(lcdPins[4].pinName, 1)) /*!< Turn on target LCD D5 */
#define LCD_D4_ON       (GPIO_PortSet(LCD_D4_PORT, 1U << LCD_D4_PIN))//(GPIO_DRV_WritePinOutput(lcdPins[5].pinName, 1)) /*!< Turn on target LCD D4 */

      
      // CLEAR 
#define LCD_ENABLE_OFF  (GPIO_PortClear(LCD_EN_PORT, 1U << LCD_EN_PIN))//(GPIO_DRV_WritePinOutput(lcdPins[0].pinName, 1)) /*!< Turn on target LCD Enable */
#define LCD_RS_OFF      (GPIO_PortClear(LCD_RS_PORT, 1U << LCD_RS_PIN))//(GPIO_DRV_WritePinOutput(lcdPins[1].pinName, 1)) /*!< Turn on target LCD RS */
#define LCD_D7_OFF      (GPIO_PortClear(LCD_D7_PORT, 1U << LCD_D7_PIN))//(GPIO_DRV_WritePinOutput(lcdPins[2].pinName, 1)) /*!< Turn on target LCD D7 */
#define LCD_D6_OFF      (GPIO_PortClear(LCD_D6_PORT, 1U << LCD_D6_PIN))//(GPIO_DRV_WritePinOutput(lcdPins[3].pinName, 1)) /*!< Turn on target LCD D6 */
#define LCD_D5_OFF      (GPIO_PortClear(LCD_D5_PORT, 1U << LCD_D5_PIN))//(GPIO_DRV_WritePinOutput(lcdPins[4].pinName, 1)) /*!< Turn on target LCD D5 */
#define LCD_D4_OFF      (GPIO_PortClear(LCD_D4_PORT, 1U << LCD_D4_PIN))//(GPIO_DRV_WritePinOutput(lcdPins[5].pinName, 1)) /*!< Turn on target LCD D4 */


//-----------------------------------------------------------------------
// Function Prototypes
//-----------------------------------------------------------------------
void delay(unsigned long time);
extern volatile long 		 count;

void SetUp ();
void LCD_en_togle(void);
void LCD_inst (unsigned char x);
void LCD_data_to_port(unsigned char x);
void LCD_init(void);
void LCD_string(char* msg);
void LCD_clr(void);
void LCD_soft_Clr(void);
void LCD_to_xy(unsigned char line,unsigned char column);
void LCD_write(unsigned char x);
void LCD_Pin_Enable(void);






