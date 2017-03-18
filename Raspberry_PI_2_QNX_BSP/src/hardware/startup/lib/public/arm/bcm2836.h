#ifndef __ARM_BCM2836_H_INCLUDED
#define __ARM_BCM2836_H_INCLUDED

/* Bit definitions */
#define BIT0				0x00000001
#define BIT1				0x00000002
#define BIT2				0x00000004
#define BIT3				0x00000008
#define BIT4				0x00000010
#define BIT5				0x00000020
#define BIT6				0x00000040
#define BIT7				0x00000080
#define BIT8				0x00000100
#define BIT9				0x00000200
#define BIT10				0x00000400
#define BIT11				0x00000800
#define BIT12				0x00001000
#define BIT13				0x00002000
#define BIT14				0x00004000
#define BIT15				0x00008000
#define BIT16				0x00010000
#define BIT17				0x00020000
#define BIT18				0x00040000
#define BIT19				0x00080000
#define BIT20				0x00100000
#define BIT21				0x00200000
#define BIT22				0x00400000
#define BIT23				0x00800000
#define BIT24				0x01000000
#define BIT25				0x02000000
#define BIT26				0x04000000
#define BIT27				0x08000000
#define BIT28				0x10000000
#define BIT29				0x20000000
#define BIT30				0x40000000
#define BIT31				0x80000000


/*
GPIO
*/
#define BCM2835_GPIO_BASE		0x3F200000
#define BCM2835_NUM_BANKS 2
#define BCM2835_NUM_IRQS  3

#define DIV_ROUND_UP(n,d) (((n) + (d) - 1) / (d))
#define BCM2835_PIN_BITMAP_SZ \
	DIV_ROUND_UP(BCM2835_NUM_GPIOS, sizeof(unsigned long) * 8)

/* GPIO register offsets */
#define BCM2835_GPIO_GPFSEL0		0x0	/* Function Select */
#define BCM2835_GPIO_GPFSEL1 		0x04
#define BCM2835_GPIO_GPFSEL2 		0x08
#define BCM2835_GPIO_GPFSEL3 		0x0C
#define BCM2835_GPIO_GPFSEL4 		0x10
#define BCM2835_GPIO_GPFSEL5 		0x14

#define BCM2835_GPIO_GPSET0 0x1C /* Pin Output Set */
#define BCM2835_GPIO_GPSET1 0x20 /* Pin Output Set */

#define BCM2835_GPIO_GPCLR0 0x28
#define BCM2835_GPIO_GPCLR1 0x2C

#define BCM2835_GPIO_GPLEV0 0x34
#define BCM2835_GPIO_GPLEV1 0x38

#define BCM2835_GPIO_GPEDS0 0x40
#define BCM2835_GPIO_GPEDS1 0x44

#define BCM2835_GPIO_GPREN0 0x4C
#define BCM2835_GPIO_GPREN1 0x50

#define BCM2835_GPIO_GPFEN0 0x58
#define BCM2835_GPIO_GPFEN1 0x5C

#define BCM2835_GPIO_GPHEN0 0x64
#define BCM2835_GPIO_GPHEN1 0x68

#define BCM2835_GPIO_GPLEN0 0x70
#define BCM2835_GPIO_GPLEN1 0x74

#define BCM2835_GPIO_GPAREN0 0x7C
#define BCM2835_GPIO_GPAREN1 0x80

#define BCM2835_GPIO_GPAFEN0 0x88
#define BCM2835_GPIO_GPAFEN1 0x8C

#define BCM2835_GPIO_GPPUD 0x94
#define BCM2835_GPIO_GPPUDCLK0 0x98
#define BCM2835_GPIO_GPPUDCLK1 0x9C


#define FSEL_REG(p)		(BCM2835_GPIO_GPFSEL0 + (((p) / 10) * 4))
#define FSEL_SHIFT(p)		(((p) % 10) * 3)
#define GPIO_REG_OFFSET(p)	((p) / 32)
#define GPIO_REG_SHIFT(p)	((p) % 32)

#define BCM2835_PINCONF_PACK(_param_, _arg_) ((_param_) << 16 | (_arg_))
#define BCM2835_PINCONF_UNPACK_PARAM(_conf_) ((_conf_) >> 16)
#define BCM2835_PINCONF_UNPACK_ARG(_conf_) ((_conf_) & 0xffff)

