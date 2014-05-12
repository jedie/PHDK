#include "include\Common.h"
#include "include\Memory.h"
#include "include\File.h"
#include "include\Execution.h"
#include "include\Display.h"
#include "include\Utilities.h"
#include "include\Strings.h"

#include "symbols.h"

int count;

void button_handler(menu *caller, int button_pressed, int firstRun)
{
	const void* api = iconDisplayAPI(caller, 0x1406002); // 0x1406002

	do
	{
		if (button_pressed == BUTTON_INFO)
		{
			// i wonder if this is the info button, it seems to interact with the same
			// id used in the display code. Maybe you register some text to be rendered later
			// on demand?

			// think this is some rendering thing
			
			((VOID_THREE_PARAM)0xA063333C)(caller, 0, 0); //sub_A063333C(this, 0, 0);
			//break;
		}
		else if (button_pressed == BUTTON_OK)
		{
			// jump to live view
			//((VOID_TWO_PARAM)0xA00D3C48)(caller, 3); // live view
			//((VOID_TWO_PARAM)0xA00D3C48)(caller, 2); //jump to initial mode screen  
			((VOID_TWO_PARAM)0xA00D3C48)(caller, 1); // ???
			break;
		}
		else if (button_pressed == BUTTON_PLAY)
		{
			// jump to play function
			//((VOID_TWO_PARAM)0xA00D3C70)(caller, 1); // play mode
			//((VOID_TWO_PARAM)0xA00D3C70)(caller, 2); // slideshow
			((VOID_TWO_PARAM)0xA00D3C70)(caller, 0); // ???
			break;
		}

		if (firstRun)
		{
			count = 0;
		}

		char* buffer = (char*)malloc(150);
		if (buffer != NULL)
		{
			char * line;
			switch (count)
			{
			case 0: line = "booting Linux..."; break;
			case 1: line = "INIT: version 2.78 booting"; break;
			case 2: line = "Running Linux kernel 2.6.11"; break;
			case 3: line = "OMG LULZ!!!"; break;
			case 4: line = "Sorry! I can't boot Linux just yet..."; break;
			case 5: line = "but I am running my own code!"; break;
			case 6: line = "This means I have full control"; break;
			case 7: line = "of this Pentax DSLR camera."; break;
			case 8: line = "I realize the irony of submitting a"; break;
			case 9: line = "Pentax hack to win a Nikon"; break;
			case 10: line = "but hey, LOLCATZ anyone?"; break;
			case 11: ((VOID_TWO_PARAM)0xA00D3C70)(caller,1); break;
			}

			++count;

			sprintf(buffer, line);
			iconDisplayTxt(api, buffer);

			free(buffer);
		}
		//iconDisplayTxt(api, "It worked!");

	} while (FALSE);

	
}