/************************************************************************
*           Demo
*           Pin1-10
************************************************************************/
#include <sys/io.h>
#include <stdio.h>

unsigned int indexp = 0x2e;
unsigned int datap = 0x2f;

main()
{
   char key[5] = {0};
   unsigned char temp; 
   unsigned char temp2; 
   int quit = 1;
   iopl(3);
//init GPIO
   	outb(0x87, indexp);
	outb(0x87, indexp);

   	outb(0x07, indexp);
	outb(0x06, datap);

   	outb(0x28, indexp);
	temp = (unsigned char)inb(datap);
	temp2 = temp | 0x20;
	outb(temp2, datap);

   	outb(0x27, indexp);
	temp = (unsigned char)inb(datap);
	temp2 = temp & 0xf3;
	outb(temp2, datap);

   
   /* Read/Write Data */
   printf("please input '1,0' + 'enter' to set pin1(GPIO50) to output pins low level, and '1,1' + 'enter' to high level\n");
   printf("       input '2,0' + 'enter' to set pin3(GPIO51) to output pins low level, and '2,1' + 'enter' to high level\n");
   printf("       input '3,0' + 'enter' to set pin5(GPIO52) to output pins low level, and '3,1' + 'enter' to high level\n");
   printf("please input '4,0' + 'enter' to set pin7(GPIO53) to output pins low level, and '4,1' + 'enter' to high level\n");
   printf("       input '5,0' + 'enter' to set pin4(GPIO54) to output pins low level, and '5,1' + 'enter' to high level\n");
   printf("       input '6,0' + 'enter' to set pin6(GPIO55) to output pins low level, and '6,1' + 'enter' to high level\n");
   printf("       input '7,0' + 'enter' to set pin8(GPIO56) to output pins low level, and '7,1' + 'enter' to high level\n");
   printf("       input '8,0' + 'enter' to set pin10(GPIO57) to output pins low level, and '8,1' + 'enter' to high level\n");
   printf("       input 'all,0' + 'enter' to set Pin1-10 to output pins low level '0'\n");
   printf("       input 'all,1' + 'enter' to set Pin1-10 to output pins high level '1'\n");
   printf("please input 'rd1' + 'enter' read Pin1(GPIO50) the GPIO(input) pins\n");
   printf("       input 'rd2' + 'enter' read Pin3(GPIO51) the GPIO(input) pins\n");
   printf("       input 'rd3' + 'enter' read Pin5(GPIO52) the GPIO(input) pins\n");
   printf("please input 'rd4' + 'enter' read Pin7(GPIO53) the GPIO(input) pins\n");
   printf("       input 'rd5' + 'enter' read Pin4(GPIO54) the GPIO(input) pins\n");
   printf("       input 'rd6' + 'enter' to read Pin6(GPIO55) the GPIO(input) pins\n");
   printf("       input 'rd7' + 'enter' to read Pin8(GPIO56) the GPIO(input) pins\n");
   printf("       input 'rd8' + 'enter' to read Pin10(GPIO57) the GPIO(input) pins\n");
   printf("       input 'rda' + 'enter' to read Pin1-10 the GPIO(input) pins\n");
   printf("       input 'qt' + 'enter' to quit:\n");

   while(quit)
   {
   scanf("%s", key);
   switch(key[0])
   {
      case '1': /* Pin1 GP50 */
   	outb(0xA0, indexp);
	temp = (unsigned char)inb(datap);
	temp2 = temp | 0x01;
	outb(temp2, datap);
         if (key[2] == '1')
         {
   		outb(0xA1, indexp);
		temp = (unsigned char)inb(datap);
		temp2 = temp |0x01;
		outb(temp2, datap);
         }
         else
         {
   		outb(0xA1, indexp);
		temp = (unsigned char)inb(datap);
		temp2 = temp & 0xfe;
		outb(temp2, datap);
         }
         break;
      case '2': /* Pin3 GP51 */
   	outb(0xA0, indexp);
	temp = (unsigned char)inb(datap);
	temp2 = temp | 0x02;
	outb(temp2, datap);
         if (key[2] == '1')
         {
   		outb(0xA1, indexp);
		temp = (unsigned char)inb(datap);
		temp2 = temp | 0x02;
		outb(temp2, datap);
         }
         else
         {
   		outb(0xA1, indexp);
		temp = (unsigned char)inb(datap);
		temp2 = temp & 0xfd;
		outb(temp2, datap);
         }
         break;
      case '3': /* Pin5 GP52 */
   	outb(0xA0, indexp);
	temp = (unsigned char)inb(datap);
	temp2 = temp | 0x04;
	outb(temp2, datap);
         if (key[2] == '1')
         {
   		outb(0xA1, indexp);
		temp = (unsigned char)inb(datap);
		temp2 = temp | 0x04;
		outb(temp2, datap);
         }
         else
         {
   		outb(0xA1, indexp);
		temp = (unsigned char)inb(datap);
		temp2 = temp & 0xfb;
		outb(temp2, datap);
         }
         break;
      case '4': /* Pin7 GP53 */
   	outb(0xA0, indexp);
	temp = (unsigned char)inb(datap);
	temp2 = temp | 0x08;
	outb(temp2, datap);
         if (key[2] == '1')
         {
   		outb(0xA1, indexp);
		temp = (unsigned char)inb(datap);
		temp2 = temp | 0x08;
		outb(temp2, datap);
         }
         else
         {
   		outb(0xA1, indexp);
		temp = (unsigned char)inb(datap);
		temp2 = temp & 0xf7;
		outb(temp2, datap);
         }
         break;
      case '5': /* Pin4 GP54 */
	outb(0xA0, indexp);
	temp = (unsigned char)inb(datap);
	temp2 = temp | 0x10;
	outb(temp2, datap);
         if (key[2] == '1')
         {
   		outb(0xA1, indexp);
		temp = (unsigned char)inb(datap);
		temp2 = temp | 0x10;
		outb(temp2, datap);
         }
         else
         {
   		outb(0xA1, indexp);
		temp = (unsigned char)inb(datap);
		temp2 = temp & 0xef;
		outb(temp2, datap);
         }
         break;
      case '6': /* Pin6 GP55 */
	outb(0xA0, indexp);
	temp = (unsigned char)inb(datap);
	temp2 = temp | 0x20;
	outb(temp2, datap);
         if (key[2] == '1')
         {
   		outb(0xA1, indexp);
		temp = (unsigned char)inb(datap);
		temp2 = temp | 0x20;
		outb(temp2, datap);
         }
         else
         {
   		outb(0xA1, indexp);
		temp = (unsigned char)inb(datap);
		temp2 = temp & 0xdf;
		outb(temp2, datap);
         }
         break;
      case '7': /* Pin8 GP56 */
	outb(0xA0, indexp);
	temp = (unsigned char)inb(datap);
	temp2 = temp | 0x40;
	outb(temp2, datap);
         if (key[2] == '1')
         {
   		outb(0xA1, indexp);
		temp = (unsigned char)inb(datap);
		temp2 = temp | 0x40;
		outb(temp2, datap);
         }
         else
         {
   		outb(0xA1, indexp);
		temp = (unsigned char)inb(datap);
		temp2 = temp & 0xbf;
		outb(temp2, datap);
         }
         break;
      case '8': /* Pin10 GP57 */
	outb(0xA0, indexp);
	temp = (unsigned char)inb(datap);
	temp2 = temp | 0x80;
	outb(temp2, datap);
         if (key[2] == '1')
         {
   		outb(0xA1, indexp);
		temp = (unsigned char)inb(datap);
		temp2 = temp | 0x80;
		outb(temp2, datap);
         }
         else
         {
   		outb(0xA1, indexp);
		temp = (unsigned char)inb(datap);
		temp2 = temp & 0x7f;
		outb(temp2, datap);
         }
         break;
      case 'a':
         if ((key[1] == 'l') && (key[2] == 'l') && (key[4] == '0'))
         {
		outb(0xA0, indexp);
		temp = (unsigned char)inb(datap);
		temp2 = temp | 0x00;
		outb(temp2, datap);

   		outb(0xA1, indexp);
		temp = (unsigned char)inb(datap);
		temp2 = temp & 0x00;
		outb(temp2, datap);
         }
         else if ((key[1] == 'l') && (key[2] == 'l') && (key[4] == '1'))
         {
		outb(0xA0, indexp);
		temp = (unsigned char)inb(datap);
		temp2 = temp | 0x00;
		outb(temp2, datap);

   		outb(0xA1, indexp);
		temp = (unsigned char)inb(datap);
		temp2 = temp | 0xff;
		outb(temp2, datap);
         }
         else
         {;}
         break;
      case 'r':
	if ((key[1] == 'd') && (key[2] == '1'))
         {
		//GPIO input 
		outb(0xA0, indexp);
		temp = (unsigned char)inb(datap);
		temp2 = temp & 0xfe;
		outb(temp2, datap);

	//Read GPIO STS
	outb(0xA2, indexp);
	temp = (unsigned char)inb(datap);/* Pin1 GP50 */
            printf("pin1:  %d   \n", (temp >> 0) & 0x1);
         }

	else if ((key[1] == 'd') && (key[2] == '2'))
         {
		//GPIO input 
		outb(0xA0, indexp);
		temp = (unsigned char)inb(datap);
		temp2 = temp & 0xfd;
		outb(temp2, datap);

	//Read GPIO STS
	outb(0xA2, indexp);
	temp = (unsigned char)inb(datap);/* Pin3 GP51 */
            printf("pin3:  %d   \n", (temp >> 1) & 0x1);
         }

	else if  ((key[1] == 'd') && (key[2] == '3'))
         {
		//GPIO input 
		outb(0xA0, indexp);
		temp = (unsigned char)inb(datap);
		temp2 = temp & 0xfb;
		outb(temp2, datap);

	//Read GPIO STS
	outb(0xA2, indexp);
        temp = (unsigned char)inb(datap);/* Pin5 GP52 */
            printf("pin5:  %d   \n", (temp >> 2) & 0x1);
         }

	else if  ((key[1] == 'd') && (key[2] == '4'))
         {
		//GPIO input 
		outb(0xA0, indexp);
		temp = (unsigned char)inb(datap);
		temp2 = temp & 0xf7;
		outb(temp2, datap);

	//Read GPIO STS
	outb(0xA2, indexp);
        temp = (unsigned char)inb(datap);/* Pin7 GP53 */
            printf("pin7:  %d   \n", (temp >> 3) & 0x1);
         }

	else if  ((key[1] == 'd') && (key[2] == '5'))
         {
		//GPIO input 
		outb(0xA0, indexp);
		temp = (unsigned char)inb(datap);
		temp2 = temp & 0xef;
		outb(temp2, datap);

	//Read GPIO STS
	outb(0xA2, indexp);
        temp = (unsigned char)inb(datap);/* Pin4 GP54 */
            printf("pin4:  %d   \n", (temp >> 4) & 0x1);
         }

	else if  ((key[1] == 'd') && (key[2] == '6'))
         {
		//GPIO input 
		outb(0xA0, indexp);
		temp = (unsigned char)inb(datap);
		temp2 = temp & 0xdf;
		outb(temp2, datap);

	//Read GPIO STS
	outb(0xA2, indexp);
        temp = (unsigned char)inb(datap);/* Pin6 GP55 */
            printf("pin6:  %d   \n", (temp >> 5) & 0x1);
         }

	else if  ((key[1] == 'd') && (key[2] == '7'))
         {
		//GPIO input 
		outb(0xA0, indexp);
		temp = (unsigned char)inb(datap);
		temp2 = temp & 0xbf;
		outb(temp2, datap);

	//Read GPIO STS
	outb(0xA2, indexp);
        temp = (unsigned char)inb(datap);/* Pin8 GP56 */
            printf("pin8:  %d   \n", (temp >> 6) & 0x1);
         }

	else if  ((key[1] == 'd') && (key[2] == '8'))
         {
		//GPIO input 
		outb(0xA0, indexp);
		temp = (unsigned char)inb(datap);
		temp2 = temp & 0x7f;
		outb(temp2, datap);

	//Read GPIO STS
	outb(0xA2, indexp);
        temp = (unsigned char)inb(datap);/* Pin10 GP57 */
            printf("pin10:  %d   \n", (temp >> 7) & 0x1);
         }

         else if ((key[1] == 'd') && (key[2] == 'a'))
         {
		//GPIO input 
		outb(0xA0, indexp);
		temp = (unsigned char)inb(datap);
		temp2 = temp & 0xff;
		outb(temp2, datap);
	//Read GPIO STS
	outb(0xA2, indexp);
	temp = (unsigned char)inb(datap);/* Pin1 GP50 */
            printf("pin1:  %d   ", (temp >> 0) & 0x1);
	temp = (unsigned char)inb(datap);/* Pin3 GP51 */
            printf("pin3:  %d   ", (temp >> 1) & 0x1);
        temp = (unsigned char)inb(datap);/* Pin5 GP52 */
            printf("pin5:  %d   ", (temp >> 2) & 0x1);
        temp = (unsigned char)inb(datap);/* Pin7 GP53 */
            printf("pin7:  %d   \n", (temp >> 3) & 0x1);
        temp = (unsigned char)inb(datap);/* Pin4 GP54 */
            printf("pin4:  %d   ", (temp >> 4) & 0x1);
        temp = (unsigned char)inb(datap);/* Pin6 GP55 */
            printf("pin6:  %d   ", (temp >> 5) & 0x1);
        temp = (unsigned char)inb(datap);/* Pin8 GP56 */
            printf("pin8:  %d   ", (temp >> 6) & 0x1);
        temp = (unsigned char)inb(datap);/* Pin10 GP57 */
            printf("pin10:  %d   \n", (temp >> 7) & 0x1);
         }
         else
         {;}
         break;
      case 'q':
         if (key[1] == 't')
         {

	    outb(0xAA, indexp);
            quit = 0;
         }
         else
         {;}
         break;
      default:break;
   }
   }
   printf("quit!\n");
}