// #define BCM2835_GPIO_FSEL_MASK		0x7
// #define BCM2835_GPIO_INPUT		0x0
// #define BCM2835_GPIO_OUTPUT		0x1
// #define BCM2835_GPIO_ALT0		0x4
// #define BCM2835_GPIO_ALT1		0x5
// #define BCM2835_GPIO_ALT2		0x6
// #define BCM2835_GPIO_ALT3		0x7
// #define BCM2835_GPIO_ALT4		0x3
// #define BCM2835_GPIO_ALT5		0x2

/*
Timer
*/
#define BCM2835_TIMER_SIZE          0x22
#define BCM2835_TIMER_BASE          0x3F003000
#define BCM2835_TIMER_CS 	  0x00
#define BCM2835_TIMER_VALUE_LOWER 	  0xFF
#define BCM2835_TIMER_VALUE_HIGHER 	  0xFF
// #define BCM2835_TIMER_VALUE_LOWER 	  0x04
// #define BCM2835_TIMER_VALUE_HIGHER 	  0x08
#define BCM2835_TIMER0_CMP 	  0x0C
#define BCM2835_TIMER1_CMP 	  0x10
#define BCM2835_TIMER2_CMP 	  0x14
#define BCM2835_TIMER3_CMP 	  0x18

#define TIMER_CS_MATCH_0	(1<<0)	//  Set when compare reg 0 matches
#define TIMER_CS_MATCH_1	(1<<1)	//  Set when compare reg 1 matches
#define TIMER_CS_MATCH_2	(1<<2)	//  Set when compare reg 2 matches
#define TIMER_CS_MATCH_3	(1<<3)	//  Set when compare reg 3 matches

/*
Interrupt
*/
#define ARM_IRQCTLR_BASEOFF		0x40000000

#define ARM_AIC_SIZE            0x28

#define IRQC_BASICPEND_OFF		(0x00000200)   //
#define IRQC_IRQPEND1_OFF		(0x00000204)   //
#define IRQC_IRQPEND2_OFF		(0x00000208)   //
#define IRQC_FIQCTRL_OFF		(0x0000020C)   //
#define IRQC_ENABIRQ1_OFF		(0x00000210)   //
#define IRQC_ENABIRQ2_OFF		(0x00000214)   //
#define IRQC_ENABBASIC_OFF		(0x00000218)   //
#define IRQC_DISABIRQ1_OFF		(0x0000021C)   //
#define IRQC_DISABIRQ2_OFF		(0x00000220)   //
#define IRQC_DISABBASIC_OFF		(0x00000224)   //

// Bit defs for base pending reg
#define  BCM2835_BASE_ARMTIMER	(1 << 0)		//    1
#define  BCM2835_BASE_ARMMAILBOX	(1 << 1)		// 2
#define  BCM2835_BASE_ARMDOORBEL0	(1 << 2)		//4
#define  BCM2835_BASE_ARMDOORBEL1	(1 << 3)		//8
#define  BCM2835_BASE_GPU0HALT	(1 << 4)		//
#define  BCM2835_BASE_GPU1HALT	(1 << 5)		//
#define  BCM2835_BASE_BADACCESS1	(1 << 6)		//
#define  BCM2835_BASE_BADACCESS0	(1 << 7)		//

#define  BCM2835_BASE_JPEG		(1 << 10)		//GPU_IRQ07
#define  BCM2835_BASE_USB			(1 << 11)		//GPU_IRQ09
#define  BCM2835_BASE_3D			(1 << 12)		//GPU_IRQ10
#define  BCM2835_BASE_DMA2		(1 << 13)		//GPU_IRQ18
#define  BCM2835_BASE_DMA3		(1 << 14)		//GPU_IRQ19
#define  BCM2835_BASE_I2C			(1 << 15)		//GPU_IRQ53
#define  BCM2835_BASE_SPI			(1 << 16)		//GPU_IRQ54
#define  BCM2835_BASE_I2SPCM		(1 << 17)		//GPU_IRQ55
#define  BCM2835_BASE_SDIO		(1 << 18)		//GPU_IRQ56
#define  BCM2835_BASE_UART0		(1 << 19)		//GPU_IRQ57
#define  BCM2835_BASE_ARASANSDIO	(1 << 20)		//GPU_IRQ62



#define  BCM2835_PHYSIRQ_TIMER0		0
#define  BCM2835_PHYSIRQ_TIMER1		1
#define  BCM2835_PHYSIRQ_TIMER2		2
#define  BCM2835_PHYSIRQ_TIMER3		3
#define  BCM2835_PHYSIRQ_CODEC0		4
#define  BCM2835_PHYSIRQ_CODEC1		5
#define  BCM2835_PHYSIRQ_CODEC2		6
#define  BCM2835_PHYSIRQ_VCJPEG		7
#define  BCM2835_PHYSIRQ_ISP			8
#define  BCM2835_PHYSIRQ_VC_USB		9
#define  BCM2835_PHYSIRQ_VC_3D		10
#define  BCM2835_PHYSIRQ_TRANSPOSER	11
#define  BCM2835_PHYSIRQ_MCSYNC0		12
#define  BCM2835_PHYSIRQ_MCSYNC1		13
#define  BCM2835_PHYSIRQ_MCSYNC2		14
#define  BCM2835_PHYSIRQ_MCSYNC3		15
#define  BCM2835_PHYSIRQ_DMA0			16
#define  BCM2835_PHYSIRQ_DMA1			17
#define  BCM2835_PHYSIRQ_VC_DMA2		18
#define  BCM2835_PHYSIRQ_VC_DMA3		19
#define  BCM2835_PHYSIRQ_DMA4			20
#define  BCM2835_PHYSIRQ_DMA5			21
#define  BCM2835_PHYSIRQ_DMA6			22
#define  BCM2835_PHYSIRQ_DMA7			23
#define  BCM2835_PHYSIRQ_DMA8			24
#define  BCM2835_PHYSIRQ_DMA9			25
#define  BCM2835_PHYSIRQ_DMA10		26
#define  BCM2835_PHYSIRQ_DMA11		27
#define  BCM2835_PHYSIRQ_DMA12		28
#define  BCM2835_PHYSIRQ_AUX			29
#define  BCM2835_PHYSIRQ_ARM			30
#define  BCM2835_PHYSIRQ_VPUDMA		31

#define  BCM2835_PHYSIRQ_HOSTPORT		32
#define  BCM2835_PHYSIRQ_VIDSCALER	33
#define  BCM2835_PHYSIRQ_CCP2TX		34
#define  BCM2835_PHYSIRQ_SDC			35
#define  BCM2835_PHYSIRQ_DSIO			36
#define  BCM2835_PHYSIRQ_AVE			37
#define  BCM2835_PHYSIRQ_CAM0			38
#define  BCM2835_PHYSIRQ_CAM1			39
#define  BCM2835_PHYSIRQ_HDMI0		40
#define  BCM2835_PHYSIRQ_HDMI1		41
#define  BCM2835_PHYSIRQ_PIXELVALV1	42
#define  BCM2835_PHYSIRQ_I2CSPISLAVE	43
#define  BCM2835_PHYSIRQ_DSI1			44
#define  BCM2835_PHYSIRQ_PWA0			45
#define  BCM2835_PHYSIRQ_PWA1			46
#define  BCM2835_PHYSIRQ_CPR			47
#define  BCM2835_PHYSIRQ_SMI			48
#define  BCM2835_PHYSIRQ_GPIO0		49
#define  BCM2835_PHYSIRQ_GPIO1		50
#define  BCM2835_PHYSIRQ_GPIO2		51
#define  BCM2835_PHYSIRQ_GPIO3		52
#define  BCM2835_PHYSIRQ_VC_I2C		53
#define  BCM2835_PHYSIRQ_VC_SPI		54
#define  BCM2835_PHYSIRQ_I2SPCM		55
#define  BCM2835_PHYSIRQ_SDIO			56
#define  BCM2835_PHYSIRQ_UART0		57
#define  BCM2835_PHYSIRQ_SLIMBUS		58
#define  BCM2835_PHYSIRQ_VEC			59
#define  BCM2835_PHYSIRQ_CPG			60
#define  BCM2835_PHYSIRQ_RNG			61
#define  BCM2835_PHYSIRQ_VC_ARASANSDIO 62
#define  BCM2835_PHYSIRQ_AVSPMON		63

/*
	Watch Dog
*/
#define BCM2835_WDOG_PHYSADDR				0x3f100000
#define BCM2835_WDOG_PASSWORD				0x5a000000
#define BCM2835_WDOG_RSTC_WRCFG_MASK		0x00000030
#define BCM2835_WDOG_WDOG_TIMEOUT_MASK		0x0000ffff
#define BCM2835_WDOG_WDOG					0x24
#define BCM2835_WDOG_WDOG_TIME_SET			0x000fffff

#define BCM2835_WDOG_RSTC					0x1c
#define BCM2835_WDOG_RSTC_WRCFG_CLR			0xffffffcf
#define BCM2835_WDOG_RSTC_WRCFG_SET			0x00000030
#define BCM2835_WDOG_RSTC_WRCFG_FULL_RESET	0x00000020
#define BCM2835_WDOG_RSTC_RESET				0x00000102

#define BCM2835_WDOG_RSTS					0x20
#define BCM2835_WDOG_RSTS_HADWRH_SET		0x00000040
#define BCM2835_WDOG_RSTS_PARTITION_CLR		0xfffffaaa

#define SECS_TO_WDOG_TICKS(x) 				((x) << 16)
#define WDOG_TICKS_TO_SECS(x) 				((x) >> 16)


/*
I2C
*/
#define BCM2835_I2C_C		0x0
#define BCM2835_I2C_S		0x4
#define BCM2835_I2C_DLEN	0x8
#define BCM2835_I2C_A		0xc
#define BCM2835_I2C_FIFO	0x10
#define BCM2835_I2C_DIV		0x14
#define BCM2835_I2C_DEL		0x18
#define BCM2835_I2C_CLKT	0x1c

#define BCM2835_I2C_C_READ	BIT(0)
#define BCM2835_I2C_C_CLEAR	BIT(4) /* bits 4 and 5 both clear */
#define BCM2835_I2C_C_ST	BIT(7)
#define BCM2835_I2C_C_INTD	BIT(8)
#define BCM2835_I2C_C_INTT	BIT(9)
#define BCM2835_I2C_C_INTR	BIT(10)
#define BCM2835_I2C_C_I2CEN	BIT(15)

#define BCM2835_I2C_S_TA	BIT(0)
#define BCM2835_I2C_S_DONE	BIT(1)
#define BCM2835_I2C_S_TXW	BIT(2)
#define BCM2835_I2C_S_RXR	BIT(3)
#define BCM2835_I2C_S_TXD	BIT(4)
#define BCM2835_I2C_S_RXD	BIT(5)
#define BCM2835_I2C_S_TXE	BIT(6)
#define BCM2835_I2C_S_RXF	BIT(7)
#define BCM2835_I2C_S_ERR	BIT(8)
#define BCM2835_I2C_S_CLKT	BIT(9)
#define BCM2835_I2C_S_LEN	BIT(10) /* Fake bit for SW error reporting */

#define BCM2835_I2C_CDIV_MIN	0x0002
#define BCM2835_I2C_CDIV_MAX	0xFFFE


/*
 * GIC
 */



/*
GPU
*/

#define BCM2835_GPU_BASE 	0x4000000C

/*
SPI
*/
#define BCM2835_SPI0_BASE 0x3F204000
#define BCM2835_SPI0_CS     0x00
#define BCM2835_SPI0_FIFO   0x04
#define BCM2835_SPI0_CLK    0x08
#define BCM2835_SPI0_DLEN   0x0C
#define BCM2835_SPI0_LTOH   0x10
#define BCM2835_SPI0_DC     0x14


/*
UART0
*/
#define BCM2835_UART0_BASE  0x3F201000
#define BCM2835_UART_SIZE    0x90
// The offsets for reach register for the UART.
#define BCM2835_UART0_DR     0x00
#define BCM2835_UART0_RSRECR 0x04
#define BCM2835_UART0_FR     0x18
#define BCM2835_UART0_ILPR   0x20
#define BCM2835_UART0_IBRD   0x24
#define BCM2835_UART0_FBRD   0x28
#define BCM2835_UART0_LCRH   0x2C
#define BCM2835_UART0_CR     0x30
#define BCM2835_UART0_IFLS   0x34
#define BCM2835_UART0_IMSC   0x38
#define BCM2835_UART0_RIS    0x3C
#define BCM2835_UART0_MIS    0x40
#define BCM2835_UART0_ICR    0x44
#define BCM2835_UART0_DMACR  0x48
#define BCM2835_UART0_ITCR   0x80
#define BCM2835_UART0_ITIP   0x84
#define BCM2835_UART0_ITOP   0x88
#define BCM2835_UART0_TDR    0x8C

#define BCM2835_DBGU_IE_SR_RXEMTY   0x10
#define BCM2835_DBGU_IE_SR_TXRDY    0x20

//interrupt mask.
#define BCM2835_UART0_IMSC_RX   0x10


/*
Clock Manager General Purpose Clocks Control
*/
#define BCM2835_CM_GP0CTL	0x3F101070
#define BCM2835_CM_GP1CTL	0x3F101078
#define BCM2835_CM_GP2CTL	0x3F101080

/*
Clock Manager General Purpose Clock Divisors
*/

#define BCM2835_CM_GP0DIV	0x3F101074
#define BCM2835_CM_GP1DIV	0x3F10107c
#define BCM2835_CM_GP2DIV	0x3F101084


#endif